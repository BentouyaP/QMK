#include QMK_KEYBOARD_H


extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _FN 1

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* 0: qwerty
 * ,------------------------------------------------.      ,------------------------------------------------.
 * | Esc  |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   -  |  =   |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |      |   ]  |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |   "  |      |   '  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |  (   |      |   )  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Ctrl | Pg Up| GUI  | Alt  |  Fn  |Space |Enter |      |Space |Space |  Fn  |  Alt | Menu |  Up  | Ctrl |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Home | Pg Dn| End  |xxxxxx|xxxxxx|xxxxxx| Del  |      | BkSp |xxxxxx|xxxxxx|xxxxxx| Left | Down | Right|
 * `------------------------------------------------'      `------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
 KC_ESC, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                  KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, \
 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC,                 KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, \
 KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_DQUO,                KC_QUOT, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,  \
 KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LPRN,                KC_RPRN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,  \
 KC_LCTL, KC_PGUP, KC_LGUI, KC_LALT, MO(1), KC_SPC,KC_ENT,      KC_SPC, KC_SPC, MO(1), KC_RALT, KC_APP, KC_UP, KC_RCTL,  \
 KC_HOME, KC_PGDN, KC_END, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,   KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT \
),

/* 1: fn 
 * ,------------------------------------------------.      ,------------------------------------------------.
 * | RESET|      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |RGBtog|RGBmod|RGBhud|RGBvad|RGBsad|      |  {   |      |  }   |      | INS  |SCRLK |PAUSE |PRTSC |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |RGBrmd|RGBhui|RGBvai|RGBsai|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |  Fn  |      |      |      |      |      |  Fn  |      |      | Vol+ |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |xxxxxx|xxxxxx|xxxxxx|      |      |      |xxxxxx|xxxxxx|xxxxxx| Next | Vol- | Play |
 * `------------------------------------------------'      `------------------------------------------------'
 */

[_FN] = LAYOUT( \
 RESET, _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, 			KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  \
 RGB_TOG, RGB_MOD, RGB_HUD, RGB_VAD, RGB_SAD, _______, KC_LCBR,         KC_RCBR, _______, KC_INS, KC_SLCK, KC_PAUS, KC_PSCR, _______,  \
 _______, RGB_RMOD, RGB_HUI, RGB_VAI, RGB_SAI, _______, _______,        _______, _______, _______, _______, _______, _______, _______,  \
 _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,  \
 _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, KC_VOLU, _______,  \
 _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______,         _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MNXT, KC_VOLD, KC_MPLY   \
)
};

