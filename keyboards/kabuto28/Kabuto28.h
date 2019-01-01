#ifndef Kabuto28_H
#define Kabuto28_H

#include "quantum.h"

#define KEYMAP( \
	K00, K01, K02, K03, K04,      \
	K10, K11, K12, K13, K14, K15, \
	K20, K21, K22, K23, K24, K25, \
	K30, K31, K32, K33, K34, K35, \
	K40, K41,      K43, K44, K45  \
) { \
	{ K00,   K01,   K02,   K03,   K04,   KC_NO }, \
	{ K10,   K11,   K12,   K13,   K14,   K15 }, \
	{ K20,   K21,   K22,   K23,   K24,   K25 }, \
	{ K30,   K31,   K32,   K33,   K34,   K35 }, \
	{ K40,   K41,   KC_NO, K43,   K44,   K45 }  \
}

#endif