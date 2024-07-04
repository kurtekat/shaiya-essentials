#include <map>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/CCharacter.h"
#include "include/shaiya/include/CDataFile.h"
#include "include/shaiya/include/ShaiyaColor.h"
#include "include/shaiya/include/ItemInfo.h"
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

    const std::map<uint16_t, ShaiyaColor> g_itemRangeToColor
    {
        { 1, ShaiyaColor::LightBlue },
        { 2, ShaiyaColor::Blue },
        { 3, ShaiyaColor::Green },
        { 4, ShaiyaColor::Yellow },
        { 5, ShaiyaColor::Orange },
        { 6, ShaiyaColor::Red },
        { 7, ShaiyaColor::Purple },
        { 8, ShaiyaColor::Gray }
    };

    ShaiyaColor get_mob_name_color(int mobLevel)
    {
        int gap = mobLevel - g_pPlayerData->level;
        if (gap >= 10)
            return ShaiyaColor::Gray;

        for (const auto& [diff, color] : g_levelGapToColor)
        {
            if (diff == gap)
                return color;
        }

        return ShaiyaColor::White;
    }

    D3DCOLOR get_helmet_name_color(CCharacter* user)
    {
        auto itemInfo = CDataFile::GetItemInfo(user->helmetType, user->helmetTypeId);
        if (!itemInfo)
            return 0;

        if (!itemInfo->range)
            return 0;

        for (const auto& [range, color] : g_itemRangeToColor)
        {
            if (range == itemInfo->range)
                return std::to_underlying(color);
        }

        return 0;
    }
}

void __declspec(naked) naked_0x4E50D0()
{
    __asm
    {
        push ebx
        push edi
        push esi

        movzx eax,word ptr[esp+0x10]
        push eax
        call name_color::get_mob_name_color
        add esp,0x4

        pop esi
        pop edi
        pop ebx

        retn 0x4
    }
}

unsigned u0x453821 = 0x453821;
void __declspec(naked) naked_0x45381B()
{
    __asm
    {
        push ebx
        push edi
        push esi

        push esi // user
        call name_color::get_helmet_name_color
        add esp,0x4
        test eax,eax

        pop esi
        pop edi
        pop ebx

        je original

        mov ebp,eax

        original:
        cmp dword ptr ds:[0x22AA7F8],ebx
        jmp u0x453821
    }
}

void hook::name_color()
{
    // mobs
    util::detour((void*)0x4E50D0, naked_0x4E50D0, 5);
    // users
    util::detour((void*)0x45381B, naked_0x45381B, 6);
}
