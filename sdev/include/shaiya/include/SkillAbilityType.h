#pragma once
#include <include/shaiya/common.h>

namespace shaiya
{
    enum struct SkillAbilityType : UINT8
    {
        MaxHealth = 1,
        MaxMana,
        MaxStamina,
        AbilityStrength,
        AbilityReaction,
        AbilityIntelligence,
        AbilityWisdom,
        AbilityDexterity,
        AbilityLuck,
        AddHpRecovery,
        AddSpRecovery,
        AddMpRecovery,
        DecreaseSpCostPercentage,
        DecreaseMpCostPercentage,
        AbilityAttackRange,
        AbilityAttackSpeed,
        AbilityMoveSpeed,
        AbilityCriticalHitRate,
        DecreaseSkillResetTime,
        AbilityHitRate,
        AbilityRangedHitRate,
        AbilityMagicHitRate,
        AbilityAttackPower,
        AbilityRangedAttackPower,
        AbilityMagicPower,
        AbilityAddDefense,
        AbilityAddRangedDefense,
        AbilityMagicResistance,
        AbilityEvasionRate,
        AbilityRangedEvasionRate,
        AbilityMagicEvasionRate,
        AttackBlinded,
        RangedAttackBlinded,
        Silenced,
        IncreaseExpRate,
        EternalEndurance,
        PreventItemDrop,
        PreventExpLoss,
        RecallWarehouse,
        WhiteTigerCharm,
        BlueDragonCharm,
        RedPhoenixCharm,
        DoubleWarehouse,
        IncreaseGoldRate,
        PreventEquipmentDrop,
        ContinuousResurrection,
        BattlefieldRune,
        AbilityAbsorption,
        BaseStatus,
        Frenzied = 70
    };
}