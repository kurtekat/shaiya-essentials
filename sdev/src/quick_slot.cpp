#include <format>
#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/CQuickSlot.h"
#include "include/shaiya/include/Unknown.h"
using namespace shaiya;

namespace quick_slot
{
    void get_configuration(Unknown* unknown)
    {
        auto section = std::format("INTERFACE_{}X{}", g_var->viewport.Width, g_var->viewport.Height);
        auto x = GetPrivateProfileIntA(section.c_str(), "QUICKSLOT3_POS_X", 0, g_var->iniFileName.data());
        auto y = GetPrivateProfileIntA(section.c_str(), "QUICKSLOT3_POS_Y", 0, g_var->iniFileName.data());

        g_pQuickSlot3->pos.x = x;
        g_pQuickSlot3->pos.y = y;

        std::string str(MAX_PATH, 0);
        GetPrivateProfileStringA(section.c_str(), "QUICKSLOTPLUS_PLUS", "", str.data(), str.size(), g_var->iniFileName.data());
        unknown->quickSlot2->plus = str.compare(0, 4, "TRUE") == 0;
        CTexture::CreateFromFile(&unknown->quickSlot2->plusImage, "data/interface", "main_slot_plus.tga", 32, 64);
    }

    void set_configuration(CQuickSlot* quickSlot)
    {
        auto section = std::format("INTERFACE_{}X{}", g_var->viewport.Width, g_var->viewport.Height);

        if (quickSlot->id == 1)
        {
            std::string value = quickSlot->plus ? "TRUE" : "FALSE";
            WritePrivateProfileStringA(section.c_str(), "QUICKSLOTPLUS_PLUS", value.c_str(), g_var->iniFileName.data());
        }

        if (quickSlot->id == 2)
        {
            auto x = std::to_string(g_pQuickSlot3->pos.x);
            auto y = std::to_string(g_pQuickSlot3->pos.y);
            WritePrivateProfileStringA(section.c_str(), "QUICKSLOT3_POS_X", x.c_str(), g_var->iniFileName.data());
            WritePrivateProfileStringA(section.c_str(), "QUICKSLOT3_POS_Y", y.c_str(), g_var->iniFileName.data());
        }
    }

    void create(Unknown* unknown)
    {
        auto block = Static::malloc(sizeof(CQuickSlot));
        if (!block)
            return;

        g_pQuickSlot3 = CQuickSlot::Create(block, 2);
        g_pQuickSlot3->bag = 2;
        g_pPlayerData->quickSlot3Bag = 2;
        get_configuration(unknown);

        if (!unknown->quickSlot1->plus || !unknown->quickSlot2->plus)
            g_pQuickSlot3->visible = false;
    }

    BOOL bag_to_bag(int bag, int slot)
    {
        return CQuickSlot::BagToBag(g_pQuickSlot3, bag, slot);
    }

    void reset(Unknown* unknown)
    {
        if (!g_pQuickSlot3)
            return;

        CQuickSlot::Reset(g_pQuickSlot3, true);
        g_pQuickSlot3 = nullptr;
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
        call quick_slot::set_configuration
        add esp,0x4

        popad

        jmp u0x4FE698
    }
}

unsigned u0x42B6C9 = 0x42B6C9;
void __declspec(naked) naked_0x42B6C3()
{
    __asm
    {
        pushad

        push esi
        call quick_slot::create
        add esp,0x4

        popad

        // original
        lea edx,[esi+0x1D8]
        jmp u0x42B6C9
    }
}

unsigned u0x42A68C = 0x42A68C;
void __declspec(naked) naked_0x42A686()
{
    __asm
    {
        pushad

        push esi
        call quick_slot::reset
        add esp,0x4

        popad

        // original
        mov ecx,[esi+0x190]
        jmp u0x42A68C
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
        call quick_slot::bag_to_bag
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
        call quick_slot::bag_to_bag
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
        call quick_slot::bag_to_bag
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

unsigned u0x4FF959 = 0x4FF959;
unsigned u0x4FF9A5 = 0x4FF9A5;
void __declspec(naked) naked_0x4FF950() 
{
    __asm 
    {
        // quickSlot->id
        cmp byte ptr[esi+0x124],0x2
        jge _0x4FF9A5
        jmp u0x4FF959

        _0x4FF9A5:
        jmp u0x4FF9A5
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
        jge _0x4FF44D

        // original
        mov eax,dword ptr ds:[0x7C0E8C]
        jmp u0x4FF2A0

        _0x4FF44D:
        jmp u0x4FF44D
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
        jge _0x4FFF8E

        // original
        cmp byte ptr[edi+0x124],0x0
        jmp u0x4FFE77

        _0x4FFF8E:
        mov edx,[esp+0x14]
        jmp u0x4FFF8E
    }
}

unsigned u0x4FF5D4 = 0x4FF5D4;
void __declspec(naked) naked_0x4FF5CE() 
{
    __asm 
    {
        // quickSlot->plus
        mov [esi+0x119],al
        // quickSlot->id
        cmp byte ptr[esi+0x124],0x1
        jne _0x4FF5D4

        mov edi,[g_pQuickSlot3]
        test edi,edi
        je _0x4FF5D4

        // quickSlot3->window.enabled
        mov [edi+0x20],al

        _0x4FF5D4:
        jmp u0x4FF5D4
    }
}

unsigned u0x49FA6A = 0x49FA6A;
void __declspec(naked) naked_0x49FA60()
{
    __asm 
    {
        // quickSlot1->plus
        movzx ecx,byte ptr[ecx+0x119]
        // quickSlot2->window.enabled
        mov [eax+0x20],ecx
        test ecx,ecx
        jne _0x49FA6A

        // quickSlot2->plus
        mov byte ptr[eax+0x119],cl
        mov eax,[g_pQuickSlot3]
        test eax,eax
        je _0x49FA6A

        // quickSlot3->window.enabled
        mov [eax+0x20],ecx

        _0x49FA6A:
        jmp u0x49FA6A
    }
}

void hook::quick_slot()
{
    // save configuration
    util::detour((void*)0x4FE693, naked_0x4FE693, 5);
    // allocate
    util::detour((void*)0x42B6C3, naked_0x42B6C3, 6);
    // free
    util::detour((void*)0x42A686, naked_0x42A686, 6);
    // bag to bag item
    util::detour((void*)0x4A4021, naked_0x4A4021, 7);
    // bag to bag skill
    util::detour((void*)0x4A4103, naked_0x4A4103, 8);
    // bag to bag basic action
    util::detour((void*)0x4A41D9, naked_0x4A41D9, 7);
    // plus button
    util::detour((void*)0x4FF950, naked_0x4FF950, 9);
    // interaction with contents
    util::detour((void*)0x4FF29B, naked_0x4FF29B, 5);
    util::detour((void*)0x4FFE70, naked_0x4FFE70, 7);
    // quickSlot2->plus
    util::detour((void*)0x4FF5CE, naked_0x4FF5CE, 6);
    // quickSlot2->window.enabled
    util::detour((void*)0x49FA60, naked_0x49FA60, 7);

    // quickSlot->id check
    util::write_memory((void*)0x4FEF3A, 0x02, 1);
    // remove delay
    util::write_memory((void*)0x4FE8F1, 0x90, 2);
    // remove revolver delay
    util::write_memory((void*)0x50819C, 0x90, 6);
}
