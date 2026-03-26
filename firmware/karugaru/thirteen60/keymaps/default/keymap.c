#include QMK_KEYBOARD_H

enum layer_number
{
    _BASE = 0,
    _LOWER,
};

#define LOWER TT(_LOWER)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT( \
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, \
        LOWER,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, KC_RSFT, \
        KC_LCTL, KC_LGUI, LOWER,   KC_LALT,          KC_SPC,     XXXXXXX,          KC_RALT,          LOWER,            KC_BSPC  \
        ),

    [_LOWER] =  LAYOUT( \
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
        _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______,    _______, _______, KC_INS,  _______, KC_PSCR, _______, _______, \
        _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, \
        _______, KC_CAPS, KC_SCRL, KC_NUM,  _______, QK_BOOT,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______, \
        _______, _______, _______, _______,          _______,    _______,          _______,          _______,          KC_DEL   \
        )
};
// clang-format on
