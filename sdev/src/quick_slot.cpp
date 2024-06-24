#include <array>
#include <format>
#include <memory>
#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/CQuickSlot.h"
#include "include/shaiya/include/Unknown.h"
using namespace shaiya;

inline CQuickSlot* g_pQuickSlot3 = nullptr;

namespace quick_slot
{
    void get_config(Unknown* unknown, CQuickSlot* quickSlot)
    {
        auto section = std::format("INTERFACE_{}X{}", g_static->viewport.Width, g_static->viewport.Height);
        int x = GetPrivateProfileIntA(section.c_str(), "QUICKSLOT3_POS_X", 0, g_static->iniFileName.data());
        int y = GetPrivateProfileIntA(section.c_str(), "QUICKSLOT3_POS_Y", 0, g_static->iniFileName.data());

        quickSlot->window.pos.x = x;
        quickSlot->window.pos.y = y;

        if (!unknown->quickSlot1->plus)
            return;

        int plus = GetPrivateProfileIntA(section.c_str(), "QUICKSLOT2_PLUS", 0, g_static->iniFileName.data());
        unknown->quickSlot2->plus = plus ? true : false;
        g_pQuickSlot3->window.visible = unknown->quickSlot2->plus ? true : false;
    }

    void set_config(CQuickSlot* quickSlot)
    {
        auto section = std::format("INTERFACE_{}X{}", g_static->viewport.Width, g_static->viewport.Height);
        auto x = std::to_string(g_pQuickSlot3->window.pos.x);
        auto y = std::to_string(g_pQuickSlot3->window.pos.y);

        WritePrivateProfileStringA(section.c_str(), "QUICKSLOT3_POS_X", x.c_str(), g_static->iniFileName.data());
        WritePrivateProfileStringA(section.c_str(), "QUICKSLOT3_POS_Y", y.c_str(), g_static->iniFileName.data());

        if (quickSlot->id == 1)
        {
            std::string value = quickSlot->plus ? "1" : "0";
            WritePrivateProfileStringA(section.c_str(), "QUICKSLOT2_PLUS", value.c_str(), g_static->iniFileName.data());
        }
    }

    void init(Unknown* unknown)
    {
        auto block = std::make_unique<CQuickSlot>();

        if (block)
        {
            g_pQuickSlot3 = CQuickSlot::Init(block.release(), 2);
            g_pQuickSlot3->bag = 2;
            g_pQuickSlot3->window.visible = false;
            g_static->global.quickSlot3Bag = 2;

            get_config(unknown, g_pQuickSlot3);
            unknown->quickSlot3 = g_pQuickSlot3;
        }
    }

    BOOL set_bag_to_bag(int bag, int slot)
    {
        return CQuickSlot::BagToBag(g_pQuickSlot3, bag, slot);
    }

    void set_window_visible(CQuickSlot* quickSlot)
    {
        if (quickSlot->id == 1)
            g_pQuickSlot3->window.visible = !quickSlot->plus ? true : false;
    }
}

unsigned u0x4FE3C0 = 0x4FE3C0;
unsigned u0x4FE698 = 0x4FE698;
void __declspec(naked) naked_0x4FE693()
{
    __asm
    {
        // original
        call u0x4FE3C0

        pushad

        push esi // quickSlot
        call quick_slot::set_config
        add esp,0x4

        popad

        jmp u0x4FE698
    }
}

unsigned u0x42B6DA = 0x42B6DA;
void __declspec(naked) naked_0x42B6D4()
{
    __asm
    {
        pushad

        push esi
        call quick_slot::init
        add esp,0x4

        popad

        // original
        mov eax,[esi+0x17C]
        lea edx,[esi+0x1D8]
        jmp u0x42B6DA
    }
}

unsigned u0x4A4028 = 0x4A4028;
unsigned u0x4A4004 = 0x4A4004;
void __declspec(naked) naked_0x4A4021() 
{
    __asm 
    {
        movzx ecx,byte ptr[edi+0xFC]
        movzx edx,byte ptr[edi+0xFD]

        pushad

        push ecx // slot
        push edx // bag
        call quick_slot::set_bag_to_bag
        add esp,0x8
        test eax,eax

        popad

        jne _0x4A4004

        // original
        movzx ecx,byte ptr[edi+0xFC]
        jmp u0x4A4028

        _0x4A4004:
        jmp u0x4A4004
    }
}

unsigned u0x4A410B = 0x4A410B;
void __declspec(naked) naked_0x4A4103() 
{
    __asm 
    {
        movzx eax,byte ptr[edi+0x103]

        pushad

        push eax  // slot
        push 0x64 // bag
        call quick_slot::set_bag_to_bag
        add esp,0x8
        test eax,eax

        popad

        je _original

        mov byte ptr[edi+0x103],-0x1

        _original:
        movzx eax,byte ptr[edi+0x103]
        push eax
        jmp u0x4A410B
    }
}

unsigned u0x4A41E0 = 0x4A41E0;
unsigned u0x4A41B6 = 0x4A41B6;
void __declspec(naked) naked_0x4A41D9() 
{
    __asm 
    {
        movzx edx,byte ptr[edi+0xF8]

        pushad

        push edx  // slot
        push 0x65 // bag
        call quick_slot::set_bag_to_bag
        add esp,0x8
        test eax,eax

        popad

        jne _0x4A41B6

        // original
        movzx edx,byte ptr[edi+0xF8]
        jmp u0x4A41E0

        _0x4A41B6:
        jmp u0x4A41B6
    }
}

unsigned u0x4FE582 = 0x4FE582;
unsigned u0x4FE597 = 0x4FE597;
void __declspec(naked) naked_0x4FE57C() 
{
    __asm 
    {
        cmp byte ptr[esp+0x28],0x2
        jnl _0x4FE582
        jmp u0x4FE597

        _0x4FE582:
        jmp u0x4FE582
    }
}

unsigned u0x4FF2A0 = 0x4FF2A0;
unsigned u0x4FF44D = 0x4FF44D;
void __declspec(naked) naked_0x4FF29B() 
{
    __asm 
    {
        // quickSlot->id
        cmp byte ptr[esi+0x124],0x2
        je _0x4FF44D

        // original
        mov eax,dword ptr ds:[0x7C0E8C]
        jmp u0x4FF2A0

        _0x4FF44D:
        jmp u0x4FF44D
    }
}

unsigned u0x4FF959 = 0x4FF959;
unsigned u0x4FF9A5 = 0x4FF9A5;
void __declspec(naked) naked_0x4FF950() 
{
    __asm 
    {
        // quickSlot->id
        cmp byte ptr[esi+0x124],0x1
        ja _0x4FF9A5
        jmp u0x4FF959

        _0x4FF9A5:
        jmp u0x4FF9A5
    }
}

unsigned u0x4FF99B = 0x4FF99B;
void __declspec(naked) naked_0x4FF994() 
{
    __asm 
    {
        // original
        mov byte ptr[esi+0x121],0x1

        pushad

        push esi // quickSlot
        call quick_slot::set_window_visible
        add esp,0x4

        popad

        jmp u0x4FF99B
    }
}

unsigned u0x4FFE77 = 0x4FFE77;
unsigned u0x4FFF8E = 0x4FFF8E;
void __declspec(naked) naked_0x4FFE70() 
{
    __asm 
    {
        // quickSlot->id
        cmp byte ptr[edi+0x124],0x2
        je _label

        // original
        cmp byte ptr[edi+0x124],0x0
        jmp u0x4FFE77

        _label:
        mov edx,[esp+0x14]
        jmp u0x4FFF8E
    }
}

void hook::quick_slot()
{
    // alloc quick slot
    util::detour((void*)0x42B6D4, naked_0x42B6D4, 6);
    // bag to bag item
    util::detour((void*)0x4A4021, naked_0x4A4021, 7);
    // bag to bag skill
    util::detour((void*)0x4A4103, naked_0x4A4103, 8);
    // bag to bag basic action
    util::detour((void*)0x4A41D9, naked_0x4A41D9, 7);
    // ???
    util::detour((void*)0x4FE57C, naked_0x4FE57C, 6);
    // ???
    util::detour((void*)0x4FF29B, naked_0x4FF29B, 5);
    // drag window
    util::detour((void*)0x4FF950, naked_0x4FF950, 9);
    // quickSlot->plus
    util::detour((void*)0x4FF994, naked_0x4FF994, 7);
    // ???
    util::detour((void*)0x4FFE70, naked_0x4FFE70, 7);
    // save config
    util::detour((void*)0x4FE693, naked_0x4FE693, 5);
    // max quickSlot->id
    util::write_memory((void*)0x4FEF3A, 0x02, 1);
    // remove quick slot wait
    util::write_memory((void*)0x4FE8F1, 0x90, 2);
    // remove revolver wait
    util::write_memory((void*)0x50819C, 0x90, 6);
}
