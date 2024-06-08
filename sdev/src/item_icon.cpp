#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/CDataFile.h"
#include "include/shaiya/include/CItem.h"
#include "include/shaiya/include/ItemInfo.h"
#include "include/shaiya/include/ItemType.h"
using namespace shaiya;

void draw_item_icon(void* unknown, CItem* item, long x, long y)
{
    // original code
    typedef void(__thiscall* LPFN)(void*, D3DCOLOR, long, long, int, int, int, bool, bool);
    (*(LPFN)0x4B7240)(unknown, 0xFFFFFFFF, x, y, item->type, item->typeId, item->count, false, true);

    // skip lapis and fireworks
    if (item->type == int(ItemType::Gem) || item->type == int(ItemType::Special100))
        return;

    for (const auto& typeId : item->gems)
    {
        auto itemInfo = CDataFile::GetItemInfo(int(ItemType::Gem), typeId);
        if (!itemInfo)
            continue;

        switch (itemInfo->attribute)
        {
        case Attribute::Fire1:
        case Attribute::Fire2:
            Static::DrawRect(0x50FF0000, x, y, 32, 32);
            return;
        case Attribute::Water1:
        case Attribute::Water2:
            Static::DrawRect(0x5000FFFF, x, y, 32, 32);
            return;
        case Attribute::Earth1:
        case Attribute::Earth2:
            Static::DrawRect(0x5000FF00, x, y, 32, 32);
            return;
        case Attribute::Wind1:
        case Attribute::Wind2:
            Static::DrawRect(0x50FFFFFF, x, y, 32, 32);
            return;
        default:
            continue;
        }
    }

    auto itemInfo = CDataFile::GetItemInfo(item->type, item->typeId);
    if (!itemInfo)
        return;

    switch (itemInfo->attribute)
    {
    case Attribute::Fire1:
    case Attribute::Fire2:
        Static::DrawRect(0x50FF0000, x, y, 32, 32);
        break;
    case Attribute::Water1:
    case Attribute::Water2:
        Static::DrawRect(0x5000FFFF, x, y, 32, 32);
        break;
    case Attribute::Earth1:
    case Attribute::Earth2:
        Static::DrawRect(0x5000FF00, x, y, 32, 32);
        break;
    case Attribute::Wind1:
    case Attribute::Wind2:
        Static::DrawRect(0x50FFFFFF, x, y, 32, 32);
        break;
    default:
        break;
    }
}

unsigned u0x518287 = 0x518287;
void __declspec(naked) naked_0x51826D() 
{
    __asm 
    {
        pushad

        mov ecx,dword ptr[esp+0x30]

        push ecx // y
        push ebp // x

        // inventory->item
        lea edx,[eax+0x90E2F8]
        push edx // item

        lea ecx,[esi+0x30]
        push ecx // unknown
        call draw_item_icon
        add esp,0x10

        popad

        jmp u0x518287
    }
}

unsigned u0x4FFCF7 = 0x4FFCF7;
void __declspec(naked) naked_0x4FFCE3() 
{
    __asm 
    {
        pushad

        mov edi,dword ptr[esp+0x30]
        mov eax,dword ptr[esp+0x38]
        mov ecx,dword ptr[esp+0x3C]

        push eax // y
        push ecx // x

        // inventory->item
        lea edx,[esi+0x90E2F8]
        push edx // item
        push edi // unknown
        call draw_item_icon
        add esp,0x10

        popad

        jmp u0x4FFCF7
    }
}

void hook::item_icon()
{
    // inventory
    util::detour((void*)0x51826D, naked_0x51826D, 8);
    // quickslot
    util::detour((void*)0x4FFCE3, naked_0x4FFCE3, 5);
}