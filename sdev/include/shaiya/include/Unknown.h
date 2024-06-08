#pragma once
#include "include/shaiya/common.h"

namespace shaiya
{
    struct CQuickSlot;

    #pragma pack(push, 1)
    struct Unknown
    {
        PAD(424);
        CQuickSlot* quickSlot1;          //0x1A8
        CQuickSlot* quickSlot2;          //0x1AC
        PAD(136);
        // custom
        CQuickSlot* quickSlot3;          //0x238
        PAD(9624);
        // 0x27D4
    };
    #pragma pack(pop)
}
