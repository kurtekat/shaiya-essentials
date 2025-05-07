#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/CQuickSlot.h"
#include "include/shaiya/include/Unknown.h"
using namespace shaiya;

// to-do: name these things a little better.

namespace window
{
    void assign_windows1(Unknown* unknown)
    {
        auto quickSlot3 = g_pQuickSlot3;
        unknown->windows1.quickSlot3 = quickSlot3;
    }

    void assign_windows2(Unknown* unknown)
    {
        auto quickSlot3 = g_pQuickSlot3;
        unknown->windows2.quickSlot3 = quickSlot3;
    }
}

unsigned u0x42B826 = 0x42B826;
void __declspec(naked) naked_0x42B820() 
{
    __asm
    {
        // original
        mov [esi+0x2A0],ecx

        pushad

        push esi
        call window::assign_windows1
        add esp,0x4

        popad

        jmp u0x42B826
    }
}

unsigned u0x42B9D7 = 0x42B9D7;
void __declspec(naked) naked_0x42B9D1() 
{
    __asm
    {
        // original
        mov [esi+0x370],ecx

        pushad

        push esi
        call window::assign_windows2
        add esp,0x4

        popad

        jmp u0x42B9D7
    }
}

void hook::window()
{
    // assign windows
    util::detour((void*)0x42B820, naked_0x42B820, 6);
    util::detour((void*)0x42B9D1, naked_0x42B9D1, 6);
}
