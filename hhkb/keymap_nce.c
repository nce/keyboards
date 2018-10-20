/*
 * HHKB Layout
 */
#include "hhkb.h"

#define BASE 0
#define FN 1

/*
 *  * Macro definition
 *   */
enum macro_id {
      AE,
      OE,
      UE,
      SS,
			XML
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn0|
     * `-----------------------------------------------------------'
     *       |Alt|Gui  |         Space         |Gui  |Alt|
     *       `-------------------------------------------'
     */
   [BASE] = KEYMAP(KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSLS,KC_GRV,   \
           KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSPC,       \
           KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L, LT(FN, KC_SCLN),KC_QUOT,KC_ENT,             \
           KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,MT(MOD_LCTL | KC_A, FN),             \
                KC_LGUI,KC_LALT,          KC_SPC,                KC_RALT,KC_RGUI),

    /* Layer 1: HHKB mode (HHKB Fn)
     * ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   |Del  |
     * |-----------------------------------------------------------|
     * |      |VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |  +|  -|End|PgD|Dow|      |   |
     * `-----------------------------------------------------------'
     *       |   |     |                       |     |   |
     *       `-------------------------------------------'
     */
   [FN] =  KEYMAP(LALT(LCTL(KC_DEL)), KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,   \
           M(XML),KC_VOLD,KC_VOLU,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,M(UE),KC_TRNS,M(OE),KC_TRNS,KC_TRNS,KC_TRNS, KC_DEL,      \
           KC_TRNS,M(AE)  ,M(SS),KC_MUTE,KC_TRNS,KC_TRNS,KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,KC_TRNS,KC_TRNS,KC_PENT,            \
           KC_TRNS,KC_VOLD,KC_MUTE,KC_VOLU,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,            \
                KC_TRNS,KC_TRNS,          KC_TRNS,               KC_TRNS,KC_TRNS),
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;
    //uint8_t tap_count = record->tap_count;

    switch (id) {
        case SS:
            return (event.pressed ?
                    MACRO( D(LALT), T(P0), T(P2), T(P2), T(P3), END ) :
                    MACRO( END ) );
        case AE:
            return (event.pressed ?
                    MACRO( D(LALT), T(P0), T(P2), T(P2), T(P8), END ) :
                    MACRO( END ) );
        case UE:
            return (event.pressed ?
                    MACRO( D(LALT), T(P0), T(P2), T(P5), T(P2), END ) :
                    MACRO( END ) );
        case OE:
            return (event.pressed ?
                    MACRO( D(LALT), T(P0), T(P2), T(P4), T(P6), END ) :
                    MACRO( END ) );
        case XML:
						SEND_STRING(":%!xmllint --format -");
						return false;
    }
    return MACRO_NONE;
}



const uint16_t fn_actions[] PROGMEM = {
    [0] = ACTION_LAYER_MOMENTARY(1),          // FN0
    /* Turn on layer 1 while pressing ; for a longer time */
    //[1] = ACTION_LAYER_TAP_KEY(1, KC_SCLN)    // FN1
		/* [1] = ACTION_MACRO(SS), */
		/* [2] = ACTION_MACRO(AE), */
		/* [3] = ACTION_MACRO(UE), */
		/* [4] = ACTION_MACRO(OE), */

};
