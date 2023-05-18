// Copyright 2023 Henry Galimberti. All Rights Reserved.

using UnrealBuildTool;

public class TopDownRogueLite : ModuleRules
{
	public TopDownRogueLite(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[]
			{
			});

		PrivateIncludePaths.AddRange(
			new string[]
			{
				"TopDownRogueLite",
				"TopDownRogueLite/Public",
				"TopDownRogueLite/Public/Types",
				"TopDownRogueLite/Public/HUD",
				"TopDownRogueLite/Public/Player",
				"TopDownRogueLite/Public/Items",
				"TopDownRogueLite/Public/Projectile",
				"TopDownRogueLite/Public/AI",
				"TopDownRogueLite/Public/AI/Nodes",
				"TopDownRogueLite/Public/GAS",
				"TopDownRogueLite/Public/Gameplay",
			});


		if (Target.bBuildEditor == true)
		{
			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"UnrealEd"
				}
			);
		}

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"UMG"
				// ... add other public dependencies that you statically link with here ...
			}
		);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				//"UnrealEd",
				"Slate",
				"SlateCore",
				"InputCore",
				"AIModule",
				"GameplayTasks",
				"NavigationSystem",
				"Niagara",
				"Projects",
				"GameplayAbilities",
				"GameplayTags",
				"GameplayTasks",
				"PhysicsCore",

				// ... add private dependencies that you statically link with here ...	
			}
		);


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);
	}
}