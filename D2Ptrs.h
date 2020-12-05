#ifndef __D2PTRS_ONCE_
#pragma once
#endif
#ifndef __D2PTRS_H__
#define __D2PTRS_H__

#include "D2Structs.h"

#pragma warning(push)
#pragma warning(disable : 4245)

#pragma optimize("", off)

#ifdef _DEFINE_VARS

#ifdef __D2PTRS_LIST_

#define FUNCPTR(d1, v1, t1, t2, o1) &d1##_##v1,
#define VARPTR(d1, v1, t1, o1) &p_##d1##_##v1,
#define ASMPTR(d1, v1, o1) &d1##_##v1,
void* d2ptrs_list[] = {

#else
enum {
    DLLNO_D2CLIENT,
    DLLNO_D2COMMON,
    DLLNO_D2GFX,
    DLLNO_D2LANG,
    DLLNO_D2WIN,
    DLLNO_D2NET,
    DLLNO_D2GAME,
    DLLNO_D2LAUNCH,
    DLLNO_FOG,
    DLLNO_BNCLIENT,
    DLLNO_STORM,
    DLLNO_D2CMP,
    DLLNO_D2MULTI
};

#define DLLOFFSET(a1, b1) ((DLLNO_##a1) | ((b1) << 8))
#define FUNCPTR(d1, v1, t1, t2, o1)                                                                                                                                      \
    typedef t1 d1##_##v1##_t t2;                                                                                                                                         \
    d1##_##v1##_t* d1##_##v1 = (d1##_##v1##_t*)DLLOFFSET(d1, o1);
#define VARPTR(d1, v1, t1, o1)                                                                                                                                           \
    typedef t1 d1##_##v1##_t;                                                                                                                                            \
    d1##_##v1##_t* p_##d1##_##v1 = (d1##_##v1##_t*)DLLOFFSET(d1, o1);
#define ASMPTR(d1, v1, o1) DWORD d1##_##v1 = DLLOFFSET(d1, o1);
#endif

#else

#define FUNCPTR(d1, v1, t1, t2, o1)                                                                                                                                      \
    typedef t1 d1##_##v1##_t t2;                                                                                                                                         \
    extern d1##_##v1##_t* d1##_##v1;
#define VARPTR(d1, v1, t1, o1)                                                                                                                                           \
    typedef t1 d1##_##v1##_t;                                                                                                                                            \
    extern d1##_##v1##_t* p_##d1##_##v1;
#define ASMPTR(d1, v1, o1) extern DWORD d1##_##v1;

#endif

    FUNCPTR(D2CLIENT, GetQuestInfo, void* __stdcall, (void), 0x45A00) // 1.13C from BH.dll - line 101

    FUNCPTR(D2CLIENT, SubmitItem, void __fastcall, (DWORD dwItemId), 0x45FB0) // 1.13C from BH.dll - line 103
    FUNCPTR(D2CLIENT, Transmute, void __fastcall, (void), 0x8CB90)            // 1.13C from BH.dll - line 104

    FUNCPTR(D2CLIENT, FindClientSideUnit, UnitAny* __fastcall, (DWORD dwId, DWORD dwType), 0xA5B20) // 1.13C from BH.dll - line 106
    FUNCPTR(D2CLIENT, FindServerSideUnit, UnitAny* __fastcall, (DWORD dwId, DWORD dwType), 0xA5B40) // 1.13C from BH.dll - line 107
    FUNCPTR(D2CLIENT, GetCurrentInteractingNPC, UnitAny* __fastcall, (void), 0x46150)               // 1.13C from BH.dll - line 108
    FUNCPTR(D2CLIENT, GetSelectedUnit, UnitAny* __stdcall, (), 0x51A80)                             // 1.13C from BH.dll - line 109
    FUNCPTR(D2CLIENT, GetCursorItem, UnitAny* __fastcall, (void), 0x16020)                          // 1.13C from BH.dll - line 110
    // FUNCPTR(D2CLIENT, GetMercUnit, UnitAny* __fastcall, (void), 0x97CD0)                         // 1.13C from BH.dll - line 111 - not sure why this is commented, but we have the offset
    FUNCPTR(D2CLIENT, SetSelectedUnit_I, void __fastcall, (UnitAny * pUnit), 0x51860)                           // 1.13C from BH.dll - line 114
    FUNCPTR(D2CLIENT, GetItemName, BOOL __fastcall, (UnitAny * pItem, wchar_t* wBuffer, DWORD dwSize), 0x914F0) // 1.13C from BH.dll - line 115
    FUNCPTR(D2CLIENT, LoadItemDesc, BOOL __stdcall, (UnitAny * pItem, int type), 0x97820)                       // 1.13C from BH.dll - line 117 - states it's for 1.13d
    FUNCPTR(D2CLIENT, GetMonsterOwner, DWORD __fastcall, (DWORD nMonsterId), 0x216A0)                           // 1.13C from BH.dll - line 119
    FUNCPTR(D2CLIENT, GetUnitHPPercent, DWORD __fastcall, (DWORD dwUnitId), 0x21580)                            // 1.13C from BH.dll - line 120
    FUNCPTR(D2CLIENT, InitInventory, void __fastcall, (void), 0x908C0)                                          // 1.13C from BH.dll - line 121
    FUNCPTR(D2CLIENT, SetUIVar, DWORD __fastcall, (DWORD varno, DWORD howset, DWORD unknown1), 0xC2790)         // 1.13C from BH.dll - line 122
    FUNCPTR(D2CLIENT, GetUnitX, int __fastcall, (UnitAny * pUnit), 0x1630)                                      // 1.13C from BH.dll - line 123
    FUNCPTR(D2CLIENT, GetUnitY, int __fastcall, (UnitAny * pUnit), 0x1660)                                      // 1.13C from BH.dll - line 124

    FUNCPTR(D2CLIENT, ShopAction, void __fastcall, (UnitAny * pNpc, UnitAny* pItem, DWORD dwSell, DWORD unk, DWORD dwItemCost, DWORD dwMode, DWORD _2, DWORD _3),
            0x47D60) // 1.13C from BH.dll - line 126

    FUNCPTR(D2CLIENT, CloseNPCInteract, void __fastcall, (void), 0x492F0) // 1.13C from BH.dll - line 128 
    FUNCPTR(D2CLIENT, CloseInteract, void __fastcall, (void), 0x43870)    // 1.13C from BH.dll - line 130

    FUNCPTR(D2CLIENT, GetAutomapSize, DWORD __stdcall, (void), 0x5F080)                                                     // 1.13C from BH.dll - line 132
    FUNCPTR(D2CLIENT, NewAutomapCell, AutomapCell* __fastcall, (), 0x5F6B0)                                                 // 1.13C from BH.dll - line 133
    FUNCPTR(D2CLIENT, AddAutomapCell, void __fastcall, (AutomapCell * aCell, AutomapCell** node), 0x61320)                  // 1.13C from BH.dll - line 134
    FUNCPTR(D2CLIENT, RevealAutomapRoom, void __stdcall, (Room1 * pRoom1, DWORD dwClipFlag, AutomapLayer* aLayer), 0x62580) // 1.13C from BH.dll - line 135
    FUNCPTR(D2CLIENT, InitAutomapLayer_I, AutomapLayer* __fastcall, (DWORD nLayerNo), 0x62710)                              // 1.13C from BH.dll - line 136

    FUNCPTR(D2CLIENT, ClickMap, void __fastcall, (DWORD MouseFlag, DWORD x, DWORD y, DWORD Type), 0x1BF20) // 1.13C from BH.dll - line 138
    FUNCPTR(D2CLIENT, LeftClickItem_I, void __stdcall,
            (UnitAny * pPlayer, Inventory* pInventory, int x, int y, DWORD dwClickType, InventoryLayout* pLayout, DWORD Location),
            0x96AA0) // 1.13C from BH.dll - line 139

    FUNCPTR(D2CLIENT, GetMouseXOffset, DWORD __fastcall, (VOID), 0x3F6C0) // 1.13C from BH.dll - line 141
    FUNCPTR(D2CLIENT, GetMouseYOffset, DWORD __fastcall, (VOID), 0x3F6D0) // 1.13C from BH.dll - line 142

    FUNCPTR(D2CLIENT, PrintGameString, void __fastcall, (wchar_t * wMessage, int nColor), 0x7D850)  // 1.13C from BH.dll - line 145
    FUNCPTR(D2CLIENT, PrintPartyString, void __fastcall, (wchar_t * wMessage, int nColor), 0x7D610) // 1.13C from BH.dll - line 144

    FUNCPTR(D2CLIENT, LeaveParty, void __fastcall, (void), 0x9E5D0) // 1.13C from BH.dll - line 147

    FUNCPTR(D2CLIENT, AcceptTrade, void __fastcall, (void), 0x59600) // 1.13C from BH.dll - line 149
    FUNCPTR(D2CLIENT, CancelTrade, void __fastcall, (void), 0x595C0) // 1.13C from BH.dll - line 150
    FUNCPTR(D2CLIENT, TradeOK, void __stdcall, (void), 0xB8A30)      // 1.13C from BH.dll - line ?? grep the codebase

    FUNCPTR(D2CLIENT, GetDifficulty, BYTE __stdcall, (), 0x41930) // 1.13C from BH.dll - line 152

    FUNCPTR(D2CLIENT, ExitGame, void __fastcall, (void), 0x42850) // 1.13C from BH.dll - line 154

    FUNCPTR(D2CLIENT, GetUiVar_I, DWORD __fastcall, (DWORD dwVarNo), 0xBE400) // 1.13C from BH.dll - line 156

    FUNCPTR(D2CLIENT, DrawRectFrame, VOID __fastcall, (DWORD Rect), 0xBE4C0) // 1.13C from BH.dll - line 158

    FUNCPTR(D2CLIENT, PerformGoldDialogAction, void __fastcall, (void), 0xBFDF0) // 1.13C from BH.dll - line 160 

    FUNCPTR(D2CLIENT, GetPlayerUnit, UnitAny* __stdcall, (), 0xA4D60) // 1.13C from BH.dll - line 162

    // FUNCPTR(D2CLIENT, GetLevelName_I, wchar_t* __fastcall, (DWORD levelId), 0xBE240) // 1.13C from BH.dll - line 164 - not sure why commented

    FUNCPTR(D2CLIENT, ClearScreen, void __fastcall, (void), 0x492F0) // 1.13C from BH.dll - line 129: comment // unused but I want to look into using it // wrong function

    FUNCPTR(D2CLIENT, CloseNPCTalk, DWORD __stdcall, (void* unk), 0x492F0) // 1.13C from BH.dll - line 128? - CloseNPCInteract

    FUNCPTR(D2CLIENT, TestPvpFlag, DWORD __fastcall, (DWORD dwUnitId1, DWORD dwUnitId2, DWORD dwFlag), 0x4FD90) // 1.13C from BH.dll - line  283

    FUNCPTR(D2CLIENT, GetGameLanguageCode, DWORD __fastcall, (), 0x125150) // 1.13C from BH.dll - line ??

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Client Globals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    VARPTR(D2CLIENT, ScreenSizeX, DWORD, 0xDBC48)  // 1.13C from BH.dll - line 173
    VARPTR(D2CLIENT, ScreenSizeY, DWORD, 0xDBC4C) // 1.13C from BH.dll - line 174

    VARPTR(D2CLIENT, CursorHoverX, DWORD, 0xE0EB8)  // 1.13C from BH.dll - line 176
    VARPTR(D2CLIENT, CursorHoverY, DWORD, 0xE0EBC) // 1.13C from BH.dll - line 177

    VARPTR(D2CLIENT, MouseY, DWORD, 0x11B828) // 1.13C from BH.dll - line 179
    VARPTR(D2CLIENT, MouseX, DWORD, 0x11B828) // 1.13C from BH.dll - line 180

    VARPTR(D2CLIENT, MouseOffsetY, int, 0x11995C) // 1.13C from BH.dll - line 182
    VARPTR(D2CLIENT, MouseOffsetZ, int, 0x3A5214) // 1.13C from BH.dll - line ??- maybe 0x11995F
    VARPTR(D2CLIENT, MouseOffsetX, int, 0x119960) // 1.13C from BH.dll - line 184

    VARPTR(D2CLIENT, AutomapOn, DWORD, 0xFADA8)             // 1.13C from BH.dll - line 185
    VARPTR(D2CLIENT, AutomapMode, int, 0xF16B0)             // 1.13C from BH.dll - line 186 **Divisor**
    VARPTR(D2CLIENT, Offset, POINT, 0x11C1F8)               // 1.13C from BH.dll - line 187
    VARPTR(D2CLIENT, AutomapLayer, AutomapLayer*, 0x11C1C4) // 1.13C from BH.dll - line 190

    // VARPTR(D2CLIENT, MercStrIndex, WORD, 0xF23E8) // 1.13C from BH.dll - line 192 - not sure why commented
    VARPTR(D2CLIENT, MercReviveCost, DWORD, 0x11C334) // 1.13C from BH.dll - line 193

    VARPTR(D2CLIENT, ServerSideUnitHashTables, UnitHashTable, 0x3A5E70) // 1.13C from BH.dll - line ?? maybe 107
    VARPTR(D2CLIENT, ClientSideUnitHashTables, UnitHashTable, 0x3A5270) // 1.13C from BH.dll - line ?? maybe 106

    VARPTR(D2CLIENT, ViewportY, int, 0x3A5208) // 1.13C from BH.dll - line ?? **MouseOffsetY
    VARPTR(D2CLIENT, ViewportX, int, 0x3A520C) // 1.13C from BH.dll - line ?? **MouseOffsetX

    VARPTR(D2CLIENT, GoldDialogAction, DWORD, 0xFAD5C)  // 1.13C from BH.dll - line 195
    VARPTR(D2CLIENT, GoldDialogAmount, DWORD, 0x11BBB0) // 1.13C from BH.dll - line 196

    VARPTR(D2CLIENT, NPCMenu, NPCMenu*, 0xF3BA0)     // 1.13C from BH.dll - line 198
    VARPTR(D2CLIENT, NPCMenuAmount, DWORD, 0xF42F0) // 1.13C from BH.dll - line 199

    VARPTR(D2CLIENT, TradeLayout, InventoryLayout*, 0x10B288)     // 1.13C from BH.dll - line 201
    VARPTR(D2CLIENT, StashLayout, InventoryLayout*, 0x10B2D0)     // 1.13C from BH.dll - line 202
    VARPTR(D2CLIENT, StoreLayout, InventoryLayout*, 0x10B3B0)     // 1.13C from BH.dll - line 203
    VARPTR(D2CLIENT, CubeLayout, InventoryLayout*, 0x10B3C8)      // 1.13C from BH.dll - line 204
    VARPTR(D2CLIENT, InventoryLayout, InventoryLayout*, 0x10B3E0) // 1.13C from BH.dll - line 205
    VARPTR(D2CLIENT, MercLayout, InventoryLayout*, 0x11BD94)      // 1.13C from BH.dll - line 206

    VARPTR(D2CLIENT, RegularCursorType, DWORD, 0x11B864) // 1.13C from BH.dll - line 211
    VARPTR(D2CLIENT, ShopCursorType, DWORD, 0x11BC34)    // 1.13C from BH.dll - line 212

    VARPTR(D2CLIENT, Ping, DWORD, 0x119804)  // 1.13C from BH.dll - line 215
    VARPTR(D2CLIENT, Skip, DWORD, 0x119810)  // 1.13C from BH.dll - line 217
    VARPTR(D2CLIENT, FPS, DWORD, 0x11C2AC)   // 1.13C from BH.dll - line 216
    VARPTR(D2CLIENT, Lang, DWORD, 0x3BB5DC)  // 1.13C from BH.dll - line ??
    VARPTR(D2CLIENT, Divisor, int, 0xF16B0) // 1.13C from BH.dll - line 218

    VARPTR(D2CLIENT, OverheadTrigger, DWORD, 0x113ACE) // 1.13C from BH.dll - line 220

    VARPTR(D2CLIENT, RecentInteractId, DWORD, 0x11971D) // 1.13C from BH.dll - line 222

    VARPTR(D2CLIENT, ItemPriceList, DWORD, 0x11973B) // 1.13C from BH.dll - line 224

    VARPTR(D2CLIENT, TransactionDialog, void*, 0x11975B)                           // 1.13C from BH.dll - line 226
    VARPTR(D2CLIENT, TransactionDialogs, DWORD, 0x11BC08)                          // 1.13C from BH.dll - line 227
    VARPTR(D2CLIENT, TransactionDialogs_2, DWORD, 0x11BC04)                        // 1.13C from BH.dll - line 228
    VARPTR(D2CLIENT, pTransactionDialogsInfo, TransactionDialogsInfo_t*, 0x3C0E54) // 1.13C from BH.dll - line ??

    VARPTR(D2CLIENT, GameInfo, GameStructInfo*, 0x11B980) // 1.13C from BH.dll - line 230

    VARPTR(D2CLIENT, WaypointTable, DWORD, 0xFCDD1) // 1.13C from BH.dll - line 232

    VARPTR(D2CLIENT, PlayerUnit, UnitAny*, 0x11BBFC)      // 1.13C from BH.dll - line 234 
    VARPTR(D2CLIENT, SelectedInvItem, UnitAny*, 0x11BC38) // 1.13C from BH.dll - line 235
    // VARPTR(D2CLIENT, SelectedUnit, UnitAny*, 0x11C4D8) // unused, but can we use it somewhere maybe? // 1.12 still
    VARPTR(D2CLIENT, PlayerUnitList, RosterUnit*, 0x11BC14) // 1.13C from BH.dll - line 237

    VARPTR(D2CLIENT, bWeapSwitch, DWORD, 0x11BC94) // 1.13C from BH.dll - line 239

    VARPTR(D2CLIENT, bTradeAccepted, DWORD, 0x11BE64) // 1.13C from BH.dll - line 241
    VARPTR(D2CLIENT, bTradeBlock, DWORD, 0x11BE74)    // 1.13C from BH.dll - line 242

    // VARPTR(D2CLIENT, RecentTradeName, wchar_t*, 0x12334C)
    VARPTR(D2CLIENT, RecentTradeId, DWORD, 0x11C2CC) // 1.13C from BH.dll - line 244

    VARPTR(D2CLIENT, ExpCharFlag, DWORD, 0x119854) // 1.13C from BH.dll - line 245

    VARPTR(D2CLIENT, MapId, DWORD, 0x11C3BC) // 1.13C from BH.dll - line 248 // unused but I want to add it

    VARPTR(D2CLIENT, AlwaysRun, DWORD, 0x11C3EC) // 1.13C from BH.dll - line 250
    VARPTR(D2CLIENT, NoPickUp, DWORD, 0x11C2F0)  // 1.13C from BH.dll - line 251 // unused but I want to add it

    // VARPTR(D2CLIENT, ScreenCovered, DWORD, 0x1E8F9) // unused, appears to be an int specifying which screens (if any) are opened...

    VARPTR(D2CLIENT, ChatMsg, wchar_t*, 0x11EC80)     // 1.13C from BH.dll - line 255 
    VARPTR(D2CLIENT, OrificeId, DWORD, 0x3C547C)      // 1.13C from BH.dll - line ??
    VARPTR(D2CLIENT, CursorItemMode, DWORD, 0x3C5474) // 1.13C from BH.dll - line ??

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Client Stubs
    ////////////////////////////////////////////////////////////////////////////////////////////////

    ASMPTR(D2CLIENT, TakeWaypoint_I, 0xAA8B3) // 1.13C from BH.dll - line 262

    ASMPTR(D2CLIENT, ClickShopItem_I, 0x46EE0)  // 1.13C from BH.dll - line 264
    ASMPTR(D2CLIENT, ClickBelt_I, 0x28260)      // 1.13C from BH.dll - line 265
    ASMPTR(D2CLIENT, ClickBeltRight_I, 0x29990) // 1.13C from BH.dll - line 266
    ASMPTR(D2CLIENT, ClickItemRight_I, 0x98B60) // 1.13C from BH.dll - line 267
    ASMPTR(D2CLIENT, MercItemAction_I, 0x14A10) // 1.13C from BH.dll - line 268

    ASMPTR(D2CLIENT, Interact_I, 0x1BDE0) // // 1.13C from BH.dll - line 268 - line 270 // 6FADB2E0

    ASMPTR(D2CLIENT, ClickParty_I, 0x9E180)  // 1.13C from BH.dll - line 272
    ASMPTR(D2CLIENT, ClickParty_II, 0x773A0) // 1.13C from BH.dll - line 273

    ASMPTR(D2CLIENT, ShopAction_I, 0x47D60) // 1.13C from BH.dll - line 273 275 // 6FB2D030 **ShopAction**

    ASMPTR(D2CLIENT, GetUnitName_I, 0xA5D90) // 1.13C from BH.dll - line 277
    ASMPTR(D2CLIENT, GetItemDesc_I, 0x560B0) // 1.13C from BH.dll - line 278

    ASMPTR(D2CLIENT, AssignPlayer_I, 0xA7630) // 1.13C from BH.dll - line 280

    // ASMPTR(D2CLIENT, TestPvpFlag_I, 0x4FD90) // 1.13C from BH.dll - line 283 - not sure why commented //6FB1A720 - Fastcall now

    ASMPTR(D2CLIENT, InputCall_I, 0x147A0) // 1.13C from BH.dll - line 287
 
    ASMPTR(D2CLIENT, Say_I, 0x70EC6) // 1.13C from BH.dll - line 289

    ASMPTR(D2CLIENT, BodyClickTable, 0xE0EC4) // 1.13C from BH.dll - line 291

    ASMPTR(D2CLIENT, LoadUIImage_I, 0x2B420) // 1.13C from BH.dll - line 293 /// switch to d2win LoadCellFile //

    ASMPTR(D2CLIENT, GetMinionCount_I, 0x217E0) // 1.13C from BH.dll - line 295

    ASMPTR(D2CLIENT, GameLeave_I, 0x5D110) // 1.13C from BH.dll - line 297

    ASMPTR(D2CLIENT, CongratsScreen_I, 0xF6190) // 1.13C from BH.dll - line ??

    // ASMPTR(D2CLIENT, ClickMap_I, 0x11C8B4) //6FBCC8B4
    // ASMPTR(D2CLIENT, ClickMap_II, 0x11D2CC)//6FBCD2CC //MoveOn
    // ASMPTR(D2CLIENT, ClickMap_III, 0x5BB50)//ClickMap_III //CallOne
    // ASMPTR(D2CLIENT, ClickMap_IV, 0x2B499)//6FADB499

    ASMPTR(D2CLIENT, GameAddUnit_I, 0xA6500) // 1.13C from BH.dll - line 304

    // ASMPTR(D2CLIENT, LoadAct_1, 0x547F0) //Updated 1.14b //004547F0-BASE
    // ASMPTR(D2CLIENT, LoadAct_2, 0x5E4A0) //Updated 1.14b //0045E4A0-BASE

    // ASMPTR(D2CLIENT, GetUnitFromId_I, 0x61480) //GetUnitFromId_II //6FB11480
    // VARPTR(D2CLIENT, pUnitTable, POINT, 0x1047B8) //6FBB47B8 //GetUnitFromId_I //IrC

    // ASMPTR(D2CLIENT, OverrideShrinePatch_ORIG, 0x3A3150)//Updated 1.14d //007A3150-BASE

    ASMPTR(D2CLIENT, SendGamePacket_I, 0x78350) // 1.13C from BH.dll - line ??  //SendPacket_I
    ASMPTR(D2CLIENT, SendPacket_II, 0x12AE62)   //// 1.13C from BH.dll - line ?? Updated **NEW** 1.14d //0052AE62-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Common Ordinals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2COMMON, InitLevel, void __stdcall, (Level * pLevel), 0x2E360)       // 1.13C from BH.dll - line 321
    FUNCPTR(D2COMMON, UnloadAct, unsigned __stdcall, (Act * pAct), -10868)       // 1.13C from BH.dll - line 322
    FUNCPTR(D2COMMON, GetObjectTxt, ObjectTxt* __stdcall, (DWORD objno), 0x3E980) // 1.13C from BH.dll - line 323
    FUNCPTR(D2COMMON, LoadAct, Act* __stdcall,
            (DWORD ActNumber, DWORD MapId, DWORD Unk, DWORD Unk_2, DWORD Unk_3, DWORD Unk_4, DWORD TownLevelId, DWORD Func_1, DWORD Func_2),
        0x3CB30) // 1.13C from BH.dll - line 324

    FUNCPTR(D2COMMON, GetLevelText, LevelTxt* __stdcall, (DWORD levelno), -10014) // 1.13C from BH.dll - line 326
    FUNCPTR(D2COMMON, GetObjectText, ObjectTxt* __stdcall, (DWORD objno), -10688) // 1.13C from BH.dll - line 327
    FUNCPTR(D2COMMON, GetItemText, ItemTxt* __stdcall, (DWORD itemno), -10695)    // 1.13C from BH.dll - line 328

    FUNCPTR(D2COMMON, GetLayer, AutomapLayer2* __fastcall, (DWORD dwLevelNo), -10749)          // 1.13C from BH.dll - line 330
    FUNCPTR(D2COMMON, GetLevel, Level* __fastcall, (ActMisc * pMisc, DWORD dwLevelNo), -10207) // 1.13C from BH.dll - line  331

    FUNCPTR(D2COMMON, GetStatList, StatList* __stdcall, (UnitAny * pUnit, DWORD dwUnk, DWORD dwMaxEntries), -10930)        // 1.13C from BH.dll - line 333
    FUNCPTR(D2COMMON, CopyStatList, DWORD __stdcall, (StatList * pStatList, Stat* pStatArray, DWORD dwMaxEntries), -10658) // 1.13C from BH.dll - line 334
    FUNCPTR(D2COMMON, GetUnitStat, DWORD __stdcall, (UnitAny * pUnit, DWORD dwStat, DWORD dwStat2), -10973)                // 1.13C from BH.dll - line 336
    FUNCPTR(D2COMMON, GetUnitState, int __stdcall, (UnitAny * pUnit, DWORD dwStateNo), -10494)                             // 1.13C from BH.dll - line 337

    FUNCPTR(D2COMMON, CheckUnitCollision, DWORD __stdcall, (UnitAny * pUnitA, UnitAny* pUnitB, DWORD dwBitMask), -10839) // 1.13C from BH.dll - line 339
    FUNCPTR(D2COMMON, GetRoomFromUnit, Room1* __stdcall, (UnitAny * ptUnit), -10331)                                     // 1.13C from BH.dll - line 340
    FUNCPTR(D2COMMON, GetTargetUnitType, Path* __stdcall, (Path * pPath), -10392)                                          //1.13c From BH.dll - line 341

        FUNCPTR(D2COMMON, GetSkillLevel, INT __stdcall, (UnitAny * pUnit, Skill* pSkill, BOOL bTotal), -10306) // 1.13C from BH.dll - line 343

    FUNCPTR(D2COMMON, GetItemLevelRequirement, DWORD __stdcall, (UnitAny * pItem, UnitAny* pPlayer), -11015) // 1.13C from BH.dll - line 345

    FUNCPTR(D2COMMON, GetItemPrice, DWORD __stdcall, (UnitAny * MyUnit, UnitAny* pItem, DWORD U1_, DWORD U2_, DWORD U3_, DWORD U4_),
        -10107) // 1.13C from BH.dll - line 346
    FUNCPTR(D2COMMON, GetRepairCost, DWORD __stdcall, (DWORD _1, UnitAny* pUnit, DWORD dwNpcId, DWORD dwDifficulty, DWORD dwItemPriceList, DWORD _2),
        -10071)                                                                            // 1.13C from BH.dll - line 347
    FUNCPTR(D2COMMON, GetItemMagicalMods, char* __stdcall, (WORD wPrefixNum), -10248)          // 1.13C from BH.dll - line 348
    FUNCPTR(D2COMMON, GetItemFromInventory, UnitAny* __stdcall, (Inventory * inv), -10460)     // 1.13C from BH.dll - line 349
    FUNCPTR(D2COMMON, GetNextItemFromInventory, UnitAny* __stdcall, (UnitAny * pItem), -10464) // 1.13C from BH.dll - line 350

    FUNCPTR(D2COMMON, GenerateOverheadMsg, OverheadMsg* __stdcall, (DWORD dwUnk, CHAR* szMsg, DWORD dwTrigger), -10454) // 1.13C from BH.dll - line 357
    FUNCPTR(D2COMMON, FixOverheadMsg, VOID __stdcall, (OverheadMsg * pMsg, DWORD dwUnk), -10097)                        // 1.13C from BH.dll - line 358

    FUNCPTR(D2COMMON, AddRoomData, void __stdcall, (Act * ptAct, int LevelId, int Xpos, int Ypos, Room1* pRoom), -10401)    // 1.13C from BH.dll - line 360
    FUNCPTR(D2COMMON, RemoveRoomData, void __stdcall, (Act * ptAct, int LevelId, int Xpos, int Ypos, Room1* pRoom), -11099) // 1.13C from BH.dll - line 361

    FUNCPTR(D2COMMON, GetQuestFlag, int __stdcall, (void* QuestInfo, DWORD dwAct, DWORD dwQuest), -10174) // 1.13C from BH.dll - line 363

    FUNCPTR(D2COMMON, MapToAbsScreen, void __stdcall, (long* pX, long* pY), -11087)             // 1.13C from BH.dll - line 367
    FUNCPTR(D2COMMON, AbsScreenToMap, void __stdcall, (long* ptMouseX, long* ptMouseY), -10474) // 1.13C from BH.dll - line 366

    FUNCPTR(D2COMMON, CheckWaypoint, DWORD __stdcall, (DWORD WaypointTable, DWORD dwLevelId), -10373) // 1.13C from BH.dll - line 369

    FUNCPTR(D2COMMON, IsTownByLevelNo, BOOL __stdcall, (DWORD dwLevelNo), -10416)      // 1.13C from BH.dll - line 371
    FUNCPTR(D2COMMON, GetLevelNoFromRoom, BOOL __stdcall, (Room1 * pRoom1), 0x21A1B0)    // 1.13C from BH.dll - line ??
    FUNCPTR(D2COMMON, FindRoom1, Room1* __stdcall, (Act * pAct, int x, int y), 0x219DA3) // 1.13C from BH.dll - line ??
    FUNCPTR(D2COMMON, GetItemPalette, int __stdcall, (UnitAny * pPlayer, UnitAny* pItem, BYTE* pColor, int nTransType),
            0x22C100) // 1.13C from BH.dll - line ??
    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Common Globals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    VARPTR(D2COMMON, sgptDataTable, DWORD, 0x99E1C) // 1.13C from BH.dll - line 378

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Common Stubs
    ////////////////////////////////////////////////////////////////////////////////////////////////

    ASMPTR(D2COMMON, DisplayOverheadMsg_I, -10422) // 1.13C from BH.dll - line 389
    ASMPTR(D2COMMON, GetLevelIdFromRoom_I, 0x3C000) // 1.13C from BH.dll - line 390

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Net Functions
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2NET, SendPacket, void __stdcall, (size_t aLen, DWORD arg1, BYTE* aPacket), -10024, )      // 1.13C from BH.dll - line 397
    FUNCPTR(D2NET, ReceivePacket, void __fastcall, (BYTE * aPacket, DWORD aLen), -10033)              // 1.13C from BH.dll - line 398 ??
    FUNCPTR(D2NET, ReceivePacket_I, void __fastcall, (BYTE * aPacket, DWORD aLen, int* arg3), 0x12B920) // 1.13C from BH.dll - line ??

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Net Globals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    VARPTR(D2NET, CriticalPacketSection, CRITICAL_SECTION, 0xB400) // unused but we need to use it

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Gfx Ordinals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    // FUNCPTR(D2GFX, DrawAutomapCell, void __stdcall, (CellContext *context, DWORD xpos, DWORD ypos, RECT *cliprect, DWORD bright), 0xF6510) //Updated 1.14d
    // //004F6510-BASE
    FUNCPTR(D2GFX, DrawRectangle, void __stdcall, (int X1, int Y1, int X2, int Y2, DWORD dwColor, DWORD dwTrans), -10014) // 1.13C from BH.dll - line 416
    FUNCPTR(D2GFX, DrawLine, void __stdcall, (int X1, int Y1, int X2, int Y2, DWORD dwColor, DWORD dwUnk), -10010)        // 1.13C from BH.dll - line 415
    FUNCPTR(D2GFX, DrawAutomapCell2, void __stdcall, (CellContext * context, DWORD xpos, DWORD ypos, DWORD bright2, DWORD bright, BYTE* coltab),
        -10041)                                            // 1.13C from BH.dll - line 417
    FUNCPTR(D2GFX, GetHwnd, HWND __stdcall, (void), -10048)    // 1.13C from BH.dll - line 422
    FUNCPTR(D2GFX, GetScreenSize, DWORD __stdcall, (), -10031) // 1.13C from BH.dll - line 420

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Multi Functions
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2MULTI, DoChat, void __fastcall, (void), 0xCB30)                                               // 1.13C from BH.dll - line 435
    FUNCPTR(D2MULTI, PrintChannelText_, void __fastcall, (int unused, char* szText, DWORD dwColor), 0xFC90) // 1.13C from BH.dll - line 436

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Multi Globals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    VARPTR(D2MULTI, ChatBoxMsg, char*, 0x38F18)         // 1.13C from BH.dll - line 443
    VARPTR(D2MULTI, GameListControl, Control*, 0x39CC0) // 1.13C from BH.dll - line 444

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Multi Stubs
    ////////////////////////////////////////////////////////////////////////////////////////////////

    ASMPTR(D2MULTI, ChannelChat_I, 0x108A6) ASMPTR(D2MULTI, ChannelEmote_I, 0x107A6) ASMPTR(D2MULTI, ChannelWhisper_I, 0x10000)
        ASMPTR(D2MULTI, ChannelInput_I, 0xD5B0) // 1.13C from BH.dll - line 454,455,456,457

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Cmp Ordinals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2CMP, InitCellFile, VOID __stdcall, (LPVOID File, CellFile** Out, LPSTR SourceFile, DWORD Line, DWORD FileVersion, LPSTR Filename),
        -10006)                                                           // 1.13C from BH.dll - line 463
    FUNCPTR(D2CMP, DeleteCellFile, void __stdcall, (CellFile * File), -10106) // 1.13C from BH.dll - line 464

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Lang Ordinals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2LANG, GetLocaleText, wchar_t* __fastcall, (WORD nLocaleTxtNo), 0x124A30) // 1.13C from BH.dll - line 

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Lang Stubs
    ////////////////////////////////////////////////////////////////////////////////////////////////

    ASMPTR(D2LANG, Say_II, 0xB0B0) // 1.13C from BH.dll - line 478

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Launch Globals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    VARPTR(D2LAUNCH, BnData, BnetData*, 0x25ABC) // 1.13C from BH.dll - line 485

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Win Functions
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2WIN, SetControlText, void* __fastcall, (Control * box, const wchar_t* txt), -10042) // 1.13C from BH.dll - line 506
    FUNCPTR(D2WIN, DrawSprites, void __fastcall, (void), 0x18750)                                  // 1.13C from BH.dll - line 492
    FUNCPTR(D2WIN, LoadCellFile, CellFile* __fastcall, (const char* szFile, int Type), -10111)    // 1.13C from BH.dll - line 493

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Win Ordinals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2WIN, TakeScreenshot, void __fastcall, (), 0x17EB0)                                                               // 1.13C from d2bs patch-113 d2ptrs.h 385
    FUNCPTR(D2WIN, DrawText, void __fastcall, (const wchar_t* wStr, int xPos, int yPos, DWORD dwColor, DWORD dwUnk), -10150) // 1.13C from BH.dll - line 501
    FUNCPTR(D2WIN, GetTextSize, DWORD __fastcall, (wchar_t * wStr, DWORD* dwWidth, DWORD* dwFileNo), -10177)                 // 1.13C from BH.dll - line 503
    FUNCPTR(D2WIN, SetTextSize, DWORD __fastcall, (DWORD dwSize), -10184)                                                    // 1.13C from BH.dll - line 504
    FUNCPTR(D2WIN, GetTextWidthFileNo, DWORD __fastcall, (wchar_t * wStr, DWORD* dwWidth, DWORD* dwFileNo), -10177)          // 1.13C from BH.dll - line 507
    FUNCPTR(D2WIN, DestroyEditBox, DWORD __fastcall, (Control * box), 0x159E0)                                                 // 1.13C from BH.dll - line 510
    FUNCPTR(D2WIN, DestroyControl, VOID __stdcall, (Control * pControl), 0x18490)                                              // 1.13C from BH.dll - line 511
    FUNCPTR(D2WIN, SetEditBoxCallback, VOID __fastcall, (Control * pControl, BOOL(__stdcall* FunCallBack)(Control* pControl, DWORD dwInputType, char* pChar)),
        0x13970) // 1.13C from BH.dll - line 512
    FUNCPTR(D2WIN, SetEditBoxProc, void __fastcall, (Control * box, BOOL(__stdcall* FunCallBack)(Control*, DWORD, DWORD)),
        0x13970)                                                                                          // 1.13C from BH.dll - line 513
    FUNCPTR(D2WIN, SelectEditBoxText, void __fastcall, (Control * box), 0x7708)                              // 1.13C from BH.dll - line 514
    FUNCPTR(D2WIN, InitMPQ, DWORD __fastcall, (const char* mpqfile, char* mpqname, int v4, int v5), 0x7E60) // 1.13C from BH.dll - line 515

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Win Globals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    VARPTR(D2WIN, FirstControl, Control*, 0x214A0)   // 1.13C from BH.dll - line 521
    VARPTR(D2WIN, FocusedControl, Control*, 0x214B0) // 1.13C from BH.dll - line  522 unused, but we ought to use it
    VARPTR(D2MULTI, ChatInputBox, DWORD*, 0x3A0D0)   // 1.13C from BH.dll - line 447

    ASMPTR(BNCLIENT, DClass, 0x123673) // 1.13C from BH.dll - line ??
    ASMPTR(BNCLIENT, DLod, 0x12395D)   // 1.13C from BH.dll - line ??

    VARPTR(BNCLIENT, ClassicKey, char*, 0x1E8D8)                    // 1.13C from d2bs patch-113 d2ptrs.h 433
    VARPTR(BNCLIENT, XPacKey, char*, 0x1E8E0)                       // 1.13C from d2bs patch-113 d2ptrs.h 434
    VARPTR(BNCLIENT, KeyOwner, char*, 0x1E8E4)                      // 1.13C from d2bs patch-113 d2ptrs.h 435
    FUNCPTR(BNCLIENT, DecodeAndLoadKeys, char __cdecl, (), 0x162B0) // 1.13C from d2bs patch-113 d2ptrs.h 426
    VARPTR(STORM, WindowHandlers, WindowHandlerHashTable, 0x55370)  // 1.13C from d2bs patch-113 d2ptrs.h 413

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Game Functions
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2GAME, Rand, DWORD __fastcall, (DWORD * seed), 0x1160) // 1.13C from d2bs patch-113 d2ptrs.h 420

    FUNCPTR(D2GAME, exit0, DWORD __fastcall, (), 0x576F) // NEW 1.14d //0040576F-BASE ??

#undef FUNCPTR
#undef VARPTR
#undef ASMPTR

#ifdef __D2PTRS_LIST_
};
#else

//#define D2CLIENT_TestPvpFlag(dwId1, dwId2, dwFlag)		(D2CLIENT_TestPvpFlag_STUB(dwId1, dwId2, dwFlag))
#define D2MULTI_PrintChannelText(text, color) (D2MULTI_PrintChannelText_(0, text, color))
#define D2CLIENT_GetUIState(dwVarNo) (D2CLIENT_GetUIVar_STUB(dwVarNo))
#define D2CLIENT_SetUIState(dwVarNo, value) (D2CLIENT_SetUIVar(dwVarNo, value, 0))
#define D2CLIENT_InitAutomapLayer(layerlvl) ((AutomapLayer*)D2CLIENT_InitAutomapLayer_STUB(layerlvl))
#define D2CLIENT_GetUnitName(x) (wchar_t*)D2CLIENT_GetUnitName_STUB((DWORD)x)
#define D2CLIENT_SetSelectedUnit(x) (D2CLIENT_SetSelectedUnit_STUB((DWORD)x))
//#define D2CLIENT_LoadUIImage(x)							((CellFile*)D2CLIENT_LoadUIImage_ASM(x))
#define D2CLIENT_Interact_STUB(x) (D2CLIENT_Interact_ASM((DWORD)x))
#define D2CLIENT_ClickParty(x, y) (D2CLIENT_ClickParty_ASM((DWORD)x, (DWORD)y))
#define D2CLIENT_RightClickItem(x, y, loc, player, invdata) D2CLIENT_ClickItemRight_ASM(x, y, loc, (DWORD)player, (DWORD)invdata)
#define D2CLIENT_ClickBeltRight(pPlayer, pInventory, dwShift, dwPotPos) D2CLIENT_ClickBeltRight_ASM((DWORD)pPlayer, (DWORD)pInventory, dwShift, dwPotPos)
#define D2CLIENT_GetItemDesc(pUnit, pBuffer) D2CLIENT_GetItemDesc_ASM((DWORD)pUnit, pBuffer)
#define D2CLIENT_MercItemAction(bPacketType, dwSlotId) D2CLIENT_MercItemAction_ASM(bPacketType, dwSlotId)
#define D2CLIENT_SendGamePacket(dwLen, bPacket) D2CLIENT_SendGamePacket_ASM(dwLen, bPacket)

#define D2COMMON_DisplayOverheadMsg(pUnit) D2COMMON_DisplayOverheadMsg_ASM((DWORD)pUnit)

#define D2GFX_DrawFrame(Rect) D2GFX_DrawRectFrame_STUB(Rect)

#endif

#pragma warning(pop)
#pragma optimize("", on)

#endif
