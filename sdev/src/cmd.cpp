#include <sstream>
#include <string>
#include <vector>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
using namespace shaiya;

void get_global_config()
{
    auto value = GetPrivateProfileIntA("INTERFACE", "SHOW_COSTUME", 1, g_static->iniFileName.data());
    g_showCostume = value ? true : false;

    value = GetPrivateProfileIntA("INTERFACE", "SHOW_WINGS", 1, g_static->iniFileName.data());
    g_showWings = value ? true : false;

    value = GetPrivateProfileIntA("INTERFACE", "SHOW_EFT", 1, g_static->iniFileName.data());
    g_showEft = value ? true : false;

    value = GetPrivateProfileIntA("INTERFACE", "SHOW_PET", 1, g_static->iniFileName.data());
    g_showPet = value ? true : false;
    g_showMobEft = g_showPet;
}

int command_handler(char* text)
{
    std::istringstream iss(text);
    std::vector<std::string> argv;

    for (std::string str; std::getline(iss, str, ' '); )
        argv.push_back(str);

    if (argv.empty())
        return 0;

    auto argc = argv.size();

    if (iss.str() == "/eft on")
    {
        g_showEft = true;
        g_showMobEft = true;
        WritePrivateProfileStringA("INTERFACE", "SHOW_EFT", "1", g_static->iniFileName.data());
        return 0;
    }

    if (iss.str() == "/eft off")
    {
        g_showEft = false;
        g_showMobEft = false;
        WritePrivateProfileStringA("INTERFACE", "SHOW_EFT", "0", g_static->iniFileName.data());
        return 0;
    }

    if (iss.str() == "/pet on")
    {
        g_showMobEft = true;
        g_showPet = true;
        WritePrivateProfileStringA("INTERFACE", "SHOW_PET", "1", g_static->iniFileName.data());
        return 0;
    }

    if (iss.str() == "/pet off")
    {
        g_showMobEft = false;
        g_showPet = false;
        WritePrivateProfileStringA("INTERFACE", "SHOW_PET", "0", g_static->iniFileName.data());
        return 0;
    }

    if (iss.str() == "/wings on")
    {
        g_showWings = true;
        WritePrivateProfileStringA("INTERFACE", "SHOW_WINGS", "1", g_static->iniFileName.data());
        return 0;
    }

    if (iss.str() == "/wings off")
    {
        g_showWings = false;
        WritePrivateProfileStringA("INTERFACE", "SHOW_WINGS", "0", g_static->iniFileName.data());
        return 0;
    }

    if (iss.str() == "/costume on")
    {
        g_showCostume = true;
        WritePrivateProfileStringA("INTERFACE", "SHOW_COSTUME", "1", g_static->iniFileName.data());
        return 0;
    }

    if (iss.str() == "/costume off")
    {
        g_showCostume = false;
        WritePrivateProfileStringA("INTERFACE", "SHOW_COSTUME", "0", g_static->iniFileName.data());
        return 0;
    }

    return 1;
}

unsigned u0x406140 = 0x406140;
void __declspec(naked) naked_0x40613A()
{
    __asm 
    {
        pushad

        call get_global_config

        popad

        // original
        mov edi,dword ptr ds:[0x746348]
        jmp u0x406140
    }
}

unsigned u0x4867A6 = 0x4867A6;
unsigned u0x487532 = 0x487532;
void __declspec(naked) naked_0x4867A1() 
{
    __asm 
    {
        pushad

        push edi
        call command_handler
        add esp,0x4
        test eax,eax

        popad

        je _0x487532

        // original
        push 0x13D4
        jmp u0x4867A6

        _0x487532:
        jmp u0x487532
    }
}

unsigned u0x41634D = 0x41634D;
void __declspec(naked) naked_0x416343()
{
    __asm 
    {
        cmp dword ptr[g_showCostume],0x1
        jne label

        // original
        mov dword ptr[esi+0xAC],0x1
        jmp u0x41634D

        label:
        mov dword ptr[esi+0xAC],0x0
        jmp u0x41634D
    }
}

unsigned u0x59F092 = 0x59F092;
unsigned u0x59F4BA = 0x59F4BA;
void __declspec(naked) naked_0x59F08B()
{
    __asm 
    {
        movzx ecx,byte ptr[edi+0x7]
        cmp ecx,0x96
        je label

        original:
        mov eax,[edi+0x2]
        jmp u0x59F092

        label:
        cmp dword ptr[g_showCostume],0x1
        jne _0x59F4BA
        jmp original

        _0x59F4BA:
        jmp u0x59F4BA
    }
}

unsigned u0x459127 = 0x459127;
void __declspec(naked) naked_0x459120() 
{
    __asm 
    {
        cmp dword ptr[g_showEft],0x1
        je _original

        retn 0x18

        _original:
        mov eax,[esp+0x4]
        sub esp,0x10
        jmp u0x459127
    }
}

unsigned u0x43A307 = 0x43A307;
void __declspec(naked) naked_0x43A300() 
{
    __asm 
    {
        cmp dword ptr[g_showEft],0x1
        je _original

        retn 0x18

        _original:
        mov eax,[esp+0x4]
        sub esp,0x10
        jmp u0x43A307
    }
}

unsigned u0x41A2C7 = 0x41A2C7;
void __declspec(naked) naked_0x41A2C0() 
{
    __asm 
    {
        cmp dword ptr[g_showEft],0x1
        je _original

        retn 0x1C

        _original:
        mov eax,[esp+0x4]
        sub esp,0x10
        jmp u0x41A2C7
    }
}

unsigned u0x43A2FA = 0x43A2FA;
unsigned u0x43A147 = 0x43A147;
void __declspec(naked) naked_0x43A142()
{
    __asm 
    {
        cmp dword ptr[g_showMobEft],0x0
        je _0x43A2FA
        cmp dword ptr[g_showEft],0x1
        je _original

        _0x43A2FA:
        jmp u0x43A2FA

        _original:
        mov edi,ecx
        mov edx,[edi+0x30]
        jmp u0x43A147
    }
}

unsigned u0x418305 = 0x418305;
unsigned u0x4184CF = 0x4184CF;
void __declspec(naked) naked_0x4182FF() 
{
    __asm 
    {
        // original
        mov eax,[ebx+0x430]

        cmp dword ptr[g_showPet],0x1
        jne _0x4184CF
        jmp u0x418305

        _0x4184CF:
        jmp u0x4184CF
    }
}

unsigned u0x41F81D = 0x41F81D;
unsigned u0x41F9ED = 0x41F9ED;
void __declspec(naked) naked_0x41F816() 
{
    __asm 
    {
         // original
        mov eax,[esi+0x434]
        push edi

        cmp dword ptr[g_showWings],0x1
        jne _0x41F9ED
        jmp u0x41F81D

        _0x41F9ED:
        jmp u0x41F9ED
    }
}

void hook::cmd()
{
    // get client config
    util::detour((void*)0x40613A, naked_0x40613A, 6);
    // commands
    util::detour((void*)0x4867A1, naked_0x4867A1, 5);
    // show or hide costumes
    util::detour((void*)0x59F08B, naked_0x59F08B, 7);
    util::detour((void*)0x416343, naked_0x416343, 10);
    // shen1l's effect on/off
    util::detour((void*)0x459120, naked_0x459120, 7);
    util::detour((void*)0x43A300, naked_0x43A300, 7);
    util::detour((void*)0x41A2C0, naked_0x41A2C0, 7);
    // show or hide pets
    util::detour((void*)0x4182FF, naked_0x4182FF, 6);
    // show or hide wings
    util::detour((void*)0x41F816, naked_0x41F816, 7);
    // show or hide mob effects
    util::detour((void*)0x43A142, naked_0x43A142, 5);
}
