#include <util/util.h>
#include "include/main.h"

void __declspec(naked) naked_0x4E83CA()
{
    __asm
    {
        // realType
        movzx eax,al
        cmp eax,0x2
        je return_1
        cmp eax,0x4
        je return_1
        cmp eax,0x5
        je return_1
        cmp eax,0x6
        je return_1
        cmp eax,0x8
        je return_1

        xor eax,eax
        retn 0x4

        return_1:
        mov eax,0x1
        retn 0x4
    }
}

void hook::equipment()
{
    // CPlayerData::IsTwoHandWeapon
    util::detour((void*)0x4E83CA, naked_0x4E83CA, 6);
}
