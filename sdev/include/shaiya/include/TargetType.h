#pragma once
#include "include/shaiya/common.h"

namespace shaiya
{
    enum struct TargetType : UINT32
    {
        Mob,
        Item,
        User,
        Npc,
        Default = UINT_MAX
    };
}
