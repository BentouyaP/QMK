
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _DVORAK 1
#define _COLEMAK 2
#define _LOWER 3
#define _RAISE 4
#define _FUNCTION 15
#define _ADJUST 16

enum atreus62_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  COLEMAK,
  FN,
  LOWER,
  RAISE
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom
#define SFT_ENT SFT_T(KC_ENT)  // Tap for Enter, hold for Shift
#define FNC MO(_FUNCTION)  // Momentarily turn on FUNCTION layer
#define KANA KC_INT2  // JIS Katakana/Hiragana
#define E_J KC_LANG5  // JIS Zenkaku/Hankaku
//UnUse
//#define CTL_ESC CTL_T(KC_ESC)  // Tap for Escape, hold for Control
//#define CTL_ENT CTL_T(KC_ENT)  // Tap for Enter, hold for Control
//#define SFT_BSP SFT_T(KC_BSPC) // Tap for Backspace, hold for Shift
//#define SFT_SPC SFT_T(KC_SPC)  // Tap for Space, hold for Shift
//#define SFT_DEL SFT_T(KC_DEL)  // Tap for Delete, hold for Shift
//#define HPR_TAB ALL_T(KC_TAB)  // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-------------------------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |XXXXXX|XXXXXX|   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |XXXXXX|XXXXXX|   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |XXXXXX|XXXXXX|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |XXXXXX|XXXXXX|   N  |   M  |   ,  |   .  |   /  |Sf/Ent|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Func | Alt  | Left |Right |Lower | Space| Del  | Enter| Bksp |Raise | Down |  Up  | GUI  | Ctrl |
 * `-------------------------------------------------------------------------------------------------'
 */
  [_QWERTY] = LAYOUT ( /* qwerty */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
    FNC,     KC_LALT, KC_LEFT, KC_RGHT, LOWER,   KC_SPC,  KC_DEL,  KC_ENT,  KC_BSPC, RAISE,   KC_DOWN, KC_UP,   KC_RGUI, KC_RCTL
  ),
/* Dvorak
 * ,-------------------------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |XXXXXX|XXXXXX|   6  |   7  |   8  |   9  |   0  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |XXXXXX|XXXXXX|   F  |   G  |   C  |   R  |   L  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |XXXXXX|XXXXXX|   D  |   H  |   T  |   N  |   S  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |XXXXXX|XXXXXX|   B  |   M  |   W  |   V  |   Z  |Sf/Ent|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Func | Alt  | Left |Right |Lower | Space| Del  | Enter| Bksp |Raise | Down |  Up  | GUI  | Ctrl |
 * `-------------------------------------------------------------------------------------------------'
 */
  [_DVORAK] = LAYOUT ( /* dvorak */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
    KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    SFT_ENT,
    FNC,     KC_LALT, KC_LEFT, KC_RGHT, LOWER,   KC_SPC,  KC_DEL,  KC_ENT,  KC_BSPC, RAISE,   KC_DOWN, KC_UP,   KC_RGUI, KC_RCTL
  ),
/* Colemak
 * ,-------------------------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |XXXXXX|XXXXXX|   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |XXXXXX|XXXXXX|   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   R  |   S  |   T  |   D  |XXXXXX|XXXXXX|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |XXXXXX|XXXXXX|   K  |   M  |   ,  |   .  |   /  |Sf/Ent|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Func | Alt  | Left |Right |Lower | Space| Del  | Enter| Bksp |Raise | Down |  Up  | GUI  | Ctrl |
 * `-------------------------------------------------------------------------------------------------'
 */
  [_COLEMAK] = LAYOUT ( /* colemak */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
    FNC,     KC_LALT, KC_LEFT, KC_RGHT, LOWER,   KC_SPC,  KC_DEL,  KC_ENT,  KC_BSPC, RAISE,   KC_DOWN, KC_UP,   KC_RGUI, KC_RCTL
  ),

/* Lower
 * ,-------------------------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |XXXXXX|XXXXXX|  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   !  |   @  |   #  |   $  |   %  |XXXXXX|XXXXXX|   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |XXXXXX|XXXXXX|  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |XXXXXX|XXXXXX|  F12 |ISO ~ |ISO | |JIS _ |JIS | |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Home | End  |      |Muhen | E/J  | KANA |Henkan|      |Pg-dwn| Pg-up|      |      |
 * `-------------------------------------------------------------------------------------------------'
 */
  [_LOWER] = LAYOUT ( /* lower */
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  S(KC_NUHS),S(KC_NUBS), S(KC_RO), S(KC_JYEN), _______,
    _______, _______, KC_HOME, KC_END,  _______, KC_MHEN, E_J,    KANA,     KC_HENK, _______, KC_PGDN, KC_PGUP, _______, _______
  ),

/* Raise
 * ,-------------------------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |XXXXXX|XXXXXX|  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   1  |   2  |   3  |   4  |   5  |XXXXXX|XXXXXX|   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |XXXXXX|XXXXXX|  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |XXXXXX|XXXXXX|  F12 |ISO # |ISO / |JIS \ |JIS Y |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Home | End  |      |Muhen | E/J  | KANA |Henkan|      |Pg-dwn| Pg-up|      |      |
 * `-------------------------------------------------------------------------------------------------'
 */
  [_RAISE] = LAYOUT ( /* raise */
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  KC_NUHS, KC_NUBS, KC_RO,   KC_JYEN, _______,
    _______, _______, KC_HOME, KC_END,  _______, KC_MHEN, E_J,    KANA,     KC_HENK, _______, KC_PGDN, KC_PGUP, _______, _______
  ),

/* Function
 * ,-------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |XXXXXX|XXXXXX| Caps | SCLK | PAUSE| INS  |      | Mute |
 * |-------------------------------------------------------------------------------------------------|
 * |      | M0   | M1   | M2   | M3   | M4   |XXXXXX|XXXXXX| MENU | Pg-up|  Up  |Pg-dwn| PSCR |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | M5   | M6   | M7   | M8   | M9   |XXXXXX|XXXXXX| Home | Left | Down |Right | End  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | M10  | M11  | M12  | M13  | M14  |XXXXXX|XXXXXX|      | Stop | Prev | Next | Play |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | M15  | M16  |      |      | M17  |      |      |      | Vol- | Vol+ |      |      |
 * `-------------------------------------------------------------------------------------------------'
//Macros:
//M(0)   F2				//M(1)   Shft + F2
//M(2)   Shft + F2			//M(3)   Ctrl + K, Ctrl + C
//M(4)   Ctrl + K, Ctrl + U		//M(5)   F12
//M(6)   Ctrl + Shft + S		//M(7)   Ctrl + M, Ctrl + M
//M(8)   Ctrl + Alt + PageDown		//M(9)   Ctrl + Alt + PageUp
//M(10)  Ctrl + Z			//M(11)  Ctrl + X
//M(12)  Ctrl + C			//M(13)  Ctrl + V
//M(14)  Ctrl + Shft + B		//M(15)  Ctrl + "-"
//M(16)  Ctrl + Shft + "-"		//M(17)  Ctrl + Alt + Delete
*/
  [_FUNCTION] = LAYOUT ( /* function */
    _______, _______, _______, _______, _______, _______,                   KC_CAPS, KC_SLCK, KC_PAUS, KC_INS, _______, KC_MUTE,
    _______, M(0),    M(1),    M(2),    M(3),    M(4),                      KC_APP,  KC_PGUP, KC_UP,   KC_PGDN, KC_PSCR, _______,
    _______, M(5),    M(6),    M(7),    M(8),    M(9),                      KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_ENT,
    _______, M(10),   M(11),   M(12),   M(13),   M(14),                     _______, KC_MSTP, KC_MPRV, KC_MNXT, KC_MPLY, _______,
    _______, _______, M(15),   M(16),   _______, _______,  M(17),  _______, _______, _______, KC_VOLD, KC_VOLU, _______, _______
  ),

/* Adjust (Lower + Raise)
 * ,-------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |XXXXXX|XXXXXX|      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |XXXXXX|XXXXXX|      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |XXXXXX|XXXXXX|      |Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |XXXXXX|XXXXXX|      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-------------------------------------------------------------------------------------------------'
 */
  [_ADJUST] = LAYOUT ( /* adjust */
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, RESET,   _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, QWERTY,  COLEMAK, DVORAK,  _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )

};

const uint16_t PROGMEM fn_actions[] = {

};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
    case 0: //M(0) //F2
        if (record->event.pressed) {// on keydown
            return MACRO(T(F2), END);
        }
        break;
    case 1: //M(1) //Ctrl + F4
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), T(F4), U(LCTL), END);
        }
        break;
    case 2: //M(2) //Shft + F2
        if (record->event.pressed) {// on keydown
            return MACRO(D(LSFT), T(F2), U(LSFT), END);
        }
        break;
    case 3: //M(3) //Ctrl + K, Ctrl + C
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), T(K), U(LCTL), D(LCTL), T(C), U(LCTL), END);
        }
        break;
    case 4: //Ctrl + K, Ctrl + U
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), T(K), U(LCTL), D(LCTL), T(U), U(LCTL), END);
        }
        break;
    case 5: //M(5) //F12
        if (record->event.pressed) {// on keydown
            return MACRO(T(F12), END);
        }
        break;
    case 6: //M(6) //Ctrl + Shft + S
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), D(LSFT), T(S), U(LSFT), U(LCTL), END);
        }
        break;
    case 7: //M(7) //Ctrl + M, Ctrl + M
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), T(M), U(LCTL), D(LCTL), T(M), U(LCTL), END);
        }
        break;
    case 8: //M(8) //Ctrl + Alt + PageDown
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), D(LALT), T(PGDN), U(LALT), U(LCTL), END);
        }
        break;
    case 9: //M(9) //Ctrl + Alt + PageUp
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), D(LALT), T(PGUP), U(LALT), U(LCTL), END);
        }
        break;
    case 10: //M(10)//Ctrl + Z
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), T(Z), U(LCTL), END);
        }
        break;
    case 11: //M(11)//Ctrl + X
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), T(X), U(LCTL), END);
        }
        break;
    case 12: //M(12)//Ctrl + C
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), T(C), U(LCTL), END);
        }
        break;
    case 13: //M(13)//Ctrl + V
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), T(V), U(LCTL), END);
        }
        break;
    case 14: //M(14)//Ctrl + Shft + B
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), D(LSFT), T(B), U(LSFT), U(LCTL), END);
        }
        break;
    case 15: //M(15)//Ctrl + "-"
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), T(MINS), U(LCTL), END);
        }
        break;
    case 16: //M(16)//Ctrl + Shft + "-"
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), D(LSFT), T(MINS), U(LSFT), U(LCTL), END);
        }
        break;
    case 17: //M(17)//Ctrl + Alt + Delete
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), D(LALT), T(DEL), U(LALT), U(LCTL), END);
        }
        break;
    }
    return MACRO_NONE;
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {// on keydown
            persistent_default_layer_set(1UL<<_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {// on keydown
            persistent_default_layer_set(1UL<<_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {// on keydown
            persistent_default_layer_set(1UL<<_DVORAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {// on keydown
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {// on keyup
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {// on keydown
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {// on keyup
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};
