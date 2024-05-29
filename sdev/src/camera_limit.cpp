#include <include/main.h>
#include <util/include/util.h>

unsigned u0x442BD3 = 0x442BD3;
void __declspec(naked) naked_0x442BCD()
{
    __asm
    {
        fld dword ptr[g_cameraLimit]
        jmp u0x442BD3
    }
}

void hook::camera_limit()
{
    // set cam limit
    util::detour((void*)0x442BCD, naked_0x442BCD, 6);
}
