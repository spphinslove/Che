// Copyright 2023 Henry Galimberti. All Rights Reserved.

using UnrealBuildTool;

public class TopDownRogueLiteEditor : ModuleRules
{
	public TopDownRogueLiteEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
		new string[] {

		});

		PrivateIncludePaths.AddRange(
		new string[] {
			"TopDownRogueLite",
			"TopDownRogueLiteEditor",

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

		PublicDependencyModuleNames.AddRange(
		new string[]
		{
				"Core",
				"UMG",
				"UnrealEd"
			// ... add other public dependencies that you statically link with here ...
		}
		);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"TopDownRogueLite"
				
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
