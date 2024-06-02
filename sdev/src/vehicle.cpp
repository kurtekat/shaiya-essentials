#include <array>
#include <map>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <include/main.h>
#include <include/shaiya/include/CCharacter.h>
#include <include/shaiya/include/CDataFile.h>
#include <include/shaiya/include/ItemInfo.h>
#include <include/shaiya/include/ItemType.h>
#include <util/include/util.h>
using namespace shaiya;

namespace vehicle
{
    int get_main_bone(int model)
    {
        for (int i = 1; i <= 255; ++i)
        {
            auto itemInfo = CDataFile::GetItemInfo(int(ItemType::Vehicle), i);

            if (!itemInfo)
                continue;

            if (itemInfo->vehicleModel == model)
            {
                if (!itemInfo->reqRec)
                    continue;

                return itemInfo->reqRec;
            }
        }

        return 0;
    }

    int get_rear_bone(int model)
    {
        for (int i = 1; i <= 255; ++i)
        {
            auto itemInfo = CDataFile::GetItemInfo(int(ItemType::Vehicle), i);

            if (!itemInfo)
                continue;

            if (itemInfo->vehicleModel == model)
            {
                if (!itemInfo->reqRec)
                    continue;

                return itemInfo->reqInt;
            }
        }

        return 0;
    }

    int set_solo_bone(int model)
    {
        // models coded in game.exe
        if (model == 31 || model == 32)
        {
            UINT8 bone = 0x03;
            std::memcpy((void*)0x414B13, &bone, 1);
            std::memcpy((void*)0x414B67, &bone, 1);
            return 1;
        }

        UINT8 main = get_main_bone(model);

        if (!main)
            return 0;

        std::memcpy((void*)0x414B13, &main, 1);
        std::memcpy((void*)0x414B67, &main, 1);
        return 1;
    }

    int set_dual_bone(int model)
    {
        // models coded in game.exe
        if (model == 14 || model == 15 || model == 21)
        {
            UINT8 rear = 0x44;
            UINT8 main = 0x31;

            // rear bone
            std::memcpy((void*)0x4137A2, &rear, 1);
            std::memcpy((void*)0x4137F6, &rear, 1);

            // main bone
            std::memcpy((void*)0x413847, &main, 1);
            std::memcpy((void*)0x41389B, &main, 1);
            return 1;
        }

        UINT8 main = get_main_bone(model);
        UINT8 rear = get_rear_bone(model);

        if (!main || !rear)
            return 0;

        // rear bone
        std::memcpy((void*)0x4137A2, &rear, 1);
        std::memcpy((void*)0x4137F6, &rear, 1);

        // main bone
        std::memcpy((void*)0x413847, &main, 1);
        std::memcpy((void*)0x41389B, &main, 1);
        return 1;
    }
}

unsigned u0x414626 = 0x414626;
unsigned u0x4149F1 = 0x4149F1;
unsigned u0x4146FD = 0x4146FD;
unsigned u0x414AFF = 0x414AFF;
unsigned u0x414D85 = 0x414D85;
void __declspec(naked) naked_0x4145FE() 
{
    __asm 
    {
        // original
        cmp al,0x0C
        je _0x4149F1
        cmp al,0x0D
        je _0x4149F1
        movzx ecx,al
        cmp ecx,0x1F
        jge _label
        cmp al,0x7
        jne _0x4146FD

        // continue
        jmp u0x414626

        _0x4146FD:
        jmp u0x4146FD

        _0x4149F1:
        jmp u0x4149F1

        _label:
        pushad

        push ecx // model
        call vehicle::set_solo_bone
        add esp,0x4
        test eax,eax

        popad

        jne _0x414AFF

        // default
        jmp u0x414D85

        _0x414AFF:
        jmp u0x414AFF
    }
}

unsigned u0x413010 = 0x413010;
unsigned u0x41378E = 0x41378E;
unsigned u0x4132AB = 0x4132AB;
void __declspec(naked) naked_0x412FF0() 
{
    __asm 
    {
        // original
        cmp al,0x0E
        je _label
        cmp al,0x0F
        je _label
        cmp al,0x15
        je _label

        // custom >= 33
        movzx ecx,al
        cmp ecx,0x21
        jge _label
        cmp al,0x11
        jne _0x4132AB

        // continue
        jmp u0x413010

        _0x4132AB:
        jmp u0x4132AB

        _label:
        pushad

        push ecx // model
        call vehicle::set_dual_bone
        add esp,0x4
        test eax,eax

        popad

        jne _0x41378E

        // default
        jmp u0x414D85

        _0x41378E:
        jmp u0x41378E
    }
}

void hook::vehicle()
{
    // solo vehicles
    util::detour((void*)0x4145FE, naked_0x4145FE, 8);
    // dual vehicles
    util::detour((void*)0x412FF0, naked_0x412FF0, 8);
    // play the default sound
    std::array<UINT8, 6> a00{ 0xE9, 0xD0, 0x00, 0x00, 0x00, 0x90 };
    util::write_memory((void*)0x41A7DF, &a00, 6);
}
