#pragma once
#include "include/shaiya/common.h"

namespace shaiya
{
    enum struct ShaiyaColor : D3DCOLOR
    {
        White = 0xFFFFFFFF,
        LightBlue = 0xFF80FFFF,
        Aqua = 0xFF00FFFF,
        Blue = 0xFF0080FF,
        DarkBlue = 0xFF00FFFF,
        Green = 0xFF00FF40,
        Yellow = 0xFFFFEE00,
        Orange = 0xFFFF8000,
        Red = 0xFFFF0000,
        Pink = 0xFFFF00FF,
        Purple = 0xFF8000FF,
        Gray = 0xFF808080,
        Black = 0xFF000000,
        Violet = 0xFF9400D3,
        Indigo = 0xFF4B0082,

        CharNameAdmin = 0xFF00FFFF,
        CharNamePvP = 0xFFFF0000,

        GuildNameMaster = 0xFFE0AFFA,
        GuildNameMember = 0xFFE4E4E4,

        // ReqDex
        ItemName00 = 0xFFFFFFFF,
        ItemName01 = 0xFF80FFFF,
        ItemName02 = 0xFF0080FF,
        ItemName03 = 0xFF00FF40,
        ItemName04 = 0xFFFFFF00,
        ItemName05 = 0xFFFF8000,
        ItemName06 = 0xFFFF00FF,
        ItemName07 = 0xFF8000FF,

        MobNameClassicBlue = 0xFF0000FF,
        MobNameClassicGreen = 0xFF00FF00,
        MobNameClassicYellow = 0xFFFFFF00,
        MobNameClassicOrange = 0xFFFF8000,
        MobNameClassicRed = 0xFFFF0000,
        MobNameClassicPink = 0xFFFF00FF,
        MobNameClassicGray = 0xFF808080,

        MobNameYellow = 0xFFF2C200,
        MobNameOrange = 0xFFF24F00,
        MobNameRed = 0xFF7D1D1E,
        MobNameGray = 0xFFADABAC
    };
}
