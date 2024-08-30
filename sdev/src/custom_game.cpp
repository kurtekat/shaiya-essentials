#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/Country.h"
#include "include/shaiya/include/CNetwork.h"
#include "include/shaiya/include/CPlayerData.h"
#include "include/shaiya/include/NpcType.h"
using namespace shaiya;

enum HelpMenuButtonIndex
{
    BasicPlay,
    PlayGuide,
    Interface,
    Blessing,
    BasicAction,
    PlayMode
};

#pragma pack(push, 1)
struct VetRewardLevelOutgoing
{
    UINT16 opcode{ 0x218 };

    VetRewardLevelOutgoing() = default;
};
#pragma pack(pop)

void set_help_menu_npc(HelpMenuButtonIndex buttonIndex)
{
    // should not allow two windows at once
    if (g_pPlayerData->windowType != WindowType::None)
    {
        Static::GetMsg(31, 806, 12);
        return;
    }

    switch (buttonIndex)
    {
    case BasicPlay:
    {
        g_pPlayerData->npcType = NpcType32::Blacksmith;
        g_pPlayerData->npcTypeId = 40;
        g_pPlayerData->npcIcon = 55;
        g_pPlayerData->textBuf[0] = '\0';
        g_pPlayerData->windowType = WindowType::Blacksmith;
        break;
    }
    case PlayGuide:
    {
        g_pPlayerData->npcType = NpcType32::Merchant;
        g_pPlayerData->npcTypeId = 248;
        g_pPlayerData->npcIcon = 55;
        g_pPlayerData->textBuf[0] = '\0';
        g_pPlayerData->windowType = WindowType::Recreation;
        break;
    }
    case Interface:
    {
        if (g_pPlayerData->country == Country::Light)
        {
            VetRewardLevelOutgoing outgoing{};
            CNetwork::Send(&outgoing, sizeof(VetRewardLevelOutgoing));

            g_var->killLv = 0;
            g_var->deathLv = 0;

            g_pPlayerData->npcType = NpcType32::VetManager;
            g_pPlayerData->npcTypeId = 1;
            g_pPlayerData->npcIcon = 55;
            g_pPlayerData->textBuf[0] = '\0';
        }
        else
        {
            VetRewardLevelOutgoing outgoing{};
            CNetwork::Send(&outgoing, sizeof(VetRewardLevelOutgoing));

            g_var->killLv = 0;
            g_var->deathLv = 0;

            g_pPlayerData->npcType = NpcType32::VetManager;
            g_pPlayerData->npcTypeId = 2;
            g_pPlayerData->npcIcon = 55;
            g_pPlayerData->textBuf[0] = '\0';
        }

        break;
    }
    case Blessing:
    {
        if (g_pPlayerData->country == Country::Light)
        {
            g_pPlayerData->npcType = NpcType32::Merchant;
            g_pPlayerData->npcTypeId = 179;
            g_pPlayerData->npcIcon = 55;
            g_pPlayerData->textBuf[0] = '\0';
            g_pPlayerData->windowType = WindowType::BankTeller;
        }
        else
        {
            g_pPlayerData->npcType = NpcType32::Merchant;
            g_pPlayerData->npcTypeId = 180;
            g_pPlayerData->npcIcon = 55;
            g_pPlayerData->textBuf[0] = '\0';
            g_pPlayerData->windowType = WindowType::BankTeller;
        }

        break;
    }
    case BasicAction:
    {
        if (g_pPlayerData->country == Country::Light)
        {
            g_pPlayerData->npcType = NpcType32::GuildMaster;
            g_pPlayerData->npcTypeId = 1;
            g_pPlayerData->npcIcon = 55;
            g_pPlayerData->textBuf[0] = '\0';
            g_pPlayerData->windowType = WindowType::GuildMaster;
        }
        else
        {
            g_pPlayerData->npcType = NpcType32::GuildMaster;
            g_pPlayerData->npcTypeId = 2;
            g_pPlayerData->npcIcon = 55;
            g_pPlayerData->textBuf[0] = '\0';
            g_pPlayerData->windowType = WindowType::GuildMaster;
        }

        break;
    }
    case PlayMode:
    {
        g_pPlayerData->npcType = NpcType32::Merchant;
        g_pPlayerData->npcTypeId = 437;
        g_pPlayerData->npcIcon = 55;
        g_pPlayerData->textBuf[0] = '\0';
        g_pPlayerData->windowType = WindowType::Merchant;
        break;
    }
    default:
        break;
    }
}

unsigned u0x522165 = 0x522165;
unsigned u0x51C070 = 0x51C070;
void __declspec(naked) naked_0x522160() 
{
    __asm 
    {
        cmp edi,0x5
        ja original

        pushad

        push edi
        call set_help_menu_npc
        add esp,0x4

        popad

        original:
        call u0x51C070
        jmp u0x522165
    }
}

void hook::custom_game()
{
    // npc-to-go
    util::detour((void*)0x522160, naked_0x522160, 5);

    // npc-to-go bug workaround
    util::write_memory((void*)0x444129, 0xEB, 1);
    // speed recreation
    util::write_memory((void*)0x4C4D2F, 0x02, 1);
    // speed enhance
    util::write_memory((void*)0x501600, 0x02, 1);
    util::write_memory((void*)0x501602, 0x02, 1);
    util::write_memory((void*)0x501631, 0x02, 1);
    util::write_memory((void*)0x501633, 0x02, 1);
    util::write_memory((void*)0x501644, 0x03, 1);
    util::write_memory((void*)0x50164D, 0x03, 1);
    // show dungeon maps
    util::write_memory((void*)0x4D9497, 0x90, 2);
}
