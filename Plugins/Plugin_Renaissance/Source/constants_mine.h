#include "Slots_mine.h"
#include "Lara.h"
#include "flipeffect_mine.h"

// TYPE_HERE: here you can type your mnemonic constants, using the #define directive
// like trng did it in the "Tomb_NextGeneration.h" file
// in this source you can also type your declaration of tomb raider function
// like it happens for "functions.h" source

// -------- START PRESET CONSTANTS ---------------------------------
// please don't remove the constants in this "PRESET CONSTANT" zone. 
// They will be used by some preset function in your plugin source

#define MAX_MYPROGR_ACTIONS 100
#define MAX_ASSIGN_SLOT_MINE 200

#define ENDLESS_DURATE 0xFFFF // to use as number of frames to set an infinite durate
#define NGTAG_END_SEQUENCE		   0   // signals the end of ng token sequence
#define NGTAG_PROGRESSIVE_ACTIONS  1
#define NGTAG_LOCAL_DATA           2
#define NGTAG_GLOBAL_DATA          3
#define AXN_FREE  0  // this record is to free an action record. You type this value in ActionType to free a action progress record
// --------- END PRESET CONSTANTS ---------------------------------
// type here the constant name for new progressive action you create
// use progressive number to have always different value for each AXN_ constant/action

/* General */
#define ONE_DEGREE 182
#define WALL_L  	 1024
#define WALL_SHIFT 10
#define STEP_L     (WALL_L/4)
#define PITCH_SHIFT 4
#define NO_HEIGHT (-0x7f00)
#define SFX_ALWAYS	2

#define W2V_SHIFT	12			// Shift scale of View.Frame to World.Frame
#define W2V_SCALE 	(1<<W2V_SHIFT)	//  Scale of View Frame to World Frame

#define SQUARE(A) ((A)*(A))
#define ABS(x)	  ((x)<0 ? (-(x)):(x))

#define phd_PopMatrix() *Trng.pGlobTomb4->pAdr->pZonaRecord30 -= 48

#define objects		Trng.pGlobTomb4->pAdr->pVetSlot
#define items		Trng.pGlobTomb4->pAdr->pVetItems
#define anims		Trng.pGlobTomb4->pAdr->pVetAnimations
#define lara_item	Trng.pGlobTomb4->pAdr->pLara
#define input		Trng.pGlobTomb4->pAdr->pInputCommandFlags

/* Enemy stuff */
typedef enum target_type {NO_TARGET, PRIME_TARGET, SECONDARY_TARGET} TARGET_TYPE;
typedef enum mood_type {BORED_MOOD, ATTACK_MOOD, ESCAPE_MOOD, STALK_MOOD} MOOD_TYPE;

#define TIMID   0
#define VIOLENT 1

#define NO_ITEM -1
#define FRONT_ARC 0x4000
#define MAX_HEAD_CHANGE (ONE_DEGREE*5)
#define MAX_JOINT_CHANGE (ONE_DEGREE*5)
#define MAX_TILT			(ONE_DEGREE*3)
#define MAX_JOINTS 4

#define ROT_X 4
#define ROT_Y 8
#define ROT_Z 16

#define UNIT_SHADOW 256
#define DONT_TARGET	(-16384)


/* Box stuff */
#define MAX_EXPANSION 5

#define NUM_SLOTS	5
#define NUM_NONLOT_SLOTS	12
#define NO_BOX 	0x7ff
#define BOX_NUMBER  0x7ff
#define BOX_END_BIT	0x8000

#define EXPAND_LEFT   0x1
#define EXPAND_RIGHT  0x2
#define EXPAND_TOP    0x4
#define EXPAND_BOTTOM 0x8

#define BLOCKABLE     0x8000
#define BLOCKED       0x4000
#define OVERLAP_INDEX 0x3fff

#define SEARCH_NUMBER  0x7fff
#define BLOCKED_SEARCH 0x8000

#define NO_FLYING 0
#define FLY_ZONE 0x2000


/* Search Object stuff */
#define PICKUPSO1 180
#define PICKUPSO2 100
#define PICKUPSO3 153
#define PICKUPSO4  83
#define SO1ANIM   446
#define SO2ANIM   447
#define SO3ANIM   448
#define SO4ANIM   449

/* Statue Puzzle */
#define STATUE_EMPTY 0xFFFFFFC3
#define STATUE_SHIELD1 0xFFFFFFC7
#define STATUE_SHIELD2 0xFFFFFFCB
#define STATUE_SHIELD3 0xFFFFFFD3
#define STATUE_SHIELD4 0xFFFFFFE3
// 0xFFFFFFC3 No Shields
	// 0xFFFFFFC7 Shield 1
	// 0xFFFFFFCB Shield 2
	// 0xFFFFFFD3 Shield 3
	// 0xFFFFFFE3 Shield 4

/* Corrected flags */
#define CFITEM_ACTIVE 0x0001
#define CFITEM_SACTIVE 0x0002
#define CFITEM_DEACTIVATED 0x0004
#define CFITEM_INVISIBLE 0x006
#define CFITEM_GRAVITY_STATUS 0x0008
#define CFITEM_HIT_STATUS 0x0010
#define CFITEM_COLLIDABLE 0x0020
#define CFITEM_LOOKED_AT 0x0040
#define CFITEM_DYNAMIC_LIGHT 0x0080 // used in cutscenes
#define CFITEM_POISONED 0x0100
// AI bits
#define CFITEM_REALLY_ACTIVE 0x4000
#define CFITEM_IN_DRAW_ROOM 0x8000 // not sure what this does

#define CFSLOT_LOADED 0x0001
#define CFSLOT_INTELLIGENT 0x0002
#define CFSLOT_NON_LOT 0x0004
#define CFSLOT_SAVE_POSITION 0x0008
#define CFSLOT_SAVE_HITPOINTS 0x0010
#define CFSLOT_SAVE_FLAGS 0x0020
#define CFSLOT_SAVE_ANIM 0x0040
#define CFSLOT_SEMI_TRANSPARENT 0x0080
#define CFSLOT_WATER_CREATURE 0x0100
#define CFSLOT_USING_DRAWANIMATING_ITEM 0x0200
#define CFSLOT_HIT_EFFECT1 0x0400
#define CFSLOT_HIT_EFFECT2 0x0800
#define CFSLOT_UNDEAD 0x1000
#define CFSLOT_SAVE_MESH 0x2000

#define CFCOLL_SLOPES_ARE_WALLS1 0x0001
#define CFCOLL_SLOPES_ARE_WALLS2 0x0002
#define CFCOLL_LAVA_IS_PIT 0x0004
#define CFCOLL_ENABLE_BADDIE_PUSH 0x0008
#define CFCOLL_ENABLE_SPAZ 0x0010
#define CFCOLL_HIT_CEILING 0x020


// MPS_ flags
// you should type here your MPS_ flags for plugin command.
// then you'll test the presence of these flags checking the Trng.MainPluginFlags  value using "&" operator
// please: do not use the value 0x40000000 (MPS_DISABLE) because it has been already set by trng engine
