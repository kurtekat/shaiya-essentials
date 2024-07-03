#include <map>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/ShaiyaColor.h"
using namespace shaiya;

namespace name_color
{
    const std::map<int, ShaiyaColor> g_levelGapToColor
    {
        { 9, ShaiyaColor::Pink },
        { 8, ShaiyaColor::Pink },
        { 7, ShaiyaColor::Red },
        { 6, ShaiyaColor::Red },
        { 5, ShaiyaColor::Orange },
        { 4, ShaiyaColor::Orange },
        { 3, ShaiyaColor::Yellow },
        { 2, ShaiyaColor::Yellow },
        { 1, ShaiyaColor::Green },
        { 0, ShaiyaColor::Green },
        { -1, ShaiyaColor::Green },
        { -2, ShaiyaColor::Blue },
        { -3, ShaiyaColor::Blue },
        { -4, ShaiyaColor::LightBlue },
        { -5, ShaiyaColor::LightBlue }
    };

    ShaiyaColor get_by_lv_gap(int level)
    {
        int gap = level - g_pPlayerData->level;
        if (gap >= 10)
            return ShaiyaColor::Gray;

        for (const auto& [diff, color] : g_levelGapToColor)
        {
            if (diff == gap)
                return color;
        }

        return ShaiyaColor::White;
    }
}

void __declspec(naked) naked_0x4E50D5()
{
    __asm
    {
        push eax // level
        call name_color::get_by_lv_gap
        add esp,0x4

        retn 0x4
    }
}

void hook::name_color()
{
    // mob name color
    util::detour((void*)0x4E50D5, naked_0x4E50D5, 6);
}
