// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Che : ModuleRules
{
	public Che(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
        PrivateIncludePaths.AddRange(
        	new string[] {
        		"../Plugins/TopDownRogueLite",
        
        		"../Plugins/TopDownRogueLite/Source/TopDownRogueLite/Public",
        		"../Plugins/TopDownRogueLite/Source/TopDownRogueLite/Public/Types",
        		"../Plugins/TopDownRogueLite/Source/TopDownRogueLite/Public/HUD",
        		"../Plugins/TopDownRogueLite/Source/TopDownRogueLite/Public/Player",
        		"../Plugins/TopDownRogueLite/Source/TopDownRogueLite/Public/Items",
        		"../Plugins/TopDownRogueLite/Source/TopDownRogueLite/Public/Projectile",
        		"../Plugins/TopDownRogueLite/Source/TopDownRogueLite/Public/AI",
        		"../Plugins/TopDownRogueLite/Source/TopDownRogueLite/Public/Nodes",
        		"../Plugins/TopDownRogueLite/Source/TopDownRogueLite/Public/GAS",
        		"../Plugins/TopDownRogueLite/Source/TopDownRogueLite/Public/Gameplay",
        	});	
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
