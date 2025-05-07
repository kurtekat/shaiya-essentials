#pragma once
#include <shaiya/include/common.h>
#include <shaiya/include/common/SkillTypes.h>
#include "include/shaiya/common.h"
#include "include/shaiya/include/CPlayerData.h"
#include "include/shaiya/include/CWorldMgr.h"
#include "include/shaiya/include/TargetType.h"

namespace shaiya
{
    struct CStaticText;
    struct CSwordEffect;
    struct CVertexShader;

    enum struct HealPointType : uint8_t
    {
        Health,
        Stamina,
        Mana
    };

    // notes: code page (see 0x408060)
    // CP_ACP (see winnls.h)
    enum struct LoginVersion : int32_t
    {
        Korea = 1,     //
        China,         //
        Vietnam,       // 65001 (UTF-8)
        Japan,         // 932
        Taiwan,        // 950
        English,       // CP_ACP
        Germany,       // CP_ACP
        SingaMala,     // 950
        HongKong,      // 950
        France,        // CP_ACP
        Russia,        // CP_ACP
        Turkey,        // 1254
        Brazil,        // CP_ACP
        LatinAmerica,  // CP_ACP
        Poland,        // 1250
        Italy,         // CP_ACP
        Philippines    // CP_ACP
    };

    #pragma pack(push, 1)
    // 00572D30 ctor
    struct Camera
    {
        D3DXMATRIX world;           //0x22B69B0  0x00
        D3DXMATRIX view;            //0x22B69F0  0x40
        D3DXMATRIX projection;      //0x22B6A30  0x80
        D3DVECTOR pos;              //0x22B6A70  0xC0
        D3DVECTOR lookAt;           //0x22B6A7C  0xCC
        D3DVECTOR up;               //0x22B6A88  0xD8
        D3DVECTOR vec1;             //0x22B6A94  0xE4
        D3DVECTOR target;           //0x22B6AA0  0xF0
        D3DXMATRIX mat1;            //0x22B6AAC  0xFC
        D3DXMATRIX mat2;            //0x22B6AEC  0x13C
        D3DXMATRIX mat3;            //0x22B6B2C  0x17C
        D3DXMATRIX mat4;            //0x22B6B6C  0x1BC
        D3DXMATRIX mat5;            //0x22B6BAC  0x1FC
        // 0x22B6BEC  0x23C
        PAD(260);
        D3DCOLOR fogColor;          //0x22B6CF0  0x340
        PAD(20);
        // 0x22B6D08  0x358
        LPDIRECT3DVERTEXBUFFER9 vertexBuffer1;
        // 0x22B6D0C  0x35C
        LPDIRECT3DVERTEXBUFFER9 vertexBuffer2;
        // 0x22B6D10  0x360
        CVertexShader* vertexShader;
        // 0x22B6D14  0x364
        D3DPRESENT_PARAMETERS presentParameters;
        LPD3DXFONT d3dxFont3;       //0x22B6D4C  0x39C
        LPD3DXFONT d3dxFont2;       //0x22B6D50  0x3A0
        LPD3DXFONT d3dxFont1;       //0x22B6D54  0x3A4
        LPD3DXFONT d3dxFont0;       //0x22B6D58  0x3A8
        HFONT hFont;                //0x22B6D5C  0x3AC
        int32_t text0Width;         //0x22B6D60  0x3B0
        int32_t text1Width;         //0x22B6D64  0x3B4
        int32_t text0Height;        //0x22B6D68  0x3B8
        int32_t text1Height;        //0x22B6D6C  0x3BC
        uint32_t textColorR;        //0x22B6D70  0x3C0
        uint32_t textColorG;        //0x22B6D74  0x3C4
        uint32_t textColorB;        //0x22B6D78  0x3C8
        D3DMATERIAL9 material;      //0x22B6D7C  0x3CC
        LPDIRECT3D9 d3d9;           //0x22B6DC0  0x410
        LPDIRECT3DDEVICE9 device;   //0x22B6DC4  0x414
        uint32_t primitiveCount;    //0x22B6DC8  0x418
        bool32_t enableInfoText;    //0x22B6DCC  0x41C
        CStaticText* staticText;    //0x22B6DD0  0x420
        PAD(4);
        D3DGAMMARAMP gammaRamp1;    //0x22B6DD8  0x428
        D3DGAMMARAMP gammaRamp2;    //0x22B73D8  0xA28
        LPDIRECTDRAW directDraw;    //0x22B79D8  0x1028
        D3DGAMMARAMP gammaRamp3;    //0x22B79DC  0x102C
        PAD(4);
        D3DCOLOR clearDeviceColor;  //0x22B7FE0  0x1630
        // 0x1634
    };
    #pragma pack(pop)

    static_assert(sizeof(Camera) == 0x1634);

    #pragma pack(push, 1)
    struct ExtraHotkey
    {
        int key1;   // DIK_NUMPAD1
        int key2;   // DIK_NUMPAD2
        int key3;   // DIK_NUMPAD3
        int key4;   // DIK_NUMPAD4
        int key5;   // DIK_NUMPAD5
        int key6;   // DIK_NUMPAD6
        int key7;   // DIK_NUMPAD7
        int key8;   // DIK_NUMPAD8
        int key9;   // DIK_NUMPAD9
        int key10;  // DIK_NUMPAD0
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct HotkeyOptions
    {
        int moveLeft;        // DIK_A
        int moveForward;     // DIK_W
        int walkLeft;        // DIK_Q
        int walkRun;         // DIK_TAB
        int sitStand;        // DIK_C
        int statWindow;      // DIK_T
        int skillWindow;     // DIK_K
        int questWindow;     // DIK_U
        int optionWindow;    // DIK_O
        int miniMap;         // DIK_V
        int moveRight;       // DIK_D
        int moveBackward;    // DIK_S
        int walkRight;       // DIK_E
        int autoMove;        // DIK_W
        int jump;            // DIK_SPACE
        int inventory;       // DIK_I
        int subSkillWindow;  // DIK_B
        int guildWindow;     // DIK_G
        int map;             // DIK_M
        int closeWindow;     // DIK_ESCAPE
    };
    #pragma pack(pop)


    #pragma pack(push, 1)
    // the .data section
    struct Static
    {
        PAD(212);                            //0x7AB000
        LoginVersion loginVersion;           //0x7AB0D4
        D2D_SIZE_U client;                   //0x7AB0D8
        D3DVIEWPORT9 viewport;               //0x7AB0E0
        // 0x7AB0F8
        PAD(2788);
        uint32_t targetId;                   //0x7ABBDC
        TargetType targetType;               //0x7ABBE0
        PAD(16164);
        WNDCLASSEXA wndClassExa;             //0x7AFB08
        // 0x7AFB38
        PAD(68584);
        String<260> iniFileName;             //0x7C0720
        // 0x7C0824
        PAD(1384);
        bool32_t enableWaterSurface;         //0x7C0D8C
        bool32_t enableShadows;              //0x7C0D90
        float viewFarthest;                  //0x7C0D94
        float viewNearest;                   //0x7C0D98
        // 0: 16-bit, 1: 32-bit
        int32_t colorDepth;                  //0x7C0D9C
        float cameraTargetSpeed;             //0x7C0DA0
        float fogNearest;                    //0x7C0DA4
        float fogFarthest;                   //0x7C0DA8
        float fogStart;                      //0x7C0DAC
        float fogEnd;                        //0x7C0DB0
        bool32_t disableFog;                 //0x7C0DB4
        float modelFarthest;                 //0x7C0DB8
        float grassFarthest;                 //0x7C0DBC
        // user, npc, mob
        float otherFarthest;                 //0x7C0DC0
        PAD(12);
        String<16> ipv4;                     //0x7C0DD0
        // 0x7C0DE0
        PAD(172);
        ExtraHotkey extraHotkey;             //0x7C0E8C
        HotkeyOptions hotkeyOptions;         //0x7C0EB4
        // 0x7C0F04
        PAD(1176);
        HWND hwnd;                           //0x7C139C
        HINSTANCE hinst;                     //0x7C13A0
        bool32_t isFullscreenWindow;         //0x7C13A4
        PAD(4);
        bool32_t isActiveWindow;             //0x7C13AC
        PAD(1408);
        uint32_t msgValue2;                  //0x7C1930  <v2>
        HealPointType msgHealPointType1;     //0x7C1934  <up>
        SkillStatusType msgStatusType;       //0x7C1935  <zz>
        HealPointType msgHealPointType2;     //0x7C1936  <hp>
        PAD(1);
        Array<char, 512> msgLapisName;       //0x7C1938  <r>
        Array<char, 512> msgTargetName;      //0x7C1B38  <t>
        Array<char, 1024> msgBuffer;         //0x7C1D38  <b>
        Array<char, 512> msgSkillName;       //0x7C2138  <s>
        Array<char, 512> msgPlayerName;      //0x7C2338  <p>
        Array<char, 512> msgItemName;        //0x7C2538  <i>
        uint32_t msgValue3;                  //0x7C2738  <v3>
        uint32_t msgValue;                   //0x7C273C  <v>
        Array<char, 1024> msgTextBuffer1;    //0x7C2740
        Array<char, 1024> msgTextBuffer2;    //0x7C2B40
        Array<char, 1024> msgTextBuffer3;    //0x7C2F40
        Array<char, 1024> msgTextBuffer4;    //0x7C3340
        Array<char, 1024> msgTextBuffer5;    //0x7C3740
        // 0:5 (switches buffers)
        uint32_t msgTextBufferIndex;         //0x7C3B40
        PAD(200);
        int32_t cursorX;                     //0x7C3C0C
        int32_t cursorY;                     //0x7C3C10
        PAD(3660);
        CSwordEffect* seffEventEffect;       //0x7C4A60
        CSwordEffect* seffWeather;           //0x7C4A64
        CWorldMgr worldMgr;                  //0x7C4A68
        CSwordEffect* seffLoginCloud;        //0x906DE0
        CSwordEffect* seffWeapon;            //0x906DE4
        PAD(25576);
        CPlayerData playerData;              //0x90D1D0
        // 0x22B0208
        PAD(6384);
        int32_t killLv;                      //0x22B1AF8
        int32_t deathLv;                     //0x22B1AFC
        PAD(16040);
        Array<wchar_t, 1024> wideBuffer1;    //0x22B59A8
        Array<wchar_t, 1024> wideBuffer2;    //0x22B61A8
        LPDIRECT3DDEVICE9 device;            //0x22B69A8
        PAD(4);
        Camera camera;                       //0x22B69B0
        // 0x22B7FE4
        PAD(16);
        float fps;                           //0x22B7FF4
        PAD(237504);
        LPDIRECTSOUND8 directSound8;         //0x22F1FB8
        PAD(33608);
        int socket;                          //0x22FA304
        PAD(21368);
        String<260> exeFileName;             //0x22FF680
        // 0x22FF784
        PAD(116);
        CRITICAL_SECTION cs;                 //0x22FF7F8
        // 0x22FF810
        PAD(568);
        HMODULE hModule;                     //0x22FFA48
        PAD(21940);
        // 0x2305000 (.rsrc)

        // static functions

        static void DrawRect(D3DCOLOR argb, int x, int y, int w, int h);
        static void MsgTextOut(int messageType, int messageNumber, int unknown);
        static bool PlayWav(const char* wavFileName, D3DVECTOR* origin, float volume, bool repeat);

        // D3DX utilities (deprecated)

        static D3DXMATRIX* D3DXMatrixMultiply(D3DXMATRIX* out, D3DXMATRIX* mat1, D3DXMATRIX* mat2);
        static D3DXMATRIX* D3DXMatrixRotationY(D3DXMATRIX* out, float angle);
        static D3DXMATRIX* D3DXMatrixRotationZ(D3DXMATRIX* out, float angle);

        // CRT
        static void* malloc(size_t size);
    };
    #pragma pack(pop)

    static_assert(sizeof(Static) == 0x1B5A000);
    static auto g_var = (Static*)0x7AB000;
}
