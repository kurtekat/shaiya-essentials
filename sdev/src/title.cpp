#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/CCharacter.h"
#include "include/shaiya/include/CDataFile.h"
#include "include/shaiya/include/CMonster.h"
#include "include/shaiya/include/CStaticText.h"
#include "include/shaiya/include/ItemInfo.h"
using namespace shaiya;

namespace title
{
    constexpr float chat_y_add = 1.75F;

    void hook(CCharacter* user, float x, float y, float extrusion)
    {
        const char* text = nullptr;
        int color = 0xFFFFFFFF;
        const int effectDataId = 280;

        if (!user->mantleType)
            return;

        auto itemInfo = CDataFile::GetItemInfo(user->mantleType, user->mantleTypeId);
        if (!itemInfo)
            return;

        auto itemId = (itemInfo->type * 1000) + itemInfo->typeId;

switch (itemId) {
    case 24028:
        text = "Champion of Teos";
        color = 0xFFFF0000; // Red
        break;
    case 24029:
        text = "Gladiator";
        color = 0xFF00FF00; // Green
        break;
    case 24030:
        text = "Protector";
        color = 0xFF0000FF; // Blue
        break;
    case 24031:
        text = "Archimage";
        color = 0xFFFFFF00; // Yellow
        break;
    case 24032:
        text = "Hawk Eye";
        color = 0xFF00FFFF; // Aqua
        break;
    case 24033:
        text = "Outlaw";
        color = 0xFFFF00FF; // Fuchsia
        break;
    case 24034:
        text = "Healer";
        color = 0xFF800000; // Maroon
        break;
    case 24035:
        text = "Hardcore Player";
        color = 0xFF008000; // Dark Green
        break;
    case 24036:
        text = "Duelist";
        color = 0xFF000080; // Navy
        break;
    case 24037:
        text = "Commander";
        color = 0xFF808000; // Olive
        break;
    case 24038:
        text = "Captain";
        color = 0xFF800080; // Purple
        break;
    case 24039:
        text = "Veteran";
        color = 0xFFC0C0C0; // Silver
        break;
    case 24040:
        text = "War Chief";
        color = 0xFF808080; // Gray
        break;
    case 24041:
        text = "Adventurer";
        color = 0xFF400040; // Dark Purple
        break;
    case 24042:
        text = "Queen";
        color = 0xFF004080; // Dark Blue-Gray
        break;
    case 24043:
        text = "King";
        color = 0xFF008080; // Teal
        break;
    case 24044:
        text = "Baron";
        color = 0xFF800000; // Maroon
        break;
    case 24045:
        text = "Baroness";
        color = 0xFF008000; // Dark Green
        break;
    case 24046:
        text = "Mystic";
        color = 0xFF000080; // Navy
        break;
    case 24047:
        text = "King of Arena";
        color = 0xFFFFA500; // Orange
        break;
    case 24048:
        text = "Elemental Master";
        color = 0xFF800080; // Purple
        break;
    case 24049:
        text = "Witch";
        color = 0xFF008080; // Teal
        break;
    case 24050:
        text = "Paladin";
        color = 0xFF00FA9A; // Medium Spring Green
        break;
    case 24051:
        text = "Shaman";
        color = 0xFFDAA520; // Golden Rod
        break;
    case 24052:
        text = "Druid";
        color = 0xFFB22222; // Fire Brick
        break;
    case 24053:
        text = "Death Knight";
        color = 0xFFADFF2F; // Green Yellow
        break;
    case 24054:
        text = "High Priestess";
        color = 0xFF7FFF00; // Chartreuse
        break;
    case 24055:
        text = "Interloper";
        color = 0xFFDC143C; // Crimson
        break;
    case 24056:
        text = "Crazy Cat Lady";
        color = 0xFFFF69B4; // Hot Pink
        break;
    case 24057:
        text = "Mercenary";
        color = 0xFFFA8072; // Salmon
        break;
    case 24058:
        text = "Salty";
        color = 0xFF8A2BE2; // Blue Violet
        break;
    case 24059:
        text = "MVP";
        color = 0xFF5F9F9F; // Cadet Blue
        break;
    case 24060:
        text = "Old School";
        color = 0xFFB0E0E6; // Powder Blue
        break;
    case 24061:
        text = "Cryptic";
        color = 0xFFB22222; // Fire Brick
        break;
    case 24062:
        text = "Chill Player";
        color = 0xFF8B4513; // Saddle Brown
        break;
    case 24063:
        text = "Farmer";
        color = 0xFFFAEBD7; // Antique White
        break;
    case 24064:
        text = "Enigmatic";
        color = 0xFF7CFC00; // Lawn Green
        break;
    case 24065:
        text = "Rich";
        color = 0xFFFFD700; // Gold
        break;
    case 24066:
        text = "Fairy";
        color = 0xFFDA70D6; // Orchid
        break;
    case 24067:
        text = "Survivor";
        color = 0xFF00FF7F; // Spring Green
        break;
    case 24068:
        text = "Untouchable";
        color = 0xFF4682B4; // Steel Blue
        break;
    case 24069:
        text = "Maniac";
        color = 0xFF32CD32; // Lime Green
        break;
    case 240104:
        text = "Love Fool";
        color = 0xFFFF1493; // Deep Pink
        break;
    case 24105:
        text = "Archivist";
        color = 0xFFB0C4DE; // Light Steel Blue
        break;
    case 24106:
        text = "Hero";
        color = 0xFF00CED1; // Dark Turquoise
        break;
    case 24107:
        text = "Mad Scientist";
        color = 0xFF1E90FF; // Dodger Blue
        break;
    case 24108:
        text = "Artisan";
        color = 0xFF7B68EE; // Medium Slate Blue
        break;
    case 24109:
        text = "Staff Member";
        color = 0xFF8B008B; // Dark Magenta
        break;
    case 24110:
        text = "Game Master";
        color = 0xFFB8860B; // Dark Golden Rod
        break;
    case 24114:
        text = "Content Creator";
        color = 0xFFBC8F8F; // Rosy Brown
        break;
    default:
            return;
        }

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

void hook::title()
{
    util::detour((void*)0x453E7C, naked_0x453E7C, 5);
    // hide pets without a model
    util::detour((void*)0x41830D, naked_0x41830D, 5);
    // increase chat balloon height (1.5 to 1.75)
    util::detour((void*)0x41275F, naked_0x41275F, 6);
}
