#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _WORKMAN 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  WORKMAN
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * .-----------------------------------------.   .-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |  ;   |  '   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |Lower |   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  |Raise |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Ctrl | Ctrl |      | Alt  | Cmd  |Shift |   |Space |Bksp  |Enter |      |      |      |
 * '-----------------------------------------'   '-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS, \
   KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,      KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, \
   LOWER  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,      KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, RAISE  , \
   KC_LCTL, KC_LCTL, _______, KC_LALT, KC_LGUI, KC_LSFT,      KC_SPC , KC_BSPC, KC_ENT , _______, _______, _______  \
),

[_WORKMAN] = LAYOUT_ortho_4x12(
   KC_TAB , KC_Q   , KC_D   , KC_R   , KC_W   , KC_B   ,      KC_J   , KC_F   , KC_U   , KC_P   , KC_SCLN, KC_MINS, \
   KC_ESC , KC_A   , KC_S   , KC_H   , KC_T   , KC_G   ,      KC_Y   , KC_N   , KC_E   , KC_O   , KC_I   , KC_QUOT, \
   LOWER  , KC_Z   , KC_X   , KC_M   , KC_C   , KC_V   ,      KC_K   , KC_L   , KC_COMM, KC_DOT , KC_SLSH, RAISE  , \
   KC_LCTL, KC_LCTL, _______, KC_LALT, KC_LGUI, KC_LSFT,      KC_SPC , KC_BSPC, KC_ENT , _______, _______, _______  \
),

/* Lower
 * .-----------------------------------------.  .-----------------------------------------.
 * | Term |      | PgUp |  Up  | PgDn |      |  |      |   7  |   8  |   9  |   :  |  -   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      | Home | Left | Down |Right | End  |  |   =  |   4  |   5  |   6  |   0  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |   ,  |   1  |   2  |   3  |   .  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * '-----------------------------------------'  '-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
C(KC_GRV), XXXXXXX, KC_PGUP, KC_UP  , KC_PGDN, XXXXXXX,       XXXXXXX, KC_7   , KC_8   , KC_9   , KC_COLN, KC_MINS, \
  XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END ,       KC_EQL , KC_4   , KC_5   , KC_6   , KC_0   , XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_COMM, KC_1   , KC_2   , KC_3   , KC_PDOT, _______, \
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______  \
),

/* Raise
 * .-----------------------------------------.  .-----------------------------------------.
 * |   `  |  !   |  @   |  #   |  $   |  %   |  |  ^   |  &   |  *   |      |      |  =   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |  (   |   )  |      |  |      |   [  |   ]  |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |   \  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * '-----------------------------------------'  '-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV , S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),     S(KC_6), S(KC_7), S(KC_8), XXXXXXX, XXXXXXX, KC_EQL , \
  XXXXXXX, KC_GRV , XXXXXXX, S(KC_9), S(KC_0), XXXXXXX,     XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, _______, \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______  \
),

/* Adjust (Lower + Raise)
 * .-----------------------------------------.  .-----------------------------------------.
 * | Reset| F1   | F2   | F3   | F4   | F5   |  | F6   | F7   | F8   | F9   | F10  |Qwerty|
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      | F11  | F12  |      |      |      |  | Mute | Vol- | Vol+ | Br-  | Br+  |Worknm|
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  | |<<  | Play | >>|  |      |      |      |
 * |------+------+------+------+------+------|  +------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * '-----------------------------------------'  '-----------------------------------------'
 */
// keep alt around, for option-volume, in case i ever, ever press that
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,       KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , QWERTY , \
  XXXXXXX, KC_F11 , KC_F12 , XXXXXXX, XXXXXXX, XXXXXXX,       KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, WORKMAN, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
  }
  return true;
}
