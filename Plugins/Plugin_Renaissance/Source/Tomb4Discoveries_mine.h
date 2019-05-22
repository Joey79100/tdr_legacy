
// FOR_YOU: here you can type your discoveries about tomb4 procedures
// if you mean use the C language to call them, you can create the
// prototypes of them like it has been done in the "DefTomb4Funct.h" file
// and "functions.h" file.
// While if you wish use only assembly code, you can type here
// the #define ADR_NOME_PROC 0x404040  to remember and use in the asm
// code all addresses of the tomb4 procedures

// TYPE_HERE: prototype (c++ language), mnemonic constants for 
// addresses (assembly)


// FOR_YOU: here you can type your discoveries about tomb4 procedures
// if you mean use the C language to call them, you can create the
// prototypes of them like it has been done in the "DefTomb4Funct.h" file
// and "functions.h" file.
// While if you wish use only assembly code, you can type here
// the #define ADR_NOME_PROC 0x404040  to remember and use in the asm
// code all addresses of the tomb4 procedures

// TYPE_HERE: prototype (c++ language), mnemonic constants for 
// addresses (assembly)

typedef void (__cdecl* TYPE_GetAITarget) (CREATURE_INFO *creature);
typedef void (__cdecl* TYPE_CreatureAIInfo) (StrItemTr4 *item, AI_INFO *info);
typedef void (__cdecl* TYPE_GetCreatureMood) (StrItemTr4 *item, AI_INFO *info, int violent);
typedef void (__cdecl* TYPE_CreatureMood) (StrItemTr4 *item, AI_INFO *info, int violent);
typedef int (__cdecl* TYPE_phd_atan) (int x, int y);
typedef void (__cdecl* TYPE_AlertAllGuards) (short ItemIndex);
typedef short (__cdecl* TYPE_CreatureEffect) (StrItemTr4 *item, BITE_INFO *bite, short (*generate)(DWORD CordX, int CordY, DWORD CordZ, int Casuale, WORD Orientamento, WORD Room));
typedef void (__cdecl* TYPE_CreatureTilt) (StrItemTr4 *item, short angle);
typedef void (__cdecl* TYPE_CreatureJoint) (StrItemTr4 *item, short joint, short required);
typedef int (__cdecl* TYPE_CreatureAnimation) (short ItemIndex, short angle, short tilt);
typedef short (__cdecl* TYPE_CreatureTurn) (StrItemTr4 *item, short maximum_turn);
typedef void (__cdecl* TYPE_CreatureUnderwater) (StrItemTr4 *item, int depth);
typedef void (__cdecl* TYPE_CreatureFloat) (short ItemIndex);
typedef int (__cdecl* TYPE_BadFloor) (int x, int y, int z, int box_height, int next_height, short room_number, LOT_INFO *LOT);
typedef int (__cdecl* TYPE_CreatureCreature) (short ItemIndex);
typedef int (__cdecl* TYPE_ValidBox) (StrItemTr4 *item, short zone_number, short box_number);
typedef void (__cdecl* TYPE_EscapeBox) (StrItemTr4 *item, StrItemTr4 *enemy, short box_number);
typedef void (__cdecl* TYPE_TargetBox) (LOT_INFO *LOT, short box_number);
typedef int (__cdecl* TYPE_SearchLOT) (LOT_INFO *LOT, int expansion);
typedef int (__cdecl* TYPE_UpdateLOT) (LOT_INFO *LOT, int expansion);
typedef void (__cdecl* TYPE_InitialiseCreature) (short ItemIndex);
typedef int (__cdecl* TYPE_CreatureVault) (short ItemIndex, short angle, int vault, int shift);
typedef void (__cdecl* TYPE_CreatureKill) (StrItemTr4 *item, int kill_anim, int kill_state, int lara_kill_state);
typedef void (__cdecl* TYPE_AlertNearbyGuards) (StrItemTr4 *item);
typedef short (__cdecl* TYPE_AIGuard) (CREATURE_INFO *creature);
typedef short (__cdecl* TYPE_SameZone) (CREATURE_INFO *creature, StrItemTr4 *target_item);
typedef void (__cdecl* TYPE_AdjustStopperFlag) (StrItemTr4 *item, long dir, long set);
typedef short (__cdecl* TYPE_CreateEffect) (short room_num);
typedef int (__cdecl* TYPE_TargetVisible) (StrItemTr4 *item, AI_INFO *info);
typedef int (__cdecl* TYPE_Targetable) (StrItemTr4 *item, AI_INFO *info);
typedef short (__cdecl* TYPE_GunShot) (int x, int y, int z, short speed, short yrot, short room_number); // PHD_ANGLE yrot = short?
typedef short (__cdecl* TYPE_GunHit) (int x, int y, int z, short speed, short yrot, short room_number);
typedef short (__cdecl* TYPE_GunMiss) (int x, int y, int z, short speed, short yrot, short room_number);
typedef int (__cdecl* TYPE_ShotLara) (StrItemTr4 *item, AI_INFO *info, BITE_INFO *gun, short extra_rotation, int damage);
typedef void (__cdecl* TYPE_phd_TranslateRel) (int x, int y, int z);
typedef void (__cdecl* TYPE_phd_RotX) (short Orient);
typedef void (__cdecl* TYPE_phd_RotZ) (short Orient);
typedef void (__cdecl* TYPE_gar_RotYXZsuperpack) (short **pprot, int skip);
typedef void (__cdecl* TYPE_SeedRandomControl) (int seed); // 0x48EB70
typedef int (__cdecl* TYPE_GetRandomDraw)(void); // 0x48EB90
typedef void (__cdecl* TYPE_SeedRandomDraw)(void); // 0x48EBA0
//typedef void (__cdecl* TYPE_GetValidLevelsList)(REQUEST_INFO *req); // 0x48EBB0
typedef void (__cdecl* TYPE_InitialiseItem)(short ItemIndex); // 0x453840 or 0x453850
typedef void (__cdecl* TYPE_ShiftItem)(StrItemTr4 *item, StrCollisionLara *coll);
typedef void (__cdecl* TYPE_LaraBaddieCollision)(StrItemTr4 *laraitem, StrCollisionLara *coll);
typedef void (__cdecl* TYPE_CreatureCollision)(short ItemIndex, StrItemTr4 *laraitem, StrCollisionLara *coll);
typedef void (__cdecl* TYPE_DetachSpark)(long num, long type);
typedef long (__cdecl* TYPE_GetFreeSpark)(void);

TYPE_GetAITarget GetAITarget = (TYPE_GetAITarget) 0x441EE0;
TYPE_CreatureAIInfo CreatureAIInfo = (TYPE_CreatureAIInfo) 0x43F3E0;
TYPE_phd_atan phd_atan = (TYPE_phd_atan) 0x48DE90;
TYPE_GetCreatureMood GetCreatureMood = (TYPE_GetCreatureMood) 0x43FBD0;
TYPE_CreatureMood CreatureMood = (TYPE_CreatureMood) 0x43FE10;
TYPE_AlertAllGuards AlertAllGuards = (TYPE_AlertAllGuards) 0x441D10;
TYPE_CreatureEffect CreatureEffect = (TYPE_CreatureEffect) 0x4418E0; //0x441940;
TYPE_CreatureTilt CreatureTilt = (TYPE_CreatureTilt) 0x4416B0;
TYPE_CreatureJoint CreatureJoint = (TYPE_CreatureJoint) 0x4416F0;
TYPE_CreatureAnimation CreatureAnimation = (TYPE_CreatureAnimation) 0x4409F0;
TYPE_CreatureTurn CreatureTurn = (TYPE_CreatureTurn) 0x441430;
TYPE_CreatureUnderwater CreatureUnderwater = (TYPE_CreatureUnderwater) 0x441850;
TYPE_CreatureFloat CreatureFloat = (TYPE_CreatureFloat) 0x441750;
TYPE_BadFloor BadFloor = (TYPE_BadFloor) 0x440790;
TYPE_CreatureCreature CreatureCreature = (TYPE_CreatureCreature) 0x440220; // Not sure
TYPE_ValidBox ValidBox = (TYPE_ValidBox) 0x43FB20;
TYPE_EscapeBox EscapeBox = (TYPE_EscapeBox) 0x43FA70;
TYPE_TargetBox TargetBox = (TYPE_TargetBox) 0x43F9D0;
TYPE_SearchLOT SearchLOT = (TYPE_SearchLOT) 0x43F760; // not sure if this is right
TYPE_UpdateLOT UpdateLOT = (TYPE_UpdateLOT) 0x43F7D0; // not sure if this is right
TYPE_InitialiseCreature InitialiseCreature = (TYPE_InitialiseCreature) 0x43F330;
TYPE_CreatureVault CreatureVault = (TYPE_CreatureVault) 0x4419A0; // 0x441940 <- this one seems to crash the game
TYPE_CreatureKill CreatureKill = (TYPE_CreatureKill) 0x4419A0; // not sure - might be CreatureVault
TYPE_AlertNearbyGuards AlertNearbyGuards = (TYPE_AlertNearbyGuards) 0x441D90;
TYPE_AIGuard AIGuard = (TYPE_AIGuard) 0x441E30;
TYPE_SameZone SameZone = (TYPE_SameZone) 0x442220; // ?
TYPE_AdjustStopperFlag AdjustStopperFlag = (TYPE_AdjustStopperFlag) 0x442400; // ?
TYPE_CreateEffect CreateEffect = (TYPE_CreateEffect) 0x453DD0;
TYPE_TargetVisible TargetVisible = (TYPE_TargetVisible) 0x40ADF0; // Check all of these V
TYPE_Targetable Targetable = (TYPE_Targetable) 0x40AEC0;
TYPE_GunShot GunShot = (TYPE_GunShot) 0x40AF90; // this one is weird - definitely check
TYPE_GunHit GunHit = (TYPE_GunHit) 0x40AFA0;
TYPE_GunMiss GunMiss = (TYPE_GunMiss) 0x40B060;
TYPE_ShotLara ShotLara = (TYPE_ShotLara) 0x40B110;
TYPE_phd_TranslateRel phd_TranslateRel = (TYPE_phd_TranslateRel) 0x48DFD0;
TYPE_phd_RotX phd_RotX = (TYPE_phd_RotX) 0x48E080;
TYPE_phd_RotZ phd_RotZ = (TYPE_phd_RotZ) 0x48E1E0;
TYPE_gar_RotYXZsuperpack gar_RotYXZsuperpack = (TYPE_gar_RotYXZsuperpack) 0x44FE00;
TYPE_ShiftItem ShiftItem = (TYPE_ShiftItem) 0x446700;
TYPE_LaraBaddieCollision LaraBaddieCollision = (TYPE_LaraBaddieCollision) 0x446940;
TYPE_CreatureCollision CreatureCollision = (TYPE_CreatureCollision) 0x446BE0;
TYPE_DetachSpark DetachSpark = (TYPE_DetachSpark) 0x433770;
TYPE_GetFreeSpark GetFreeSpark = (TYPE_GetFreeSpark) 0x433830;