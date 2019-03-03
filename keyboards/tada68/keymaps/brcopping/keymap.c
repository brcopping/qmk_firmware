#include QMK_KEYBOARD_H

#define _BL 0
#define _FL 1

#define _______ KC_TRNS

enum custom_keycodes {
    M_LCS = SAFE_RANGE,
	M_CLR
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case M_LCS:
                SEND_STRING(SS_TAP(X_END)", "SS_TAP(X_DELETE));
                return false;
            case M_CLR:
                SEND_STRING(SS_LCTRL("a") SS_TAP(X_DELETE));
                return false;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Home|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     |End |
   * |-------------------------------------------------------    -----|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;| '|  #|Entr|PgUp|
   * |----------------------------------------------------------------|
   * |Shift|  \ |  Z|  X|  C|  V|  B|  N|  M|  ,|  .| /|Rshift|Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
  [_BL] = LAYOUT_iso(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_END,  \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_PGUP, \
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN, \
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(_FL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
	),

  /* Keymap _FL1: Function Layer 1
   * ,----------------------------------------------------------------.
   * | Ins | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| Del |~ ` |
   * |----------------------------------------------------------------|
   * |     |   |   |   |    |   |   |   |   |   |   |   |   |    |    |
   * |-------------------------------------------------------    -----|
   * |       |   |   |   |   |   |   |   |   |   |   |   |   |   |    |
   * |----------------------------------------------------------------|
   * |     |   |   |   |Cal|   |   |   |Mute|   |   |   |    | Up|    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    | Lt| Dn| Rt |
   * `----------------------------------------------------------------'
   */
  [_FL] = LAYOUT_iso(
     KC_INS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_DEL,  KC_GRV, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, KC_CALC, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, KC_MS_U, _______, \
    _______, _______, _______,                   _______,                            _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
	),
};
