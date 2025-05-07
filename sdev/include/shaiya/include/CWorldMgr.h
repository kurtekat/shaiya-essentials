#pragma once
#include <shaiya/include/common.h>
#include "include/shaiya/common.h"

namespace shaiya
{
    struct CCharacter;
    struct CMonster;
    struct CNpc;

    #pragma pack(push, 1)
    // 0x45A0F0 ctor
    struct CWorldMgr
    {
        PAD(1300868);               //0x7C4A68
        // max: 10000
        uint32_t effectCount;       //0x9023EC  0x13D988
        PAD(9904);
        CCharacter* user;           //0x904AA0  0x140038
        PAD(536);
        // F=2048, 70=1600, D=1024
        uint32_t mapSize;           //0x904CBC  0x140254
        PAD(500);
        // see Dungeon_MiniMap.cfg
        float mapImagePosX;         //0x904EB4  0x14044C
        float mapImagePosY;         //0x904EB8  0x140450
        PAD(7972);
        // 0x906DE0  0x142378

        static CCharacter* FindUser(uint objectId);
        static CMonster* FindMob(uint objectId);
        static CNpc* FindNpc(uint objectId);
    };
    #pragma pack(pop)

    static_assert(sizeof(CWorldMgr) == 0x142378);
    static auto g_pWorldMgr = (CWorldMgr*)0x7C4A68;
}
