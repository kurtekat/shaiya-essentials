#pragma once
#pragma warning(disable: 4005)
#define DIRECTINPUT_VERSION 0x800
#include <array>
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <mmsystem.h>
#include <dxgi.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <d2d1.h>
#include <ddraw.h>
#include <dinput.h>
#include <dsound.h>
#include <dwrite.h>

// thanks, Cups ^^
#define CONCAT(x, y) x ## y
#define EXPAND(x, y) CONCAT(x, y)
#define PAD(size) char EXPAND(pad, __LINE__)[size]

namespace shaiya
{
    template<class T, size_t N>
    using Array = std::array<T, N>;

    template<size_t N>
    using CharArray = std::array<char, N>;

    template<size_t N>
    using CharArrayW = std::array<wchar_t, N>;

    using Address = unsigned;
    using Packet = unsigned char*;

    using UserId = unsigned long;
    using CharId = unsigned long;
    using ItemId = uint32_t;
}
