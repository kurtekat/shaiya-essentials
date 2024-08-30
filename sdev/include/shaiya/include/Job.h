#pragma once
#include "include/shaiya/common.h"

namespace shaiya
{
    enum struct Job : UINT8
    {
        AttackFighter,
        DefenseFighter,
        PatrolRogue,
        ShootRogue,
        AttackMage,
        DefenseMage
    };
}
