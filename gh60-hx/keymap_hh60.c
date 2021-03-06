#include "keymap_common.h"

/*
 * HHKB Layout on a default 60% keyboard
 */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: Default layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \    |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Bspc |
     * |-----------------------------------------------------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|Fn1|  '|Return  |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
     * |-----------------------------------------------------------|
     * |Ctrl|Alt |Gui |      Space             |Gui |Alt |Fn0 |Ctrl|
     * `-----------------------------------------------------------'
     */
    KEYMAP_ANSI(
         ESC,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,BSLS, \
         TAB,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,BSPC, \
        LCTL,   A,   S,   D,   F,   G,   H,   J,   K,   L, FN1,QUOT, ENT,      \
        LSFT,   Z,   X,   C,   V,   B,   N,   M,     COMM, DOT,SLSH,RSFT,      \
        LCTL, FN0,LGUI,          SPC,                     RGUI,RALT, FN0,RCTL),
    /* 1: HHKB Fn layer
     * ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   |     |
     * |-----------------------------------------------------------|
     * |      |VoD|VoU|Mut|Ejc|   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |  +|  -|End|PgD|Dow|      |   |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    KEYMAP_ANSI(
         PWR,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12, DEL, \
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,  UP,TRNS, GRV, \
        TRNS,VOLD,VOLU,MUTE,EJCT,TRNS,LEFT,DOWN,  UP,RGHT,TRNS,TRNS,PENT,      \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS, END,PGDN,DOWN,     TRNS,      \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    /* Turn on layer 1 while holding down key */
    ACTION_LAYER_MOMENTARY(1),          // FN0
    /* Turn on layer 1 while pressing ; for a longer time */
    ACTION_LAYER_TAP_KEY(1, KC_SCLN)    // FN0
};
