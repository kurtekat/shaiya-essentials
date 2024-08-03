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

        if (!user->pet)
            return;

        auto itemInfo = CDataFile::GetItemInfo(user->petType, user->petTypeId);
        if (!itemInfo)
            return;

        auto itemId = (itemInfo->type * 1000) + itemInfo->typeId;

        switch (itemId) {
        case 120001:
            text = "Champion of Shaiya";
            color = 0xFFFF0000;
            break;
        case 120002:
            text = "Test2";
            color = 0xFF00FF00;
            break;
        case 120003:
            text = "Test3";
            color = 0xFF0000FF;
            break;
        case 120004:
            text = "Test4";
            color = 0xFFFFFF00;
            break;
        case 120005:
            text = "Test5";
            color = 0xFF00FFFF;
            break;
        case 120006:
            text = "Test6";
            color = 0xFFFF00FF;
            break;
        case 120007:
            text = "Test7";
            color = 0xFF800000;
            break;
        case 120008:
            text = "Test8";
            color = 0xFF008000;
            break;
        case 120009:
            text = "Test9";
            color = 0xFF000080;
            break;
        case 120010:
            text = "Test10";
            color = 0xFF808000;
            break;
        case 120011:
            text = "Test11";
            color = 0xFF800080;
            break;
        case 120012:
            text = "Test12";
            color = 0xFFC0C0C0;
            break;
        case 120013:
            text = "Test13";
            color = 0xFF808080;
            break;
        case 120014:
            text = "Test14";
            color = 0xFF400040;
            break;
        case 120015:
            text = "Test15";
            color = 0xFF004080;
            break;
        case 120016:
            text = "Test16";
            color = 0xFF008080;
            break;
        case 120017:
            text = "Test17";
            color = 0xFF800000;
            break;
        case 120018:
            text = "Test18";
            color = 0xFF008000;
            break;
        case 120019:
            text = "Test19";
            color = 0xFF000080;
            break;
        case 120020:
            text = "Test20";
            color = 0xFFFFA500;
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
