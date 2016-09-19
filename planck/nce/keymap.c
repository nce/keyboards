#include "planck.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  (   | Ctrl | Alt  | GUI  | Bksp | Esc  | Enter| Space| Raise|      |  Up  |  )   |
 * `-----------------------------------------------------------------------------------'
 */
[0] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC},
  {KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J, KC_K,    KC_L,   LT(3,KC_SCLN), KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT },
  {LSFT(KC_9),KC_LCTL,KC_LALT,M(1), KC_BSPC,  KC_ESC,  KC_ENT,   KC_SPC,M(2)   , KC_DOWN, KC_UP, RSFT(KC_0)}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[1] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______},
  {RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[2] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______},
  {RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
},

/* Symbol Layer
 * ,-----------------------------------------------------------------------------------.
 * |      | Mprv | Mply | Mnxt | Wref |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | VolD | VolU | Mute |      |      |      | LEFT | DOWN |  UP  | RGHT |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | PWR  | SLEP |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[3] = {
  {_______, KC_MPRV, KC_MPLY, KC_MNXT, KC_WREF, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______},
  {_______, _______, _______, _______, _______, _______, QWERTY , _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, KC_PWR , KC_SLEP, _______, _______, _______, _______, _______, _______}
},

};

const uint16_t PROGMEM fn_actions[] = {
};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]    = SONG(DVORAK_SOUND);
float tone_raise[][2]    = SONG(SCROLL_LOCK_ON_SOUND);
float tone_lower[][2]    = SONG(SCROLL_LOCK_OFF_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 1:
      if (record->event.pressed) {
        /* #ifdef AUDIO_ENABLE */
        /*   PLAY_NOTE_ARRAY(tone_lower, false, 0); */
        /* #endif */
        layer_on(1);
      } else {
        layer_off(1);
      }
      break;
    case 2:
      if (record->event.pressed) {
        /* #ifdef AUDIO_ENABLE */
        /*   PLAY_NOTE_ARRAY(tone_raise, false, 0); */
        /* #endif */

        layer_on(2);
      } else {
        layer_off(2);
      }
      break;
  }
  return MACRO_NONE;
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
      }
      break;
      return false;
  }
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
