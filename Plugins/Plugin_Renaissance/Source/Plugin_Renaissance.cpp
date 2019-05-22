// FOR_YOU:
// This is the main source of your plugin.
// It's in this source you'll type all your assembly or c++ code and all 
// the variables and memory zones you need.

// ************  Top/Header section ************
#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "bass.h"		// prototypes for extra sound library: bass.dll
	// Following header files will be updated for every new version of 
	// the tomb_NextGeneration.dll, so it's better you don't change them
	//  because they will be replaced for any new update.

#include "Tomb_NextGeneration.h" // mnemonic constants defined in tomb_NextGeneration.dll
#include "structures.h" // structure of tomb4 program and trng dll
#include "DefTomb4Funct.h" // defines of tomb4 procedure prototypes
#include "functions.h"  // assigments of real tomb4 address to each tomb4 procedures
#include "macros.h"  // definition of macros

	// FOR_YOU:
	// While the followings are the headers you can use 
	// to type your structures, constants and new tomb4 procedures you 
	// discovered. 
	// Following files are only yours and trng will not ever change them:
#include "macros_mine.h"  // here you define your own macros
#include "constants_mine.h" // here you define your mnemonic constants
#include "structures_mine.h" // here you type your structure definitions
#include "Tomb4Discoveries_mine.h" // here type tomb4 procedures you discovered

#include "trng.h" // list of trng functions imported from trng.cpp source. 

#pragma warning( error : 4706 )
#pragma warning(disable: 4996)

// ************  Early function declarations ************

 
// ************  Global Variables Section *************

StrTestPositionCmd SearchObject1TestPosition;
StrTestPositionCmd SearchObject2TestPosition;
StrTestPositionCmd SearchObject3TestPosition;
StrTestPositionCmd SearchObject4TestPosition;
bool StepRight;
int OldZoom;
int NoFlyby;

// FOR_YOU:
// here you type the variables or memory zones you wish use in different
// C++ procedures.
// If you use the assembly you'll have to type ALL your variables in this
// section.
// for example if you wish have a 32 bits signed variable to store big
// numbers you can type:
// TYPE_HERE:
// int MyNumber;
// and then you can use it in asm in this way:
//		mov  eax, [MyNumber]
// or
//      mov eax, dword ptr [MyNumber]
// same speech for wide memory zones.
// If you wish having a memory zone of 13000 bytes you can type:
//  BYTE MyZone[13000];
// and then you can use it in this way:
//     mov  al, MyNumber[ecx]  ; read the ECXth byte and copy it in AL
// or also:
//     mov al, [MyNumber+ecx] ; same result of above instruction

// Variables and memory zone to TYPE_HERE:

HINSTANCE MyDllInstance=NULL;  // the instance handle of your dll

extern char BufferLog[4096]; // temporary global buffer to host error and warning messages

// FOR_YOU: If you mean create code patch (changes in tomb4 code to call your code in the plugin dll,
// you MUST change the MyTomb4PatcherAddress value (here below) 
// You can discover a free tomb4 zone using TrngPatcher program, with the 
// menu command "Tools->Get Assignment of Free Memory range"
// Note: choose an address, in the given range, terminating with hex 
// digits: 0,4,8, or C
// because it's usefull that the address was a multiple by 4
// If you chose an address used from other plugins you'll get an error and
// the game will be aborted
// note: if you don't mean use code patches you can let 0x0 in following line
DWORD MyTomb4PatcherAddress = 0x0; // <- TYPE_HERE: the new address you chose
								
// this text will contain your plugin name (omitting .dll extension).
// it will be used to give a title to messagebox for error messages or warnings
char TexMyPluginName[80];  
// in this MyData structure you can store all global variables for your plugin
// you have to define them in structures_mine.h source inside structure "StrMyData" or for variable
// to save and restore in savegames, in "StrSavegameGlobalData" or "StrSavegameLocalData" structures
StrMyData MyData;


// ************  Utilities section  ****************



// ************  Patcher Functions section  ***************
// Note: please, don't change or remove the C++ procedure you find here,
// because they are necessary to do work the plugin with the trng dll
// Anyway in many of these functions you can add your code


// FOR_YOU: In this function you insert the callings of functions used to change tomb4 code
// You can get these functions, in the correct format, using Trng Core -> Asm Souce Editor -> Debugging menu
// program
// note: if there is a conflict the function will return "false"
// and the tomb4 program will abort with an error message
bool CreateMyCodePatches(void)
{
	// the call of the code patch to TYPE_HERE:
	// example: 
	// SET_PATCH(Path_RedirCollision)
	// to call the function Patch_RedirCollision() created with TrngPatcher program (command Assmembly->Create Dynamic Patch Generator)

	return true;
}

// ************  Assembly Procedures section  ******************

// FOR_YOU: In the SubPatchArray you'll type all procedure names of your code in the dll you
// wish were called from tomb4 code.
// type them in the order of ax value. So first asm proc in the list, will be called
// with ax=0, while the second in the list will be called with ax=1 ect.



void *SubPatchArray[] = {
	
// TYPE_HERE your asm procedure names to call from tomb4 code
	NULL
};


// ************  MainPatcher() asm procedure  *****************

// FOR_YOU: This is your main patcher procedure.
// All your patch in tomb4 code will call this procedure passing to it, in ax register,
// the number of subpatch to call

BEGIN_ASM_PROC(MainPatcher)
	and eax, 0ffffh
	mov eax, dword ptr [SubPatchArray+eax*4];
	jmp eax
END_ASM_PROC



// ************  CallBack functions section  *****************

// TYPE_HERE: your callback function

void cbInitProgram(int NumberLoadedPlugins, char *VetPluginNames[]) 
{

	// save number of plugins (enclosed yours and the tomb_nextgeneration.dll ) and their names
	// these data will be used to locate IDs of any loaded plugins using FindPluginID() function
	Trng.TotPlugins = NumberLoadedPlugins;
	Trng.pVetPluginNames = VetPluginNames;

	// clear all my global variables
	ClearMemory(&MyData, sizeof(StrMyData));
}

void InitAlchemyPuzzle()
{
	SendToLog("Init Alchemy Puzzle");
	for (int i=0; i<4; i++)
	{
		MyData.Save.Global.Puzzle[i].Lock = false;
		MyData.Save.Global.Puzzle[i].State = 0;
	}
}

void cbInitGame(void)
{
	// here you can initialize your global data for whole adventure
	// this procedure will be called only once, before loading title level
}

void cbInitLevel(int LevelNow, int LevelOld, DWORD FIL_Flags)
{
	// here you can initialize specific items of currnet level.
	// it will be called only once for level, when all items has been already initialized
	// and just a moment before entering in main game cycle.
	NoFlyby = *Trng.pGlobTomb4->pAdr->pTestFlybyInProgress; // For FOV Fix
}

// called everytime player save the game (but also when lara move from a level to another HUB saving). 
// in this procedure your plugin will save its own data in savegame
// SavingType inform about the kind of saving it is happening (SAVT_... values)
// pAdrZone is a byte pointer where this procedure will save the address from where begin data to save in savegame
// this function will return the size of data to save
// note: It's better you don't change anything of this code. It will save byself of data you stored in MyData.Save
// structure. If you wish adding other variables to save, just you add new fields in Structures of MyData.Save 
DWORD cbSaveMyData(BYTE **pAdrZone, int SavingType)
{
	DWORD SizeData;
	int i;
	static WORD *pVetExtras;
	int TotNWords;
	int TotNewActions;


	if (SavingType & SAVT_COMPLETED) {
		// this call is not to save data but only it is a confirm that the previous saving has been completed
		// now we can free the temporary memory used to save the data in previous call
		if (pVetExtras != NULL) {
			FreeMemory(pVetExtras);
			pVetExtras=NULL;
		}

		return 0;
	}


	TotNWords=0;
	pVetExtras = (WORD *) GetMemory(16);
	// save id of my plugin in first word

	pVetExtras[TotNWords++] = Trng.IdMyPlugin;

	if (SavingType & SAVT_LOCAL_DATA) {
		// save local data

		// save Local structure
		AddNGToken(NGTAG_LOCAL_DATA, NO_ARRAY, sizeof(StrSavegameLocalData), &MyData.Save.Local, 
						&pVetExtras, &TotNWords);


		// save all (currently enabled) progressive actions
		// before saving, compact progressive action array to remove intermediate free records
		TotNewActions=0;

		for (i=0;i<MyData.TotProgrActions;i++) {
			if (MyData.VetProgrActions[i].ActionType != AXN_FREE) {

				MyData.VetProgrActions[TotNewActions] = MyData.VetProgrActions[i];

				TotNewActions++;
			}
		}
		// update new valuese after recompatting
		MyData.LastProgrActionIndex =0;
		MyData.TotProgrActions= TotNewActions;

		// store all progressive action records
		AddNGToken(NGTAG_PROGRESSIVE_ACTIONS, MyData.TotProgrActions, sizeof(StrProgressiveAction), 
				&MyData.VetProgrActions[0], &pVetExtras, &TotNWords);

	}

	if (SavingType & SAVT_GLOBAL_DATA) {
		// save global data
		AddNGToken(NGTAG_GLOBAL_DATA, NO_ARRAY, sizeof(StrSavegameGlobalData), &MyData.Save.Global , 
						&pVetExtras, &TotNWords);
	}
	// write final sequence
	AddTokenFinalSequence(&pVetExtras, &TotNWords);

	// return to trng the infos about start of memory where there are our data and their size:
	*pAdrZone = (BYTE *) pVetExtras;
	SizeData = TotNWords * 2;

	return SizeData;
	

}
// called when a savegame will be loaded (but also when lara move from a level to another)
// pAdrZone will point to memory zone with data just loaded from savegame
// SizeData is the size of data pointed by pAdrZone
// note: it's better you don't change anything of this code. It's alread thought to reload all data you saved in MyData.Save 
// structure. There is no need of changes by you
void cbLoadMyData(BYTE *pAdrZone, DWORD SizeData)
{

	WORD *pVetExtras;
	StrParseNGField  ParseField;
	int Indice;
	int i;
	WORD TotActions;

	
	pVetExtras = (WORD*) pAdrZone;

	Indice=0;

	while (ParseNgField(pVetExtras ,Indice, &ParseField)==true) {
		
		// recover different ng token
		switch (ParseField.Type) {
		case NGTAG_LOCAL_DATA:
			// local data
			memcpy(&MyData.Save.Local, ParseField.pData, sizeof(StrSavegameLocalData));
			break;

		case NGTAG_GLOBAL_DATA:
			// global data
			memcpy(&MyData.Save.Global, ParseField.pData, sizeof(StrSavegameGlobalData));
			break;
			
		case NGTAG_PROGRESSIVE_ACTIONS:
			// progressive actions
			i= ParseField.StartDataIndex;
			// read tot actions value
			TotActions = pVetExtras[i++];
			// copy all tot records
			memcpy(&MyData.VetProgrActions[0], &pVetExtras[i], sizeof(StrProgressiveAction) * TotActions);
			MyData.TotProgrActions = TotActions;
			break;
		}
		Indice= ParseField.NextIndex; 
	}

}
// free memory used to store all data about your customize commands loaded in previous level
void FreeMemoryCustomize(void)
{
	int i;

	for (i=0;i<MyData.BaseCustomizeMine.TotCustomize;i++) {
		FreeMemory(MyData.BaseCustomizeMine.pVetCustomize[i].pVetArg);
	}

	if (MyData.BaseCustomizeMine.TotCustomize > 0) {
		FreeMemory(MyData.BaseCustomizeMine.pVetCustomize);
		MyData.BaseCustomizeMine.TotCustomize=0;
	}


	MyData.BaseCustomizeMine.pVetCustomize=NULL;
}

// free memory used to store all data about your parameters commands loaded in previous level
void FreeMemoryParameters(void)
{
	int i;

	for (i=0;i<MyData.BaseParametersMine.TotParameters;i++) {
		FreeMemory(MyData.BaseParametersMine.pVetParameters[i].pVetArg);
	}

	if (MyData.BaseParametersMine.TotParameters > 0) {
		FreeMemory(MyData.BaseParametersMine.pVetParameters);
		MyData.BaseParametersMine.TotParameters=0;
	}

	MyData.BaseParametersMine.pVetParameters=NULL;
}

// this procedure will be called at end of any level
// you can type here code to free resources allocated for level (that quits now)
void FreeLevelResources(void)
{

	// free memory used to store all data about your customize commands loaded in previous level
	FreeMemoryCustomize();
	// free memory used to store all data about your parameters commands loaded in previous level
	FreeMemoryParameters();
	MyData.BaseAssignSlotMine.TotAssign=0;

}
// it will be called before beginning the loading for a new level.
// you can type here code to initialise all variables used for level (to clear old values changed by previous level)
// and to free resources allocated in old level since now we'are going to another new level.

void cbInitLoadNewLevel(void)
{
	int i;

	StrProgressiveAction *pAction;

	// clear all LOCAL variables
	ClearMemory(&MyData.Save.Local,sizeof(StrSavegameLocalData));

	// clear progressive actions
	pAction= &MyData.VetProgrActions[0];

	for (i=0;i<MyData.TotProgrActions;i++) {
		if (pAction->ActionType != AXN_FREE) {
			// here you could analise to free resoruce allocated from this specific action

			pAction->ActionType = AXN_FREE;
		}
	}

	MyData.TotProgrActions=0;
	MyData.LastProgrActionIndex=0;

	// here you can initialise other variables of MyData different than Local and progressive actions
	// free resources allocate in previous level
	FreeLevelResources();

}



// this procedure will be called everytime a flipeffect of yours will be engaged
// you have to elaborate it and then return a TRET_.. value (most common is TRET_PERFORM_ONCE_AND_GO)
int cbFlipEffectMine(WORD FlipIndex, WORD Timer, WORD Extra, WORD ActivationMode)
{
	int RetValue;
	WORD TimerFull;

	RetValue = enumTRET.PERFORM_ONCE_AND_GO;
	// if the flip has no Extra paremeter you can handle a Timer value with values upto 32767
	// in this case you'll use the following TimerFull variable, where (with following code) we set a unique big number 
	// pasting togheter the timer+extra arguments:
	TimerFull = Timer | (Extra << 8);

	switch (FlipIndex) {
		// here type the "case Number:" for each flipeffect number. At end of the code you'll use the "break;" instruction to signal the code ending
		// Note: when you'll add your first "case Number:" then you can remove the following "case -1: and break;" instructions
	case FE_ALCHEMY_MOVE: 
		SendToLog("FE_ALCHEMY_MOVE");
		for (int i=0; i<4; i++)
		{
			SendToLog("Ring %d, Lock %b, State %d", i, MyData.Save.Global.Puzzle[i].Lock, MyData.Save.Global.Puzzle[i].State);
			if (MyData.Save.Global.Puzzle[i].Lock == false)
				MyData.Save.Global.Puzzle[i].State++;
			SendToLog("Ring %d, Lock %b, State %d", i, MyData.Save.Global.Puzzle[i].Lock, MyData.Save.Global.Puzzle[i].State);
			if (MyData.Save.Global.Puzzle[i].State > 3)
				MyData.Save.Global.Puzzle[i].State = 0;
			SendToLog("Ring %d, Lock %b, State %d", i, MyData.Save.Global.Puzzle[i].Lock, MyData.Save.Global.Puzzle[i].State);
		}
		break;
	case FE_ALCHEMY_RESET:
		InitAlchemyPuzzle();
		break;
	case FE_ALCHEMY_LOCK:
		SendToLog("FE_ALCHEMY_LOCK %d", Timer);
		if (MyData.Save.Global.Puzzle[Timer].Lock == false)
			MyData.Save.Global.Puzzle[Timer].Lock = true;
		else
			MyData.Save.Global.Puzzle[Timer].Lock = false;
		break;
	case FE_ALCHEMY_FORCE:
		MyData.Save.Global.Puzzle[Timer].State = Extra;
		break;
	default:
		SendToLog("WARNING: Flipeffect trigger number %d has not been handled in cbFlipEffectMine() function", FlipIndex);
		break;
	}

	// if there was the one-shot button enabled, return TRET_PERFORM_NEVER_MORE
	if (ActivationMode & enumSCANF.BUTTON_ONE_SHOT) RetValue= enumTRET.PERFORM_NEVER_MORE; 
	return RetValue;
}
// this procedure will be called everytime an action trigger of yours will be engaged 
// you have to elaborate it and then return a TRET_.. value (most common is TRET_PERFORM_ONCE_AND_GO)
int cbActionMine(WORD ActionIndex, int ItemIndex, WORD Extra, WORD ActivationMode)
{
	int RetValue;
	
	RetValue=TRET_PERFORM_ONCE_AND_GO;

	switch (ActionIndex) {
		// type here the code per your action trigger.
		// add "case Number:" and complete the code with "break;" instruction
	case -1:
		// note: remove this "case -1:" and its "break;" it has been added only to avoid warning messages about empty switch
		break;
	default:
		SendToLog("WARNING: action trigger number %d has not been handled in cbActionMine() function", ActionIndex);
		break;
	}
	
	// if there was the one-shot button enabled, return TRET_PERFORM_NEVER_MORE
	if (ActivationMode & enumSCANF.BUTTON_ONE_SHOT) RetValue= enumTRET.PERFORM_NEVER_MORE;
	return RetValue;


}

// this procedure will be called everytime a conditional trigger of yours will be engaged
// you have to elaborate it and then return a CTRET_.. value (most common is CTRET_ONLY_ONCE_ON_TRUE)
int cbConditionMine(WORD ConditionIndex, int ItemIndex, WORD Extra, WORD ActivationMode)
{
	int RetValue;
	
	RetValue=CTRET_ONLY_ONCE_ON_TRUE;

	switch (ConditionIndex){
		// type here the code for your condition trigger, inserting the code in the section
		// beginning with "case NumberOfAction:" and ending with row "break;"
	case -1:
		// note: remove this "case -1:" and its "break;" it has been added only to avoid warning messages about empty switch
		break;
	default:
		SendToLog("WARNING: condition trigger number %d has not been handled in cbConditionMine() function", ConditionIndex);
		break;


	}
	return RetValue;
	  
}

// this procedure vill be called for each Customize=CUST_... command read from script
// having one of yours CUST_ constant
// CustomizeValue will be the value of your CUST_ constant
// NumberOfItems will be the number of following Item (signed 16 bit values) following
// the CUST_ constant in the customize= script command
// pItemArray is the array with all NumberOfItems arguments of customize command
void cbCustomizeMine(WORD CustomizeValue, int NumberOfItems, short *pItemArray)
{
	// here you can replace this default management of anonymous customize commands
	// with your procedure where you can recognize each different CUST_ value and 
	// save its arguments in meaningful names fields, or elaboriting them immediatly
	// when it is possible (warning: in this moment nothing of level it has been yet loaded, excepting the script section)

	// ----- default management (optional)----
	// all customize values will be saved in MyData structure
	DWORD SizeMem;
	StrGenericCustomize *pMyCust;
	int TotCust;

	// ask memory to have another (new) record of StrGenericCustomize structure
	TotCust= MyData.BaseCustomizeMine.TotCustomize;
	TotCust++;
	SizeMem = TotCust * sizeof(StrGenericCustomize);
	MyData.BaseCustomizeMine.pVetCustomize = 
				(StrGenericCustomize *) ResizeMemory(MyData.BaseCustomizeMine.pVetCustomize, SizeMem);

	pMyCust = & MyData.BaseCustomizeMine.pVetCustomize[TotCust-1];
	
	// now require memory for all arguments (NumberOfItems) store in pItemArray

	pMyCust->pVetArg = (short *) GetMemory(2 * NumberOfItems);
	// copy data
	pMyCust->NArguments = NumberOfItems;
	memcpy(pMyCust->pVetArg, pItemArray, 2*NumberOfItems);
	pMyCust->CustValue = CustomizeValue;

	MyData.BaseCustomizeMine.TotCustomize= TotCust;
	// ---- end of default managemnt for generic customize -------------	
}
// callback called everytime in current level section of the script it has been found an AssignSlot command
// with one of your OBJ_ constants
void cbAssignSlotMine(WORD Slot, WORD ObjType)
{
	int i;

	i = MyData.BaseAssignSlotMine.TotAssign;

	if (i >= MAX_ASSIGN_SLOT_MINE) {
		SendToLog("ERROR: too many AssignSlot= commands for current plugin");
		return;
	}

	MyData.BaseAssignSlotMine.VetAssignSlot[i].MioSlot = Slot;
	MyData.BaseAssignSlotMine.VetAssignSlot[i].TipoSlot = ObjType;
	MyData.BaseAssignSlotMine.TotAssign++;

}
// this procedure vill be called for each Parameters=PARAM_... command read from script
// having one of yours PARAM_ constants
// ParameterValue will be the value of your PARAM_ constant
// NumberOfItems will be the number of following Item (signed 16 bit values) following
// the PARAM_ constant in the customize= script command
// pItemArray is the array with all NumberOfItems arguments of Parameter command
void cbParametersMine(WORD ParameterValue, int NumberOfItems, short *pItemArray)
{
	// here you can replace this default management of anonymous parameters commands
	// with your procedure where you can recognize each different Param_ value and 
	// save its arguments in meaningful names fields, or elaboriting them immediatly
	// when it is possible (warning: in this moment nothing of level it has been yet loaded, excepting the script section)

	// ----- default management (optional)----
	// all parameters values will be saved in MyData structure
	DWORD SizeMem;
	StrGenericParameters *pMyParam;
	int TotParam;

	// ask memory to have another (new) record of StrGenericparameters structure
	TotParam= MyData.BaseParametersMine.TotParameters;
	TotParam++;
	SizeMem = TotParam * sizeof(StrGenericParameters);
	MyData.BaseParametersMine.pVetParameters = 
		(StrGenericParameters *) ResizeMemory(MyData.BaseParametersMine.pVetParameters, SizeMem);

	pMyParam = & MyData.BaseParametersMine.pVetParameters[TotParam-1];
	
	// now require memory for all arguments (NumberOfItems) store in pItemArray

	pMyParam->pVetArg = (short *) GetMemory(2 * NumberOfItems);
	// copy data
	pMyParam->NArguments = NumberOfItems;
	memcpy(pMyParam->pVetArg, pItemArray, 2*NumberOfItems);

	MyData.BaseParametersMine.TotParameters= TotParam;
	// ---- end of default managemnt for generic parameters -------------


}

void GetItem(int Item, int Amount, bool ShowPickup)
{
	for (int j = 0; j < Amount; j++)
	{
		for (int i = 0; i <= 128; i++)
		{
			if (Trng.pGlobTomb4->VetInventory[i] == Item)
			{
				PerformFlipeffect(NULL, 48, i, ShowPickup);
				break;
			}
		}
	}
}

void StepDownFix()
{
	Get(enumGET.LARA, 0, 0);
	Get(enumGET.ANIMATION, GET.pLara->AnimationNow, 0);

	if (GET.pLara->AnimationNow == 40)
	{
		if ((GET.pLara->FrameNow - GET.pAnimation->FrameStart >= 30) && (GET.pLara->FrameNow - GET.pAnimation->FrameStart <= 59))
		{
			StepRight = true;
		} else {
			StepRight = false;
		}
	}

	if (GET.pLara->AnimationNow == 61 && StepRight == true)
	{
		ForceAnimationForLara(62, 16);
		StepRight = false;
	}
}

void BinocularsZoom()
{
	if (*Trng.pGlobTomb4->pAdr->pTestLaserSight || (*Trng.pGlobTomb4->pAdr->pFlagsLara2 & FL2_IS_USING_LASER_SIGHT_OR_BINOCULARS))
	{
		if (*Trng.pGlobTomb4->pAdr->pZoomFactor != OldZoom)
		{
			SoundEffect(313, NULL, 0);
			OldZoom = *Trng.pGlobTomb4->pAdr->pZoomFactor;
		}
	}
	else if (OldZoom != 128) // Set default value when not used
	{
		OldZoom = 128;
	}
}

void WideScreen()
{
	int w = Trng.pGlobTomb4->ScreenSizeX;
	int h = Trng.pGlobTomb4->ScreenSizeY;
	double ratio = (double) w / (double) h;
	Get(enumGET.INFO_LARA, 0, 0);

	//SendToLog("Flyby %d", *Trng.pGlobTomb4->pAdr->pTestFlybyInProgress);
	if ((*Trng.pGlobTomb4->pAdr->pTestFlybyInProgress != NoFlyby) && (*Trng.pGlobTomb4->pAdr->pLevelNow != 0))
		return;

	if (GET.LaraInfo.HoldedItem == HOLD_CROSSBOW)
	{
		Get(enumGET.LARA, 0, 0);
		if (GET.pLara->StateIdCurrent == AS_STOP)
		{
			Get(enumGET.INPUT, 0, 0);
			if (GET.Input.GameCommandsRead & enumCMD.LOOK)
			{
				return;
			}
		}
	}
	if (*Trng.pGlobTomb4->pAdr->pFlagsLara2 & enumFL2.IS_USING_LASER_SIGHT_OR_BINOCULARS)
		return;

	//if ((Trng.pGlobTomb4->ScreenSizeX % 16 == 0) && (Trng.pGlobTomb4->ScreenSizeY % 9 == 0))
		//AlterFOV(92 * ONE_DEGREE);	// 16:9
	
	// Joey's FOV formula
	AlterFOV((int)((ratio * 30) + 40) * ONE_DEGREE);
	if (*Trng.pGlobTomb4->pAdr->pLevelNow == 0)
		if (ratio > (4/3))
			AlterFOV((int)((ratio * 30) + 50) * ONE_DEGREE);
}

// this procedure will be called every game cycle (at begin of cycle)

void cbCycleBegin(void)
{
	BinocularsZoom();
}

// Not yet linked! To link it add to RequireMyCallBacks() function the row:
//  	GET_CALLBACK(CB_CYCLE_END, 0, 0, cbCycleEnd);
// this procedure will be called everygame cycle, at end.
// you have to return a RET_CYCLE_ value
int cbCycleEnd(void)
{
	StepDownFix();
	WideScreen();
	return RET_CYCLE_CONTINUE;	
}

// this function will be called for each your (common) progressive action to be peformed
void PerformMyProgrAction(StrProgressiveAction *pAction)
{


	switch (pAction->ActionType) {
// replace the "case -1:" with your first "case AXN_...:" progressive action to manage)		
	case -1:
		break;

	}

}
// callback called from trng for each frame in game cycle to perform your (common) progressive action
void cbProgrActionMine(void)
{
	int i;
	StrProgressiveAction *pAction;

	pAction = &MyData.VetProgrActions[0];
	for (i=0;i<MyData.TotProgrActions;i++) {
		if (pAction->ActionType != AXN_FREE) {
			PerformMyProgrAction(pAction);
		}
		pAction++;
	}


}
// inside this function you'll type call to functions to intialise your new objects or customize that olds.
// this callback will be called at start of loading new level and a bit after having started to load level data



void InitAnimating(short ItemIndex)
{
	Get(enumGET.ITEM, ItemIndex, 0);

	GET.pItem->StateIdCurrent = 0;
	GET.pItem->StateIdNext = 0;

	Get(enumGET.SLOT, GET.pItem->SlotID, 0);
	GET.pItem->AnimationNow = GET.pSlot->IndexFirstAnim;
	Get(enumGET.ANIMATION, GET.pItem->AnimationNow, 0);
	GET.pItem->FrameNow = GET.pAnimation->FrameStart;

	GET.pItem->FlagsMain = enumFITEM.NOT_YET_ENABLED;
}

void AnimatingCollision(short ItemIndex, StrItemTr4 *laraitem, StrCollisionLara *coll)
{
	StrItemTr4 *item;

	item = &items[ItemIndex];
	if (!TestBoundCollide(item, laraitem, coll->LaraSizeX))
		return;
	if (!TestCollision(item, laraitem))
		return;

	ItemPushLara(item, laraitem, coll, 0, 1);
}

void InitialiseSearchObject(int ItemIndex)
{
	StrItemTr4 *item;
	Get(enumGET.ITEM, ItemIndex, 0);
	Get(enumGET.SLOT, GET.pItem->SlotID, 0);
	item = GET.pItem;
	//item = &items[ItemIndex];

	//item->AnimationNow = GET.pSlot->IndexFirstAnim;
	Get(enumGET.ANIMATION, item->AnimationNow, 0);
	//item->AnimationNow = objects[item->SlotID].IndexFirstAnim;
	item->FrameNow = GET.pAnimation->FrameStart;
	//item->FrameNow = anims[item->AnimationNow].FrameStart;
	item->StateIdCurrent = 0;
	item->StateIdNext = 0;
	item->FlagsMain = CFITEM_COLLIDABLE;
	AddActiveItem(ItemIndex);
}

void CollisionSearchObject(short ItemIndex, StrItemTr4 *lara, StrCollisionLara *coll)
{
	StrItemTr4 *item;

	Get(enumGET.ITEM, ItemIndex, 0);
	item = GET.pItem;
	//item = &items[ItemIndex];

	if (lara->AnimationNow == SO1ANIM || lara->AnimationNow == SO2ANIM || lara->AnimationNow == SO3ANIM || lara->AnimationNow == SO4ANIM)
		return;

	if (GetMaxDistance(&item->CordX, &lara->CordX, false) > 1024)
		return;

	if (Trng.pGlobTomb4->TestAlignmentInProgress == true && *Trng.pGlobTomb4->pAdr->pObjectActive == ItemIndex)
	{
		if (item->SlotID == SEARCH_OBJECT1)
		{
			if (AlignLaraAtPosition(&SearchObject1TestPosition, ItemIndex) == false)
				return;
			ForceAnimationForLara(SO1ANIM, -1);
			return;
		}
		else if (item->SlotID == SEARCH_OBJECT2)
		{
			if (AlignLaraAtPosition(&SearchObject2TestPosition, ItemIndex) == false)
				return;
			ForceAnimationForLara(SO2ANIM, -1);
			return;
		}
		else if (item->SlotID == SEARCH_OBJECT3)
		{
			if (AlignLaraAtPosition(&SearchObject3TestPosition, ItemIndex) == false)
				return;
			ForceAnimationForLara(SO3ANIM, -1);
			return;
		}
		else if (item->SlotID == SEARCH_OBJECT4)
		{
			if (AlignLaraAtPosition(&SearchObject4TestPosition, ItemIndex) == false)
				return;
			//ForceAnimationForLara(SO4ANIM, -1); // makes it crash
			lara->AnimationNow = SO4ANIM;
			Get(enumGET.ANIMATION, lara->AnimationNow, 0);
			lara->FrameNow = GET.pAnimation->FrameStart;
			return;
		}
	}
	Get(enumGET.INPUT, 0, 0);
	if (GET.Input.GameCommandsRead & enumCMD.ACTION)
	{
		if (lara->StateIdCurrent == 2 && (lara->AnimationNow == 11 || lara->AnimationNow == 103))
		{
			if (*Trng.pGlobTomb4->pAdr->pFlagsLaraHands == FLH_ALMOST_FREE_HANDS)
			{
				if (item->SlotID == SEARCH_OBJECT1)
				{
					if (CheckPositionAlignment(&SearchObject1TestPosition, ItemIndex) == true)
					{
						if (AlignLaraAtPosition(&SearchObject1TestPosition, ItemIndex) == false)
							return;
						ForceAnimationForLara(SO1ANIM, -1);
						return;
					}
				}
				else if (item->SlotID == SEARCH_OBJECT2)
				{
					if (CheckPositionAlignment(&SearchObject2TestPosition, ItemIndex) == true)
					{
						if (AlignLaraAtPosition(&SearchObject2TestPosition, ItemIndex) == false)
							return;
						ForceAnimationForLara(SO2ANIM, -1);
						return;
					}
				}
				else if (item->SlotID == SEARCH_OBJECT3)
				{
					if (CheckPositionAlignment(&SearchObject3TestPosition, ItemIndex) == true)
					{
						if (AlignLaraAtPosition(&SearchObject3TestPosition, ItemIndex) == false)
							return;
						ForceAnimationForLara(SO3ANIM, -1);
						return;
					}
				}
				else if (item->SlotID == SEARCH_OBJECT4)
				{
					if (CheckPositionAlignment(&SearchObject4TestPosition, ItemIndex) == true)
					{
						if (AlignLaraAtPosition(&SearchObject4TestPosition, ItemIndex) == false)
							return;
						//ForceAnimationForLara(SO4ANIM, -1);
						lara->AnimationNow = SO4ANIM;
						Get(enumGET.ANIMATION, lara->AnimationNow, 0);
						lara->FrameNow = GET.pAnimation->FrameStart;
						return;
					}
				}
			}
		}
	}
	if (!TestBoundCollide(item, lara, coll->LaraSizeX))
		return;
	if (!TestCollision(item, lara))
		return;

	ItemPushLara(item, lara, coll, 0, 1);
}

void SearchObjectControl(short ItemIndex)
{
	StrItemTr4 *item;
	StrItemTr4 *lara;

	Get(enumGET.ITEM, ItemIndex, 0);
	item = GET.pItem;
	Get(enumGET.SLOT, item->SlotID, 0);
	Get(enumGET.LARA, 0, 0);
	lara = GET.pLara;

	// no need to animate if it's not the opening animation
	if (item->AnimationNow == GET.pSlot->IndexFirstAnim + 1)
		AnimateItem(item);

	if (lara->AnimationNow == SO1ANIM || lara->AnimationNow == SO2ANIM || lara->AnimationNow == SO3ANIM || lara->AnimationNow == SO4ANIM)
	{
		if (GetMaxDistance(&item->CordX, &lara->CordX, false) < 512)
		{
			//ForceAnimationForItem(item, GetRelativeAnimation(GET.pItem) + 1, 0);
			if (item->AnimationNow != GET.pSlot->IndexFirstAnim + 1)
			{
				item->AnimationNow = GET.pSlot->IndexFirstAnim + 1;
				Get(enumGET.ANIMATION, item->AnimationNow, 0);
				item->FrameNow = GET.pAnimation->FrameStart;
			}
		}
		if (item->OcbCode != 0)
		{
			StrMovePosition pos;
			pos.RelX = lara->CordX;
			pos.RelY = lara->CordY;
			pos.RelZ = lara->CordZ;

			if (item->SlotID == SEARCH_OBJECT1)
			{
				Get(enumGET.ANIMATION, item->AnimationNow, 0);
				if (item->FrameNow == GET.pAnimation->FrameStart + PICKUPSO1)
				{
					GetItem(item->OcbCode, 1, 1);
					item->OcbCode = 0;
					SoundEffect(62, &pos, 0);
				}
			}
			else if (item->SlotID == SEARCH_OBJECT2)
			{
				Get(enumGET.ANIMATION, item->AnimationNow, 0);
				if (item->FrameNow == GET.pAnimation->FrameStart + PICKUPSO2)
				{
					GetItem(item->OcbCode, 1, 1);
					item->OcbCode = 0;
					SoundEffect(62, &pos, 0);
				}
			}
			else if (item->SlotID == SEARCH_OBJECT3)
			{
				Get(enumGET.ANIMATION, item->AnimationNow, 0);
				if (item->FrameNow == GET.pAnimation->FrameStart + PICKUPSO3)
				{
					GetItem(item->OcbCode, 1, 1);
					item->OcbCode = 0;
					SoundEffect(62, &pos, 0);
				}
			}
			else if (item->SlotID == SEARCH_OBJECT4)
			{
				Get(enumGET.ANIMATION, item->AnimationNow, 0);
				if (item->FrameNow == GET.pAnimation->FrameStart + PICKUPSO4)
				{
					GetItem(item->OcbCode, 1, 1);
					item->OcbCode = 0;
					SoundEffect(62, &pos, 0);
				}
			}
		}
	}
	// Prevent opening animation from looping
	else if (!(item->AnimationNow == GET.pSlot->IndexFirstAnim))
	{
		item->AnimationNow = GET.pSlot->IndexFirstAnim;
	}
	return;
}

void StatueControl(short ItemIndex)
{
	StrItemTr4 *item;

	item = &items[ItemIndex];

	switch(item->Reserved_34)
	{
	case 1:
		item->MeshVisibilityMask = STATUE_SHIELD1;
	case 2:
		item->MeshVisibilityMask = STATUE_SHIELD2;
	case 3:
		item->MeshVisibilityMask = STATUE_SHIELD3;
	case 4:
		item->MeshVisibilityMask = STATUE_SHIELD4;
	default:
		item->MeshVisibilityMask = STATUE_EMPTY;
	}

	if ((item->Reserved_34 > 0) && (item->Reserved_34 != item->OcbCode))
	{
		// wrong puzzle object, hurt her
		lara_item->Health = 0;
	}
}

#define AlchemyPuzzleSlot() (item->SlotID - ALCHEMY_PUZZLE1)
#define GetRelativeAnim() (item->AnimationNow - objects[item->SlotID].IndexFirstAnim)
#define SetRelativeAnim() (objects[item->SlotID].IndexFirstAnim + state)

void AlchemyPuzzleControl(short ItemIndex)
{
	int state;
	StrItemTr4* item;
	item = &items[ItemIndex];

	state = MyData.Save.Global.Puzzle[AlchemyPuzzleSlot()].State;
	
	if (state != GetRelativeAnim())
		item->AnimationNow = SetRelativeAnim();

	SendToLog("AP1 %d, AP2 %d, AP3 %d, AP4 %d", MyData.Save.Global.Puzzle[0].State, MyData.Save.Global.Puzzle[1].State, MyData.Save.Global.Puzzle[2].State, MyData.Save.Global.Puzzle[3].State);
	SendToLog("Anim %d", GetRelativeAnim());

	AnimateItem(item);
}

void InitSearchObject1()
{
	Get(enumGET.SLOT, SEARCH_OBJECT1, 0);
	if (GET.pSlot->Flags && enumFSLOT.PRESENT == 0) {
		return;
	}
	GET.pSlot->pProcInitialise = InitialiseSearchObject;
	GET.pSlot->pProcCollision = CollisionSearchObject;
	GET.pSlot->pProcControl = SearchObjectControl;
	GET.pSlot->Flags = CFSLOT_SAVE_ANIM | CFSLOT_SAVE_FLAGS;
}

void InitSearchObject2()
{
	Get(enumGET.SLOT, SEARCH_OBJECT2, 0);
	if (GET.pSlot->Flags && enumFSLOT.PRESENT == 0) {
		return;
	}
	GET.pSlot->pProcInitialise = InitialiseSearchObject;
	GET.pSlot->pProcCollision = CollisionSearchObject;
	GET.pSlot->pProcControl = SearchObjectControl;
	GET.pSlot->Flags = CFSLOT_SAVE_ANIM | CFSLOT_SAVE_FLAGS;
}

void InitSearchObject3()
{
	Get(enumGET.SLOT, SEARCH_OBJECT3, 0);
	if (GET.pSlot->Flags && enumFSLOT.PRESENT == 0) {
		return;
	}
	GET.pSlot->pProcInitialise = InitialiseSearchObject;
	GET.pSlot->pProcCollision = CollisionSearchObject;
	GET.pSlot->pProcControl = SearchObjectControl;
	GET.pSlot->Flags = CFSLOT_SAVE_ANIM | CFSLOT_SAVE_FLAGS;
}

void InitSearchObject4()
{
	Get(enumGET.SLOT, SEARCH_OBJECT4, 0);
	if (GET.pSlot->Flags && enumFSLOT.PRESENT == 0)
		return;

	GET.pSlot->pProcInitialise = InitialiseSearchObject;
	GET.pSlot->pProcCollision = CollisionSearchObject;
	GET.pSlot->pProcControl = SearchObjectControl;
	GET.pSlot->Flags = CFSLOT_SAVE_ANIM | CFSLOT_SAVE_FLAGS;
}

void InitAlchemyPuzzleObject()
{
	Get(enumGET.SLOT, ALCHEMY_PUZZLE1, 0);
	if (GET.pSlot->Flags && enumFSLOT.PRESENT == 0)
		return;
	GET.pSlot->pProcControl = AlchemyPuzzleControl;
	GET.pSlot->pProcCollision = AnimatingCollision;
	GET.pSlot->pProcInitialise = InitAnimating;
	GET.pSlot->Flags = CFSLOT_SAVE_POSITION | CFSLOT_SAVE_FLAGS | CFSLOT_SAVE_ANIM;

	Get(enumGET.SLOT, ALCHEMY_PUZZLE2, 0);
	if (GET.pSlot->Flags && enumFSLOT.PRESENT == 0)
		return;
	GET.pSlot->pProcControl = AlchemyPuzzleControl;
	GET.pSlot->pProcCollision = AnimatingCollision;
	GET.pSlot->pProcInitialise = InitAnimating;
	GET.pSlot->Flags = CFSLOT_SAVE_POSITION | CFSLOT_SAVE_FLAGS | CFSLOT_SAVE_ANIM;

	Get(enumGET.SLOT, ALCHEMY_PUZZLE3, 0);
	if (GET.pSlot->Flags && enumFSLOT.PRESENT == 0)
		return;
	GET.pSlot->pProcControl = AlchemyPuzzleControl;
	GET.pSlot->pProcCollision = AnimatingCollision;
	GET.pSlot->pProcInitialise = InitAnimating;
	GET.pSlot->Flags = CFSLOT_SAVE_POSITION | CFSLOT_SAVE_FLAGS | CFSLOT_SAVE_ANIM;

	Get(enumGET.SLOT, ALCHEMY_PUZZLE4, 0);
	if (GET.pSlot->Flags && enumFSLOT.PRESENT == 0)
		return;
	GET.pSlot->pProcControl = AlchemyPuzzleControl;
	GET.pSlot->pProcCollision = AnimatingCollision;
	GET.pSlot->pProcInitialise = InitAnimating;
	GET.pSlot->Flags = CFSLOT_SAVE_POSITION | CFSLOT_SAVE_FLAGS | CFSLOT_SAVE_ANIM;
}

void cbInitObjects(void) 
{
	InitSearchObject1();
	InitSearchObject2();
	InitSearchObject3();
	InitSearchObject4();
	InitAlchemyPuzzleObject();
}


// FOR_YOU:
// in this function RequireMyCallBacks() you'll type
// a list of:
//		GET_CALLBACK(CB_..., ,)
// one for each callback you need
bool RequireMyCallBacks(void)
{
// ************  RequireMyCallBacks() function  *****************
	// protype of GET_CALLBACK:
	// GET_CALLBACK(CallBackCB, CBT_Flags, Index, MyProcToCall)
	// default callbacks required always 
	GET_CALLBACK(CB_INIT_PROGRAM, 0, 0, cbInitProgram)
	GET_CALLBACK(CB_INIT_GAME, 0, 0, cbInitGame)
	GET_CALLBACK(CB_INIT_LEVEL, 0,0, cbInitLevel)
	GET_CALLBACK(CB_SAVING_GAME, 0, 0, cbSaveMyData)
	GET_CALLBACK(CB_LOADING_GAME, 0, 0, cbLoadMyData)
	GET_CALLBACK(CB_INIT_LOAD_NEW_LEVEL, 0,0, cbInitLoadNewLevel);
	GET_CALLBACK(CB_FLIPEFFECT_MINE, 0, 0, cbFlipEffectMine);
	GET_CALLBACK(CB_ACTION_MINE, 0,0, cbActionMine);
	GET_CALLBACK(CB_CONDITION_MINE,0,0,cbConditionMine);
	GET_CALLBACK(CB_CUSTOMIZE_MINE, 0,0, cbCustomizeMine);
	GET_CALLBACK(CB_PARAMETER_MINE, 0, 0, cbParametersMine);
	GET_CALLBACK(CB_ASSIGN_SLOT_MINE, 0,0, cbAssignSlotMine);
	GET_CALLBACK(CB_CYCLE_BEGIN, 0, 0, cbCycleBegin);
	GET_CALLBACK(CB_PROGR_ACTION_MINE, 0, 0, cbProgrActionMine);
	GET_CALLBACK(CB_INIT_OBJECTS, 0, 0, cbInitObjects);
	GET_CALLBACK(CB_CYCLE_END, 0, 0, cbCycleEnd);

	return true;
}
// FOR_YOU:
// This function will be the first code to be executed of your plugin
// It happens when trng will load your plugin.
// In this moment no directX graphic is yet active, so you can show
// message boxes (TryMessageBox) to advise your players or level designer 
// about something
// Note: if you wish abort all (because there is an error or something
// is missing) you have to exit from this function returning: false
bool InitializeAll(void)
{
	StrTestPosition *pPos;
	OldZoom = 128;
// ************  InitializeAll() function  ****************
	//  perform all your patches
	CALL_CHECK(CreateMyCodePatches)

	// call the function that requires all callback you need
	CALL_CHECK(RequireMyCallBacks)

	// TYPE_HERE: code to allocate global resource to use in the whole game

	SearchObject1TestPosition.Slot = SEARCH_OBJECT1;
	pPos = &SearchObject1TestPosition.DatiPosition;
	pPos->Distance.MinX = 0 - 256;
	pPos->Distance.MaxX = 0 + 256;
	pPos->Distance.MinY = 0;
	pPos->Distance.MaxY = 0;
	pPos->Distance.MinZ = 0 - 512;
	pPos->Distance.MaxZ = 0 + 512;
	pPos->Orienting.OrientHMin = -10 * ONE_DEGREE;
	pPos->Orienting.OrientHMax = 10 * ONE_DEGREE;
	pPos->Orienting.OrientRMin = -30 * ONE_DEGREE;
	pPos->Orienting.OrientRMax = 30 * ONE_DEGREE;
	pPos->Orienting.OrientVMin = -10 * ONE_DEGREE;
	pPos->Orienting.OrientVMax = 10 * ONE_DEGREE;
	/*pPos->Distance.MinX = -512;
	pPos->Distance.MaxX = 512;
	pPos->Distance.MinY = -128;
	pPos->Distance.MaxY = 128;
	pPos->Distance.MinZ = -192;
	pPos->Distance.MaxZ = 192;

	pPos->Orienting.OrientHMin = -6000;
	pPos->Orienting.OrientHMax = 6000;
	pPos->Orienting.OrientVMin = -1000;
	pPos->Orienting.OrientVMax = 1000;
	pPos->Orienting.OrientRMin = -1000;
	pPos->Orienting.OrientRMax = 1000;*/

	// Search Object2
	SearchObject2TestPosition.Slot = SEARCH_OBJECT2;
	pPos = &SearchObject2TestPosition.DatiPosition;
	pPos->Distance.MinX = -256;
	pPos->Distance.MaxX = 256;
	pPos->Distance.MinY = -128;
	pPos->Distance.MaxY = 128;
	pPos->Distance.MinZ = 128-332;
	pPos->Distance.MaxZ = 160;

	pPos->Orienting.OrientHMin = -6000;
	pPos->Orienting.OrientHMax = 6000;
	pPos->Orienting.OrientVMin = -1000;
	pPos->Orienting.OrientVMax = 1000;
	pPos->Orienting.OrientRMin = -1000;
	pPos->Orienting.OrientRMax = 1000;

	// Search Object3
	SearchObject3TestPosition.Slot = SEARCH_OBJECT3;
	pPos = &SearchObject3TestPosition.DatiPosition;
	pPos->Distance.MinX = -512;
	pPos->Distance.MaxX = 512;
	pPos->Distance.MinY = -128;
	pPos->Distance.MaxY = 128;
	pPos->Distance.MinZ = -192;
	pPos->Distance.MaxZ = 192;

	pPos->Orienting.OrientHMin = -6000;
	pPos->Orienting.OrientHMax = 6000;
	pPos->Orienting.OrientVMin = -1000;
	pPos->Orienting.OrientVMax = 1000;
	pPos->Orienting.OrientRMin = -1000;
	pPos->Orienting.OrientRMax = 1000;

	// Search Object 4
	SearchObject4TestPosition.Slot = SEARCH_OBJECT4;
	pPos = &SearchObject4TestPosition.DatiPosition;
	pPos->Distance.MinX = 0 - 256;
	pPos->Distance.MaxX = 0 + 256;
	pPos->Distance.MinY = 0;
	pPos->Distance.MaxY = 0;
	pPos->Distance.MinZ = -313 - 256;
	pPos->Distance.MaxZ = -313 + 256;
	pPos->Orienting.OrientHMin = -10 * ONE_DEGREE;
	pPos->Orienting.OrientHMax = 10 * ONE_DEGREE;
	pPos->Orienting.OrientRMin = -30 * ONE_DEGREE;
	pPos->Orienting.OrientRMax = 30 * ONE_DEGREE;
	pPos->Orienting.OrientVMin = -10 * ONE_DEGREE;
	pPos->Orienting.OrientVMax = 10 * ONE_DEGREE;

	//InitAlchemyPuzzle();
	return true;
}

// FOR_YOU: Tyis function will be called when tomb4 game is to be closed.
// you should type in this function further codes to free the global
// resource you had allocated in the InitializeAll() function 
void ReleaseAll(void)
{
// ************  ReleaseAll() function  ******************
	FreeLevelResources();
}


BOOL APIENTRY DllMain( HINSTANCE hInstanceDll, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved)
{

    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			MyDllInstance = hInstanceDll;
			GetTrngInfo();
			// control per check control value about size and alignment with globtomb4 structure
			if (CheckControlGlobTomb4() == false) return FALSE;

			if  (InitializeAll()==false) {
				return FALSE;
			}
			return TRUE;
			

		case DLL_PROCESS_DETACH:
			ReleaseAll();
			break;
    }
    return TRUE;
}


