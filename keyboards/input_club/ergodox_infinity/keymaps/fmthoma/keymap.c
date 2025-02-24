#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"

enum custom_layers {
    BASE,   // default layer
    ARRW,   // Arrow keys
    NUM,    // Num pad
};


enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    VRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ^°   |   1  |   2  |   3  |   4  |   5  | Ins  |           | Esc  |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Cut    |   Q  |   W  |   E  |   R  |   T  | Del  |           | Bksp |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Copy   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------| Tab  |           | Enter|------+------+------+------+------+--------|
     * | Paste  |  <>| |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |  NUM   |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ???  | ???  | ???  | ???  | GUI  |                                       | ARRW |  F4  |  ??? |  ??? |C+S+F12|
     *   `----------------------------------'                                       `-----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | ???  | ???  |       | ???  | ???  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | LAlt |       | ???  |      |      |
     *                                 | Shift| Caps |------|       |------| AltGr| Space|
     *                                 |      |      | LCtrl|       | RCtrl|      |      |
     *                                 `--------------------'       `--------------------'
     */
    [BASE] = LAYOUT_ergodox(      // layer 0 : default
        // left hand
        KC_GRV,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_INS,
        LSFT(KC_DEL),   KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_DEL,
        LCTL(KC_INS),   LGUI_T(KC_A),   LSFT_T(KC_S),   LALT_T(KC_D),   LCTL_T(KC_F),   KC_G,
        LSFT(KC_INS),   KC_NUBS,        KC_X,           KC_C,           KC_V,           KC_B,           KC_TAB,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_LGUI,
                                                                                        KC_NO,          KC_NO,
                                                                                                        KC_LALT,
                                                                        KC_LSFT,        KC_CAPS,        KC_LCTL,
        // right hand
        KC_ESC,         KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,
        KC_BSPC,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
                        KC_H,           RCTL_T(KC_J),   LALT_T(KC_K),   RSFT_T(KC_L),   RGUI_T(KC_SCLN),KC_QUOT,
        KC_ENT,         KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        TG(2),
                                        MO(1),          KC_F4,          KC_NO,          KC_NO,          MEH(KC_F12),
        KC_NO,          KC_NO,
        KC_NO,
        KC_RCTL,        KC_RALT,        KC_SPC
    ),
    /* Keymap 1: Arrow and function keys
     *
     * ,---------------------------------------------------.           ,--------------------------------------------------.
     * |   F1    |  F2  |  F3  |  F4  |  F5  |  F6  |      |           |      |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
     * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
     * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
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
        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_TRNS,
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        KC_TRNS,        KC_LGUI,        KC_LSFT,        KC_LALT,        KC_LCTL,        KC_NO,
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        EE_CLR,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                        KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,
        // right hand
        KC_TRNS,        KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        KC_NO,          KC_NO,
        KC_TRNS,        KC_HOME,        KC_PGDN,        KC_PGUP,        KC_END,         KC_NO,          KC_NO,
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,
        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),
    /* Keymap 2: Num keys
     *
     * ,---------------------------------------------------.           ,--------------------------------------------------.
     * |         |      |      |      |      |      |      |           |      |      |  Num |   /  |   *  |   -  |        |
     * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
     * |         |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   +  |        |
     * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |         | GUI  | Shift| Alt  | Ctrl |      |------|           |------|      |   4  |   5  |   6  |   +  |        |
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
    [NUM] = LAYOUT_ergodox(
        // left  hand
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        KC_TRNS,        KC_LGUI,        KC_LSFT,        KC_LALT,        KC_LCTL,        KC_NO,
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        EE_CLR,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                        KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,
        // right  hand
        KC_TRNS,        KC_NO,          KC_NUM,         KC_PSLS,        KC_PAST,        KC_PMNS,        KC_TRNS,
        KC_TRNS,        KC_NO,          KC_P7,          KC_P8,          KC_P9,          KC_PPLS,        KC_TRNS,
                        KC_NO,          KC_P4,          KC_P5,          KC_P6,          KC_PPLS,        KC_TRNS,
        KC_TRNS,        KC_NO,          KC_P1,          KC_P2,          KC_P3,          KC_PENT,        KC_TRNS,
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,
        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_P0
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // dynamically generate these.
        case VRSN:
            if (record->event.pressed) {
              SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
    }
    return true;
}

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

const uint16_t PROGMEM er_esc[] = { KC_E,         KC_R,         COMBO_END };
const uint16_t PROGMEM df_del[] = { LALT_T(KC_D), LCTL_T(KC_F), COMBO_END };
const uint16_t PROGMEM cv_tab[] = { KC_C,         KC_V,         COMBO_END };
const uint16_t PROGMEM ui_ins[] = { KC_U,         KC_I,         COMBO_END };
const uint16_t PROGMEM jk_bsp[] = { RCTL_T(KC_J), LALT_T(KC_K), COMBO_END };
const uint16_t PROGMEM mc_ent[] = { KC_M,         KC_COMM,      COMBO_END };

combo_t key_combos[] = {
    COMBO(er_esc, KC_ESC),
    COMBO(df_del, KC_DEL),
    COMBO(cv_tab, KC_TAB),
    COMBO(ui_ins, KC_INS),
    COMBO(jk_bsp, KC_BSPC),
    COMBO(mc_ent, KC_ENT),
};
