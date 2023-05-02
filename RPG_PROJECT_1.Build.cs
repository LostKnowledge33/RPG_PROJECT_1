// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RPG_PROJECT_1 : ModuleRules
{
	public RPG_PROJECT_1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "LevelSequence", "MovieScene", "AnimGraphRuntime", "AIModule", "GameplayTasks", "Niagara", "EnhancedInput", "UMG" });

        PublicIncludePaths.Add(ModuleDirectory);
    }
}
