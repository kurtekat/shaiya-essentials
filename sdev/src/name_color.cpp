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
    const std::map<uint16_t, ShaiyaColor> g_itemRangeToColor
    {
        { 1, ShaiyaColor::LightBlue },
        { 2, ShaiyaColor::Blue },
        { 3, ShaiyaColor::Green },
        { 4, ShaiyaColor::Yellow },
        { 5, ShaiyaColor::Orange },
        { 6, ShaiyaColor::Red },
        { 7, ShaiyaColor::Pink },
        { 8, ShaiyaColor::Purple },
        { 9, ShaiyaColor::Gray },
        { 10, ShaiyaColor::Black }
    };

    ShaiyaColor get_mob_name_color(int mobLevel)
    {
        int gap = mobLevel - g_pPlayerData->level;
        if (gap >= 10)
            return ShaiyaColor::Gray;

        switch (gap)
        {
        case 9: case 8:
            return ShaiyaColor::Pink;
        case 7: case 6:
            return ShaiyaColor::Red;
        case 5: case 4:
            return ShaiyaColor::Orange;
        case 3: case 2:
            return ShaiyaColor::Yellow;
        case 1: case 0: case -1:
            return ShaiyaColor::Green;
        case -2: case -3:
            return ShaiyaColor::Blue;
        case -4: case -5:
            return ShaiyaColor::LightBlue;
        default:
            break;
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
