#pragma once
#include <shaiya/include/common.h>

namespace shaiya
{
    #pragma pack(push, 1)
    struct GameStatusResultInfoIncoming
    {
        uint16_t opcode{ 0x218 };
    };
    #pragma pack(pop)
}
