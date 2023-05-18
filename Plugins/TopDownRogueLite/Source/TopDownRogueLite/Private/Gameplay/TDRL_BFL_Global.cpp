// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BFL_Global.h"
#include "TDRL_Character.h"
#include "TDRL_NPCController.h"
#include "TDRL_HUD.h"
#include "TDRL_PlayersSpawn.h"
#include "TDRL_GameplayTypes.h"
#include "TDRL_GameModeBase.h"
#include "TDRL_GameStateBase.h"

#include "Async/ParallelFor.h"
#include "Materials/MaterialInstance.h"
#include "Animation/Skeleton.h"

#include "Chaos/ChaosEngineInterface.h"
#include "PhysicalMaterials/PhysicalMaterial.h"

#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"

#include "Engine/SkeletalMesh.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Engine/DataTable.h"
#include "Engine/DecalActor.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

#include "SkeletalMeshMerge.h"

#include "NiagaraFunctionLibrary.h"

#pragma region HUD

ATDRL_HUD* UTDRL_BFL_Global::GetTDRLHUD(UObject* WorldContextObject)
{
	if (!UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		return nullptr;
	}
	return Cast<ATDRL_HUD>(UGameplayStatics::GetPlayerController(WorldContextObject, 0)->GetHUD());
}

#pragma endregion

#pragma region Gameplay

ATDRL_Character* UTDRL_BFL_Global::GetPlayerCharacterTDRL(UObject* WorldContextObject)
{
	if (!UGameplayStatics::GetPlayerCharacter(WorldContextObject, 0))
	{
		return nullptr;
	}
	return Cast<ATDRL_Character>(UGameplayStatics::GetPlayerCharacter(WorldContextObject, 0));
}

ATDRL_GameModeBase* UTDRL_BFL_Global::GetGameModeTDRL(UObject* WorldContextObject)
{
	if (!WorldContextObject)
	{
		return nullptr;
	}
	if (WorldContextObject->GetWorld())
	{
		return nullptr;
	}

	return WorldContextObject->GetWorld()->GetAuthGameMode<ATDRL_GameModeBase>();
}

ATDRL_GameStateBase* UTDRL_BFL_Global::GetGameStateTDRL(UObject* WorldContextObject)
{
	if (!WorldContextObject)
	{
		return nullptr;
	}
	if (WorldContextObject->GetWorld())
	{
		return nullptr;
	}

	return WorldContextObject->GetWorld()->GetGameState<ATDRL_GameStateBase>();
}

void UTDRL_BFL_Global::SetActorHiddenInGameWithAttached(UObject* WorldContextObject, AActor* InActor,
                                                        const bool bShouldHide)
{
	TArray<AActor*> ActorsToHide = TArray<AActor*>{InActor};
	InActor->GetAttachedActors(ActorsToHide, false, true);

	for (auto& Act : ActorsToHide)
	{
		Act->SetActorHiddenInGame(bShouldHide);
	}
}

bool UTDRL_BFL_Global::IsValidStun(UObject* WorldContextObject, FStunParameters StunValue)
{
	return StunValue.IsValid();
}

TArray<class ATDRL_PlayersSpawn*> UTDRL_BFL_Global::GetAllPlayersSpawn(UObject* WorldContextObject)
{
	if (!WorldContextObject)
	{
		return TArray<class ATDRL_PlayersSpawn*>();
	}

	TArray<AActor*> FoundActors = TArray<AActor*>();
	UGameplayStatics::GetAllActorsOfClass(WorldContextObject, ATDRL_PlayersSpawn::StaticClass(), FoundActors);
	TArray<ATDRL_PlayersSpawn*> PlayersStartArray = TArray<ATDRL_PlayersSpawn*>();
	PlayersStartArray.Init(nullptr, FoundActors.Num());

	ParallelFor(FoundActors.Num(), [&](int32 Idx)
	{
		PlayersStartArray[Idx] = Cast<ATDRL_PlayersSpawn>(FoundActors[Idx]);
	});

	return PlayersStartArray;
}

#pragma endregion

#pragma region Skeletal Merge

USkeletalMesh* UTDRL_BFL_Global::MergeSkeletalMeshes(UObject* WorldContextObject,
                                                     const FMergeSkeletalMeshesParameters& Params)
{
	TArray<USkeletalMesh*> MeshesToMergeCopy = Params.MeshesToMerge;

	MeshesToMergeCopy.RemoveAll([](USkeletalMesh* InMesh)
	{
		return InMesh == nullptr;
	});

	if (MeshesToMergeCopy.Num() <= 1)
	{
		if (MeshesToMergeCopy.Num() == 1)
		{
			return MeshesToMergeCopy[0];
		}

		UE_LOG(LogTemp, Warning, TEXT("Must provide multiple valid Skeletal Meshes in order to perform a merge."));
		return nullptr;
	}
	EMeshBufferAccess BufferAccess = Params.bNeedsCpuAccess
		                                 ? EMeshBufferAccess::ForceCPUAndGPU
		                                 : EMeshBufferAccess::Default;

	TArray<FSkelMeshMergeSectionMapping> SectionMappings = Params.MeshSectionMappings;
	const FSkelMeshMergeUVTransformMapping* UvTransforms = &Params.UVTransformsPerMesh;

	bool bRunDuplicateCheck = false;
	USkeletalMesh* BaseMesh = NewObject<USkeletalMesh>(WorldContextObject,
	                                                   MakeUniqueObjectName(
		                                                   WorldContextObject, USkeletalMesh::StaticClass(),
		                                                   FName("MergedSkeletalAsset")));
	if (Params.bSkeletonBefore)
	{
		if (Params.Skeleton)
		{
			BaseMesh->SetSkeleton(Params.Skeleton);
		}
		else
		{
			BaseMesh->SetSkeleton(Params.MeshesToMerge[0]->GetSkeleton());
		}

		bRunDuplicateCheck = true;
		for (USkeletalMeshSocket* Socket : BaseMesh->GetMeshOnlySocketList())
		{
			if (Socket)
			{
				UE_LOG(LogTemp, Warning, TEXT("SkelMeshSocket: %s"), *(Socket->SocketName.ToString()));
			}
		}
		for (USkeletalMeshSocket* Socket : BaseMesh->GetSkeleton()->Sockets)
		{
			if (Socket)
			{
				UE_LOG(LogTemp, Warning, TEXT("SkelSocket: %s"), *(Socket->SocketName.ToString()));
			}
		}
	}

	FSkeletalMeshMerge Merger(BaseMesh, MeshesToMergeCopy, SectionMappings, Params.StripTopLODS, BufferAccess,
	                          UvTransforms);

	if (!Merger.DoMerge())
	{
		UE_LOG(LogTemp, Warning, TEXT("Merge failed!"));
		return nullptr;
	}

	if (!Params.bSkeletonBefore)
	{
		if (Params.Skeleton)
		{
			BaseMesh->SetSkeleton(Params.Skeleton);
		}
		else
		{
			BaseMesh->SetSkeleton(Params.MeshesToMerge[0]->GetSkeleton());
		}
	}
	if (bRunDuplicateCheck)
	{
		TArray<FName> SkelMeshSockets;
		TArray<FName> SkelSockets;
		for (USkeletalMeshSocket* Socket : BaseMesh->GetMeshOnlySocketList())
		{
			if (Socket)
			{
				SkelMeshSockets.Add(Socket->GetFName());
				UE_LOG(LogTemp, Warning, TEXT("SkelMeshSocket: %s"), *(Socket->SocketName.ToString()));
			}
		}
		for (USkeletalMeshSocket* Socket : BaseMesh->GetSkeleton()->Sockets)
		{
			if (Socket)
			{
				SkelSockets.Add(Socket->GetFName());
				UE_LOG(LogTemp, Warning, TEXT("SkelSocket: %s"), *(Socket->SocketName.ToString()));
			}
		}
		TSet<FName> UniqueSkelMeshSockets;
		TSet<FName> UniqueSkelSockets;
		UniqueSkelMeshSockets.Append(SkelMeshSockets);
		UniqueSkelSockets.Append(SkelSockets);
		int32 Total = SkelSockets.Num() + SkelMeshSockets.Num();
		int32 UniqueTotal = UniqueSkelMeshSockets.Num() + UniqueSkelSockets.Num();
		UE_LOG(LogTemp, Warning, TEXT("SkelMeshSocketCount: %d | SkelSocketCount: %d | Combined: %d"),
		       SkelMeshSockets.Num(), SkelSockets.Num(), Total);
		UE_LOG(LogTemp, Warning, TEXT("SkelMeshSocketCount: %d | SkelSocketCount: %d | Combined: %d"),
		       UniqueSkelMeshSockets.Num(), UniqueSkelSockets.Num(), UniqueTotal);
		UE_LOG(LogTemp, Warning, TEXT("Found Duplicates: %s"),
		       *((Total != UniqueTotal) ? FString("True") : FString("False")));
	}

	if (Params.PhysicsAsset)
	{
		BaseMesh->SetPhysicsAsset(Params.PhysicsAsset);
	}
	else
	{
		BaseMesh->SetPhysicsAsset(MeshesToMergeCopy[0]->GetPhysicsAsset());
	}

	if (Params.ShadowPhysicsAsset)
	{
		BaseMesh->SetShadowPhysicsAsset(Params.ShadowPhysicsAsset);
	}
	else
	{
		BaseMesh->SetShadowPhysicsAsset(MeshesToMergeCopy[0]->GetShadowPhysicsAsset());
	}

	BaseMesh->RebuildSocketMap();
	BaseMesh->GetRefSkeleton().RebuildRefSkeleton(BaseMesh->GetSkeleton(), true);

	return BaseMesh;
}

FMergeSkeletalMeshesParameters UTDRL_BFL_Global::CosmeticParamToMergeParam(
	UObject* WorldContextObject, const FCosmeticParameterList& Params)
{
	FMergeSkeletalMeshesParameters ParamOut;
	ParamOut.MeshesToMerge = Params.Meshes;
	ParamOut.Skeleton = Params.Skeleton;
	ParamOut.PhysicsAsset = Params.PhysicsAsset;
	ParamOut.ShadowPhysicsAsset = Params.ShadowPhysicsAsset;

	return ParamOut;
}

void UTDRL_BFL_Global::ApplyCustomProperties(UObject* WorldContextObject, const TMap<FName, FName> InProperties,
                                             AActor* InActor)
{
	if (!InActor || InProperties.Num() == 0)
	{
		return;
	}

	for (auto& property : InProperties)
	{
		// Get the property name and value from the map
		FName propertyName = property.Key;
		FName propertyValue = property.Value;

		// Get the property from the class using its name
		FProperty* classProperty = FindFProperty<FProperty>(InActor->GetClass(), propertyName);

		// If the property exists in the class, we can set its value
		if (classProperty)
		{
			// Convert the FName value to the appropriate type
			if (classProperty->GetClass() == FBoolProperty::StaticClass())
			{
				bool boolValue = (propertyValue == TEXT("True") || propertyValue == TEXT("true")) ? true : false;
				FBoolProperty* boolProperty = CastField<FBoolProperty>(classProperty);
				boolProperty->SetPropertyValue_InContainer(InActor, boolValue);
			}
			else if (classProperty->GetClass() == FIntProperty::StaticClass())
			{
				int32 intValue = FCString::Atoi(*propertyValue.ToString());
				FIntProperty* intProperty = CastField<FIntProperty>(classProperty);
				intProperty->SetPropertyValue_InContainer(InActor, intValue);
			}
			else if (classProperty->GetClass() == FFloatProperty::StaticClass())
			{
				float floatValue = FCString::Atof(*propertyValue.ToString());
				FFloatProperty* floatProperty = CastField<FFloatProperty>(classProperty);
				floatProperty->SetPropertyValue_InContainer(InActor, floatValue);
			}
			else if (classProperty->GetClass() == FByteProperty::StaticClass())
			{
				uint8 byteValue = FCString::Atof(*propertyValue.ToString());
				FByteProperty* byteProperty = CastField<FByteProperty>(classProperty);
				byteProperty->SetPropertyValue_InContainer(InActor, byteValue);
			}
			else if (classProperty->GetClass() == FNameProperty::StaticClass())
			{
				FNameProperty* byteProperty = CastField<FNameProperty>(classProperty);
				byteProperty->SetPropertyValue_InContainer(InActor, propertyValue);
			}
			else if (classProperty->GetClass() == FStrProperty::StaticClass())
			{
				FString stringValue = propertyValue.ToString();
				FStrProperty* stringProperty = CastField<FStrProperty>(classProperty);
				stringProperty->SetPropertyValue_InContainer(InActor, stringValue);
			}
			else if (classProperty->GetClass() == FStructProperty::StaticClass())
			{
				FVector vectorValue = FVector::ZeroVector;
				FString vectorString = propertyValue.ToString();

				TArray<FString> vectorComponents;
				vectorString.ParseIntoArray(vectorComponents, TEXT(","));

				if (vectorComponents.Num() == 3)
				{
					vectorValue.X = FCString::Atof(*vectorComponents[0]);
					vectorValue.Y = FCString::Atof(*vectorComponents[1]);
					vectorValue.Z = FCString::Atof(*vectorComponents[2]);

					FStructProperty* structProperty = CastField<FStructProperty>(classProperty);

					if (structProperty->Struct == TBaseStructure<FVector>::Get())
					{
						void* valuePtr = structProperty->ContainerPtrToValuePtr<void>(InActor);
						structProperty->CopyCompleteValue(valuePtr, &vectorValue);
					}
				}
			}
		}
	}
}

#pragma endregion

#pragma region VFXs

void UTDRL_BFL_Global::SpawnHitVFXsFromHit(UObject* WorldContextObject, FHitResult InHit,
                                           const UDataTable* EffectsDataTable,
                                           TArray<USceneComponent*>& GeneratedAssets)
{
	if (!InHit.PhysMaterial.IsValid() || !EffectsDataTable)
	{
		return;
	}

	FHitEffectType* CEffect = EffectsDataTable->FindRow<FHitEffectType>(FName(InHit.PhysMaterial->GetName()), "", true);

	if (!CEffect)
	{
		return;
	}

	TArray<USceneComponent*> CompOut = TArray<USceneComponent*>();

	if (CEffect->HitNiagaraEffect)
	{
		UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			WorldContextObject->GetWorld(), CEffect->HitNiagaraEffect, InHit.ImpactPoint, InHit.Normal.Rotation(),
			FVector(1.0f), true, true);
		CompOut.Add((USceneComponent*)NiagaraComp);
	}

	if (CEffect->HitParticleEffect)
	{
		UParticleSystemComponent* CParticleSyst = UGameplayStatics::SpawnEmitterAtLocation(
			WorldContextObject->GetWorld(), CEffect->HitParticleEffect,
			FTransform(InHit.Normal.Rotation(), InHit.ImpactPoint, FVector(1.0f)));
		CompOut.Add(CParticleSyst);
	}

	if (CEffect->AttachedNiagaraEffect)
	{
		UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(
			CEffect->AttachedNiagaraEffect, InHit.GetComponent(), InHit.BoneName, InHit.ImpactPoint,
			InHit.Normal.Rotation(), EAttachLocation::KeepWorldPosition, true);
		CompOut.Add((USceneComponent*)NiagaraComp);
	}

	if (CEffect->AttachedParticleEffect)
	{
		UParticleSystemComponent* CParticleSyst = UGameplayStatics::SpawnEmitterAttached(
			CEffect->AttachedParticleEffect, InHit.GetComponent(), InHit.BoneName, InHit.ImpactPoint,
			InHit.Normal.Rotation(), EAttachLocation::KeepWorldPosition, true, EPSCPoolMethod::None, true);
		CompOut.Add(CParticleSyst);
	}

	if (CEffect->SoundEffect)
	{
		CompOut.Add((USceneComponent*)UGameplayStatics::SpawnSoundAtLocation(
			WorldContextObject->GetWorld(), (USoundBase*)CEffect->SoundEffect, InHit.ImpactPoint,
			InHit.Normal.Rotation()));
	}

	FActorSpawnParameters SpawnParam;
	SpawnParam.bNoFail = true;

	if (CEffect->ActorClass)
	{
		AActor* SpawnedActor = WorldContextObject->GetWorld()->SpawnActor<AActor>(
			CEffect->ActorClass, InHit.ImpactPoint, InHit.Normal.Rotation(), SpawnParam);

		if (CEffect->AttachedMesh && SpawnedActor)
		{
			SpawnedActor->AttachToComponent(InHit.GetComponent(), FAttachmentTransformRules::KeepWorldTransform,
			                                InHit.BoneName);
			TArray<UStaticMeshComponent*> SMComps = TArray<UStaticMeshComponent*>();
			SpawnedActor->GetComponents<UStaticMeshComponent>(SMComps, true);
			if (SMComps.Num() > 0)
			{
				SMComps[0]->SetStaticMesh(CEffect->AttachedMesh);
			}
		}
	}

	if (CEffect->DecalActorClass)
	{
		ADecalActor* SpawnedDecalActor = WorldContextObject->GetWorld()->SpawnActor<ADecalActor>(
			CEffect->DecalActorClass, InHit.ImpactPoint, UKismetMathLibrary::MakeRotFromZ(InHit.Normal), SpawnParam);
		if (SpawnedDecalActor)
		{
			SpawnedDecalActor->AttachToComponent(InHit.GetComponent(), FAttachmentTransformRules::KeepWorldTransform,
			                                     InHit.BoneName);
			SpawnedDecalActor->SetActorScale3D(CEffect->DecalScale);
			if (CEffect->DecalMaterial)
			{
				SpawnedDecalActor->SetDecalMaterial(CEffect->DecalMaterial);
			}
		}
	}

	GeneratedAssets = CompOut;
}

void UTDRL_BFL_Global::SpawnStatusVFXs(UObject* WorldContextObject, const FStatusEffect Value,
                                       USceneComponent* TargetComp, const FName BoneName,
                                       TArray<USceneComponent*>& GeneratedAssets)
{
	if (!TargetComp)
	{
		return;
	}

	if (Value.NiagaraEffect)
	{
		GeneratedAssets.Add((USceneComponent*)UNiagaraFunctionLibrary::SpawnSystemAttached(
			Value.NiagaraEffect, TargetComp, BoneName, TargetComp->GetComponentLocation(),
			TargetComp->GetComponentRotation(), EAttachLocation::KeepWorldPosition, true));
	}
	else if (Value.ParticleEffect)
	{
		GeneratedAssets.Add((USceneComponent*)UGameplayStatics::SpawnEmitterAttached(
			Value.ParticleEffect, TargetComp, BoneName, TargetComp->GetComponentLocation(),
			TargetComp->GetComponentRotation(), EAttachLocation::KeepWorldPosition, true, EPSCPoolMethod::None, true));
	}

	if (Value.Montage)
	{
		USkeletalMeshComponent* CompSKTar = Cast<USkeletalMeshComponent>(TargetComp);

		if (CompSKTar)
		{
			CompSKTar->PlayAnimation(Value.Montage, false);
		}
	}
	else if (Value.SoundEffect)
	{
		GeneratedAssets.Add((USceneComponent*)UGameplayStatics::SpawnSoundAtLocation(
			WorldContextObject->GetWorld(), (USoundBase*)Value.SoundEffect, TargetComp->GetComponentLocation(),
			TargetComp->GetComponentRotation()));
	}
}

#pragma endregion
