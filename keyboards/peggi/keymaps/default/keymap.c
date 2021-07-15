#include QMK_KEYBOARD_H
#include "print.h"

#define SPACE 6
#define MODIFIER 7

const uint16_t keyMap[6][6] = {
  { KC_HASH,  KC_T,  KC_A,     KC_W,       KC_Z,     KC_X    },
  { KC_Y,     KC_AT, KC_I,     KC_J,       KC_U,     KC_B    },
  { KC_D,     KC_G,  KC_AMPR,  KC_H,       KC_P,     KC_M    },
  { KC_F,     KC_Q,  KC_MINUS, KC_EXCLAIM, KC_S,     KC_R    },
  { KC_COMMA, KC_C,  KC_QUOT,  KC_DOT,     KC_SLASH, KC_E    },
  { KC_V,     KC_K,  KC_O,     KC_L,       KC_N,     KC_QUES },
};

const uint16_t altKeyMap[6][6] = { 
  { KC_NO, KC_NO,    KC_NO,   KC_NO, KC_NO, KC_NO   },
  { KC_NO, KC_NO,    KC_LPRN, KC_NO, KC_NO, KC_NO   },
  { KC_NO, KC_ENTER, KC_NO,   KC_NO, KC_NO, KC_NO   },
  { KC_NO, KC_NO,    KC_NO,   KC_NO, KC_NO, KC_NO   },
  { KC_NO, KC_NO,    KC_NO,   KC_NO, KC_NO, KC_RPRN },
  { KC_NO, KC_NO,    KC_NO,   KC_NO, KC_NO, KC_NO   },
};

static uint16_t last_keypress = 0;
static int8_t index = -1;
static bool caps = false;
static bool modifier_held = false;

static uint16_t unregister[8] = {
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
};

void press(uint16_t input, uint16_t keycode) {
  unregister[input] = keycode;
  register_code16(keycode);
  uprintf("registering %u\n", keycode);
}

void clear_state(void) {
  index = -1;
  caps = false;
}

uint16_t capitalize(uint16_t keycode) {
  if (keycode >= KC_A && keycode <= KC_Z) {
    return S(keycode);
  }
  switch (keycode) {
    case KC_QUOT: return KC_DOUBLE_QUOTE;
    case KC_COMMA: return KC_SCOLON;
    case KC_DOT: return KC_COLON;
    case KC_MINUS: return KC_UNDERSCORE;
  }
  return keycode;
}

bool process_record_user(uint16_t input, keyrecord_t *record) {
  if (input == MODIFIER) {
    if (record->event.pressed) { 
      modifier_held = true;
      clear_state();
    } else {
      modifier_held = false;
    }
    return false;
  }

  if (!record->event.pressed) {
    if (unregister[input] != KC_NO) {
      unregister_code16(unregister[input]);
      unregister[input] = KC_NO;
    }

    return false;
  }

  if (timer_elapsed(last_keypress) > 2000) {
    if (index != -1) {
      print("expiring\n");
    }
    clear_state();
  }

  switch (input) {
    case SPACE:
      clear_state();
      if (modifier_held) {
        press(input, KC_BSPACE);
      } else {
        press(input, KC_SPACE);
      }
      break;
    case MODIFIER: break;
    default:
      if (index == -1) {
        index = input;
      } else if (index == input && !caps && !modifier_held) {
        caps = true;
      } else {
        uint16_t keycode;
        if (modifier_held) {
          keycode = altKeyMap[index][input];
        } else {
          keycode = keyMap[index][input];
          if (caps) {
            keycode = capitalize(keycode);
          }
        }
        uprintf("index=%u input=%u keycode=%u\n", index, input, keycode);
        press(input, keycode);
        clear_state();
      }
      break;
  }

  last_keypress = timer_read();
  return false;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT_peggi(2, 1, 0, SPACE,
               5, 4, 3, MODIFIER)
};
