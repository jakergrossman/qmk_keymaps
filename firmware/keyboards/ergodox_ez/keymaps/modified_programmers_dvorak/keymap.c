#include <stdint.h>
#include QMK_KEYBOARD_H
#include "version.h"

#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CUT LCTL(KC_X)
#define TT_NUMP TT(NUMPAD)
#define FN_ESC LT(FN, KC_ESC)
#define OS_FKEY OSL(FKEY)
#define UNDO LCTL(KC_Z)
#define REDO LCTL(LSFT(KC_Z))
#define END_CTL MT(MOD_LCTL, KC_END)

enum layers {
    DVO,
    GAME,
    FN,

    // layers below this do NOT pass through
    NUMPAD,
    FKEY,
};

enum custom_keycodes {
    KC_VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* MODIFED PROGRAMMING DVORAK
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮                    ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │   $ ~  │ + 1  │ [ 2  │ { 3  │ ( 4  │ & 5  │ COPY │                    │ CALC │ = 6  │ ) 7  │ } 8  │ ] 9  │ * 0  │  ! %   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │   /    │   ;  │   ,  │   .  │   P  │   Y  │PASTE │                    │ @ ^  │   F  │   G  │   C  │   R  │   L  │  \ #   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                    │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ FN_ESC │   A  │   O  │   E  │   U  │   I  ├──────┤                    ├──────┤   D  │   H  │   T  │   N  │   S  │    -   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤ CUT  │                    │ | `  ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ LShift │   '  │   Q  │   J  │   K  │   X  │      │                    │      │   B  │   M  │   W  │   V  │   Z  │ RShift │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯                    ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │ FUNC │ F13  │ F14  │ F15  │ F16  │                                                │      │      │      │      │ NUMP │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                                ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮                ╭──────┬────────╮
 *                                        │ LGui │ LAlt │                │ Alt  │  Ctrl  │
 *                                 ╭──────┼──────┼──────┤                ├──────┼────────┼──────╮
 *                                 │      │      │ Home │                │ PgUp │        │      │
 *                                 │Space │ Tab  ├──────┤                ├──────┤  Enter │ Bspc │
 *                                 │      │      │EndCtl│                │ PgDn │        │      │
 *                                 ╰──────┴──────┴──────╯                ╰──────┴────────┴──────╯
 */
[DVO] = LAYOUT_ergodox_pretty(
  // left hand                                                           // right hand
  KC_DLR,  KC_PLUS, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, COPY,            KC_CALC, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_ASTR, KC_EXLM,
  KC_SLSH, KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    PASTE,           KC_AT,   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS,
  FN_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                              KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
  KC_LSFT, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    CUT,             KC_PIPE, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
  OS_FKEY, KC_F13,  KC_F14,  KC_F15,  KC_F16,                                              _______, _______, _______, _______, TT_NUMP,

                                               KC_LGUI, KC_LALT,         KC_RALT, KC_LCTL,
                                                        KC_HOME,         KC_PGUP,
                                      KC_SPC,  KC_TAB,  END_CTL,         KC_PGDN, KC_ENT,  KC_BSPC
),
/* standard dvorak (for games who only intepret the base keys like silly willies)
 * also replaces home with escape so it can be held
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮                    ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │   ~    │   1  │   2  │   3  │   4  │   5  │ COPY │                    │      │   6  │   7  │   8  │   9  │   0  │    =   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │   /    │   ;  │   ,  │   .  │   P  │   Y  │PASTE │                    │   [  │   F  │   G  │   C  │   R  │   L  │    \   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                    │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ FN_ESC │   A  │   O  │   E  │   U  │   I  ├──────┤                    ├──────┤   D  │   H  │   T  │   N  │   S  │    -   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤ CUT  │                    │   ]  ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ LShift │   '  │   Q  │   J  │   K  │   X  │      │                    │      │   B  │   M  │   W  │   V  │   Z  │ RShift │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯                    ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │ FUNC │ F13  │ F14  │ F15  │ F16  │                                                │      │      │      │      │ NUMP │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                                ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮                ╭──────┬────────╮
 *                                        │ LGui │ LAlt │                │ Alt  │  Ctrl  │
 *                                 ╭──────┼──────┼──────┤                ├──────┼────────┼──────╮
 *                                 │      │      │ Esc  │                │ PgUp │        │      │
 *                                 │Space │ Tab  ├──────┤                ├──────┤  Enter │ Bspc │
 *                                 │      │      │EndCtl│                │ PgDn │        │      │
 *                                 ╰──────┴──────┴──────╯                ╰──────┴────────┴──────╯
 */
[GAME] = LAYOUT_ergodox_pretty(
  // left hand                                                           // right hand
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    COPY,            _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL, 
  KC_SLSH, KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    PASTE,           KC_LBRC, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS,
  FN_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                              KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
  KC_LSFT, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    CUT,             KC_RBRC, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
  OS_FKEY, KC_F13,  KC_F14,  KC_F15,  KC_F16,                                              _______, _______, _______, _______, TT_NUMP,

                                               KC_LGUI, KC_LALT,         KC_RALT, KC_LCTL,
                                                        KC_ESC,          KC_PGUP,
                                      KC_SPC,  KC_TAB,  END_CTL,         KC_PGDN, KC_ENT,  KC_BSPC
),

/* FUNCTION
 
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮                    ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │      │      │      │      │      │      │                    │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │ Vol- │ Mute │ Vol+ │ UNDO │ DVO  │                    │      │      │      │      │      │RIGHT │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                    │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │ Prev │ Play │ Next │ REDO ├──────┤                    ├──────┤      │ LEFT │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤ GAME │                    │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │ DOWN │ UP   │ DEL  │      │                    │      │      │      │      │      │      │        │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯                    ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │      │      │      │      │                                                │      │      │      │      │      │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                                ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮                ╭──────┬────────╮
 *                                        │      │      │                │ VRSN │        │
 *                                 ╭──────┼──────┼──────┤                ├──────┼────────┼──────╮
 *                                 │      │      │      │                │      │        │      │
 *                                 │      │      ├──────┤                ├──────┤        │Delete│
 *                                 │      │      │      │                │      │        │      │
 *                                 ╰──────┴──────┴──────╯                ╰──────┴────────┴──────╯
 */
[FN] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, UNDO,    DF(DVO),         _______, _______, _______, _______, _______, KC_RGHT, _______,
  _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, REDO,                              _______, KC_LEFT, _______, _______, _______, _______,
  _______, _______, _______, KC_DOWN, KC_UP,   KC_DEL,  DF(GAME),        _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                             _______, _______, _______, _______, _______,

                                             _______,   _______,         KC_VRSN, _______,
                                                        _______,         _______,
                                      _______, _______, _______,         _______, _______, KC_DEL
),

/* NUMPAD
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮                    ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │      │      │      │      │      │      │                    │      │      │ NMLK │  =   │ /    │  *   │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      │      │                    │      │   ^  │  7   │  8   │  9   │  -   │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                    │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      ├──────┤                    ├──────┤   |  │  4   │  5   │  6   │  +   │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                    │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      │      │                    │      │   &  │  1   │  2   │  3   │ ENT  │        │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯                    ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │      │      │      │      │                                                │  0   │  .   │      │      │      │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                                ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮                ╭──────┬────────╮
 *                                        │      │      │                │      │        │
 *                                 ╭──────┼──────┼──────┤                ├──────┼────────┼──────╮
 *                                 │      │      │      │                │      │        │ Back │
 *                                 │SPACE │      ├──────┤                ├──────┤        │ Space│
 *                                 │      │      │      │                │      │        │      │
 *                                 ╰──────┴──────┴──────╯                ╰──────┴────────┴──────╯
 */
[NUMPAD] = LAYOUT_ergodox_pretty(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, KC_NUM,  KC_PEQL, KC_PSLS, KC_PAST, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, KC_CIRC, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           KC_PIPE, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, KC_AMPR, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             KC_KP_0, KC_PDOT, XXXXXXX, XXXXXXX, TT_NUMP,

                                               XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX,
                                                        XXXXXXX,         XXXXXXX,
                                      KC_SPC,  XXXXXXX, XXXXXXX,         XXXXXXX, KC_ENT,  KC_BSPC
),


/* FKEY
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮                    ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │      │      │      │      │      │      │                    │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │ F9   │ F10  │ F11  │ F12  │      │                    │      │      │ F21  │ F22  │ F23  │ F24  │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                    │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │ F5   │ F6   │ F7   │ F8   ├──────┤                    ├──────┤      │ F17  │ F18  │ F19  │ F20  │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                    │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │ F1   │ F2   │ F3   │ F4   │      │                    │      │      │ F13  │ F14  │ F15  │ F16  │        │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯                    ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │      │      │      │      │                                                │      │      │      │      │      │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                                ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮                ╭──────┬────────╮
 *                                        │      │      │                │      │        │
 *                                 ╭──────┼──────┼──────┤                ├──────┼────────┼──────╮
 *                                 │      │      │      │                │      │        │      │
 *                                 │      │      ├──────┤                ├──────┤        │      │
 *                                 │      │      │      │                │      │        │      │
 *                                 ╰──────┴──────┴──────╯                ╰──────┴────────┴──────╯
 */
[FKEY] = LAYOUT_ergodox_pretty(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,         XXXXXXX, XXXXXXX, KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX,
  XXXXXXX, XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,                             XXXXXXX, KC_F17,  KC_F18,  KC_F19,  KC_F20,  XXXXXXX,
  XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,         XXXXXXX, XXXXXXX, KC_F13,  KC_F14,  KC_F15,  KC_F16,  XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                                               XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX,
                                                        XXXXXXX,         XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX
),

};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KC_VRSN:
                SEND_STRING(QMK_VERSION ", Compiled: " __DATE__ ", " __TIME__);
                return false;
        }
    }
    return true;
}

void matrix_scan_user(void) {
    ergodox_led_all_off();
    switch (biton32(layer_state)) {
        case NUMPAD:
            ergodox_right_led_1_on();
            if (host_keyboard_led_state().num_lock) {
                ergodox_right_led_3_on();
            }
            break;
        case FN:
            ergodox_right_led_2_on();
            break;
        case FKEY:
            ergodox_led_all_on();
            break;
        default:
            if (get_highest_layer(default_layer_state) == GAME) {
                ergodox_right_led_3_on();
            }
            break;
    }


    if (is_caps_word_on()) {
        ergodox_led_all_on();
    }
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

bool caps_word_press_user(uint16_t keycode) {
    if (keycode == KC_RCBR || keycode == KC_LCBR) {
        add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
        return true;
    }

    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
        case KC_PLUS:
        case KC_LBRC:
        case KC_LPRN:
        case KC_AMPR:
        case KC_EQL:
        case KC_RPRN:
        case KC_RBRC:
        case KC_ASTR:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_DOT:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }

}
