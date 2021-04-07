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
#define COLON  S(KC_SCOLON)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * .-----------------------------------------.   .-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |  ;   |  '   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |Lower |   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  |Raise |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Ctl  | Ctl  |      | Alt  | Cmd  |Shift |   |Space |Bksp  | Ret  |      |      |      |
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
 * |      |      | PgUp |  Up  | PgDn |      |  |      |   7  |   8  |   9  |   :  |  -   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      | Home | Left | Down |Right | End  |  |   =  |   4  |   5  |   6  |   0  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |   ,  |   1  |   2  |   3  |   .  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * '-----------------------------------------'  '-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  XXXXXXX, XXXXXXX, KC_PGUP, KC_UP  , KC_PGDN, XXXXXXX,       XXXXXXX, KC_7   , KC_8   , KC_9   , COLON  , KC_MINS, \
  XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END ,       KC_EQL , KC_4   , KC_5   , KC_6   , KC_0   , XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_COMM, KC_1   , KC_2   , KC_3   , KC_PDOT, _______, \
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______  \
),

/* Raise
 * .-----------------------------------------.  .-----------------------------------------.
 * |   `  |  !   |  @   |  #   |  $   |  %   |  |  ^   |  &   |  *   |      |      |  =   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |  (   |   )  |      |  |      |   [  |   ]  |   \  |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * '-----------------------------------------'  '-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV , S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),     S(KC_6), S(KC_7), S(KC_8), XXXXXXX, XXXXXXX, KC_EQL , \
  XXXXXXX, KC_GRV , XXXXXXX, S(KC_9), S(KC_0), XXXXXXX,     XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______  \
),

/* Adjust (Lower + Raise)
 * .-----------------------------------------.  .-----------------------------------------.
 * | Reset|      |      |      |      |      |  | |<<  | Play | >>|  |      |      |Qwerty|
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  | Mute | Vol- | Vol+ |      |      |Worknm|
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  +------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * '-----------------------------------------'  '-----------------------------------------'
 */
// keep alt around, for option-volume, in case i ever, ever press that
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, QWERTY , \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, WORKMAN, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
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
