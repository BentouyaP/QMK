#ifndef REV1_H
#define REV1_H

#include "shuriken.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"


#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

//void promicro_bootloader_jmp(bool program);

#ifndef FLIP_HALF
// Standard Keymap
// (TRRS jack on the left half is to the right, TRRS jack on the right half is to the left)
#define LAYOUT_shuriken( \
	L00, L01, L02, L03, L04, L05, L06, R00, R01, R02, R03, R04, R05, R06,\
	L10, L11, L12, L13, L14, L15, L16, R10, R11, R12, R13, R14, R15, R16,\
	L20, L21, L22, L23, L24, L25, L26, R20, R21, R22, R23, R24, R25, R26,\
	L30, L31, L32, L33, L34, L35, L36, R30, R31, R32, R33, R34, R35, R36,\
	L40, L41, L42, L43, L44, L45, L46, R40, R41, R42, R43, R44, R45, R46,\
	L50, L51, L52, L53, L54, L55, L56, R50, R51, R52, R53, R54, R55, R56 \
	) \
	{ \
		{ L00,   L01,   L02,   L03,   L04,   L05,   L06 }, \
		{ L10,   L11,   L12,   L13,   L14,   L15,   L16 }, \
		{ L20,   L21,   L22,   L23,   L24,   L25,   L26 }, \
		{ L30,   L31,   L32,   L33,   L34,   L35,   L36 }, \
		{ L40,   L41,   L42,   L43,   L44,   L45,   L46 }, \
		{ L50,   L51,   L52,   L53,   L54,   L55,   L56 }, \
		{ R06,   R05,   R04,   R03,   R02,   R01,   R00 }, \
		{ R16,   R15,   R14,   R13,   R12,   R11,   R10 }, \
		{ R26,   R25,   R24,   R23,   R22,   R21,   R20 }, \
		{ R36,   R35,   R34,   R33,   R32,   R31,   R30 }, \
		{ R46,   R45,   R44,   R43,   R42,   R41,   R40 }, \
		{ R56,   R55,   R54,   R53,   R52,   R51,   R50 }  \
	}
#else
// Keymap with Left side flipped
// (TRRS jack on both halves are to the right)
#define LAYOUT_shuriken( \
	L00, L01, L02, L03, L04, L05, L06, R00, R01, R02, R03, R04, R05, R06,\
	L10, L11, L12, L13, L14, L15, L16, R10, R11, R12, R13, R14, R15, R16,\
	L20, L21, L22, L23, L24, L25, L26, R20, R21, R22, R23, R24, R25, R26,\
	L30, L31, L32, L33, L34, L35, L36, R30, R31, R32, R33, R34, R35, R36,\
	L40, L41, L42, L43, L44, L45, L46, R40, R41, R42, R43, R44, R45, R46,\
	L50, L51, L52, L53, L54, L55, L56, R50, R51, R52, R53, R54, R55, R56 \
	) \
	{ \
		{ L06,   L05,   L04,   L03,   L02,   L01,   L00 }, \
		{ L16,   L15,   L14,   L13,   L12,   L11,   L10 }, \
		{ L26,   L25,   L24,   L23,   L22,   L21,   L20 }, \
		{ L36,   L35,   L34,   L33,   L32,   L31,   L30 }, \
		{ L46,   L45,   L44,   L43,   L42,   L41,   L40 }, \
		{ L56,   L55,   L54,   L53,   L52,   L51,   L50 }, \
		{ L50,   L51,   L52,   L53,   L54,   L55,   L56 }, \
		{ R06,   R05,   R04,   R03,   R02,   R01,   R00 }, \
		{ R16,   R15,   R14,   R13,   R12,   R11,   R10 }, \
		{ R26,   R25,   R24,   R23,   R22,   R21,   R20 }, \
		{ R36,   R35,   R34,   R33,   R32,   R31,   R30 }, \
		{ R46,   R45,   R44,   R43,   R42,   R41,   R40 }, \
		{ R56,   R55,   R54,   R53,   R52,   R51,   R50 }  \
	}
#endif


#define LAYOUT LAYOUT_shuriken

#endif
