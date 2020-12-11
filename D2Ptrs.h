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

    FUNCPTR(D2CLIENT, GetQuestInfo, void* __stdcall, (void), 0x45A00) // Updated 1.14d //004B32D0-BASE

    FUNCPTR(D2CLIENT, SubmitItem, void __fastcall, (DWORD dwItemId), 0x45FB0) // Updated 1.14d //004B2370-BASE
    FUNCPTR(D2CLIENT, Transmute, void __fastcall, (void), 0x8CB90)            // Updated 1.14d //0048A0D0-BASE

    FUNCPTR(D2CLIENT, FindClientSideUnit, UnitAny* __fastcall, (DWORD dwId, DWORD dwType), 0xA5B20) // Updated 1.14d //00463990-BASE
    FUNCPTR(D2CLIENT, FindServerSideUnit, UnitAny* __fastcall, (DWORD dwId, DWORD dwType), 0xA5B40) // Updated 1.14d //004639B0-BASE
    FUNCPTR(D2CLIENT, GetCurrentInteractingNPC, UnitAny* __fastcall, (void), 0x46150)               // Updated 1.14d //004B1620-BASE
    FUNCPTR(D2CLIENT, GetSelectedUnit, UnitAny* __stdcall, (), 0x51A80)                             // Updated 1.14d //00467A10-BASE
    FUNCPTR(D2CLIENT, GetCursorItem, UnitAny* __fastcall, (void), 0x16020)                          // Updated 1.14d //004680A0-BASE
    // FUNCPTR(D2CLIENT, GetMercUnit, UnitAny* __fastcall, (void), 0x97CD0) //Updated 1.14d //00478A90-BASE 478F20 with 7 0 args
    FUNCPTR(D2CLIENT, SetSelectedUnit_I, void __fastcall, (UnitAny * pUnit), 0x51860)                           // Updated 1.14d //00466DE0-BASE
    FUNCPTR(D2CLIENT, GetItemName, BOOL __fastcall, (UnitAny * pItem, wchar_t* wBuffer, DWORD dwSize), 0x914F0) // Updated 1.14d //0048C060-BASE
    FUNCPTR(D2CLIENT, LoadItemDesc, BOOL __stdcall, (UnitAny * pItem, int type), 0x97820)                       // Updated 1.14d //0048DD90-BASE
    FUNCPTR(D2CLIENT, GetMonsterOwner, DWORD __fastcall, (DWORD nMonsterId), 0x216A0)                           // Updated 1.14d //00479150-BASE
    FUNCPTR(D2CLIENT, GetUnitHPPercent, DWORD __fastcall, (DWORD dwUnitId), 0x21580)                            // Updated 1.14d //00479080-BASE
    FUNCPTR(D2CLIENT, InitInventory, void __fastcall, (void), 0x908C0)                                          // Updated 1.14d //004845A0-BASE
    FUNCPTR(D2CLIENT, SetUIVar, DWORD __fastcall, (DWORD varno, DWORD howset, DWORD unknown1), 0xC2790)         // Updated 1.14d //00455F20-BASE
    FUNCPTR(D2CLIENT, GetUnitX, int __fastcall, (UnitAny * pUnit), 0x1630)                                     // Updated 1.14d //0045ADF0-BASE
    FUNCPTR(D2CLIENT, GetUnitY, int __fastcall, (UnitAny * pUnit), 0x1660)                                     // Updated 1.14d //0045AE20-BASE

    FUNCPTR(D2CLIENT, ShopAction, void __fastcall, (UnitAny * pNpc, UnitAny* pItem, DWORD dwSell, DWORD unk, DWORD dwItemCost, DWORD dwMode, DWORD _2, DWORD _3),
            0x47D60) // Updated 1.14d //004B3870-BASE

    FUNCPTR(D2CLIENT, CloseNPCInteract, void __fastcall, (void), 0x492F0) // Updated 1.14d //004B3F10-BASE
    FUNCPTR(D2CLIENT, CloseInteract, void __fastcall, (void), 0x43870)    // Updated 1.14d //0044C6B0-BASE

    FUNCPTR(D2CLIENT, GetAutomapSize, DWORD __stdcall, (void), 0x5F080)                                                // Updated 1.14d //0045A710-BASE
    FUNCPTR(D2CLIENT, NewAutomapCell, AutomapCell* __fastcall, (), 0x5F6B0)                                                 // Updated 1.14d //00457C30-BASE
    FUNCPTR(D2CLIENT, AddAutomapCell, void __fastcall, (AutomapCell * aCell, AutomapCell** node), 0x61320)                  // Updated 1.14d //00457B00-BASE
    FUNCPTR(D2CLIENT, RevealAutomapRoom, void __stdcall, (Room1 * pRoom1, DWORD dwClipFlag, AutomapLayer* aLayer), 0x62580) // Updated 1.14d //00458F40-BASE
    FUNCPTR(D2CLIENT, InitAutomapLayer_I, AutomapLayer* __fastcall, (DWORD nLayerNo), 0x62710)                              // Updated 1.14d //00458D40-BASE

    FUNCPTR(D2CLIENT, ClickMap, void __fastcall, (DWORD MouseFlag, DWORD x, DWORD y, DWORD Type), 0x2B420) // Updated 1.14d //00462D00-BASE
    FUNCPTR(D2CLIENT, LeftClickItem_I, void __stdcall,
            (UnitAny * pPlayer, Inventory* pInventory, int x, int y, DWORD dwClickType, InventoryLayout* pLayout, DWORD Location),
            0x96AA0) // Updated 1.14d //0048FFE0-BASE

    FUNCPTR(D2CLIENT, GetMouseXOffset, DWORD __fastcall, (VOID), 0x3F6C0) // Updated 1.14d //0045AFC0-BASE
    FUNCPTR(D2CLIENT, GetMouseYOffset, DWORD __fastcall, (VOID), 0x3F6D0) // Updated 1.14d //0045AFB0-BASE

    FUNCPTR(D2CLIENT, PrintGameString, void __fastcall, (wchar_t * wMessage, int nColor), 0x7D610)  // Updated 1.14d //0049E3A0-BASE
    FUNCPTR(D2CLIENT, PrintPartyString, void __fastcall, (wchar_t * wMessage, int nColor), 0x7D850) // Updated 1.14d //0049E5C0-BASE

    FUNCPTR(D2CLIENT, LeaveParty, void __fastcall, (void), 0x9E5D0) // Updated 1.14d //00479FC0-BASE

    FUNCPTR(D2CLIENT, AcceptTrade, void __fastcall, (void), 0x59600) // Updated 1.14d //004B9070-BASE
    FUNCPTR(D2CLIENT, CancelTrade, void __fastcall, (void), 0x595C0) // Updated 1.14d //004B90B0-BASE
    FUNCPTR(D2CLIENT, TradeOK, void __stdcall, (void), NULL)     // missing

    FUNCPTR(D2CLIENT, GetDifficulty, BYTE __stdcall, (), 0x41930) // Updated 1.14d //0044DCD0-BASE

    FUNCPTR(D2CLIENT, ExitGame, void __fastcall, (void), 0x42850) // Updated 1.14d //0044DD60-BASE

    FUNCPTR(D2CLIENT, GetUiVar_I, DWORD __fastcall, (DWORD dwVarNo), 0xBE400) // Updated 1.14d //004538D0-BASE

    FUNCPTR(D2CLIENT, DrawRectFrame, VOID __fastcall, (DWORD Rect), 0xBE4C0) // Updated 1.14d //00452E50-BASE

    FUNCPTR(D2CLIENT, PerformGoldDialogAction, void __fastcall, (void), 0xBFDF0) // Updated 1.14d //00454080-BASE

    FUNCPTR(D2CLIENT, GetPlayerUnit, UnitAny* __stdcall, (), 0xA4D60) // Updated 1.14d //00463DD0-BASE

    // FUNCPTR(D2CLIENT, GetLevelName_I, wchar_t* __fastcall, (DWORD levelId), 0x53E70) //Updated 1.14d //00453E70-BASE

    FUNCPTR(D2CLIENT, ClearScreen, void __fastcall, (void), NULL) // Updated 1.14d //004B4620-BASE

    FUNCPTR(D2CLIENT, CloseNPCTalk, DWORD __stdcall, (void* unk), NULL) // Updated 1.14d //004A17D0-BASE

    FUNCPTR(D2CLIENT, TestPvpFlag, DWORD __fastcall, (DWORD dwUnitId1, DWORD dwUnitId2, DWORD dwFlag), NULL) // Updated 1.14d //004DC440-BASE

    FUNCPTR(D2CLIENT, GetGameLanguageCode, DWORD __fastcall, (), NULL) // New 1.14d //00525150-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Client Globals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    VARPTR(D2CLIENT, ScreenSizeX, DWORD, 0xDBC48) // Updated 1.14d //0071146C-BASE
    VARPTR(D2CLIENT, ScreenSizeY, DWORD, 0xDBC4C) // Updated 1.14d //00711470-BASE

    VARPTR(D2CLIENT, CursorHoverX, DWORD, 0xE0EB8) // Updated 1.14d //00721E4C-BASE
    VARPTR(D2CLIENT, CursorHoverY, DWORD, 0xE0EBC) // Updated 1.14d //00721E50-BASE

    VARPTR(D2CLIENT, MouseY, DWORD, 0x11B828) // Updated 1.14d //007A6AAC-BASE
    VARPTR(D2CLIENT, MouseX, DWORD, 0x11B824) // Updated 1.14d //007A6AB0-BASE

    VARPTR(D2CLIENT, MouseOffsetY, int, 0x11995C) // Updated 1.14d //007A5208-BASE
    VARPTR(D2CLIENT, MouseOffsetZ, int, 0x119960) // Updated 1.14d //007A5214-BASE
    VARPTR(D2CLIENT, MouseOffsetX, int, NULL) // Updated 1.14d //007A520C-BASE

    VARPTR(D2CLIENT, AutomapOn, DWORD, 0xFADA8)            // Updated 1.14d //007A27E8-BASE
    VARPTR(D2CLIENT, AutomapMode, int, 0xF16B0)            // Updated 1.14d //00711254-BASE **Divisor**
    VARPTR(D2CLIENT, Offset, POINT, 0x11C1F8)               // Updated 1.14d //007A5198-BASE
    VARPTR(D2CLIENT, AutomapLayer, AutomapLayer*, 0x11C1C4) // Updated 1.14d //007A5164-BASE

    // VARPTR(D2CLIENT, MercStrIndex, WORD, 0xF23E8) //Updated 1.14d //00725494-BASE
    VARPTR(D2CLIENT, MercReviveCost, DWORD, 0x11C334) // Updated 1.14d //007C0DD0-BASE

    VARPTR(D2CLIENT, ServerSideUnitHashTables, UnitHashTable, 0x3A5E70) // Updated 1.14d //007A5E70-BASE
    VARPTR(D2CLIENT, ClientSideUnitHashTables, UnitHashTable, 0x3A5270) // Updated 1.14d //007A5270-BASE

    VARPTR(D2CLIENT, ViewportY, int, 0x3A5208) // Updated 1.14d //007A5208-BASE **MouseOffsetY
    VARPTR(D2CLIENT, ViewportX, int, 0x3A520C) // Updated 1.14d //007A520C-BASE **MouseOffsetX

    VARPTR(D2CLIENT, GoldDialogAction, DWORD, 0xFAD5C) // Updated 1.14d //007A279C-BASE
    VARPTR(D2CLIENT, GoldDialogAmount, DWORD, 0x11BBB0) // Updated 1.14d //007A2A68-BASE

    VARPTR(D2CLIENT, NPCMenu, NPCMenu*, 0xF3BA0)    // Updated 1.14d //00726C48-BASE
    VARPTR(D2CLIENT, NPCMenuAmount, DWORD, 0xF42F0) // Updated 1.14d //00725A74-BASE

    VARPTR(D2CLIENT, TradeLayout, InventoryLayout*, 0x10B288)     // Updated 1.14d //007BCA30-BASE
    VARPTR(D2CLIENT, StashLayout, InventoryLayout*, 0x10B2D0)     // Updated 1.14d //007BCA78-BASE
    VARPTR(D2CLIENT, StoreLayout, InventoryLayout*, 0x10B3B0)     // Updated 1.14d //007BCB58-BASE
    VARPTR(D2CLIENT, CubeLayout, InventoryLayout*, 0x10B3C8)      // Updated 1.14d //007BCB70-BASE
    VARPTR(D2CLIENT, InventoryLayout, InventoryLayout*, 0x10B3E0) // Updated 1.14d //007BCB88-BASE
    VARPTR(D2CLIENT, MercLayout, InventoryLayout*, 0x11BD94)      // Updated 1.14d //007BCD4C-BASE

    VARPTR(D2CLIENT, RegularCursorType, DWORD, 0x11B864) // Updated 1.14d //007A6AF0-BASE
    VARPTR(D2CLIENT, ShopCursorType, DWORD, 0x11BC34)    // Updated 1.14d //007BCBF0-BASE

    VARPTR(D2CLIENT, Ping, DWORD, 0x119804)  // Updated 1.14d  //007A04A4-BASE
    VARPTR(D2CLIENT, Skip, DWORD, 0x119810)  // Updated 1.14d //007A04B0-BASE
    VARPTR(D2CLIENT, FPS, DWORD, 0x11C2AC)   // Updated 1.14d //007BB390-BASE
    VARPTR(D2CLIENT, Lang, DWORD, NULL)  // Updated 1.14d //007BB5DC-BASE
    VARPTR(D2CLIENT, Divisor, int, 0xF16B0) // Updated 1.14d //00711254-BASE

    VARPTR(D2CLIENT, OverheadTrigger, DWORD, 0x113ACE) // Updated 1.14d  //007BF20E-BASE

    VARPTR(D2CLIENT, RecentInteractId, DWORD, 0x11971D) // Updated 1.14d //007C0D25-BASE

    VARPTR(D2CLIENT, ItemPriceList, DWORD, 0x11973B) // Updated 1.14d //007C0D43-BASE

    VARPTR(D2CLIENT, TransactionDialog, void*, 0x11975B)                           // Updated 1.14d //007C0D63-BASE
    VARPTR(D2CLIENT, TransactionDialogs, DWORD, 0x11BC08)                          // Updated 1.14d //007C0E5C-BASE
    VARPTR(D2CLIENT, TransactionDialogs_2, DWORD, 0x11BC04)                        // Updated 1.14d //007C0E58-BASE
    VARPTR(D2CLIENT, pTransactionDialogsInfo, TransactionDialogsInfo_t*, NULL) // Updated 1.14d //007C0E54-BASE

    VARPTR(D2CLIENT, GameInfo, GameStructInfo*, 0x11B980) // Updated 1.14d //007A0438-BASE

    VARPTR(D2CLIENT, WaypointTable, DWORD, 0xFCDD1) // Updated 1.14d //007BF081-BASE

    VARPTR(D2CLIENT, PlayerUnit, UnitAny*, 0x11BBFC)      // Updated 1.14d //007A6A70-BASE
    VARPTR(D2CLIENT, SelectedInvItem, UnitAny*, 0x11BC38) // Updated 1.14d //007BCBF4-BASE
    // VARPTR(D2CLIENT, SelectedUnit, UnitAny*, 0x11C4D8) // unused, but can we use it somewhere maybe? // 1.12 still
    VARPTR(D2CLIENT, PlayerUnitList, RosterUnit*, 0x11BC14) // Updated 1.14d //007BB5C0-BASE

    VARPTR(D2CLIENT, bWeapSwitch, DWORD, 0x11BC94) // Updated 1.14d //007BCC4C-BASE

    VARPTR(D2CLIENT, bTradeAccepted, DWORD, 0x11BE64) // Updated 1.14d //007BCE18-BASE
    VARPTR(D2CLIENT, bTradeBlock, DWORD, 0x11BE74)    // Updated 1.14d //007BCE28-BASE

    // VARPTR(D2CLIENT, RecentTradeName, wchar_t*, 0x12334C)
    VARPTR(D2CLIENT, RecentTradeId, DWORD, 0x11C2CC) // Updated 1.14d //007C0E7C-BASE

    VARPTR(D2CLIENT, ExpCharFlag, DWORD, 0x119854) // Updated 1.14d //007A04F4-BASE

    VARPTR(D2CLIENT, MapId, DWORD, 0x11C3BC) // Updated 1.14d //007A0638-BASE // unused but I want to add it

    VARPTR(D2CLIENT, AlwaysRun, DWORD, 0x11C3EC) // Updated 1.14d //007A0660-BASE
    VARPTR(D2CLIENT, NoPickUp, DWORD, 0x11C2F0)  // Updated 1.14d //007A6A90-BASE // unused but I want to add it

    // VARPTR(D2CLIENT, ScreenCovered, DWORD, 0x1E8F9) // unused, appears to be an int specifying which screens (if any) are opened...

    VARPTR(D2CLIENT, ChatMsg, wchar_t*, 0x11EC80)     // Updated 1.14d //007BB638-BASE
    VARPTR(D2CLIENT, OrificeId, DWORD, NULL)      // Updated 1.14d //007C547C-BASE
    VARPTR(D2CLIENT, CursorItemMode, DWORD, NULL) // Updated 1.14d //007C5474-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Client Stubs
    ////////////////////////////////////////////////////////////////////////////////////////////////

    ASMPTR(D2CLIENT, TakeWaypoint_I, 0xAA8B3) // Updated 1.14d //0049D0F1-BASE

    ASMPTR(D2CLIENT, ClickShopItem_I, 0x46EE0)  // Updated 1.14d //004B2653-BASE
    ASMPTR(D2CLIENT, ClickBelt_I, 0x28260)      // Updated 1.14d //00498870-BASE
    ASMPTR(D2CLIENT, ClickBeltRight_I, 0x29990) // Updated 1.14d //00498A90-BASE
    ASMPTR(D2CLIENT, ClickItemRight_I, 0x98B60) // Updated 1.14d //00487740-BASE
    ASMPTR(D2CLIENT, MercItemAction_I, 0x14A10) // Updated 1.14d //004785B0-BASE

    ASMPTR(D2CLIENT, Interact_I, 0x1BDE0) // 6FADB2E0

    ASMPTR(D2CLIENT, ClickParty_I, 0x9E180)  // Updated 1.14d //00479EB0-BASE
    ASMPTR(D2CLIENT, ClickParty_II, 0x773A0) // Updated 1.14d //0049B990-BASE

    ASMPTR(D2CLIENT, ShopAction_I, 0x47D60) // 6FB2D030 **ShopAction**

    ASMPTR(D2CLIENT, GetUnitName_I, 0xA5D90) // Updated 1.14d //00464A60-BASE
    ASMPTR(D2CLIENT, GetItemDesc_I, 0x560B0) // 6FADE380

    ASMPTR(D2CLIENT, AssignPlayer_I, 0xA7630) // Updated 1.14d //00466200-BASE

    // ASMPTR(D2CLIENT, TestPvpFlag_I, 0x4FD90) //6FB1A720 - Fastcall now

    ASMPTR(D2CLIENT, InputCall_I, 0x147A0) // Updated 1.14d //004787B0-BASE

    ASMPTR(D2CLIENT, Say_I, 0x70EC6) // Updated 1.14d //0047CBDA-BASE

    ASMPTR(D2CLIENT, BodyClickTable, 0xE0EC4) // Updated 1.14d //00721E58-BASE

    ASMPTR(D2CLIENT, LoadUIImage_I, 0x2B420) // Updated 1.14d //004788B0-BASE /// switch to d2win LoadCellFile //

    ASMPTR(D2CLIENT, GetMinionCount_I, 0x217E0) // Updated 1.14d //00478EE0-BASE

    ASMPTR(D2CLIENT, GameLeave_I, 0x5D110) // Updated 1.14d //00481830-BASE

    ASMPTR(D2CLIENT, CongratsScreen_I, NULL) // Updated 1.14d //004F6190-BASE

    // ASMPTR(D2CLIENT, ClickMap_I, 0x11C8B4) //6FBCC8B4
    // ASMPTR(D2CLIENT, ClickMap_II, 0x11D2CC)//6FBCD2CC //MoveOn
    // ASMPTR(D2CLIENT, ClickMap_III, 0x5BB50)//ClickMap_III //CallOne
    // ASMPTR(D2CLIENT, ClickMap_IV, 0x2B499)//6FADB499

    ASMPTR(D2CLIENT, GameAddUnit_I, 0xA6500) // 6FB128E0

    // ASMPTR(D2CLIENT, LoadAct_1, 0x547F0) //Updated 1.14b //004547F0-BASE
    // ASMPTR(D2CLIENT, LoadAct_2, 0x5E4A0) //Updated 1.14b //0045E4A0-BASE

    // ASMPTR(D2CLIENT, GetUnitFromId_I, 0x61480) //GetUnitFromId_II //6FB11480
    // VARPTR(D2CLIENT, pUnitTable, POINT, 0x1047B8) //6FBB47B8 //GetUnitFromId_I //IrC

    // ASMPTR(D2CLIENT, OverrideShrinePatch_ORIG, 0x3A3150)//Updated 1.14d //007A3150-BASE

    ASMPTR(D2CLIENT, SendGamePacket_I, NULL) // Updated 1.14d //00478350-BASE //SendPacket_I
    ASMPTR(D2CLIENT, SendPacket_II, NULL)   // Updated **NEW** 1.14d //0052AE62-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Common Ordinals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2COMMON, InitLevel, void __stdcall, (Level * pLevel), 0x2E360)       // Updated 1.14d //006424A0-BASE
    FUNCPTR(D2COMMON, UnloadAct, unsigned __stdcall, (Act * pAct), -10868)       // Updated 1.14d //0061AFD3-BASE
    FUNCPTR(D2COMMON, GetObjectTxt, ObjectTxt* __stdcall, (DWORD objno), 0x3E980) // Updated 1.14d //00640E90-BASE
    FUNCPTR(D2COMMON, LoadAct, Act* __stdcall,
            (DWORD ActNumber, DWORD MapId, DWORD Unk, DWORD Unk_2, DWORD Unk_3, DWORD Unk_4, DWORD TownLevelId, DWORD Func_1, DWORD Func_2),
            0x3CB30) // Updated 1.14d //006194A0-BASE

    FUNCPTR(D2COMMON, GetLevelText, LevelTxt* __stdcall, (DWORD levelno), -10014) // Updated 1.14d //0061DB70-BASE
    FUNCPTR(D2COMMON, GetObjectText, ObjectTxt* __stdcall, (DWORD objno), -10688) // Updated 1.14d //00640E90-BASE
    FUNCPTR(D2COMMON, GetItemText, ItemTxt* __stdcall, (DWORD itemno), -10695)    // Updated 1.14d //006335F0-BASE

    FUNCPTR(D2COMMON, GetLayer, AutomapLayer2* __fastcall, (DWORD dwLevelNo), -10749)          // Updated 1.14d //0061E470-BASE
    FUNCPTR(D2COMMON, GetLevel, Level* __fastcall, (ActMisc * pMisc, DWORD dwLevelNo), -10207) // Updated 1.14d //00642AE0-BASE

    FUNCPTR(D2COMMON, GetStatList, StatList* __stdcall, (UnitAny * pUnit, DWORD dwUnk, DWORD dwMaxEntries), -10930)        // Updated 1.14d //006257D0-BASE
    FUNCPTR(D2COMMON, CopyStatList, DWORD __stdcall, (StatList * pStatList, Stat* pStatArray, DWORD dwMaxEntries), -10658) // Updated 1.14d //0625C90-BASE
    FUNCPTR(D2COMMON, GetUnitStat, DWORD __stdcall, (UnitAny * pUnit, DWORD dwStat, DWORD dwStat2), -10973)                // Updated 1.14d //00625480-BASE
    FUNCPTR(D2COMMON, GetUnitState, int __stdcall, (UnitAny * pUnit, DWORD dwStateNo), -10494)                             // Updated 1.14d //00639DF0-BASE

    FUNCPTR(D2COMMON, CheckUnitCollision, DWORD __stdcall, (UnitAny * pUnitA, UnitAny* pUnitB, DWORD dwBitMask), -10839) // Updated 1.14d //00622AA0-BASE
    FUNCPTR(D2COMMON, GetRoomFromUnit, Room1* __stdcall, (UnitAny * ptUnit), -10331)                                     // Updated 1.14d //00620BB0-BASE
    FUNCPTR(D2COMMON, GetTargetUnitType, Path* __stdcall, (Path * pPath), -10392)

    FUNCPTR(D2COMMON, GetSkillLevel, INT __stdcall, (UnitAny * pUnit, Skill* pSkill, BOOL bTotal), -10306) // Updated 1.14d //006442A0-BASE

    FUNCPTR(D2COMMON, GetItemLevelRequirement, DWORD __stdcall, (UnitAny * pItem, UnitAny* pPlayer), -11015) // Updated 1.14d //0062BA60-BASE

    FUNCPTR(D2COMMON, GetItemPrice, DWORD __stdcall, (UnitAny * MyUnit, UnitAny* pItem, DWORD U1_, DWORD U2_, DWORD U3_, DWORD U4_),
            -10107) // Updated 1.14d //0062FDC0-BASE
    FUNCPTR(D2COMMON, GetRepairCost, DWORD __stdcall, (DWORD _1, UnitAny* pUnit, DWORD dwNpcId, DWORD dwDifficulty, DWORD dwItemPriceList, DWORD _2),
            -10071)                                                                            // Updated 1.14d //0062FE60-BASE
    FUNCPTR(D2COMMON, GetItemMagicalMods, char* __stdcall, (WORD wPrefixNum), -10248)          // Updated 1.14d //00633EE0-BASE
    FUNCPTR(D2COMMON, GetItemFromInventory, UnitAny* __stdcall, (Inventory * inv), -10460)     // Updated 1.14d //0063B2C0-BASE
    FUNCPTR(D2COMMON, GetNextItemFromInventory, UnitAny* __stdcall, (UnitAny * pItem), -10464) // Updated 1.14d //0063DFA0-BASE

    FUNCPTR(D2COMMON, GenerateOverheadMsg, OverheadMsg* __stdcall, (DWORD dwUnk, CHAR* szMsg, DWORD dwTrigger), -10454) // Updated 1.14d //00661110-BASE
    FUNCPTR(D2COMMON, FixOverheadMsg, VOID __stdcall, (OverheadMsg * pMsg, DWORD dwUnk), -10097)                        // Updated 1.14d //00661230-BASE

    FUNCPTR(D2COMMON, AddRoomData, void __stdcall, (Act * ptAct, int LevelId, int Xpos, int Ypos, Room1* pRoom), -10401)    // Updated 1.14d //0061A070-BASE
    FUNCPTR(D2COMMON, RemoveRoomData, void __stdcall, (Act * ptAct, int LevelId, int Xpos, int Ypos, Room1* pRoom), -11099) // Updated 1.14d //0061A0C0-BASE

    FUNCPTR(D2COMMON, GetQuestFlag, int __stdcall, (void* QuestInfo, DWORD dwAct, DWORD dwQuest), -10174) // Updated 1.14d //0065C310-BASE

    FUNCPTR(D2COMMON, MapToAbsScreen, void __stdcall, (long* pX, long* pY), -11087)             // Updated 1.14d //00643260-BASE
    FUNCPTR(D2COMMON, AbsScreenToMap, void __stdcall, (long* ptMouseX, long* ptMouseY), -10474) // Updated 1.14d  //00643510-BASE

    FUNCPTR(D2COMMON, CheckWaypoint, DWORD __stdcall, (DWORD WaypointTable, DWORD dwLevelId), -10373) // Updated 1.14d //00660E50-BASE

    FUNCPTR(D2COMMON, IsTownByLevelNo, BOOL __stdcall, (DWORD dwLevelNo), -10416)      // Updated 1.14d //0061AAF0-BASE
    FUNCPTR(D2COMMON, GetLevelNoFromRoom, BOOL __stdcall, (Room1 * pRoom1), NULL)    // Updated 1.14d //0061A1B0-BASE
    FUNCPTR(D2COMMON, FindRoom1, Room1* __stdcall, (Act * pAct, int x, int y), NULL) // Updated 1.14d //00619DA3-BASE
    FUNCPTR(D2COMMON, GetItemPalette, int __stdcall, (UnitAny * pPlayer, UnitAny* pItem, BYTE* pColor, int nTransType),
            NULL) // Updated 1.14d //0062C100-BASE
    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Common Globals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    VARPTR(D2COMMON, sgptDataTable, DWORD, 0x99E1C) // Updated 1.14d //00744304-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Common Stubs
    ////////////////////////////////////////////////////////////////////////////////////////////////

    ASMPTR(D2COMMON, DisplayOverheadMsg_I, -10422) // Updated 1.14d //006611A0-BASE
    ASMPTR(D2COMMON, GetLevelIdFromRoom_I, 0x3C000) // Updated 1.14d //0061A1B0-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Net Functions
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2NET, SendPacket, void __stdcall, (size_t aLen, DWORD arg1, BYTE* aPacket), -10024)      // Updated 1.14d //0052AE50-BASE
    FUNCPTR(D2NET, ReceivePacket, void __fastcall, (BYTE * aPacket, DWORD aLen), NULL)              // Updated 1.14d //0052AEB0-BASE
    FUNCPTR(D2NET, ReceivePacket_I, void __fastcall, (BYTE * aPacket, DWORD aLen, int* arg3), -10033) // Updated 1.14d //0052B920-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Net Globals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    VARPTR(D2NET, CriticalPacketSection, CRITICAL_SECTION, 0xB400) // unused but we need to use it

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Gfx Ordinals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    // FUNCPTR(D2GFX, DrawAutomapCell, void __stdcall, (CellContext *context, DWORD xpos, DWORD ypos, RECT *cliprect, DWORD bright), 0xF6510) //Updated 1.14d
    // //004F6510-BASE
    FUNCPTR(D2GFX, DrawRectangle, void __stdcall, (int X1, int Y1, int X2, int Y2, DWORD dwColor, DWORD dwTrans), -10014) // Updated 1.14d //004F6300-BASE
    FUNCPTR(D2GFX, DrawLine, void __stdcall, (int X1, int Y1, int X2, int Y2, DWORD dwColor, DWORD dwUnk), -10010)        // Updated 1.14d //004F6380-BASE
    FUNCPTR(D2GFX, DrawAutomapCell2, void __stdcall, (CellContext * context, DWORD xpos, DWORD ypos, DWORD bright2, DWORD bright, BYTE* coltab),
            -10041)                                            // Updated 1.14d //004F6480-BASE
    FUNCPTR(D2GFX, GetHwnd, HWND __stdcall, (void), -10048)    // Updated 1.14d //004F59A0-BASE
    FUNCPTR(D2GFX, GetScreenSize, DWORD __stdcall, (), -10031) // Updated 1.14d //004F5160-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Multi Functions
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2MULTI, DoChat, void __fastcall, (void), 0xCB30)                                               // Updated 1.14d //00442810-BASE
    FUNCPTR(D2MULTI, PrintChannelText_, void __fastcall, (int unused, char* szText, DWORD dwColor), 0xFC90) // Updated 1.14d //00447AB0-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Multi Globals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    VARPTR(D2MULTI, ChatBoxMsg, char*, 0x38F18)         // Updated 1.14d //0077AE40-BASE
    VARPTR(D2MULTI, GameListControl, Control*, 0x39CC0) // Updated 1.14d //00798BC0-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Multi Stubs
    ////////////////////////////////////////////////////////////////////////////////////////////////

    ASMPTR(D2MULTI, ChannelChat_I, 0x14BE6)
	ASMPTR(D2MULTI, ChannelEmote_I, 0x14856)
	ASMPTR(D2MULTI, ChannelWhisper_I, 0x142F0)
    ASMPTR(D2MULTI, ChannelInput_I, 0x428D0) // Updated 1.14d //004428D0-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Cmp Ordinals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2CMP, InitCellFile, VOID __stdcall, (LPVOID File, CellFile** Out, LPSTR SourceFile, DWORD Line, DWORD FileVersion, LPSTR Filename),
            -10006)                                                           // Updated 1.14d //00601340-BASE
    FUNCPTR(D2CMP, DeleteCellFile, void __stdcall, (CellFile * File), -10106) // Updated 1.14d //00601A50-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Lang Ordinals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2LANG, GetLocaleText, wchar_t* __fastcall, (WORD nLocaleTxtNo), -10003) // Updated 1.14d //00524A30-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Lang Stubs
    ////////////////////////////////////////////////////////////////////////////////////////////////

    ASMPTR(D2LANG, Say_II, 0xB0B0) // Updated 1.14d //00526800-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Launch Globals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    VARPTR(D2LAUNCH, BnData, BnetData*, 0x25ABC) // Updated 1.14d //007795D4-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Win Functions
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2WIN, SetControlText, void* __fastcall, (Control * box, const wchar_t* txt), -10042) // Updated 1.14d //004FF5A0-BASE
    FUNCPTR(D2WIN, DrawSprites, void __fastcall, (void), 0x18750)                                  // Updated 1.14d //004F9870-BASE
    FUNCPTR(D2WIN, LoadCellFile, CellFile* __fastcall, (const char* szFile, int Type), -10111)    // Updated 1.14d //004FA9B0-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Win Ordinals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2WIN, TakeScreenshot, void __fastcall, (), NULL)                                                               // Updated 1.14d //004FA7A0-BASE
    FUNCPTR(D2WIN, DrawText, void __fastcall, (const wchar_t* wStr, int xPos, int yPos, DWORD dwColor, DWORD dwUnk), -10150) // Updated 1.14d //00502320-BASE
    FUNCPTR(D2WIN, GetTextSize, DWORD __fastcall, (wchar_t * wStr, DWORD* dwWidth, DWORD* dwFileNo), -10177)                 // Updated 1.14d //00502520-BASE
    FUNCPTR(D2WIN, SetTextSize, DWORD __fastcall, (DWORD dwSize), -10184)                                                    // Updated 1.14d //00502EF0-BASE
    FUNCPTR(D2WIN, GetTextWidthFileNo, DWORD __fastcall, (wchar_t * wStr, DWORD* dwWidth, DWORD* dwFileNo), -10177)          // Updated 1.14d //00502520-BASE
    FUNCPTR(D2WIN, DestroyEditBox, DWORD __fastcall, (Control * box), 0x159E0)                                                 // Updated 1.14d //004FDAA0-BASE
    FUNCPTR(D2WIN, DestroyControl, VOID __stdcall, (Control * pControl), 0x18490)                                              // Updated 1.14d // 004f95c0-BASE
    FUNCPTR(D2WIN, SetEditBoxCallback, VOID __fastcall, (Control * pControl, BOOL(__stdcall* FunCallBack)(Control* pControl, DWORD dwInputType, char* pChar)),
            0x13970) // Updated 1.14d //004FDAD0-BASE
    FUNCPTR(D2WIN, SetEditBoxProc, void __fastcall, (Control * box, BOOL(__stdcall* FunCallBack)(Control*, DWORD, DWORD)),
            0x13970)                                                                                          // Updated 1.14d //004FDAD0-BASE
    FUNCPTR(D2WIN, SelectEditBoxText, void __fastcall, (Control * box), 0x7708)                              // Updated 1.14d //004fdd00-BASE
    FUNCPTR(D2WIN, InitMPQ, DWORD __fastcall, (const char* mpqfile, char* mpqname, int v4, int v5), 0x7E60) // Updated 1.14d //00517332-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Win Globals
    ////////////////////////////////////////////////////////////////////////////////////////////////

    VARPTR(D2WIN, FirstControl, Control*, 0x214A0)   // Updated 1.14d //007D55BC-BASE
    VARPTR(D2WIN, FocusedControl, Control*, 0x214B0) // Updated 1.14d //007D55CC-BASE unused, but we ought to use it
    VARPTR(D2MULTI, ChatInputBox, DWORD*, 0x3A0D0)   // Updated 1.14d //00798C80-BASE

    ASMPTR(BNCLIENT, DClass, NULL) // Updated 1.14d //00523673-BASE
    ASMPTR(BNCLIENT, DLod, NULL)   // Updated 1.14d //0052395D-BASE

    VARPTR(BNCLIENT, ClassicKey, char*, NULL)                    // Updated 1.14d //00882744-BASE
    VARPTR(BNCLIENT, XPacKey, char*, NULL)                       // Updated 1.14d //0088274C-BASE
    VARPTR(BNCLIENT, KeyOwner, char*, NULL)                      // Updated 1.14d //00882750-BASE
    FUNCPTR(BNCLIENT, DecodeAndLoadKeys, char __cdecl, (), NULL) // Updated 1.14d //005234D0-BASE
    VARPTR(STORM, WindowHandlers, WindowHandlerHashTable, NULL)  // Updated 1.14d //00779300-BASE

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // D2Game Functions
    ////////////////////////////////////////////////////////////////////////////////////////////////

    FUNCPTR(D2GAME, Rand, DWORD __fastcall, (DWORD * seed), 0x1160) // Updated 1.14d //0045C370-BASE

    FUNCPTR(D2GAME, exit0, DWORD __fastcall, (), NULL) // NEW 1.14d //0040576F-BASE

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
