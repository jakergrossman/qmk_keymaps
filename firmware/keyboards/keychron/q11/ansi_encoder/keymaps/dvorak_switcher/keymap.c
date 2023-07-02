/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "dip_switch.h"
#include QMK_KEYBOARD_H

// clang-format off

enum layers{
    QWERTY,
    DVORAK,
    FN
};

bool dip_switch_update_user(uint8_t index, bool active)
{
    if (index == 0) {
        default_layer_set(1UL << (active ? DVORAK : QWERTY));
    }
    return false;
}

#define KC_ESFN LT(FN, KC_ESC)

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //   QWERTY
    //  ╭──────╮ ╭──────┬──────┬──────┬──────┬──────┬──────┬─────╮       ╭──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────╮  ╭───────╮
    //  │ PLAY │ │ ESC  │  F1  │  F2  │  F3  │  F4  │  F5  │ F6  │       │  F7  │  F8  │  F9  │  F10 │ F11  │  F12 │ INS  │ DEL  │  │ MUTE  │
    //  ├──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┼─────┤       ├──────┼──────┼──────┼──────┼──────┼──────┼──────┴──────┤  ├───────┤
    //  │ F13  │ │  `   │  1   │  2   │  3   │  4   │  5   │  6  │       │  7   │  8   │  9   │  0   │  -   │   =  │  BACKSPACE  │  │ PGUP  │
    //  ├──────┤ ├──────┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬──╯    ╭──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬─────────┤  ├───────┤
    //  │ F14  │ │   TAB   │  Q   │  W   │  E   │  R   │  T   │       │  Y   │  U   │  I   │  O   │  P   │  [   │  ]   │    \    │  │ PGDN  │
    //  ├──────┤ ├─────────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─╮     ╰─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─────────┤  ├───────┤
    //  │ F15  │ │  FN_ESC   │  A   │  S   │  D   │  F   │  G   │       │  H   │  J   │  K   │  L   │  ;   │  '   │    RETURN    │  │ HOME  │
    //  ├──────┤ ├───────────┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴─╮     ╰─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴───────┬─┬────┴──┼───────╯
    //  │ F16  │ │    LSHIFT    │  Z   │  X   │  C   │  V   │  B  │       │  N   │  M   │  ,   │  .   │  /   │  RSHIFT    │ │  UP   │
    //  ├──────┤ ├───────┬──────┴─┬────┴──┬───┴───┬──┴──────┴─────┤       ├──────┴──────┴──┬───┴───┬──┴────┬─┴──────┬┬────┴─┼───────┼───────╮
    //  │ F17  │ │   F18 │  F19   │ SUPER │  ALT  │     SPACE     │       │    CONTROL     │  ALT  │ SUPER │  CTRL  ││  UP  │ DOWN  │ RIGHT │
    //  ╰──────╯ ╰───────┴────────┴───────┴───────┴───────────────╯       ╰────────────────┴───────┴───────┴────────╯╰──────┴───────┴───────╯
    [QWERTY] = LAYOUT_ansi_91(
        KC_MPLY,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        KC_F13,   KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_F14,   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_F15,   KC_ESFN,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        KC_F16,   KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_F17,   KC_F18,   KC_F19,   KC_LWIN,  KC_LALT,            KC_SPC,                        KC_LCTL,            KC_RALT,  KC_RWIN,    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    //   MODIFIED PROGRAMMER'S DVORAK
    //  ╭──────╮ ╭──────┬──────┬──────┬──────┬──────┬──────┬─────╮       ╭──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────╮  ╭───────╮
    //  │ PLAY │ │ ESC  │  F1  │  F2  │  F3  │  F4  │  F5  │ F6  │       │  F7  │  F8  │  F9  │  F10 │ F11  │  F12 │ INS  │ DEL  │  │ MUTE  │
    //  ├──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┼─────┤       ├──────┼──────┼──────┼──────┼──────┼──────┼──────┴──────┤  ├───────┤
    //  │ F13  │ │ $,~  │  +,1 │  [,2 │  {,3 │  (,4 │  &,5 │ =,6 │       │  ),7 │  },8 │  ],9 │  *,0 │  !,% │  |,` │  BACKSPACE  │  │ PGUP  │
    //  ├──────┤ ├──────┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬──╯    ╭──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬─────────┤  ├───────┤
    //  │ F14  │ │   TAB   │  ;   │  ,   │  .   │  P   │  Y   │       │  F   │  G   │  C   │  R   │  L   │  /   │  @,^ │   \,#   │  │ PGDN  │
    //  ├──────┤ ├─────────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─╮     ╰─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─────────┤  ├───────┤
    //  │ F15  │ │  FN_ESC   │  A   │  O   │  E   │  U   │  I   │       │  D   │  H   │  T   │  N   │  S   │  -   │    RETURN    │  │ HOME  │
    //  ├──────┤ ├───────────┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴─╮     ╰─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴───────┬─┬────┴──┼───────╯
    //  │ F16  │ │    LSHIFT    │  '   │  Q   │  J   │  K   │  X  │       │  B   │  M   │  W   │  V   │  Z   │  RSHIFT    │ │  UP   │
    //  ├──────┤ ├───────┬──────┴─┬────┴──┬───┴───┬──┴──────┴─────┤       ├──────┴──────┴──┬───┴───┬──┴────┬─┴──────┬┬────┴─┼───────┼───────╮
    //  │ F17  │ │   F18 │  F19   │ SUPER │  ALT  │     SPACE     │       │    CONTROL     │  ALT  │ SUPER │  CTRL  ││  UP  │ DOWN  │ RIGHT │
    //  ╰──────╯ ╰───────┴────────┴───────┴───────┴───────────────╯       ╰────────────────┴───────┴───────┴────────╯╰──────┴───────┴───────╯
    [DVORAK] = LAYOUT_ansi_91(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  KC_DLR,   KC_PLUS,  KC_LBRC,  KC_LCBR,  KC_LPRN,  KC_AMPR,   KC_EQL,   KC_RPRN,  KC_RCBR,  KC_RBRC,  KC_ASTR,  KC_EXLM,    KC_PIPE,  _______,            _______,
        _______,  _______,  KC_SCLN,  KC_COMMA, KC_DOT,   KC_P,     KC_Y,      KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,    KC_AT,    KC_BSLS,            _______,
        _______,  _______,  KC_A,     KC_O,     KC_E,     KC_U,     KC_I,      KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,              _______,            _______,
        _______,  _______,            KC_QUOT,  KC_Q,     KC_J,     KC_K,      KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,                 _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

    //   FN (mostly RGB settings)
    //  ╭──────╮ ╭──────┬──────┬──────┬──────┬──────┬──────┬─────╮       ╭──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────╮  ╭───────╮
    //  │RTGTOG│ │      │ BRIU │ BRID │ TASK │ FLXP │ VAD  │ VAI │       │ MPRV │ MPLY │ MNXT │ MUTE │ VOLD │ VOLU │      │      │  │ RGBTOG│
    //  ├──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┼─────┤       ├──────┼──────┼──────┼──────┼──────┼──────┼──────┴──────┤  ├───────┤
    //  │      │ │      │      │      │      │      │      │     │       │      │      │      │      │      │      │             │  │       │
    //  ├──────┤ ├──────┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬──╯    ╭──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬─────────┤  ├───────┤
    //  │      │ │         │ MOD  │ VAI  │ HUI  │ SAI  │ SPI  │       │      │      │      │      │      │      │      │         │  │       │
    //  ├──────┤ ├─────────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─╮     ╰─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─────────┤  ├───────┤
    //  │      │ │           │ RMOD │ VAD  │ HUD  │ SAD  │ SPD  │       │ LEFT │ DOWN │  UP  │ RIGHT│      │      │              │  │       │
    //  ├──────┤ ├───────────┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴─╮     ╰─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴───────┬─┬────┴──┼───────╯
    //  │      │ │              │      │      │      │      │     │       │ NKEY │      │      │      │      │            │ │       │
    //  ├──────┤ ├───────┬──────┴─┬────┴──┬───┴───┬──┴──────┴─────┤       ├──────┴──────┴──┬───┴───┬──┴────┬─┴──────┬┬────┴─┼───────┼───────╮
    //  │      │ │       │        │       │       │               │       │                │       │       │        ││      │       │       │
    //  ╰──────╯ ╰───────┴────────┴───────┴───────┴───────────────╯       ╰────────────────┴───────┴───────┴────────╯╰──────┴───────┴───────╯
    [FN] = LAYOUT_ansi_91(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)


// ENCODERS
//
// MEDIA_PREVIOUS ╭─╮ MEDIA_NEXT                               VOLUME_DOWN ╭─╮ VOLUME_UP
//                ╰─╯                                                      ╰─╯
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [QWERTY] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [DVORAK] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [FN]     = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};

// programmer dvorak key overrides for non-standard shifts
const key_override_t dlr_override   = ko_make_with_layers(MOD_MASK_SHIFT, KC_DLR , KC_TILD, 1 << DVORAK);
const key_override_t one_override   = ko_make_with_layers(MOD_MASK_SHIFT, KC_PLUS, KC_1   , 1 << DVORAK);
const key_override_t two_override   = ko_make_with_layers(MOD_MASK_SHIFT, KC_LBRC, KC_2   , 1 << DVORAK);
const key_override_t three_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_LCBR, KC_3   , 1 << DVORAK);
const key_override_t four_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_LPRN, KC_4   , 1 << DVORAK);
const key_override_t five_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_AMPR, KC_5   , 1 << DVORAK);
const key_override_t six_override   = ko_make_with_layers(MOD_MASK_SHIFT, KC_EQL , KC_6   , 1 << DVORAK);
const key_override_t seven_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_RPRN, KC_7   , 1 << DVORAK);
const key_override_t eight_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_RCBR, KC_8   , 1 << DVORAK);
const key_override_t nine_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_RBRC, KC_9   , 1 << DVORAK);
const key_override_t zero_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_ASTR, KC_0   , 1 << DVORAK);
const key_override_t minus_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_EXLM, KC_PERC, 1 << DVORAK);
const key_override_t at_override    = ko_make_with_layers(MOD_MASK_SHIFT, KC_AT,   KC_CIRC, 1 << DVORAK);
const key_override_t bsls_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSLS, KC_HASH, 1 << DVORAK);
const key_override_t pipe_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_PIPE, KC_GRV , 1 << DVORAK);

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


#endif // ENCODER_MAP_ENABLE
