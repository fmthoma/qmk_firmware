#include QMK_KEYBOARD_H
#include "version.h"
#include "fmthoma.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
     *
     * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
     * │   ^°   │   1  │   2  │   3  │   4  │   5  │ Ins  │           │ Esc  │   6  │   7  │   8  │   9  │   0  │   -    │
     * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
     * │ Cut    │   Q  │   W  │   E  │   R  │   T  │ Del  │           │ Bksp │   Y  │   U  │   I  │   O  │   P  │   {[   │
     * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
     * │ Copy   │   A  │   S  │   D  │   F  │   G  ├──────┤           ├──────┤   H  │   J  │   K  │   L  │   ;  │   '    │
     * ├────────┼──────┼──────┼──────┼──────┼──────┤ Tab  │           │ Enter├──────┼──────┼──────┼──────┼──────┼────────┤
     * │ Paste  │      │   X  │   C  │   V  │   B  │      │           │      │   N  │   M  │   ,  │   .  │   /  │ NUMPAD │
     * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼───────┬╯
     *   │ ???  │ ???  │ ???  │ ???  │ GUI  │                                       │ NUMFN│  F4  │  ??? │  ??? │C+S+F12│
     *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴───────╯
     *                                        ╭──────┬──────╮       ╭──────┬──────╮
     *                                        │ ???  │ ???  │       │ ???  │ ???  │
     *                                 ╭──────┼──────┼──────┤       ├──────┼──────┼──────╮
     *                                 │      │      │ LAlt │       │ ???  │      │      │
     *                                 │ Shift│ AltGr├──────┤       ├──────┤ Caps │ Space│
     *                                 │      │      │ LCtrl│       │ RCtrl│      │      │
     *                                 ╰──────┴──────┴──────╯       ╰──────┴──────┴──────╯
     */
    [BASE] = LAYOUT_ergodox(
        // left hand
        DE_CIRC,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_INS,
        OSKC_CUT,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_DEL,
        OSKC_COPY,      HRM_A,          HRM_S,          HRM_D,          HRM_F,          KC_G,
        OSKC_PSTE,      KC_Y,           KC_X,           KC_C,           KC_V,           KC_B,           KC_TAB,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_LGUI,
                                                                                        XXXXXXX,        XXXXXXX,
                                                                                                        KC_LALT,
                                                                        KC_LSFT,        KC_RALT,        KC_LCTL,
        // right hand
        KC_ESC,         KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           MINS_GRV,
        KC_BSPC,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SS_ACUTE,
                        KC_H,           HRM_J,          HRM_K,          HRM_L,          HRM_ODIA,       DE_ADIA,
        KC_ENT,         KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        TG(NUMPAD),
                                        MO(NUMFN),      KC_F4,          XXXXXXX,        XXXXXXX,        RCS(KC_F12),
        XXXXXXX,        XXXXXXX,
        XXXXXXX,
        KC_RCTL,        KC_CAPS,        SPC_ARRW
    ),
    /* Keymap 1: Disabled home row mods
     * This is for resolving timing issues with Neo modifiers on thumb keys:
     * If the thumb key is released before the tap term is over, then the
     * events are sent in the wrong order:
     *     (mod down, mod up, key down, key up)
     * instead of
     *     (mod down, key down, key up, mod up).
     * Disabling home row mods helps by sending the keycodes immediately.
     *
     * ,---------------------------------------------------.           ,--------------------------------------------------.
     * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
     * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |         |   A  |   S  |   D  |   F  |      |------|           |------|      |   J  |   K  |   L  |   ;  |        |
     * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |       |      |      |      |      |                                       |      |      |      |      |      |
     *   `-----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [NOHRM] = LAYOUT_ergodox(
        // left hand
        _______,        _______,        _______,        _______,        _______,        _______,        _______,
        _______,        _______,        _______,        _______,        _______,        _______,        _______,
        _______,        KC_A,           KC_S,           KC_D,           KC_F,           _______,
        _______,        _______,        _______,        _______,        _______,        _______,        _______,
        _______,        _______,        _______,        _______,        _______,
                                                                                        _______,        _______,
                                                                                                        _______,
                                                                        _______,        _______,        _______,
        // right hand
        _______,        _______,        _______,        _______,        _______,        _______,        _______,
        _______,        _______,        _______,        _______,        _______,        _______,        _______,
                        _______,        KC_J,           KC_K,           KC_L,           DE_ODIA,        _______,
        _______,        _______,        _______,        _______,        _______,        _______,        _______,
                                        _______,        _______,        _______,        _______,        _______,
        _______,        _______,
        _______,
        _______,        _______,        _______
    ),
    /* NEO1: Poor Man's Neo layer 1
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ^°   |   1  |   2  |   3  |   4  |   5  | Ins  |           | Esc  |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Cut    |   Q  |   W  |   E  |   R  |   T  | Del  |           | Bksp |   Y  |   U  |   I  |   O  |   P  |   {[   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Copy   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------| Tab  |           | Enter|------+------+------+------+------+--------|
     * | Paste  |  <>| |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |  NUM   |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ???  | ???  | ???  | ???  | GUI  |                                       | NUMFN|  F4  |  ??? |  ??? |C+S+F12|
     *   `----------------------------------'                                       `-----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | ???  | ???  |       | ???  | ???  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | LAlt |       | ???  |      |      |
     *                                 | Shift| NEO4 |------|       |------| NEO3 | Space|
     *                                 |      |      | LCtrl|       | RCtrl|      |      |
     *                                 `--------------------'       `--------------------'
     */
    [NEO1] = LAYOUT_ergodox(
        // left hand
        XXXXXXX,        NEO_1_DEG,      NEO_2_SECT,     KC_3,           NEO_4_RAQUO,    NEO_5_LAQUO,    KC_INS,
        OSKC_CUT,       KC_X,           KC_V,           KC_L,           KC_C,           KC_W,           KC_DEL,
        OSKC_COPY,      HRM_N_U,        HRM_N_I,        HRM_N_A,        HRM_N_E,        KC_O,
        OSKC_PSTE,      DE_UDIA,        DE_ODIA,        DE_ADIA,        KC_P,           DE_Z,           KC_TAB,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_LGUI,
                                                                                        XXXXXXX,        XXXXXXX,
                                                                                                        KC_LALT,
                                                                        KC_LSFT,        MO(NEO4),       KC_LCTL,
        // right hand
        KC_ESC,         NEO_6_DLLR,     NEO_7_EURO,     NEO_8_BDQUO,    NEO_9_LDQUO,    NEO_0_RDQUO,    NEO_MINS_EMDASH,
        KC_BSPC,        KC_K,           KC_H,           KC_G,           KC_F,           KC_Q,           DE_SS,
                        KC_S,           HRM_N_N,        HRM_N_R,        HRM_N_T,        HRM_N_D,        DE_Y,
        KC_ENT,         KC_B,           KC_M,           NEO_COMM_ENDASH,NEO_DOT_BULLET, KC_J,           TG(NUMPAD),
                                        MO(NUMFN),      KC_F4,          XXXXXXX,        XXXXXXX,        RCS(KC_F12),
        XXXXXXX,        XXXXXXX,
        XXXXXXX,
        KC_RCTL,        MO(NEO3),       LT(ARRW, KC_SPC)
    ),
    /* NEO3: Poor Man's Neo layer 3 */
    [NEO3] = LAYOUT_ergodox(
        // left hand
        XXXXXXX,        XXXXXXX,        DE_SUP2,        DE_SUP3,        XXXXXXX,        XXXXXXX,        _______,
        XXXXXXX,        NEO_ELL,        DE_UNDS,        DE_LBRC,        DE_RBRC,        DE_CIRC,        _______,
        XXXXXXX,        DE_BSLS,        DE_SLSH,        DE_LCBR,        DE_RCBR,        DE_ASTR,
        XXXXXXX,        DE_HASH,        DE_DLR,         DE_PIPE,        DE_TILD,        DE_GRV,         _______,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                                        XXXXXXX,        XXXXXXX,
                                                                                                        XXXXXXX,
                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,
        // right hand
        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        _______,        DE_EXLM,        DE_LABK,        DE_RABK,        DE_EQL,         DE_AMPR,        XXXXXXX,
                        DE_QUES,        DE_LPRN,        DE_RPRN,        DE_MINS,        DE_COLN,        DE_AT,
        _______,        DE_PLUS,        DE_PERC,        DE_DQUO,        DE_QUOT,        DE_SCLN,        _______,
                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,
        XXXXXXX,
        XXXXXXX,        _______,        XXXXXXX
    ),
    /* NEO4: Poor Man's Neo layer 4 */
    [NEO4] = LAYOUT_ergodox(
        // left hand
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        _______,
        XXXXXXX,        KC_PGUP,        KC_BSPC,        KC_UP,          KC_DEL,         KC_PGDN,        _______,
        XXXXXXX,        KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_END,
        XXXXXXX,        KC_ESC,         KC_TAB,         KC_INS,         KC_ENT,         KC_UNDO,        _______,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                                        XXXXXXX,        XXXXXXX,
                                                                                                        XXXXXXX,
                                                                        XXXXXXX,        _______,        XXXXXXX,
        // right hand
        _______,        XXXXXXX,        KC_TAB,         DE_SLSH,        DE_ASTR,        DE_MINS,        XXXXXXX,
        _______,        TODO,           KC_P7,          KC_P8,          KC_P9,          KC_PLUS,        TODO,
                        TODO,           KC_P4,          KC_P5,          KC_P6,          KC_COMM,        KC_DOT,
        _______,        DE_COLN,        KC_P1,          KC_P2,          KC_P3,          DE_SCLN,        XXXXXXX,
                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,
        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX
    ),
    /* Keymap 2: Arrow and function keys
     *
     * ,---------------------------------------------------.           ,--------------------------------------------------.
     * |   F1    |  F2  |  F3  |  F4  |  F5  |  F6  |      |           |      |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
     * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
     * |         |      |      |      |      |      |      |           |      |      | Ctrl-| Ctrl+|      |      |        |
     * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |         | GUI  | Shift| Alt  | Ctrl |      |------|           |------| Left | Down |  Up  | Right|      |        |
     * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |         |      |      |      |      |      |      |           |      | Home | PgDn | PgUp |  End |      |        |
     * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |EE_CLR |      |      |      |      |                                       |      |      |      |      |      |
     *   `-----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [ARRW] = LAYOUT_ergodox(
        // left        hand
        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          _______,
        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        _______,
        _______,        KC_LGUI,        KC_LSFT,        KC_LALT,        KC_LCTL,        XXXXXXX,
        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        _______,
        EE_CLR,         _______,        _______,        _______,        _______,
                                                                                        _______,        _______,
                                                                                                        _______,
                                                                        _______,        _______,        _______,
        // right hand
        _______,        KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,
        _______,        XXXXXXX,        ZOOM_OUT,       ZOOM_IN,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        XXXXXXX,        XXXXXXX,
        _______,        KC_HOME,        KC_PGDN,        KC_PGUP,        KC_END,         XXXXXXX,        XXXXXXX,
                                        _______,        _______,        _______,        _______,        _______,
        _______,        _______,
        _______,
        _______,        _______,        _______
    ),
    /* Keymap 3: Number rows + Fn keys
     *
     * ,---------------------------------------------------.           ,--------------------------------------------------.
     * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
     * |    ^°   |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
     * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |         | GUI  | Shift| Alt  | Ctrl |      |------|           |------|      | Ctrl | Alt  | Shift| GUI  |        |
     * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |   F1    |  F2  |  F3  |  F4  |  F5  |  F6  |      |           |      |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
     * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |       |      |      |      |      |                                       |      |      |      |      |      |
     *   `-----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [NUMFN] = LAYOUT_ergodox(
        // left  hand
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        _______,
        XXXXXXX,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           _______,
        XXXXXXX,        KC_LGUI,        KC_LSFT,        KC_LALT,        KC_LCTL,        XXXXXXX,
        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          _______,
        _______,        _______,        _______,        _______,        _______,
                                                                                        _______,        _______,
                                                                                                        _______,
                                                                        _______,        _______,        _______,
        // right  hand
        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        _______,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           MINS_GRV,
                        XXXXXXX,        KC_RCTL,        KC_LALT,        KC_RSFT,        KC_RGUI,        XXXXXXX,
        _______,        KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,
                                        _______,        _______,        _______,        _______,        _______,
        _______,        _______,
        _______,
        _______,        _______,        _______
    ),
    /* Keymap 4: Numpad
     *
     * ,---------------------------------------------------.           ,--------------------------------------------------.
     * |         |      |      |      |      |      |      |           |      |      |  Num |   /  |   *  |      |        |
     * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
     * |         |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   -  |        |
     * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |         | GUI  | Shift| Alt  | Ctrl |      |------|           |------|      |   4  |   5  |   6  |   +  |TG(NEO1)|
     * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |         |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  | Enter|        |
     * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |       |      |      |      |      |                                       |      |      |      |      |      |
     *   `-----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |  0   |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [NUMPAD] = LAYOUT_ergodox(
        // left  hand
        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        _______,
        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        _______,
        _______,        KC_LGUI,        KC_LSFT,        KC_LALT,        KC_LCTL,        XXXXXXX,
        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        _______,
        EE_CLR,         _______,        _______,        _______,        _______,
                                                                                        _______,        _______,
                                                                                                        _______,
                                                                        _______,        _______,        _______,
        // right  hand
        _______,        XXXXXXX,        KC_NUM,         KC_PSLS,        KC_PAST,        XXXXXXX,        _______,
        _______,        XXXXXXX,        KC_P7,          KC_P8,          KC_P9,          KC_PMNS,        _______,
                        XXXXXXX,        KC_P4,          KC_P5,          KC_P6,          KC_PPLS,        TG(NEO1),
        _______,        XXXXXXX,        KC_P1,          KC_P2,          KC_P3,          KC_PENT,        _______,
                                        _______,        _______,        _______,        _______,        _______,
        _______,        _______,
        _______,
        _______,        _______,        KC_P0
    ),
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = get_highest_layer(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case ARRW:
            ergodox_infinity_lcd_color(UINT16_MAX, UINT16_MAX / 2, UINT16_MAX / 2);
            break;
        case NUMFN:
            ergodox_infinity_lcd_color(UINT16_MAX / 2, UINT16_MAX / 2, UINT16_MAX);
            break;
        case NUMPAD:
            ergodox_infinity_lcd_color(UINT16_MAX / 2, UINT16_MAX, UINT16_MAX / 2);
            break;
        case BASE:
        default:
            ergodox_infinity_lcd_color(UINT16_MAX / 2, UINT16_MAX / 2, UINT16_MAX / 2);
            break;
    }
    return state;
}

char* format_os_string(void) {
    switch (detected_host_os()) {
        case OS_LINUX:
            return "Linux";
        case OS_WINDOWS:
            return "Windows";
        case OS_MACOS:
            return "MacOS";
        case OS_IOS:
            return "iOS";
        case OS_UNSURE:
        default:
            return "Unknown OS";
    }
}

void st7565_task_user(void) {
    if (is_keyboard_master()) {
        // Output detected OS
        st7565_advance_page(true);
        st7565_write_ln(format_os_string(), false);
        st7565_advance_page(true);
        if (layer_state_is(NEO1)) st7565_write("NEO ", false);
        if (layer_state_is(ARRW)) st7565_write("ARRW ", false);
        if (layer_state_is(NUMFN)) st7565_write("NUMFN ", false);
        if (layer_state_is(NUMPAD)) st7565_write("NUMPAD ", false);
        st7565_advance_page(true);
    } else {
        // Draw logo
        static const char qmk_logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
            0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
            0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
        };

        st7565_write(qmk_logo, false);
        st7565_write("  Infinity  Ergodox  ", false);
    }
}

/* blank layer (for copy-paste)

        // left hand
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                        KC_NO,          KC_NO,
                                                                                                        KC_NO,
                                                                        KC_NO,          KC_NO,          KC_NO,
        // right hand
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,
        KC_NO,
        KC_NO,          KC_NO,          KC_NO


 */
