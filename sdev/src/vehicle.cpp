#include <format>
#include <map>
#include <string>
#include <vector>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/CCharacter.h"
#include "include/shaiya/include/CDataFile.h"
#include "include/shaiya/include/CMonster.h"
#include "include/shaiya/include/ItemInfo.h"
using namespace shaiya;

namespace vehicle
{
    struct Vehicle
    {
        int model;
        int bone1;
        int bone2;
        std::string wavFileName;
    };

    std::vector<Vehicle> g_vehicles{};

    void init()
    {
        for (int i = 1; i <= UINT8_MAX; ++i)
        {
            auto itemInfo = CDataFile::GetItemInfo(int(ItemType::Vehicle), i);
            if (!itemInfo)
                continue;

            auto model = itemInfo->vehicleModel;
            if (model < 33)
                continue;

            Vehicle vehicle{};
            vehicle.model = model;
            vehicle.bone1 = itemInfo->reqRec;
            vehicle.bone2 = itemInfo->reqInt;
            // e.g., vehicle_model033.wav
            vehicle.wavFileName = std::format("vehicle_model{:03d}.wav", vehicle.model);
            g_vehicles.push_back(vehicle);
        }
    }

    int play_wav(CCharacter* user)
    {
        auto model = user->vehicleModel;
        if (model < 33)
            return 1;

        auto vehicle = std::find_if(g_vehicles.begin(), g_vehicles.end(), [&model](const auto& vehicle) {
            return vehicle.model == model;
            });

        if (vehicle != g_vehicles.end())
        {
            if (Static::PlayWav(vehicle->wavFileName.c_str(), &user->pos, 1000.0f, false))
                return 0;
        }

        Static::PlayWav("ef_dmg_transf01.wav", &user->pos, 1000.0f, false);
        return 0;
    }

    Vehicle* get_vehicle(int model)
    {
        auto vehicle = std::find_if(g_vehicles.begin(), g_vehicles.end(), [&model] (const auto& vehicle) {
            return vehicle.model == model;
            });

        if (vehicle == g_vehicles.end())
            return nullptr;

        return vehicle._Ptr;
    }

    void make_matrix(CCharacter* user, int model)
    {
        if (user->family > Family::Vail)
            return;

        auto vehicle = get_vehicle(model);
        if (!vehicle)
            return;

        if (!vehicle->bone1)
            return;

        auto bone1 = CMonster::GetBoneMatrix(user->vehicle, vehicle->bone1);
        if (!bone1)
            return;

        D3DXMATRIX rotY{};
        Static::D3DXMatrixRotationY(&rotY, 3.14F);

        D3DXMATRIX rotZ{};
        Static::D3DXMatrixRotationZ(&rotZ, 4.71F);

        D3DXMATRIX mat1{};
        Static::D3DXMatrixMultiply(&mat1, &rotY, &rotZ);

        D3DXMATRIX mat2{};
        Static::D3DXMatrixMultiply(&mat2, &mat1, bone1);

        D3DXMATRIX mat3{};
        Static::D3DXMatrixMultiply(&mat3, &mat2, &g_var->camera.world);
        g_var->camera.world = mat3;
    }

    void make_matrices(CCharacter* user, int model)
    {
        if (user->family > Family::Vail)
            return;

        auto vehicle = get_vehicle(model);
        if (!vehicle)
            return;

        if (!vehicle->bone1 || !vehicle->bone2)
            return;

        auto bone2 = CMonster::GetBoneMatrix(user->vehicle, vehicle->bone2);
        if (!bone2)
            return;

        D3DXMATRIX rotY{};
        Static::D3DXMatrixRotationY(&rotY, 3.14F);

        D3DXMATRIX rotZ{};
        Static::D3DXMatrixRotationZ(&rotZ, 4.71F);

        D3DXMATRIX mat1{};
        Static::D3DXMatrixMultiply(&mat1, &rotY, &rotZ);

        D3DXMATRIX mat2{};
        Static::D3DXMatrixMultiply(&mat2, &mat1, bone2);

        D3DXMATRIX mat3{};
        Static::D3DXMatrixMultiply(&mat3, &mat2, &g_var->camera.world);
        user->vehicleMatrix = mat3;

        auto bone1 = CMonster::GetBoneMatrix(user->vehicle, vehicle->bone1);
        if (!bone1)
            return;

        Static::D3DXMatrixRotationY(&rotY, 3.14F);
        Static::D3DXMatrixRotationZ(&rotZ, 4.71F);

        D3DXMATRIX mat4{};
        Static::D3DXMatrixMultiply(&mat4, &rotY, &rotZ);

        D3DXMATRIX mat5{};
        Static::D3DXMatrixMultiply(&mat5, &mat4, bone1);

        D3DXMATRIX mat6{};
        Static::D3DXMatrixMultiply(&mat6, &mat5, &g_var->camera.world);
        g_var->camera.world = mat6;
    }
}

unsigned u0x414606 = 0x414606;
unsigned u0x414AFF = 0x414AFF;
unsigned u0x414D85 = 0x414D85;
void __declspec(naked) naked_0x4145FE()
{
    __asm 
    {
        movzx eax,al
        cmp eax,0x21
        jge new_mount

        // original
        cmp al,0x1F
        je _0x414AFF
        jmp u0x414606

        _0x414AFF:
        jmp u0x414AFF

        new_mount:
        pushad

        push eax // model
        push ebp // user
        call vehicle::make_matrix
        add esp,0x8

        popad

        jmp u0x414D85
    }
}

unsigned u0x41378E = 0x41378E;
unsigned u0x412FF8 = 0x412FF8;
void __declspec(naked) naked_0x412FF0() 
{
    __asm 
    {
        movzx eax,al
        cmp eax,0x21
        jge new_mount

        // original
        cmp al,0xE
        je _0x41378E
        jmp u0x412FF8

        _0x41378E:
        jmp u0x41378E

        new_mount:
        pushad

        push eax // model
        push ebp // user
        call vehicle::make_matrices
        add esp,0x8

        popad

        jmp u0x414D85
    }
}

unsigned u0x74A350 = 0x74A350;
unsigned u0x4315F9 = 0x4315F9;
void __declspec(naked) naked_0x4315F4()
{
    __asm
    {
        pushad

        call vehicle::init

        popad

        // original
        push u0x74A350
        jmp u0x4315F9
    }
}

unsigned u0x41A912 = 0x41A912;
unsigned u0x41A806 = 0x41A806;
void __declspec(naked) naked_0x41A7FF()
{
    __asm
    {
        pushad

        push esi // user
        call vehicle::play_wav
        add esp,0x4
        test eax,eax

        popad

        je _0x41A912

        // original
        movzx eax,byte ptr[esi+0x2B8]
        jmp u0x41A806

        _0x41A912:
        jmp u0x41A912
    }
}

void hook::vehicle()
{
    // allocate vehicles
    util::detour((void*)0x4315F4, naked_0x4315F4, 5);
    // solo vehicles
    util::detour((void*)0x4145FE, naked_0x4145FE, 8);
    // dual vehicles
    util::detour((void*)0x412FF0, naked_0x412FF0, 8);
    // play .wav sound
    util::detour((void*)0x41A7FF, naked_0x41A7FF, 7);
}