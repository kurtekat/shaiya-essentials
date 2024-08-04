#include <map>
#include <tuple>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/CCharacter.h"
#include "include/shaiya/include/CDataFile.h"
#include "include/shaiya/include/CMonster.h"
#include "include/shaiya/include/CStaticText.h"
#include "include/shaiya/include/ItemInfo.h"
#include "include/shaiya/include/HexColor.h"
using namespace shaiya;

namespace title
{
    std::map<ItemId, std::tuple<const char*, HexColor>> mantles
    {
        { 24028, { "Champion of Teos", HexColor::Red } },
        { 24029, { "Gladiator", HexColor::Green } },
        { 24030, { "Protector", HexColor::Blue } },
        { 24031, { "Archimage", HexColor::Yellow } },
        { 24032, { "Hawk Eye", HexColor::Aqua } },
        { 24033, { "Outlaw", HexColor::Fuchsia } },
        { 24034, { "Healer", HexColor::Maroon } },
        { 24035, { "Hardcore Player", HexColor::DarkGreen } },
        { 24036, { "Duelist", HexColor::NavyBlue } },
        { 24037, { "Commander", HexColor::Olive } },
        { 24038, { "Captain", HexColor::Purple } },
        { 24039, { "Veteran", HexColor::Silver } },
        { 24040, { "War Chief", HexColor::Gray } },
        { 24041, { "Adventurer", HexColor::DarkPurple } },
        { 24042, { "Queen", HexColor::DarkBlueGray } },
        { 24043, { "King", HexColor::Teal } },
        { 24044, { "Baron", HexColor::Maroon } },
        { 24045, { "Baroness", HexColor::DarkGreen } },
        { 24046, { "Mystic", HexColor::NavyBlue } },
        { 24047, { "King of Arena", HexColor::Orange } },
        { 24048, { "Elemental Master", HexColor::Purple } },
        { 24049, { "Witch", HexColor::Teal } },
        { 24050, { "Paladin", HexColor::MediumSpringGreen } },
        { 24051, { "Shaman", HexColor::GoldenRod } },
        { 24052, { "Druid", HexColor::FireBrick } },
        { 24053, { "Death Knight", HexColor::GreenYellow } },
        { 24054, { "High Priestess", HexColor::Chartreuse } },
        { 24055, { "Interloper", HexColor::Crimson } },
        { 24056, { "Crazy Cat Lady", HexColor::HotPink } },
        { 24057, { "Mercenary", HexColor::Salmon } },
        { 24058, { "Salty", HexColor::BlueViolet } },
        { 24059, { "MVP", HexColor::CadetBlue } },
        { 24060, { "Old School", HexColor::PowderBlue } },
        { 24061, { "Cryptic", HexColor::FireBrick } },
        { 24062, { "Chill Player", HexColor::SaddleBrown } },
        { 24063, { "Farmer", HexColor::AntiqueWhite } },
        { 24064, { "Enigmatic", HexColor::LawnGreen } },
        { 24065, { "Rich", HexColor::Gold } },
        { 24066, { "Fairy", HexColor::Orchid } },
        { 24067, { "Survivor", HexColor::SpringGreen } },
        { 24068, { "Untouchable", HexColor::SteelBlue } },
        { 24069, { "Maniac", HexColor::LimeGreen } },
        { 24104, { "Love Fool", HexColor::DeepPink } },
        { 24105, { "Archivist", HexColor::LightSlateBlue } },
        { 24106, { "Hero", HexColor::Turquoise } },
        { 24107, { "Mad Scientist", HexColor::DodgerBlue } },
        { 24108, { "Artisan", HexColor::MediumSlateBlue } },
        { 24109, { "Staff Member", HexColor::DarkMagenta } },
        { 24110, { "Game Master", HexColor::DarkGoldenRod } },
        { 24114, { "Content Creator", HexColor::RosyBrown } },
    };

    constexpr float chat_y_add = 1.75F;

    void hook(CCharacter* user, float x, float y, float extrusion)
    {
        if (!user->mantleType || !user->mantleTypeId)
            return;

        auto itemInfo = CDataFile::GetItemInfo(user->mantleType, user->mantleTypeId);
        if (!itemInfo)
            return;

        auto itemId = (itemInfo->type * 1000) + itemInfo->typeId;

        auto it = mantles.find(itemId);
        if (it == mantles.end())
            return;

        auto text = std::get<0>(it->second);
        auto color = std::to_underlying(std::get<1>(it->second));

        if (!user->title.text)
        {
            user->title.text = CStaticText::Create(text);
            auto w = CStaticText::GetTextWidth(text);
            user->title.pointX = long(w * 0.5);
        }

        if (!user->title.text)
            return;

        auto posY = y - 30.0;
        auto posX = x - user->title.pointX;

        CStaticText::Draw(user->title.text, long(posX), long(posY), extrusion, color);
    }

    void reset(CCharacter* user)
    {
        if (!user->title.text)
            return;

        user->title.text->texture->Release();
        user->title.text = nullptr;
    }
}

unsigned u0x453E81 = 0x453E81;
void __declspec(naked) naked_0x453E7C()
{
    __asm
    {
        pushad
        pushfd

        sub esp,0xC
        fld dword ptr[esp+0x4C]
        fstp dword ptr[esp+0x8]

        fld dword ptr[esp+0x48]
        fstp dword ptr[esp+0x4]

        fld dword ptr[esp+0x44]
        fstp dword ptr[esp]

        push esi // user
        call title::hook
        add esp,0x10

        popfd
        popad

        // original
        mov eax,dword ptr ds:[0x22B69A8]
        jmp u0x453E81
    }
}

unsigned n0x4184CF = 0x4184CF;
unsigned u0x418312 = 0x418312;
void __declspec(naked) naked_0x41830D()
{
    __asm 
    {
        // monster->model
        cmp dword ptr[eax+0x74],0x0
        je _0x4184CF
        
        // original
        cmp dword ptr[esp+0x38],0x0
        jmp u0x418312

        _0x4184CF:
        jmp n0x4184CF
    }
}

unsigned u0x412765 = 0x412765;
void __declspec(naked) naked_0x41275F()
{
    __asm
    {
        fld dword ptr[title::chat_y_add]
        jmp u0x412765
    }
}

unsigned u0x412630 = 0x412630;
unsigned u0x59F1BC = 0x59F1BC;
void __declspec(naked) naked_0x59F1B7()
{
    __asm
    {
        // original 
        call u0x412630

        pushad

        push esi
        call title::reset
        add esp,0x4

        popad

        jmp u0x59F1BC
    }
}

unsigned u0x59F634 = 0x59F634;
void __declspec(naked) naked_0x59F62F()
{
    __asm
    {
        // original 
        call u0x412630

        pushad

        push esi
        call title::reset
        add esp,0x4

        popad

        jmp u0x59F634
    }
}

void hook::title()
{
    util::detour((void*)0x453E7C, naked_0x453E7C, 5);
    // hide pets without a model
    util::detour((void*)0x41830D, naked_0x41830D, 5);
    // increase chat balloon height (1.5 to 1.75)
    util::detour((void*)0x41275F, naked_0x41275F, 6);
    // mantle remove case
    util::detour((void*)0x59F1B7, naked_0x59F1B7, 5);
    // mantle swap case
    util::detour((void*)0x59F62F, naked_0x59F62F, 5);
}
