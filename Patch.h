#pragma once

#include "Offset.h"
#include "D2Intercepts.h"
#include "D2Handlers.h"
#include "D2BS.h"

PatchHook Patches[] = {
    {PatchCall, GetDllOffset("D2Client.dll", 0x70B75), (DWORD)GameInput_Intercept, 5},          // Updated 1.14d //0047C89D-BASE
    {PatchJmp, GetDllOffset("D2Client.dll", 0xC3DB4), (DWORD)GameDraw_Intercept, 6},            // Updated 1.14d //00453B30-BASE
    {PatchCall, GetDllOffset("D2Client.dll", 0xACE61), (DWORD)GamePacketReceived_Intercept, 5}, // Updated 1.14d //0045F802-BASE
    {PatchJmp, GetDllOffset("D2Client.dll", NULL), (DWORD)GamePacketSent_Interception, 5},  // Updated 1.14d //0052AE5A-BASE
    {PatchCall, GetDllOffset("D2Client.dll", 0x1BF94), (DWORD)GetSelectedUnit_Intercept, 5},    // Updated 1.14d //00462D72-BASE
    {PatchJmp, GetDllOffset("D2Client.dll", 0xADF37), (DWORD)PlayerAssignment_Intercept, 5},    // Updated 1.14d //0045E4D5-BASE
    {PatchBytes, GetDllOffset("D2Client.dll", 0x161B0), (DWORD)0xc3, 1},                        // Updated 1.14d //00468770-BASE
    {PatchBytes, GetDllOffset("D2CLIENT.DLL", NULL), (BYTE)0x75, 1},                         // Congrats Screen //0044EBFB-BASE
    {PatchCall, GetDllOffset("D2Client.dll", NULL), (DWORD)CongratsScreen_Intercept, 5},     // Updated 1.14d //0044EBEF-BASE
    {PatchCall, GetDllOffset("D2Client.dll", 0xC14F7), (DWORD)GameActChange_Intercept, 5},      // Updated 1.14d //004547B6-BASE
    {PatchJmp, GetDllOffset("D2Client.dll", 0xC19A4), (DWORD)GameActChange2_Intercept, 5},      // Updated 1.14d //004567EB-BASE
    {PatchCall, GetDllOffset("D2Client.dll", 0x4515D), (DWORD)GameLeave_Intercept, 5},          // Updated 1.14d //0044F57C-BASE
    {PatchCall, GetDllOffset("D2Client.dll", 0x1A060), (DWORD)GameAttack_Intercept, 5},         // Updated 1.14d //00461704-BASE
    //	{PatchCall,	GetDllOffset("D2Client.dll", 0xA7364),	(DWORD)AddUnit_Intercept,				5},
    //	{PatchCall,	GetDllOffset("D2Client.dll", 0xA6F25),	(DWORD)RemoveUnit_Interept,			9},

    // this patch needs a constant in ChatPacketRecv_Interception updated also
    {PatchCall, GetDllOffset("BNCLIENT.DLL", NULL), (DWORD)ChatPacketRecv_Interception, 7}, // Updated 1.14d //00521B20-BASE

    {PatchCall, GetDllOffset("D2Multi.dll", 0x1000C), (DWORD)Whisper_Intercept, 7},      // Updated 1.14d //00448813-BASE
    {PatchCall, GetDllOffset("D2Multi.dll", 0xD753), (DWORD)ChannelInput_Intercept, 5}, // Updated 1.14d //00442A61-BASE

    //{PatchCall,	GetDllOffset("D2Multi.dll", 0x14A9A),	(DWORD)ChannelWhisper_Intercept,		5},//1.13d //not used
    //{PatchJmp,	GetDllOffset("D2Multi.dll", 0x14BE0),	(DWORD)ChannelChat_Intercept,			6},//1.13d
    //{PatchJmp,	GetDllOffset("D2Multi.dll", 0x14850),	(DWORD)ChannelEmote_Intercept,			6},//1.13d

    {PatchCall, GetDllOffset("D2Win.dll", 0x18918), (DWORD)GameDrawOOG_Intercept, 5}, // Updated 1.14d //004F9A0D-BASE

    {PatchCall, GetDllOffset("D2CMP.dll", 0x17385), (DWORD)GameCrashFix_Intercept, 10}, // 1.14d //006091E5-BASE

    {PatchCall, GetDllOffset("D2MCPClient.dll", NULL), (DWORD)RealmPacketRecv_Interception, 6},

    {PatchCall, GetDllOffset("Fog.dll", NULL), (DWORD)LogMessageBoxA_Intercept, 6}, // Updated 1.14d //00408CC4-BASE
    {PatchJmp, GetDllOffset("Fog.dll", NULL), (DWORD)D2GAME_exit0, 6},              // NEW 1.14d //004082E0-BASE
    //{PatchJmp,  GetDllOffset("Fog.dll", 0x8900),		(DWORD)FogException/*D2GAME_exit0*/,		6}, //NEW 1.14d //00408900-BASE
    {PatchJmp, GetDllOffset("Fog.dll", NULL), (DWORD)ErrorReportLaunch, 6}, // NEW 1.14d //00401790-BASE
};

PatchHook Conditional[] = {
    {PatchJmp, GetDllOffset("BNCLIENT.DLL", 0x12366C), (DWORD)ClassicSTUB, 5, &Vars.bUseRawCDKey}, // Updated 1.14d //0052366C-BASE
    {PatchJmp, GetDllOffset("BNCLIENT.DLL", 0x123958), (DWORD)LodSTUB, 5, &Vars.bUseRawCDKey},     // Updated 1.14d //00523958-BASE
    {PatchCall, GetDllOffset("D2CLIENT.DLL", 0x4EF28), (DWORD)FailToJoin, 6, &Vars.bReduceFTJ},    // FTJ Reducer
    {PatchCall, GetDllOffset("D2Gfx.DLL", 0xF5623), (DWORD)Multi, 6, &Vars.bMulti},
    {PatchCall, GetDllOffset("D2Gfx.DLL", 0xF5831), (DWORD)Windowname, 6, &Vars.bMulti},
    {PatchCall, GetDllOffset("BNCLIENT.DLL", 0x11944E), (DWORD)CacheFix, 6, &Vars.bCacheFix},
    {PatchCall, GetDllOffset("BNCLIENT.DLL", 0x119434), (DWORD)CacheFix, 6, &Vars.bCacheFix},
    {PatchBytes, GetDllOffset("D2CLIENT.DLL", 0x51C31), (WORD)0x9090, 2, &Vars.bSleepy}, // Sleep
    {PatchBytes, GetDllOffset("D2Win.DLL", 0xFA66F), (BYTE)0xEB, 1, &Vars.bSleepy}       // OOG Sleep
};