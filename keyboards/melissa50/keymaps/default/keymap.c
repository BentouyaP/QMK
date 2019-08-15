#include "melissa50.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

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

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  COLEMAK,
  LOWER,
  RAISE,
  FN,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define SPC_FN LT(_FUNCTION,KC_SPC)  	// Tap for Space, hold for FUNCTION 


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   \  |      |   6  |   7  |   8  |   9  |   0  |   -  |  =   |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |xxxxxx|      |xxxxxx|   Y  |   U  |   I  |   O  |   P  | BkSp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |xxxxxx|      |xxxxxx|   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |Enter |      |   '  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Func | Menu | GUI  | Alt  |LOWER |Space |Space |      |Space |Space |RAISE | Left | Down |  Up  | Right|
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_QWERTY] = LAYOUT(
    KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,  KC_5, KC_BSLS,        KC_6,    KC_7,   KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,\
    KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,                          KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,\
    KC_LCTL, KC_A,   KC_S,    KC_D,    KC_F,  KC_G,                          KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,\
    KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,  KC_ENT,        KC_QUOT, KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,\
    FN,      KC_APP, KC_LGUI, KC_LALT, LOWER, KC_SPC,KC_SPC,        SPC_FN,  KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT\
  ),

/* Dvorak
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   \  |      |   6  |   7  |   8  |   9  |   0  |   -  |  =   |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |xxxxxx|      |xxxxxx|   F  |   G  |   C  |   R  |   L  | BkSp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |xxxxxx|      |xxxxxx|   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |Enter |      |   /  |   B  |   M  |   W  |   V  |   Z  | Shift|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Func | Menu | GUI  | Alt  |LOWER |Space |Space |      |Space |Space |RAISE | Left | Down |  Up  | Right|
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_DVORAK] = LAYOUT ( /* dvorak */
    KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,  KC_5, KC_BSLS,        KC_6,    KC_7,   KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,\
    KC_TAB,  KC_QUOT,KC_COMM, KC_DOT,  KC_P,  KC_Y,                          KC_F,   KC_G,  KC_C,    KC_R,    KC_L,    KC_BSPC,\
    KC_LCTL, KC_A,   KC_O,    KC_E,    KC_U,  KC_I,                          KC_D,   KC_H,  KC_T,    KC_N,    KC_S,    KC_ENT,\
    KC_LSFT, KC_SCLN,KC_Q,    KC_J,    KC_K,  KC_X,  KC_ENT,        KC_SLSH, KC_B,   KC_M,  KC_W,    KC_V,    KC_Z,    KC_RSFT,\
    FN,      KC_APP, KC_LGUI, KC_LALT, LOWER, KC_SPC,KC_SPC,        SPC_FN,  KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT\
  ),
/* Colemak
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   \  |      |   6  |   7  |   8  |   9  |   0  |   -  |  =   |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |xxxxxx|      |xxxxxx|   J  |   L  |   U  |   Y  |   ;  | BkSp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Ctrl |   A  |   R  |   S  |   T  |   D  |xxxxxx|      |xxxxxx|   H  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |Enter |      |   '  |   K  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Func | Menu | GUI  | Alt  |LOWER |Space |Space |      |Space |Space |RAISE | Left | Down |  Up  | Right|
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_COLEMAK] = LAYOUT ( /* colemak */
    KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,  KC_5, KC_BSLS,        KC_6,    KC_7,   KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,\
    KC_TAB,  KC_Q,   KC_W,    KC_F,    KC_P,  KC_G,                          KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_BSPC,\
    KC_LCTL, KC_A,   KC_R,    KC_S,    KC_T,  KC_D,                          KC_H,   KC_N,  KC_E,    KC_I,    KC_O,    KC_ENT,\
    KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,  KC_ENT,        KC_QUOT, KC_K,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,\
    FN,      KC_APP, KC_LGUI, KC_LALT, LOWER, KC_SPC,KC_SPC,        SPC_FN,  KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT\
  ),
/* Lower
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |  F1  |  F3  |  F3  |  F4  |  F5  |      |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Esc  |   !  |   @  |   #  |   $  |   %  |xxxxxx|      |xxxxxx|   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |xxxxxx|      |xxxxxx|  F6  |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |      |  F12 |ISO ~ |ISO | |JIS _ |JIS | |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |LOWER |      |      |      |      |      |RAISE | Home |Pg-dwn| Pg-up| End  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,\
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,          _______, KC_F12,  S(KC_NUHS),S(KC_NUBS), S(KC_RO), S(KC_JYEN), _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END \
  ),

/* Raise
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |  F1  |  F3  |  F3  |  F4  |  F5  |      |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Esc  |   1  |   2  |   3  |   4  |   5  |xxxxxx|      |xxxxxx|   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |xxxxxx|      |xxxxxx|  F6  |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |      |  F12 |ISO # |ISO / |JIS \ |JIS Y |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |LOWER |      |      |      |      |      |RAISE | Home |Pg-dwn| Pg-up| End  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_RAISE] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,\
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,          _______, KC_F12,  KC_NUHS, KC_NUBS, KC_RO,   KC_JYEN, _______,\
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END \
  ),
/* Function
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      | Caps | SCLK | PAUSE| INS  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |xxxxxx|      |xxxxxx| MENU | Pg-up|  Up  |Pg-dwn| PSCR |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |xxxxxx|      |xxxxxx| Home | Left | Down |Right | End  | Enter|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | M0   |      |      |      | Stop | Prev | Next | Play |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Func |      |      |      |      |      |      |      |      |      |      |      | Vol- | Vol+ | Mute |
 * `------------------------------------------------'      `------------------------------------------------'
 */
//Macros:
//M(0)   Ctrl + Alt + Delete
  [_FUNCTION] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,          _______, KC_CAPS, KC_SLCK, KC_PAUS, KC_INS,  _______, _______,\
    _______, _______, _______, _______, _______, _______,                            KC_APP,  KC_PGUP, KC_UP,   KC_PGDN, KC_PSCR, _______,\
    _______, _______, _______, _______, _______, _______,                            KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______,\
    _______, _______, _______, _______, _______, _______, M(0),             _______, _______, KC_MSTP, KC_MPRV, KC_MNXT, KC_MPLY, _______,\
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE \
  ),

/* Adjust (Lower + Raise)
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |RGB Tg|Mode +|Hue + |Sat + |Val + |      |xxxxxx|      |xxxxxx|      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |Mode -|Hue - |Sat - |Val - |      |xxxxxx|      |xxxxxx|      |Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |AGnorm|AGswap|Aud on|Audoff|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,\
    RGB_TOG, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,                            _______, _______, _______, _______, _______, _______, \
    _______, RGB_RMOD,RGB_HUI, RGB_SAI, RGB_VAI, _______,                            _______, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
    _______, AG_NORM, AG_SWAP, AU_ON,   AU_OFF,  _______, _______,          _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______ \
  )

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
    case 0: //M(0) //Ctrl + Alt + Delete
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), D(LALT), T(DEL), U(LALT), U(LCTL), END);
        }
        break;
    }
    return MACRO_NONE;
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
    case FN:
      if (record->event.pressed) {// on keydown
        layer_on(_FUNCTION);
      } else {// on keyup
        layer_off(_FUNCTION);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {// on keydown
        layer_on(_ADJUST);
      } else {// on keyup
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
