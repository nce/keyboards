#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#include "keymap_german.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

// Define macros for german umlauts
#define MAE 1
#define MUE 2
#define MOE 3
#define MSS 4
#define MEURO 5
#define MTILD 6



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |  =   |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '    |
 * |--------+------+------+------+------+------|   [  |           |   ]  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |   {  |           |   }  |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  (   |      |  ~   |  '"  | Lgui |                                       | Alt  |      |      |      |  )   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | Del  |      |       |     |Ctrl/Esc|
 *                                 ,------|------|------|       |------+-------+-------.
 *                                 |      |      | Home |       | MDIA |       |       |
 *                                 | Back |  Esc |------|       |------| Enter | Space |
 *                                 | spac |      |  -   |       |   =  |       |       |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,     KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_EQL,
        KC_TAB,     KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   MO(SYMB),
        KC_LCTL,    KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,    KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_LBRC,
        LSFT(KC_9),    KC_TRNS,   M(MTILD), KC_QUOT,KC_LGUI,
                                                        KC_DEL, KC_LALT,
                                                              KC_HOME,
                                                    KC_BSPC,KC_ESC,KC_MINS,
        // right hand
        KC_RGHT,    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
        MO(SYMB),   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                    KC_H,   KC_J,   KC_K,   KC_L,   LT(SYMB, KC_SCLN),KC_QUOT,
        KC_RBRC,    KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSFT,
                    KC_LALT,KC_TAB, KC_TRNS,KC_TRNS,          RSFT(KC_0),
        KC_TRNS,    CTL_T(KC_ESC),
        MO(MDIA),
        KC_EQL,KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | MPrv | MPly | Mnxt | Wref |      |      |           |      |      |  ü   |      |  ö   |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  ä   |  ß   |  €   |      |      |------|           |------| Left | Down |  Up  | Rght |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | VolD | VolU | Mute |      |      |      |           |      |      | Mail |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      | PWR  |------|       |------| POWER|      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       M(0),   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_MPRV,KC_MPLY,KC_MNXT,KC_WREF,KC_TRNS,KC_TRNS,
       KC_TRNS,M(MAE) ,M(MSS) ,M(MEURO),KC_TRNS,KC_TRNS,
       KC_TRNS,KC_VOLD,KC_VOLU,KC_MUTE,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_PWR,KC_TRNS,
       // right hand
       KC_TRNS,KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
       KC_TRNS,KC_TRNS,M(MUE) ,KC_TRNS,M(MOE) ,KC_TRNS,KC_F12,
               KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_MAIL,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,
       KC_TRNS,
       KC_TRNS,KC_POWER,KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

enum macro_id {
  UE,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        case MUE:
          return (record->event.pressed ? MACRO( D(LALT), T(U), U(LALT), T(U), END ) :
              MACRO( END ) );
        case MAE:
          return (record->event.pressed ? MACRO( D(LALT), T(U), U(LALT), T(A), END ) :
              MACRO( END ) );
        case MOE:
          return (record->event.pressed ? MACRO( D(LALT), T(U), U(LALT), T(O), END ) :
              MACRO( END ) );
        case MSS:
          return (record->event.pressed ? MACRO( D(LALT), T(S), U(LALT), END ) :
              MACRO( END ) );
        case MEURO:
          return (record->event.pressed ? MACRO( D(LALT), D(LSFT), T(2), U(LALT), U(LSFT), END ) :
              MACRO( END ) );
        case MTILD:
          return (record->event.pressed ? MACRO( D(LSFT), T(GRV), U(LSFT), T(SPC),END ) :
              MACRO( END ) );

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
