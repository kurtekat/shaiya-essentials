#pragma once

void Main();
extern "C" __declspec(dllexport) void DllExport();

namespace hook
{
    void camera_limit();
    void cmd();
    void custom_game();
    void gui();
    void item_icon();
    void name_color();
    void packet();
    void quick_slot();
    void vehicle();
}

inline int g_showCostumes = false;
inline int g_showPets = false;
inline int g_showWings = false;
inline int g_showEffects = false;
inline int g_showMobEffects = false;
inline float g_cameraLimit = 30.0f;
