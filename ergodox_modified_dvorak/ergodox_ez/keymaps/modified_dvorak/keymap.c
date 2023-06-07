#include QMK_KEYBOARD_H
#include "version.h"

#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CUT LCTL(KC_X)
#define TT_NUMP TT(NUMPAD)

enum layers {
    QWE,
    DVO,
    NUMPAD,
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮                    ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │   =    │   1  │   2  │   3  │   4  │   5  │ COPY │                    │      │   6  │   7  │   8  │   9  │   0  │   -    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │  Del   │   Q  │   W  │   E  │   R  │   T  │PASTE │                    │      │   Y  │   U  │   I  │   O  │   P  │   \    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                    │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │  BkSp  │   A  │   S  │   D  │   F  │   G  ├──────┤                    ├──────┤   H  │   J  │   K  │   L  │   ;  │   '    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤ CUT  │                    │SWITCH├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ LShift │   Z  │   X  │   C  │   V  │   B  │      │                    │DVORAK│   N  │   M  │   ,  │   .  │   /  │ RShift │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯                    ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │ NUMP │   `  │      │ Left │ Right│                                                │  Up  │ Down │   [  │   ]  │ NUMP │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                                ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮                ╭──────┬────────╮
 *                                        │ Alt  │ LGui │                │ Alt  │Ctrl/Esc│
 *                                 ╭──────┼──────┼──────┤                ├──────┼────────┼──────╮
 *                                 │      │      │ Home │                │ PgUp │  Back  │      │
 *                                 │ Tab  │Space ├──────┤                ├──────┤  Space │Enter │
 *                                 │      │      │ End  │                │ PgDn │        │      │
 *                                 ╰──────┴──────┴──────╯                ╰──────┴────────┴──────╯
 */
[QWE] = LAYOUT_ergodox_pretty(
  // left hand                                                           // right hand
  KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    COPY,            _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    PASTE,           _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    CUT,             DF(QWE), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  TT_NUMP, KC_GRV,  _______, KC_LEFT, KC_RGHT,                                             KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, TT_NUMP,

                                      ALT_T(KC_APP),    KC_LGUI,         KC_LALT, CTL_T(KC_ESC),
                                                        KC_HOME,         KC_PGUP,
                                      KC_TAB,  KC_SPC,  KC_END,          KC_PGDN, KC_BSPC, KC_ENT
),

/* MODIFIED PROGRAMMING DVORAK
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮                    ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │   $ ~  │ + 1  │ [ 2  │ { 3  │ ( 4  │ & 5  │      │                    │      │ = 6  │ ) 7  │ } 8  │ ] 9  │ * 0  │  ! %   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │   ;  │   ,  │   .  │   P  │   Y  │      │                    │      │   F  │   G  │   C  │   R  │   L  │  \ #   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                    │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │   A  │   O  │   E  │   U  │   I  ├──────┤                    ├──────┤   D  │   H  │   T  │   N  │   S  │   -    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                    │SWITCH├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │   '  │   Q  │   J  │   K  │   X  │      │                    │QWERTY│   B  │   M  │   W  │   V  │   Z  │        │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯                    ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │ | `  │      │      │      │                                                │      │      │   /  │ @ ^  │      │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                                ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮                ╭──────┬────────╮
 *                                        │      │      │                │      │        │
 *                                 ╭──────┼──────┼──────┤                ├──────┼────────┼──────╮
 *                                 │      │      │      │                │      │        │      │
 *                                 │      │      ├──────┤                ├──────│        │      │
 *                                 │      │      │      │                │      │        │      │
 *                                 ╰──────┴──────┴──────╯                ╰──────┴────────┴──────╯
 */
[DVO] = LAYOUT_ergodox_pretty(
  // left hand                                                           // right hand
  KC_DLR,  KC_PLUS, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, _______,         _______, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_ASTR, KC_EXLM,
  _______, KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    _______,         _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS,
  _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                              KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
  KC_LSFT, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    _______,         DF(QWE), KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
  _______, KC_PIPE, _______, _______, _______,                                             _______, _______, KC_SLSH, KC_AT,   _______,

                                             _______,   _______,         _______, _______,
                                                        _______,         _______,
                                      _______, _______, _______,         _______, _______, _______
),

/* NUMPAD + EXTRAS
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮                    ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │  F1  │ F2   │ F3   │ F4   │ F5   │      │                    │      │ F6   │ F7   │ F8   │ F9   │ F10  │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      │ F11  │                    │ F12  │   ^  │  7   │  8   │  9   │  *   │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                    │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      ├──────┤                    ├──────┤   |  │  4   │  5   │  6   │  +   │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                    │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      │      │                    │      │   &  │  1   │  2   │  3   │  \   │        │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯                    ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │      │      │      │      │                                                │  0   │  .   │      │  =   │      │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                                ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮                ╭──────┬────────╮
 *                                        │      │      │                │      │        │
 *                                 ╭──────┼──────┼──────┤                ├──────┼────────┼──────╮
 *                                 │      │      │      │                │      │        │      │
 *                                 │      │      ├──────┤                ├──────┤        │      │
 *                                 │      │      │      │                │      │        │      │
 *                                 ╰──────┴──────┴──────╯                ╰──────┴────────┴──────╯
 */
[NUMPAD] = LAYOUT_ergodox_pretty(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,         _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, _______, _______, _______, _______, _______, KC_F11,          KC_F12,  KC_CIRC, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, _______,
  _______, _______, _______, _______, _______, _______,                           KC_PIPE, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______,
  _______, _______, _______, _______, _______, _______, _______,         _______, KC_AMPR, KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS, _______,
  _______, _______, _______, _______, _______,                                             KC_KP_0, KC_PDOT, _______, KC_PEQL, _______,

                                             _______,   _______,         _______, _______,
                                                        _______,         _______,
                                      _______, _______, _______,         _______, _______, _______
),

};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// programmer dvorak key overrides for non-standard shifts
const key_override_t dlr_override   = ko_make_with_layers(MOD_MASK_SHIFT, KC_DLR , KC_TILD, 1 << DVO);
const key_override_t one_override   = ko_make_with_layers(MOD_MASK_SHIFT, KC_PLUS, KC_1   , 1 << DVO);
const key_override_t two_override   = ko_make_with_layers(MOD_MASK_SHIFT, KC_LBRC, KC_2   , 1 << DVO);
const key_override_t three_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_LCBR, KC_3   , 1 << DVO);
const key_override_t four_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_LPRN, KC_4   , 1 << DVO);
const key_override_t five_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_AMPR, KC_5   , 1 << DVO);
const key_override_t six_override   = ko_make_with_layers(MOD_MASK_SHIFT, KC_EQL , KC_6   , 1 << DVO);
const key_override_t seven_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_RPRN, KC_7   , 1 << DVO);
const key_override_t eight_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_RCBR, KC_8   , 1 << DVO);
const key_override_t nine_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_RBRC, KC_9   , 1 << DVO);
const key_override_t zero_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_ASTR, KC_0   , 1 << DVO);
const key_override_t minus_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_EXLM, KC_PERC, 1 << DVO);
const key_override_t at_override    = ko_make_with_layers(MOD_MASK_SHIFT, KC_AT,   KC_CIRC, 1 << DVO);
const key_override_t bsls_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSLS, KC_HASH, 1 << DVO);
const key_override_t pipe_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_PIPE, KC_GRV , 1 << DVO);

const key_override_t** key_overrides = (const key_override_t *[]){
    &dlr_override,
    &one_override,
    &two_override,
    &three_override,
    &four_override,
    &five_override,
    &six_override,
    &seven_override,
    &eight_override,
    &nine_override,
    &zero_override,
    &minus_override,
    &at_override,
    &bsls_override,
    &pipe_override,
    NULL
};

