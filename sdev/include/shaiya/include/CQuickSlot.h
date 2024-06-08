#pragma once
#include "include/shaiya/common.h"
#include "include/shaiya/include/CWindow.h"

namespace shaiya
{
    #pragma pack(push, 1)
    struct CQuickSlot
    {
        CWindow window;  //0x00
        PAD(8);
        // 0x2C
        LPDIRECT3DBASETEXTURE9 texture;
        PAD(28);
        UINT8 bar;       //0x4C
        UINT8 srcSlot;   //0x4D
        PAD(2);
        BOOL mouseOver;  //0x50
        PAD(196);
        bool change;     //0x118
        bool plus;       //0x119
        PAD(6);
        bool rotated;    //0x120
        PAD(3);
        UINT8 id;        //0x124
        PAD(3);
        // 0x128

        static CQuickSlot* Init(void* block, int id);
        static BOOL BagToBag(CQuickSlot* quickSlot, int bag, int slot);
        static void Save(CQuickSlot* quickSlot);
    };
    #pragma pack(pop)
}
