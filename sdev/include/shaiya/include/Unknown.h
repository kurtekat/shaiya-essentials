#pragma once
#include "include/shaiya/common.h"

namespace shaiya
{
    struct CQuickSlot;

    #pragma pack(push, 1)
    struct UI_Windows1
    {
        PAD(36);
        CQuickSlot* quickSlot1;  //0x1FC
        CQuickSlot* quickSlot2;  //0x200
        PAD(52);
        CQuickSlot* quickSlot3;  //0x238
        PAD(108);
        // 0xD0
    };
    #pragma pack(pop)

    static_assert(sizeof(UI_Windows1) == 0xD0);

    #pragma pack(push, 1)
    struct UI_Windows2
    {
        PAD(36);
        CQuickSlot* quickSlot1;  //0x2CC
        CQuickSlot* quickSlot2;  //0x2D0
        PAD(52);
        CQuickSlot* quickSlot3;  //0x308
        PAD(108);
        // 0xD0
    };
    #pragma pack(pop)

    static_assert(sizeof(UI_Windows2) == 0xD0);

    #pragma pack(push, 1)
    struct Unknown
    {
        PAD(424);
        CQuickSlot* quickSlot1;  //0x1A8
        CQuickSlot* quickSlot2;  //0x1AC
        PAD(40);
        UI_Windows1 windows1;    //0x1D8
        UI_Windows2 windows2;    //0x2A8
        // 0x378
        PAD(9308);
        // 0x27D4
    };
    #pragma pack(pop)

    static_assert(sizeof(Unknown) == 0x27D4);
}
