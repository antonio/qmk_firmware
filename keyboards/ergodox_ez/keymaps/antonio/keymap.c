#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0
#define GAMES 1
#define ACCENTS 2
#define MOVEMENT 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * TODO: gaming layer, vim movement layers, accents modifier
 * Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `~   |   1  |   2  |   3  |   4  |   5  |  6   |           |   7  |   8  |   9  |   0  |   -  |   =  | Bckspc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \|   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;:  |Ctrl/'" |
 * |--------+------+------+------+------+------|  [{  |           |  ]}  |------+------+------+------+------+--------|
 * |LShift/(|   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  ,<  |  .>  |  /?  |RShift/)|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |C-S-T | LAlt |                                       |ACCNTS| C-T  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |LGui  |MOVMNT|------|       |------| Enter  | Space|
 *                                 |Space |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRAVE,       KC_1,        KC_2,   KC_3,   KC_4,     KC_5,   KC_6,
        KC_TAB,         KC_Q,        KC_W,   KC_E,   KC_R,     KC_T,   KC_LBRC,
        CTL_T(KC_ESC),  KC_A,        KC_S,   KC_D,   KC_F,     KC_G,
        KC_LSPO,        KC_Z,        KC_X,   KC_C,   KC_V,     KC_B,   KC_NO,
        KC_NO,          KC_NO,       KC_NO,  LCTL(S(KC_TAB)),  KC_LALT,
        KC_NO,          KC_NO,
        KC_NO,
        GUI_T(KC_SPACE),TG(MOVEMENT),KC_NO,
        // right hand
        KC_7,        KC_8,           KC_9,   KC_0,   KC_9,     KC_0,            KC_MINS, KC_EQUAL, KC_BSPC,
        KC_RBRC,     KC_Y,           KC_U,   KC_I,   KC_O,     KC_P,            KC_BSLS,
        KC_H,        KC_J,           KC_K,   KC_L,   KC_SCLN,  CTL_T(KC_QUOT),
        KC_NO,       KC_N,           KC_M,   KC_COMM,KC_DOT,   KC_SLSH,         KC_RSPO,
        TG(ACCENTS), LCTL(KC_TAB),   KC_NO,  KC_NO,  KC_NO,
        KC_NO,       KC_NO,
        KC_NO,
        KC_NO,       KC_ENT,         KC_SPC
    ),

/* Keymap Z: Transparent layer to make it easier to write new layers
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |------|           |------|      |      |      |      |      |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |      |      |      |      |      |                                       |      |      |      |      |      |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |      |      |           |      |      |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      |      |           |      |      |      |
 *                                  |      |      |------|           |------|      |      |
 *                                  |      |      |      |           |      |      |      |
 *                                  `--------------------'           `--------------------'
 */

[TRANS] = KEYMAP(
// left hand
 KC_TRNS ,KC_TRNS    ,KC_TRNS   ,KC_TRNS    ,KC_TRNS    ,KC_TRNS    ,KC_TRNS
,KC_TRNS ,KC_TRNS    ,KC_TRNS   ,KC_TRNS    ,KC_TRNS    ,KC_TRNS    ,KC_TRNS
,KC_TRNS ,KC_TRNS    ,KC_TRNS   ,KC_TRNS    ,KC_TRNS    ,KC_TRNS
,KC_TRNS ,KC_TRNS    ,KC_TRNS   ,KC_TRNS    ,KC_TRNS    ,KC_TRNS    ,KC_TRNS
,KC_TRNS ,KC_TRNS    ,KC_TRNS   ,KC_TRNS    ,KC_TRNS

                                             ,KC_TRNS ,KC_TRNS
                                                      ,KC_TRNS
                                    ,KC_TRNS ,KC_TRNS ,KC_TRNS

                                                                // right hand
                                                               ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                               ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                                        ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                               ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                                                 ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS

                                                               ,KC_TRNS ,KC_TRNS
                                                               ,KC_TRNS
                                                               ,KC_TRNS ,KC_TRNS ,KC_TRNS
    )
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
