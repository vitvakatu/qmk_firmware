#include QMK_KEYBOARD_H
#include "version.h"

#include "oneshot.h"
#include "swapper.h"

#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)

#define TAB_L C(S(KC_TAB))
#define TAB_R C(KC_TAB)
#define RAYCAST LCMD(KC_SPACE)
#define PRSCR LCMD(S(KC_4))

enum layers {
    _BASE,  // default layer
    _SYM,  // symbols
    _NAV,  // navigation
	_NUM, // numbers
};

enum custom_keycodes {
  OS_SHFT = SAFE_RANGE,
  OS_CTRL,
  OS_ALT,
  OS_CMD,

  SW_WIN,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.              ,--------------------------------------------------.
 * |   ESC  |      |      |      |      |      |      |              | RESET|      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|              |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |              |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |              |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|              |------|   H  |   J  |   K  |   L  |  ;   |        |
 * |--------+------+------+------+------+------|      |              |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |              |      |   N  |   M  |   [  |   ]  |  /   |        |
 * `--------+------+------+------+------+-------------'              `-------------+------+------+------+------+--------'
 *   |      |      |      | LNG  | SPACE|                                          |SPACE | RALT |      |      |      |
 *   `----------------------------------'                                          `----------------------------------'
 *                                        ,----------------.       ,-------------.
 *                                        |      | Raycast |       | Vol+ | Vol- |
 *                                 ,------|------|---------|       |------+--------+------.
 *                                 |      |      |         |       |      |        |      |
 *                                 | NAV  | Shift|---------|       |------|  Shift |  SYM |
 *                                 |      |      |         |       |      |        |      |
 *                                 `-----------------------'       `----------------------'
 */
[_BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,          KC_NO,       KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,                QK_BOOTLOADER,      KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
  KC_NO,           KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_NO,                KC_NO,              KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_NO,
  KC_NO,           KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                              KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_NO,
  KC_NO,           KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    KC_NO,                KC_NO,              KC_N,    KC_M,    KC_LBRC, KC_RBRC,  KC_SLSH,  KC_NO,
  KC_NO,           KC_NO,       KC_NO,         KC_CAPS, KC_SPC,                                                     KC_SPC,  KC_RALT, KC_NO,   KC_NO,    KC_NO,
                                                           KC_NO,       RAYCAST,                 KC_VOLD, KC_VOLU,
                                                                          KC_NO,                 KC_NO,
                                                         LA_NAV, KC_LSFT, KC_NO,                 KC_NO, KC_RSFT, LA_SYM
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.            ,--------------------------------------------------.
 * |         |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |           |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO   |
 * |---------+------+------+------+------+------+------|            |------+------+------+------+------+------+--------|
 * |   NO    |   !  |   @  |   #  |   $  |   %  |  NO  |            |  NO  |  ^   |   ?  |   *  |   (  |   )  |  NO    |
 * |---------+------+------+------+------+------|      |            |      |------+------+------+------+------+--------|
 * |   NO    |   ~  |   '  |   ,  |   .  |   \  |------|            |------|  NO  |   ⇧  |   ⌃  |   ⌥  |   ⌘  |  NO    |
 * |---------+------+------+------+------+------|  NO  |            |      |------+------+------+------+------+------ -|
 * |   NO    |  NO  |  NO  |   -  |   =  |  NO  |      |            |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO   |
 * `---------+------+------+------+------+-------------'            `-------------+------+------+------+------+--------'
 *   |   NO  |  NO  |  NO  |      |      |                                       |      |      |  NO  |  NO  | NO   |
 *   `-----------------------------------'                                        `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | NO   | NO   |       | NO   |  NO  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  NO  |       | NO   |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |  NO  |       | NO   |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_SYM] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_NO,         KC_NO,   S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_NO,
  KC_NO,   KC_GRV,  KC_QUOT, KC_COMM, KC_DOT,  KC_BSLS,                         KC_NO,   OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_MINS, KC_EQL,  KC_NO,   KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,                                           KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,
                                                KC_NO,    KC_NO,       KC_NO, KC_NO,
                                                          KC_NO,       KC_NO,
                                      KC_TRNS,  KC_TRNS,  KC_NO,       KC_NO, KC_TRNS, KC_TRNS
),
/* Keymap 2: Navigation Layer
 *
 * ,---------------------------------------------------.            ,--------------------------------------------------.
 * |         |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |            |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO   |
 * |---------+------+------+------+------+------+------|            |------+------+------+------+------+------+--------|
 * |   NO    |SCRSHT|SW_WIN| TAB- | TAB+ |  NO  |  NO  |            |  NO  | HOME | BKSPC|  UP  | DEL  |  NO  |  NO    |
 * |---------+------+------+------+------+------|      |            |      |------+------+------+------+------+--------|
 * |   NO    |  ⌘   |   ⌥  |   ⌃  |   ⇧  | ENTER|------|            |------|ENTER | LEFT | DOWN | RIGHT| END  |  NO    |
 * |---------+------+------+------+------+------|  NO  |            |      |------+------+------+------+------+------ -|
 * |   NO    |  NO  |  NO  |  NO  |  NO  | TAB  |      |            |  NO  | TAB  | PgDn | PgUp |  NO  |  NO  |  NO   |
 * `---------+------+------+------+------+-------------'            `-------------+------+------+------+------+--------'
 *   |   NO  |  NO  |  NO  |      |      |                                       |      |      |  NO  |  NO  | NO   |
 *   `-----------------------------------'                                        `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | NO   | NO   |       | NO   |  NO  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  NO  |       | NO   |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |  NO  |       | NO   |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_NAV] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   PRSCR,   SW_WIN,  TAB_L,   TAB_R,   KC_NO,   KC_NO,         KC_NO,   KC_HOME, KC_BSPC, KC_UP,   KC_DEL,  KC_NO,   KC_NO,
  KC_NO,   OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, KC_ENT,                          KC_ENT,  KC_LEFT, KC_DOWN, KC_RIGHT,KC_END,  KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TAB,   KC_NO,         KC_NO,  KC_TAB,  KC_PGDN, KC_PGUP, KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,                                           KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,
                                                KC_NO,    KC_NO,       KC_NO, KC_NO,
                                                          KC_NO,       KC_NO,
                                      KC_TRNS,  KC_TRNS,  KC_NO,       KC_NO, KC_TRNS, KC_TRNS
),
/* Keymap 3: Numbers Layer
 *
 * ,---------------------------------------------------.            ,--------------------------------------------------.
 * |         |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |            |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO   |
 * |---------+------+------+------+------+------+------|            |------+------+------+------+------+------+--------|
 * |   NO    |   1  |   2  |   3  |  4   |   5  |  NO  |            |  NO  |  6   |   7  |   8  |  9   |   0  |  NO    |
 * |---------+------+------+------+------+------|      |            |      |------+------+------+------+------+--------|
 * |   NO    |  ⌘   |   ⌥  |   ⌃  |   ⇧  | F11  |------|            |------|  F12 |  ⇧   |  ⌃   |   ⌥  |  ⌘   |  NO    |
 * |---------+------+------+------+------+------|  NO  |            |      |------+------+------+------+------+------ -|
 * |   NO    |  F1  |  F2  |  F3  |  F4  | F5   |      |            |  NO  |  F6  |  F7  |  F8  |  F9  |  F10 |  NO   |
 * `---------+------+------+------+------+-------------'            `-------------+------+------+------+------+--------'
 *   |   NO  |  NO  |  NO  |      |      |                                       |      |      |  NO  |  NO  | NO   |
 *   `-----------------------------------'                                        `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | NO   | NO   |       | NO   |  NO  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  NO  |       | NO   |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |  NO  |       | NO   |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_NUM] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,         KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
  KC_NO,   OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, KC_F11,                          KC_F12,  OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_NO,
  KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,         KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,                                           KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,
                                                KC_NO,    KC_NO,       KC_NO, KC_NO,
                                                          KC_NO,       KC_NO,
                                      KC_TRNS,  KC_TRNS,  KC_NO,       KC_NO, KC_TRNS, KC_TRNS
), 
};
// clang-format on

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LCMD, KC_TAB, SW_WIN, OS_SHFT,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
};
