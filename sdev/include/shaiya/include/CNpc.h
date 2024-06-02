#pragma once
#include <include/shaiya/common.h>
#include <include/shaiya/include/NpcType.h>

namespace shaiya
{
    #pragma pack(push, 1)
    // 0049AB60 ctor
    struct CNpc
    {
        PAD(56);
        D3DVECTOR pos;  //0x38
        D3DVECTOR dir;  //0x44
        D3DVECTOR up;   //0x50
        ULONG id;       //0x5C
        NpcType8 type;  //0x60
        PAD(1);
        UINT16 typeId;  //0x62
        PAD(200);
        // 0x12C
    };
    #pragma pack(pop)
}
