#include "rising60.h"
#include "action_layer.h"
extern keymap_config_t keymap_config;

// Rising60 Default Keymap TypeB
// Defalut 60% Layout Compatible

#define _QWERTY 0
#define _DVORAK 1
#define _COLEMAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum rising60_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  COLEMAK,
  LOWER,
  RAISE
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty */
[_QWERTY] = LAYOUT (
	KC_ESC,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,   KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV,  KC_BSPC, 
	KC_TAB,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, 
	KC_LCTL,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT, 
	KC_LSFT,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,   KC_ENT,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_DEL, 
	KC_CAPS,            KC_LGUI, KC_LALT, LOWER,           KC_SPC,		  RAISE,   KC_RALT, KC_APP,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT 
	),

/* Dvorak */
[_DVORAK] = LAYOUT (
	KC_ESC,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,   KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_GRV,  KC_BSPC, 
	KC_TAB,   KC_QUOT,  KC_COMM, KC_DOT,  KC_P,    KC_Y,             KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS, 
	KC_LCTL,  KC_A,     KC_O,    KC_E,    KC_U,    KC_I,             KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, KC_BSLS, KC_ENT, 
	KC_LSFT,  KC_SCLN,  KC_Q,    KC_J,    KC_K,    KC_X,   KC_ENT,   KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, KC_UP,   KC_DEL, 
	KC_CAPS,            KC_LGUI, KC_LALT, LOWER,           KC_SPC,		  RAISE,   KC_RALT, KC_APP,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT 
	),

/* Colemak */
[_COLEMAK] = LAYOUT (
	KC_ESC,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,   KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV,  KC_BSPC, 
	KC_TAB,   KC_Q,     KC_W,    KC_F,    KC_P,    KC_G,             KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, 
	KC_LCTL,  KC_A,     KC_R,    KC_S,    KC_T,    KC_D,             KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_BSLS, KC_ENT, 
	KC_LSFT,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,   KC_ENT,   KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_DEL, 
	KC_CAPS,            KC_LGUI, KC_LALT, LOWER,           KC_SPC,		  RAISE,   KC_RALT, KC_APP,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT 
	),

/* Lower */
[_LOWER] = LAYOUT (
	KC_GRV,   KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, 
	_______,  _______,  _______, KC_UP,   _______, _______,          _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______, 
	_______,  _______,  KC_LEFT, KC_DOWN, KC_RGHT, _______,          _______, KC_INS,  KC_HOME, KC_PGUP, KC_BSPC, _______, _______, _______, 
	_______,  _______,  _______, _______, _______, _______, M(0),    _______, KC_DEL,  KC_END,  KC_PGDN, _______, _______, _______, _______, 
	_______,            _______, _______, _______,          _______,          _______, _______, _______, _______, _______, _______, _______ 
	),

/* Raise */
[_RAISE] = LAYOUT (
	KC_GRV,   KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, 
	_______,  _______,  _______, KC_UP,   _______, _______,          _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______, 
	_______,  _______,  KC_LEFT, KC_DOWN, KC_RGHT, _______,          _______, KC_INS,  KC_HOME, KC_PGUP, KC_BSPC, _______, _______, _______, 
	_______,  _______,  _______, _______, _______, _______, M(0),    _______, KC_DEL,  KC_END,  KC_PGDN, _______, _______, _______, _______, 
	_______,            _______, _______, _______,          _______,          _______, _______, _______, _______, _______, _______, _______ 
	),

/* ADJUST (Lower + Raise) */
[_ADJUST] = LAYOUT (
	_______,  RGB_M_P,  RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, _______, _______, _______, _______, 
	RGB_TOG,  RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, _______,          _______, _______, _______, _______, _______, _______, _______, _______, 
	_______,  RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,          _______, QWERTY,  DVORAK,  COLEMAK, _______, _______, _______, _______, 
	_______,  _______,  _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, 
	_______,            _______, _______, _______,          _______,          _______, _______, _______, _______, _______, _______, _______ 
	)

};


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
        case DVORAK:
          if (record->event.pressed) {// on keydown
            persistent_default_layer_set(1UL<<_DVORAK);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {// on keydown
            persistent_default_layer_set(1UL<<_COLEMAK);
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
