#pragma once
#include "include/shaiya/common.h"

namespace shaiya
{
    enum struct AuthStatus : UINT8
    {
        AdminA = 1,
        AdminB,
        AdminC,
        AdminD,
        AdminE,
        None = 11
    };
}
