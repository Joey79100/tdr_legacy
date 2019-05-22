// let below pragma directive at top of this source
#pragma pack(1)

// TYPE_HERE: here you can type your structure definitions like it has been done
// in the "structures.h" file for trng dll

// --------------- PRESET STRUCTURE ZONE -----------------------------
// Please, don't remove structures and fields you find in this "PRESET ZONE". They will be used by some
// preset functions of your plugin sources
// However, you can add new fields and structures in following structures, of course

typedef struct AlchemyPuzzle {
	int State;
	bool Lock;
}AlchemyPuzzleFields;

typedef struct StrSavegameGlobalData {
	// FOR_YOU:
	// define here your variables that you wish were saved (and then restored) to/from savegame in GLOBAL section 
	//           (only one for all levels)
	// note: the size of this structure should be always even (if you add BYTE variable, remember to compensate that 
	//       with another BYTE vairable or placefolder)
	AlchemyPuzzle Puzzle[4];
	
}SavegameGlobalDataFields;


typedef struct StrSavegameLocalData {
	// FOR_YOU:
	// define here your variables that you wish were saved (and then restored) to/from savegame in LOCAL section (one for each different level)
	// note: the size of this structure should be always even (if you add BYTE variable, compensate it with another BYTE vairable or placefolder)
}SavegameLocalDataFields;


typedef struct StrSavegameData {
	StrSavegameGlobalData Global;
	StrSavegameLocalData  Local;
}SavegameDataFields;


typedef struct StrBaseAssignSlotMine {
	int TotAssign;
	StrRecordAssSlot VetAssignSlot[MAX_ASSIGN_SLOT_MINE];
}BaseAssignSlotMineFields;

typedef struct StrMyData {
	StrSavegameData Save;  // variable that it will be saved and restored to/from savegame
	// FOR_YOU:
	// define here all your global variables, i.e. those variables that will be seen from all procedures and keep 
	// their value between all cycles of the game.
	// after you defined a variabile like:
	// int  Alfa;
	// then you'll be able to access to them using syntax like:
	// MyData.Alfa = 3;
	// if (MyData.Alfa == 5) .
	int TotProgrActions;
	int LastProgrActionIndex; // used in case of overloading

	StrProgressiveAction VetProgrActions[MAX_MYPROGR_ACTIONS];
	StrBaseGenericCustomize BaseCustomizeMine;  // stored all your customize script commands for current level
	StrBaseGenericParameters BaseParametersMine; // store of all your parameters= script commands of current level
	StrBaseAssignSlotMine BaseAssignSlotMine; // stored all AssignSlot= command script commands of current level
}MyDataFields;
// ----------------- END PRESET STRUCTURE ZONE ---------------------------------------

typedef struct	{
	int x;
	int y;
	int z;
}PHD_VECTOR;

typedef struct	{
	signed int 	x_pos;
	signed int 	y_pos;
	signed int	z_pos;
	short	x_rot;
	short	y_rot;
	short	z_rot;
}PHD_3DPOS;

typedef struct {
	int Speed;
	int MidPos;
	int FrontPos;
	int TurnX;
	int TurnZ;
	short TurnLen;
	short TurnRot;
	short YVel;
	short Gradient;
	char Flags;
	char StopDelay;
}CARTINFO;

typedef struct AI_info {
	short zone_number, enemy_zone;
	int distance, ahead, bite;
	short angle, x_angle, enemy_facing;
} AI_INFO;

typedef struct bite_info {				// Offset into given Mesh
	int			x;					// where Baddie kicks off Bite Effect
	int			y;
	int			z;
	int			mesh_num;
} BITE_INFO;

typedef struct box_node {
	short exit_box;
	unsigned short search_number;
	short next_expansion;
	short box_number;     // for storing zone box lists
} BOX_NODE;

enum zone_type
{
	SKELLY_ZONE,
	BASIC_ZONE,
	CROC_ZONE,
	HUMAN_ZONE,
	FLYER_ZONE
};

typedef struct lot_info {
	BOX_NODE *node;
	short head, tail;
	unsigned short search_number, block_mask;
	short step, drop, zone_count;
	short target_box, required_box;
	short fly;
	unsigned short can_jump : 1;
	unsigned short can_monkey : 1;
	unsigned short is_amphibious : 1;
	unsigned short is_jumping : 1;
	unsigned short is_monkeying : 1;
	StrMovePosition target;
	zone_type zone;
} LOT_INFO;

typedef struct creature_info {
	signed short 	joint_rotation[MAX_JOINTS]; // up to 4 extra rotations in addition to normal animation
	signed short 	maximum_turn;
	signed short 	flags; // spare bits that can be used for any purpose by different types of creature
	unsigned short	alerted:1;			//Time to bit pack - Lots of miscellaneous AI & behaviour stuff;
	unsigned short	head_left:1;		//Eventually these might replace 'flags'
	unsigned short	head_right:1;
	unsigned short	reached_goal:1;
	unsigned short	hurt_by_lara:1;
	unsigned short	patrol2:1;
	unsigned short	jump_ahead : 1;
	unsigned short	monkey_ahead : 1;
	MOOD_TYPE mood;
	StrItemTr4 *enemy;
	StrItemTr4 ai_target;
	short pad;
	short	item_num;
	StrMovePosition target; // not sure
	LOT_INFO LOT;
} CREATURE_INFO;

// let below pragma directive at bottom of this source
#pragma pack(2)