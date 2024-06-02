#pragma once
#include <include/shaiya/common.h>

namespace shaiya
{
    enum struct ShaiyaColor : D3DCOLOR
    {
        White = 0xFFFFFFFF,
        LightBlue = 0xFF80FFFF,
        // npc category
        Aqua = 0xFF00FFFF,
        Blue = 0xFF0080FF,
        // admin
        DarkBlue = 0xFF00FFFF,
        Green = 0xFF00FF40,
        Yellow = 0xFFFFEE00,
        MobYellow = 0xFFF2C200,
        Orange = 0xFFFF8000,
        MobOrange = 0xFFF24F00,
        Red = 0xFFFF0000,
        MobRed = 0xFF7D1D1E,
        Pink = 0xFFFF00FF,
        Purple = 0xFF8000FF,
        Gray = 0xFF808080,
        MobGray = 0xFFADABAC,
        Black = 0xFF000000,
        Violet = 0xFF9400D3,
        Indigo = 0xFF4B0082
    };
}