#include QMK_KEYBOARD_H

#include "sendstring_japanese.h"

enum layer_number {
    _BASE = 0,
    _LOWER,
    _RAISE,
};

#define ALTF13 LALT_T(KC_F13)
#define ALTF14 RALT_T(KC_F14)
#define LOWER TT(_LOWER)
#define MOD_MASK_LSHIFT MOD_BIT(KC_LSFT)
#define MOD_MASK_RSHIFT MOD_BIT(KC_RSFT)
#define RECT_PR LWIN(LSFT(KC_S))
#define WIND_PR LALT(KC_PSCR)

#define CK_JP_AT KC_LBRC
#define CK_JP_CR KC_EQUAL
#define CK_JP_CL KC_QUOTE
#define CK_JP_AND KC_6
#define CK_JP_AST KC_QUOTE
#define CK_JP_LPR KC_8
#define CK_JP_RPR KC_9
#define CK_JP_UB KC_INT1
#define CK_JP_SQ KC_7
#define CK_JP_DQ KC_2
#define CK_JP_EQ KC_MINS
#define CK_JP_PL KC_SCLN
#define CK_JP_GR KC_LBRC
#define CK_JP_TL KC_EQL

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

enum custom_keycodes {
    CK_2AT = SAFE_RANGE, // 2 and @ NS NS
    CK_6CR,              // 6 and ^ NS NS
    CK_7AND,             // 7 and & NS S
    CK_8AST,             // 8 and * NS S
    CK_9LPR,             // 9 and ( NS S
    CK_0RPR,             // 0 and ) NS S
    CK_SCCL,             // ; and : NS NS
    CK_MNUB,             // - and _ NS S
    CK_SQDQ,             // ' and " S S
    CK_EQPL,             // = and + S S
    CK_GRTL,             // ` and ~ S S
    CK_HELP,             // Print Help
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT( \
        KC_ESC,  KC_1,    CK_2AT,  KC_3,    KC_4,    KC_5,       CK_6CR,  CK_7AND, CK_8AST, CK_9LPR, CK_0RPR, CK_MNUB, CK_EQPL, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_LBRC, JP_RBRC, \
        LOWER,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    CK_SCCL, CK_SQDQ, KC_ENT,  \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, JP_YEN,  KC_RSFT, \
        KC_LCTL, KC_LGUI, LOWER,   ALTF13,           KC_SPC,     XXXXXXX,          ALTF14,           LOWER,            KC_BSPC  \
        ),

    [_LOWER] =  LAYOUT( \
        CK_GRTL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
        _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______,    _______, _______, KC_INS,  _______, KC_PSCR, KC_F16,  KC_F17,  \
        _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, \
        _______, RECT_PR, WIND_PR, _______, _______, KC_BRK,     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_F15,  _______, \
        _______, _______, _______, _______,          _______,    _______,          _______,          _______,          KC_DEL   \
        ),

    [_RAISE] =  LAYOUT( \
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    CK_HELP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        KC_LSFT, KC_CAPS, KC_SCRL, KC_NUM,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, _______, XXXXXXX,          XXXXXXX,    XXXXXXX,          XXXXXXX,          _______,          XXXXXXX  \
        )
};
// clang-format on

#define KEYMAP_HELP \
    "BASE \n\
,-----------------------------------------.      ,------------------------------------------------.\n\
| Esc  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   -  |   =  |\n\
|------+------+------+------+------+------|      |------+------+------+------+------+------+------|\n\
| Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |\n\
|------+------+------+------+------+------|      |------+------+------+------+------+------+------|\n\
| Lower|   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |   \"  | Enter|\n\
|------+------+------+------+------+------|      |------+------+------+------+------+------+------|\n\
| Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  |   \\  | Shift|\n\
|------+------+------+------+------+------|      |------+------+------+------+------+------+------|\n\
| Ctrl |  Win | Lower|AltF13|      | Space|      | Space|      |AltF14|      | Lower|      | Bksp |\n\
`-----------------------------------------'      `------------------------------------------------'\n\
\n\
LOWER \n\
,-----------------------------------------.      ,------------------------------------------------.\n\
|  ` ~ |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |\n\
|------+------+------+------+------+------|      |------+------+------+------+------+------+------|\n\
|      |LClick|  MUp |RClick| WhUp |      |      |      |      |Insert|      | PrtSc|  F16 |  F17 |\n\
|------+------+------+------+------+------|      |------+------+------+------+------+------+------|\n\
|      | MLeft| MDown|MRight| WhDn |      |      | Left | Down |  Up  | Right|      |      |      |\n\
|------+------+------+------+------+------|      |------+------+------+------+------+------+------|\n\
|      |RectPr|WindPr|      |      | Break|      | Home | PgDn | PgUp |  End |      |  F15 |      |\n\
|------+------+------+------+------+------|      |------+------+------+------+------+------+------|\n\
|      |      |      |      |      |      |      |      |      |      |      |      |      | Del  |\n\
`-----------------------------------------'      `------------------------------------------------'\n\
\n\
RAISE \n\
,-----------------------------------------.      ,------------------------------------------------.\n\
| RESET|      |      |      |      |      |      |      |      |      |      |      |      |      |\n\
|------+------+------+------+------+------|      |------+------+------+------+------+------+------|\n\
|      |      |      |      |      |      |      |      |      |      |      |      |      |      |\n\
|------+------+------+------+------+------|      |------+------+------+------+------+------+------|\n\
|      |      |      |      |      |      |      | Help |      |      |      |      |      |      |\n\
|------+------+------+------+------+------|      |------+------+------+------+------+------+------|\n\
|      |CapsLk| ScrLk| NumLk|      |      |      |      |      |      |      |      |      |      |\n\
|------+------+------+------+------+------|      |------+------+------+------+------+------+------|\n\
|      |      |      |      |      |      |      |      |      |      |      |      |      |      |\n\
`-----------------------------------------'      `------------------------------------------------'\n"

int lower_pressed_count;

void keyboard_post_init_user(void) {
    lower_pressed_count = 0;
}

/**
 * この関数は、シフトキーが押されている場合はs_keyを送信します。
 * シフトキーが押されていない場合は、ns_keyを送信します。
 *
 * イベントが押下の場合:
 *   シフトキーが押されている場合は、シフトなしでs_key押下を送信したあと、シフトの状態を戻します。
 *   シフトキーが押されていない場合は、ns_key押下を送信します。
 * イベントが押上の場合:
 *   ns_keyの押上をそのまま送信します。
 */
void handle_ns_ns(uint16_t ns_key, uint16_t s_key, keyrecord_t *record) {
    uint8_t mod = get_mods();
    if (record->event.pressed) {
        if (mod & MOD_MASK_SHIFT) {
            if (mod & MOD_MASK_LSHIFT) {
                unregister_code(KC_LSFT);
            }
            if (mod & MOD_MASK_RSHIFT) {
                unregister_code(KC_RSFT);
            }
            tap_code(s_key);
            if (mod & MOD_MASK_LSHIFT) {
                register_code(KC_LSFT);
            }
            if (mod & MOD_MASK_RSHIFT) {
                register_code(KC_RSFT);
            }
        } else {
            register_code(ns_key);
        }
    } else {
        unregister_code(ns_key);
    }
}

/**
 * この関数は、シフトキーが押されている場合はs_keyを送信します。
 * シフトキーが押されていない場合はns_keyを送信します。
 *
 * イベントが押下の場合:
 *   シフトキーが押されている場合は、s_key押下、s_key押上を送信します。
 *   シフトキーが押されていない場合は、ns_key押下を送信します。
 * イベントが押上の場合:
 *   ns_keyの押上をそのまま送信します。
 */
void handle_ns_s(uint16_t ns_key, uint16_t s_key, keyrecord_t *record) {
    uint8_t mod = get_mods();
    if (record->event.pressed) {
        if (mod & MOD_MASK_SHIFT) {
            tap_code(s_key);
        } else {
            register_code(ns_key);
        }
    } else {
        unregister_code(ns_key);
    }
}

/**
 * この関数は、シフトキーが押されている場合はs_keyを送信します。
 * シフトキーが押されていない場合は、一時的にシフトキーを押してns_keyを送信します。
 *
 * イベントが押下の場合:
 *   シフトキーが押されている場合は、s_key押下、s_key押上を送信します。
 *   シフトキーが押されていない場合は、シフトありでns_key押下を送信したあと、シフトの状態を戻します。
 * イベントが押上の場合:
 *   何もしません。
 */
void handle_s_s(uint16_t ns_key, uint16_t s_key, keyrecord_t *record) {
    uint8_t mod = get_mods();
    if (record->event.pressed) {
        if (mod & MOD_MASK_SHIFT) {
            tap_code(s_key);
        } else {
            register_code(KC_LSFT);
            tap_code(ns_key);
            unregister_code(KC_LSFT);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_2AT:
            handle_ns_ns(KC_2, CK_JP_AT, record);
            return true;
        case CK_6CR:
            handle_ns_ns(KC_6, CK_JP_CR, record);
            return true;
        case CK_7AND:
            handle_ns_s(KC_7, CK_JP_AND, record);
            return true;
        case CK_8AST:
            handle_ns_s(KC_8, CK_JP_AST, record);
            return true;
        case CK_9LPR:
            handle_ns_s(KC_9, CK_JP_LPR, record);
            return true;
        case CK_0RPR:
            handle_ns_s(KC_0, CK_JP_RPR, record);
            return true;
        case CK_SCCL:
            handle_ns_ns(KC_SEMICOLON, CK_JP_CL, record);
            return true;
        case CK_MNUB:
            handle_ns_s(KC_MINUS, CK_JP_UB, record);
            return true;
        case CK_SQDQ:
            handle_s_s(CK_JP_SQ, CK_JP_DQ, record);
            return true;
        case CK_EQPL:
            handle_s_s(CK_JP_EQ, CK_JP_PL, record);
            return true;
        case CK_GRTL:
            handle_s_s(CK_JP_GR, CK_JP_TL, record);
            return true;

        case CK_HELP:
            if (record->event.pressed) {
                SEND_STRING(KEYMAP_HELP);
            }
            return true;

        case LOWER:
            if (record->event.pressed) {
                lower_pressed_count++;
            } else {
                lower_pressed_count--;
            }
            lower_pressed_count = max(min(lower_pressed_count, 3), 0);

            if (lower_pressed_count >= 2) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return true;

        default:
            return true;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALTF13:
        case ALTF14:
            return TAPPING_TERM * 2;
        default:
            return TAPPING_TERM;
    }
}
