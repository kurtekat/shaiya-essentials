#pragma once
#include "include/shaiya/common.h"
#include "include/shaiya/include/Attribute.h"
#include "include/shaiya/include/Country.h"
#include "include/shaiya/include/Grow.h"

namespace shaiya
{
    enum struct ExtDuration : UINT8
    {
        None,
        Unexpandable,
        Expandable
    };

    enum struct ItemEffect : UINT8
    {
        HypnosisCure = 1,
        StunCure,
        SilenceCure,
        DarknessCure,
        StopCure,
        SlowCure,
        ProtectedFaint,
        ProtectedDeath,
        VenomCure,
        DiseaseCure,
        DisorderCure,
        ArcanePotion = 17,
        CurePotion,
        DispelPotion,
        AbolishingPotion,
        BlessingPotion,
        HolyPotion,
        PerfectCure = 26,
        GoddessBlessing = 30,
        PartyMemberSummon,
        PartyMemberMoveTo,
        SkillReset,
        StatReset,
        WarehouseRecall,
        LinkingHammer,
        Resurrection,
        MessageToServer,
        Teleportation,
        RepairHammer,
        TargetResurrect,
        ItemCreate,
        IncreaseFame,
        AppearanceChange,
        SexChange,
        Firework,
        CapitalRecall,
        BootleggeryRecall,
        ArenaRecall,
        ExpRemoval,
        NameChange,
        Etin1,
        Etin10,
        Etin100,
        Etin1000,
        GuildHouseRecall,
        LuckyCharm,
        ExtractionHammer,
        MoveWar,
        ItemCompose = 62,
        EnergyCrystal,
        EquipMale,
        EquipFemale,
        PerfectLinkingHammer = 69,
        MobGen = 73,
        PremiumLapisiaLv1 = 76,
        PremiumLapisiaLv2,
        PremiumLapisiaLv3,
        CrowleyEssence = 85,
        ItemComposeStr,
        ItemComposeDex,
        ItemComposeInt,
        ItemComposeWis,
        ItemComposeRec,
        ItemComposeLuc,
        CrowleyLiquid,
        ItemRemakeStr,
        ItemRemakeDex,
        ItemRemakeInt,
        ItemRemakeWis,
        ItemRemakeRec,
        ItemRemakeLuc,
        ChaoticSquare,
        DungeonMap,
        CraftingHammer = 102,
        LapisianLuckyCharm,
        TownMoveScroll,
        TransferRubiksCube,
        Catalyst,
        EnchantEnhancer,
        Dye = 110,
        HaloReactor,
        Spellbook,
        EternalContinuousResurrect,
        EternalPreventItemDrop,
        EternalPreventExpDrop,
        TyrosStone,
        AbsoluteRecreationRune,
        NpcRecall = 200,
        Item500 = 210,
        // pick-up pets
        PetGold = 212,
        PetItem,
        PetGoldItem
    };

    enum struct ItemType : UINT8
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
        Lapisian,
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

    enum struct ReqOg : UINT8
    {
        Tradable,
        AccountBound,
        CharacterBound
    };

    #pragma pack(push, 1)
    struct ItemInfo
    {
        char* name;               //0x00
        char* desc;               //0x04
        UINT8 type;               //0x08
        UINT8 typeId;             //0x09
        UINT8 model;              //0x0A
        UINT8 icon;               //0x0B
        UINT16 reqLevel;          //0x0C
        Country3 country;         //0x0E
        bool attackFighter;       //0x0F
        bool defenseFighter;      //0x10
        bool patrolRogue;         //0x11
        bool shootRogue;          //0x12
        bool attackMage;          //0x13
        bool defenseMage;;        //0x14
        Grow grow;                //0x15
        UINT16 reqStr;            //0x16
        UINT16 reqDex;            //0x18
        UINT16 reqRec;            //0x1A
        UINT16 reqInt;            //0x1C
        UINT16 reqWis;            //0x1E
        INT32 reqLuc;             //0x20
        INT16 reqVg;              //0x24
        ReqOg reqOg;              //0x26
        UINT8 reqIg;              //0x27
        UINT16 range;             //0x28
        UINT8 attackTime;         //0x2A
        Attribute attribute;      //0x2B
        ItemEffect effect;        //0x2C
        UINT8 slotCount;          //0x2D
        UINT16 quality;           //0x2E
        UINT16 minAtkPower;       //0x30
        UINT16 addAtkPower;       //0x32
        UINT16 defense;           //0x34
        UINT16 resistance;        //0x36
        UINT16 health;            //0x38
        UINT16 stamina;           //0x3A
        UINT16 mana;              //0x3C
        UINT16 strength;          //0x3E
        UINT16 dexterity;         //0x40
        UINT16 reaction;          //0x42
        UINT16 intelligence;      //0x44
        UINT16 wisdom;            //0x46
        UINT16 luck;              //0x48
        PAD(2);
        UINT32 buy;               //0x4C
        UINT32 sell;              //0x50
        UINT32 dropGrade;         //0x54
        UINT8 composeCount;       //0x58
        UINT8 count;              //0x59
        PAD(2);
        UINT32 duration;          //0x5C
        ExtDuration extDuration;  //0x60
        PAD(47);
        UINT8 vehicleModel;       //0x90
        PAD(3);
        UINT8 vehicleSeats;       //0x94
        PAD(3);
        UINT32 vehicleSpeed;      //0x98
        bool isSnowboard;         //0x9C
        PAD(15);
        // 0xAC
    };
    #pragma pack(pop)
}
