/* ScummVM - Scumm Interpreter
 * Copyright (C) 2003 The ScummVM project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header$
 *
 */

#ifndef QUEENDEFS_H
#define QUEENDEFS_H

namespace Queen {

// Maybe should be an inlined function somwhere else, feel free to change
#define InRange(x,l,h)     ((x)<=(h) && (x)>=(l)) /* X in [l..h] */

#define SAVEGAME_SIZE	24622

enum {
	COMPRESSION_NONE  = 0,
	COMPRESSION_MP3   = 1,	
	COMPRESSION_OGG   = 2
};

enum {
	GAME_SCREEN_WIDTH  = 320,
	GAME_SCREEN_HEIGHT = 200,
	ROOM_ZONE_HEIGHT   = 150,
	PANEL_ZONE_HEIGHT  =  50
};


enum {
	FRAMES_JOE      = 36,
	FRAMES_JOE_XTRA = 2,
	FRAMES_JOURNAL  = 40
};


enum Direction {
	DIR_LEFT  = 1,
	DIR_RIGHT = 2,
	DIR_FRONT = 3,
	DIR_BACK  = 4
};


enum {
	INK_BG_PANEL      = 226,
	INK_JOURNAL       = 248,
	INK_MAP7          = 243,
	INK_CMD_SELECT    = 255,
	INK_CMD_NORMAL    = 225,
	INK_CMD_LOCK      = 234,
	INK_TALK_NORMAL   = 7,
	INK_JOE           = 14,
	INK_OUTLINED_TEXT = 16
};


enum {
	ZONE_ROOM  = 0,
	ZONE_PANEL = 1
};

enum {
	ITEM_NONE                     =  0,
	ITEM_BAT                      =  1,
	ITEM_JOURNAL,
	ITEM_JOURNAL_DEMO             =  7,
	ITEM_KNIFE                    =  3,
	ITEM_COCONUT_HALVES,
	ITEM_BEEF_JERKY,
	ITEM_PROPELLER,
	ITEM_BANANA,
	ITEM_VINE,
	ITEM_SLOTH_HAIR,
	ITEM_COMIC_BOOK,
	ITEM_FLOWER,
	ITEM_BEETLE,
	ITEM_ORCHID,
	ITEM_DICTIONARY,
	ITEM_DEATH_MASH,
	ITEM_PERFUME,
	ITEM_TYRANNO_HORN,
	ITEM_LOTION,
	ITEM_RECORD,
	ITEM_VACUUM_CLEANER,
	ITEM_NET,
	ITEM_ALCOHOL,
	ITEM_ROCKET_PACK,
	ITEM_SOME_MONEY,
	ITEM_CHEESE_BITZ,
	ITEM_DOG_FOOD,
	ITEM_CAN_OPENER,
	ITEM_LETTER,
	ITEM_SQUEAKY_TOY,
	ITEM_KEY,
	ITEM_BOOK,
	ITEM_PIECE_OF_PAPER,
	ITEM_ROCKET_PLAN,
	ITEM_PADLOCK_KEY,
	ITEM_RIB_CAGE,
	ITEM_SKULL,
	ITEM_LEG_BONE,
	ITEM_BAT2,
	ITEM_MAKESHIFT_TOCH,
	ITEM_LIGHTER,
	ITEM_GREEN_JEWEL,
	ITEM_PICK,
	ITEM_STONE_KEY,
	ITEM_BLUE_JEWEL,
	ITEM_CRYSTAL_SKULL,
	ITEM_TREE_SAP,
	ITEM_DINO_RAY_GUN,
	ITEM_BRANCHES,
	ITEM_WIG,
	ITEM_TOWEL,
	ITEM_OTHER_SHEET,
	ITEM_SHEET,
	ITEM_SHEET_ROPE,
	ITEM_CROWBAR,
	ITEM_COMEDY_BREASTS,
	ITEM_DRESS,
	ITEM_KEY2,
	ITEM_CLOTHES,
	ITEM_HAY,
	ITEM_OIL,
	ITEM_CHICKEN,
	ITEM_LIT_TORCH,
	ITEM_OPENED_DOG_FOOD,
	ITEM_SOME_MONEY2,
	ITEM_SOME_MORE_MONEY,
	ITEM_PEELED_BANANA,
	ITEM_STONE_DISC,
	ITEM_GNARLED_VINE,
	ITEM_FLINT,
	ITEM_LIGHTER2,
	ITEM_REST_OF_BEEF_JERKY,
	ITEM_LOTS_OF_MONEY,
	ITEM_HEAPS_OF_MONEY,
	ITEM_OPEN_BOOK,
	ITEM_REST_OF_THE_CHEESE_BITZ,
	ITEM_SCISSORS,
	ITEM_PENCIL,
	ITEM_SUPER_WEENIE_SERUM,
	ITEM_MUMMY_WRAPPINGS,
	ITEM_COCONUT,
	ITEM_ID_CARD,
	ITEM_BIT_OF_STONE,
	ITEM_CHUNK_OF_ROCK,
	ITEM_BIG_STICK,
	ITEM_STICKY_BIT_OF_STONE,
	ITEM_STICKY_CHUNK_OF_ROCK,
	ITEM_DEATH_MASK2,
	ITEM_CHEFS_SURPRISE,
	ITEM_STICKY_BAT,
	ITEM_REST_OF_WRAPPINGS,
	ITEM_BANANA2,
	ITEM_MUG,
	ITEM_FILE,
	ITEM_POCKET_ROCKET_BLUEPRINTS,
	ITEM_HAND_PUPPET,
	ITEM_ARM_BONE,
	ITEM_CROWN,
	ITEM_COMIC_COUPON,
	ITEM_TORN_PAGE
};

enum {
	ROOM_JUNGLE_INSIDE_PLANE  =  1,
	ROOM_JUNGLE_OUTSIDE_PLANE =  2,
	ROOM_JUNGLE_PINNACLE      =  7,
	ROOM_JUNGLE_SLOTH         =  8,
	ROOM_JUNGLE_BUD_SKIP      =  9,
	ROOM_JUNGLE_BEETLE        =  11,
	ROOM_JUNGLE_MISSIONARY    =  13,
	
	ROOM_AMAZON_ENTRANCE      =  16,
	ROOM_AMAZON_HIDEOUT       =  17,
	ROOM_AMAZON_THRONE        =  18,
	ROOM_AMAZON_JAIL          =  19,
	
	ROOM_VILLAGE              =  20,
	ROOM_TRADER_BOBS          =  21,
	
	ROOM_FLODA_OUTSIDE        =  22,
	ROOM_FLODA_KITCHEN        =  26,
	ROOM_FLODA_LOCKERROOM     =  27,
	ROOM_FLODA_KLUNK          =  30,
	ROOM_FLODA_HENRY          =  32,
	ROOM_FLODA_OFFICE         =  35,
	ROOM_FLODA_JAIL           =  41,
	ROOM_FLODA_FRONTDESK      = 103,

	ROOM_TEMPLE_OUTSIDE       =  43,
	ROOM_TEMPLE_MUMMIES       =  46,
	ROOM_TEMPLE_ZOMBIES       =  50,
	ROOM_TEMPLE_SNAKE         =  53,
	ROOM_TEMPLE_LIZARD_LASER  =  55,
	ROOM_TEMPLE_MAZE          =  58,
	ROOM_TEMPLE_MAZE2         =  59,
	ROOM_TEMPLE_MAZE3         =  60,
	ROOM_TEMPLE_MAZE4         =  61,
	
	ROOM_HOTEL_UPSTAIRS       =  70,
	ROOM_HOTEL_DOWNSTAIRS     =  71,
	ROOM_HOTEL_LOLA           =  72,
	ROOM_HOTEL_LOBBY          =  73,

	//special
	SPARKY_OUTSIDE_HOTEL      =  77,
	DEATH_MASK                =  79,
	IBI_LOGO                  =  82,
	COMIC_1                   =  87,
	COMIC_2                   =  88,
	COMIC_3                   =  89,
	UNUSED_INTRO_1            =  91,
	UNUSED_INTRO_2            =  92,
	UNUSED_INTRO_3            =  93,
	UNUSED_INTRO_4            =  94,
	FOTAQ_LOGO                =  95,
	AZURA_1                   = 106,
	WARNER_LOGO               = 126
};


//! GameState vars
enum {
	VAR_DRESSING_MODE  =  19, // 0=normal clothes, 1=underwear, 2=dress
	VAR_ROOM73_CUTAWAY =  93,
	VAR_INTRO_PLAYED   = 117,
	VAR_CAN_CHANGE_CLOTES = 202
};


enum Language {
	ENGLISH  = 'E',
	FRENCH   = 'F',
	GERMAN   = 'G',
	HEBREW   = 'H',
	ITALIAN  = 'I',
	SPANISH  = 'S'
};


enum StateTalk {
	STATE_TALK_TALK,
	STATE_TALK_MUTE
};


enum StateGrab {
	STATE_GRAB_NONE,
	STATE_GRAB_DOWN,
	STATE_GRAB_UP,
	STATE_GRAB_MID
};


enum StateOn {
	STATE_ON_ON,
	STATE_ON_OFF
};


enum StateUse {
	STATE_USE,
	STATE_USE_ON
};


} // End of namespace Queen

#endif
