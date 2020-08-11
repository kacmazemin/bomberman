// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class BombermanTarget : TargetRules
{
    public BombermanTarget(TargetInfo Target) : base(Target)
    {
        bUseUnityBuild = false;
        bUsePCHFiles = false;

        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.AddRange(new string[] {"Bomberman"});
    }
}