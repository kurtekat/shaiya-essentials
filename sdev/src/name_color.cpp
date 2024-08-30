#include <map>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/CCharacter.h"
#include "include/shaiya/include/CDataFile.h"
#include "include/shaiya/include/HexColor.h"
#include "include/shaiya/include/ItemInfo.h"
using namespace shaiya;

namespace name_color
{
    const std::map<uint16_t, HexColor> g_itemRangeToColor
    {
        { 1, HexColor::LightBlue },
        { 2, HexColor::Blue },
        { 3, HexColor::Green },
        { 4, HexColor::Yellow },
        { 5, HexColor::Orange },
        { 6, HexColor::Red },
        { 7, HexColor::Pink },
        { 8, HexColor::Purple },
        { 9, HexColor::Gray },
        { 10, HexColor::Black },
        { 11, HexColor::Cyan },
        { 12, HexColor::Magenta },
        { 13, HexColor::Brown },
        { 14, HexColor::Lime },
        { 15, HexColor::Olive },
        { 16, HexColor::Maroon },
        { 17, HexColor::Navy },
        { 18, HexColor::Teal },
        { 19, HexColor::Silver },
        { 20, HexColor::Gold },
        { 21, HexColor::Crimson },
        { 22, HexColor::Khaki },
        { 23, HexColor::Lavender },
        { 24, HexColor::Peach },
        { 25, HexColor::Coral },
        { 26, HexColor::Salmon },
        { 27, HexColor::Mint },
        { 28, HexColor::Beige },
        { 29, HexColor::Plum },
        { 30, HexColor::Orchid },
        { 31, HexColor::Rose },
        { 32, HexColor::Wheat },
        { 33, HexColor::Azure },
        { 34, HexColor::Ivory },
        { 35, HexColor::Snow },
        { 36, HexColor::Honeydew },
        { 37, HexColor::LimeGreen },
        { 38, HexColor::LightCoral },
        { 39, HexColor::LightPink },
        { 40, HexColor::SeaGreen },
        { 41, HexColor::SkyBlue },
        { 42, HexColor::SlateGray },
        { 43, HexColor::Turquoise },
        { 44, HexColor::VioletRed },
        { 45, HexColor::SpringGreen },
        { 46, HexColor::Chartreuse },
        { 47, HexColor::Sienna },
        { 48, HexColor::SlateBlue },
        { 49, HexColor::SteelBlue },
        { 50, HexColor::Tomato },
        { 51, HexColor::DarkRed },
        { 52, HexColor::DarkOrange },
        { 53, HexColor::DarkViolet },
        { 54, HexColor::LightYellow },
        { 55, HexColor::LightCyan },
        { 56, HexColor::PapayaWhip },
        { 57, HexColor::Moccasin },
        { 58, HexColor::NavajoWhite },
        { 59, HexColor::LemonChiffon },
        { 60, HexColor::MistyRose }
    };

    HexColor get_mob_name_color(int mobLevel)
    {
        int gap = mobLevel - g_pPlayerData->level;
        if (gap >= 10)
            return HexColor::Gray;

        switch (gap)
        {
        case 9: case 8:
            return HexColor::Pink;
        case 7: case 6:
            return HexColor::Red;
        case 5: case 4:
            return HexColor::Orange;
        case 3: case 2:
            return HexColor::Yellow;
        case 1: case 0: case -1:
            return HexColor::Green;
        case -2: case -3:
            return HexColor::Blue;
        case -4: case -5:
            return HexColor::LightBlue;
        default:
            break;
        }

        return HexColor::White;
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

