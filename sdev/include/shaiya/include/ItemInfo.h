#pragma once
#include <include/shaiya/common.h>

namespace shaiya
{
    enum struct ItemCountry : UINT8
    {
        Human,
        Elf,
        Light,
        DeathEater,
        Vail,
        Fury,
        Neutral
    };

    enum struct ItemExtDuration : UINT8
    {
        None,
        Unexpandable,
        Expandable
    };

    enum struct ItemReqOg : UINT8
    {
        Tradable,
        AccountBound,
        CharacterBound
    };

    enum ItemType
    {
        OneHandedSword = 1,
        TwoHandedSword,
        OneHandedAxe,
        TwoHandedAxe,
        DualWield,
        Spear,
        OneHandedBlunt,
        TwoHandedBlunt,
        ReverseDagger,
        Dagger,
        Javelin,
        Staff,
        Bow,
        Crossbow,
        Knuckles,
        LightHelmet,
        LightUpperArmor,
        LightLowerArmor,
        LightShield,
        LightGloves,
        LightShoes,
        Ring,
        Necklace,
        LightCloak,
        Consumable25,
        Gold,
        Quest27,
        Quest28,
        Quest29,
        Gem,
        FuryHelmet,
        FuryUpperArmor,
        FuryLowerArmor,
        Unknown34,
        FuryGloves,
        FuryShoes,
        Ring2,
        Consumable38,
        FuryCloak,
        Bracelet,
        Consumable41,
        Vehicle,
        Etin,
        Consumable44,
        OneHandedSword2,
        TwoHandedSword2,
        OneHandedAxe2,
        TwoHandedAxe2,
        DualWield2,
        DualWield3,
        Spear2,
        Spear3,
        OneHandedBlunt2,
        OneHandedBlunt3,
        TwoHandedBlunt2,
        TwoHandedBlunt3,
        ReverseDagger2,
        Dagger2,
        Javelin2,
        Staff2,
        Staff3,
        Bow2,
        Bow3,
        Crossbow2,
        Knuckles2,
        Unknown66,
        LightUpperArmor2,
        LightLowerArmor2,
        LightShield2,
        LightGloves2,
        LightBoots2,
        LightHelmet3,
        LightUpperArmor3,
        LightLowerArmor3,
        Unknown75,
        LightGloves3,
        LightShoes3,
        Unknown78,
        Unknown79,
        Unknown80,
        Unknown81,
        FuryUpperArmor2,
        FuryLowerArmor2,
        FuryShield2,
        FuryGloves2,
        FuryShoes2,
        FuryHelmet3,
        FuryUpperArmor3,
        FuryLowerArmor3,
        Unknown90,
        FuryGloves3,
        FuryShoes3,
        Unknown93,
        GoldBar,
        Lapisia,
        Necklace2,
        Bracelet2,
        Unknown98,
        Quest99,
        Special100,
        Special101,
        Special102,
        Pet = 120,
        Wings,
        Costume = 150
    };

    #pragma pack(push, 1)
    struct ItemInfo
    {
        char* name;             //0x00
        char* desc;             //0x04
        UINT8 type;             //0x08
        UINT8 typeId;           //0x09
        UINT8 model;            //0x0A
        UINT8 icon;             //0x0B
        UINT8 level;            //0x0C
        PAD(1);
        ItemCountry country;    //0x0E
        ReqJob job;             //0x0F
        Grow grow;              //0x15
        UINT16 reqStr;          //0x16
        UINT16 reqDex;          //0x18
        UINT16 reqRec;          //0x1A
        UINT16 reqInt;          //0x1C
        UINT16 reqWis;          //0x1E
        INT32 reqLuc;           //0x20
        INT16 reqVg;            //0x24
        ItemReqOg reqOg;        //0x26
        UINT8 reqIg;            //0x27
        UINT16 range;           //0x28
        UINT8 attackTime;       //0x2A
        Attribute attribute;    //0x2B
        UINT8 special;          //0x2C
        UINT8 slotCount;        //0x2D
        UINT16 quality;         //0x2E
        UINT16 effect1;         //0x30
        UINT16 effect2;         //0x32
        UINT16 effect3;         //0x34
        UINT16 effect4;         //0x36
        PAD(20);
        UINT32 buy;             //0x4C
        UINT32 sell;            //0x50
        UINT32 dropGrade;       //0x54
        UINT8 composeCount;     //0x58
        UINT8 count;            //0x59
        PAD(2);
        UINT32 duration;        //0x5C
        // 0x60
        ItemExtDuration extDuration;
        PAD(47);
        UINT8 vehicleModel;     //0x90
        PAD(3);
        UINT8 vehicleSeats;     //0x94
        PAD(3);
        UINT32 vehicleSpeed;    //0x98
        bool isSnowboard;       //0x9C
        PAD(15);
        // 0xAC
    };
    #pragma pack(pop)
}
