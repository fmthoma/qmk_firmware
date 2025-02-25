#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"

#define TODO KC_NO
#define ALT_CODE(code) (SS_DOWN(X_LALT) code SS_UP(X_LALT))

enum custom_layers {
    BASE,   // default layer
    NOHRM,  // disabled home row mods, to resolve timing issues with Neo modifiers

    NEO1,   // Poor Man's Neo layer 1
    NEO3,   // Poor Man's Neo layer 3
//    NEO4,   // Poor Man's Neo layer 4
//    NEO5,   // Poor Man's Neo layer 5
//    NEO6,   // Poor Man's Neo layer 6

    ARRW,   // Arrow keys
    NUMFN,  // Number row & Fn keys
    NUMPAD, // Num pad
};

enum custom_keycodes {
    VRSN = SAFE_RANGE, // can always be here
    NEO_ELL,
    NEO_1_DEG,
    NEO_2_SECT,
    NEO_3_LTRS, // not implemented
    NEO_4_RAQUO,
    NEO_5_LAQUO,
    NEO_6_DLLR,
    NEO_7_EURO,
    NEO_8_BDQUO,
    NEO_9_LDQUO,
    NEO_0_RDQUO,
    NEO_MINS_EMDASH,
    NEO_COMM_ENDASH,
    NEO_DOT_BULLET,
};

// Tap Dance
enum {
    TD_MINS_GRAVE,
    TD_SZLIG_ACUTE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ^°   |   1  |   2  |   3  |   4  |   5  | Ins  |           | Esc  |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Cut    |   Q  |   W  |   E  |   R  |   T  | Del  |           | Bksp |   Y  |   U  |   I  |   O  |   P  |   {[   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Copy   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------| Tab  |           | Enter|------+------+------+------+------+--------|
     * | Paste  |  <>| |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | NUMPAD |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ???  | ???  | ???  | ???  | GUI  |                                       | NUMFN|  F4  |  ??? |  ??? |C+S+F12|
     *   `----------------------------------'                                       `-----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | ???  | ???  |       | ???  | ???  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | LAlt |       | ???  |      |      |
     *                                 | Shift| Caps |------|       |------| AltGr| Space|
     *                                 |      |      | LCtrl|       | RCtrl|      |      |
     *                                 `--------------------'       `--------------------'
     */
    [BASE] = LAYOUT_ergodox(
        // left hand
        KC_GRV,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_INS,
        LSFT(KC_DEL),   KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_DEL,
        LCTL(KC_INS),   LGUI_T(KC_A),   LSFT_T(KC_S),   LALT_T(KC_D),   LCTL_T(KC_F),   KC_G,
        LSFT(KC_INS),   KC_Y,           KC_X,           KC_C,           KC_V,           KC_B,           KC_TAB,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_LGUI,
                                                                                        KC_NO,          KC_NO,
                                                                                                        KC_LALT,
                                                                        KC_LSFT,        KC_RALT,        KC_LCTL,
        // right hand
        KC_ESC,         KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TD(TD_MINS_GRAVE),
        KC_BSPC,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           TD(TD_SZLIG_ACUTE),
                        KC_H,           RCTL_T(KC_J),   LALT_T(KC_K),   RSFT_T(KC_L),   RGUI_T(KC_SCLN),KC_QUOT,
        KC_ENT,         KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        TG(NUMPAD),
                                        MO(NUMFN),      KC_F4,          KC_NO,          KC_NO,          RCS(KC_F12),
        KC_NO,          KC_NO,
        KC_NO,
        KC_RCTL,        KC_CAPS,        LT(ARRW, KC_SPC)
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
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_A,           KC_S,           KC_D,           KC_F,           KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                        KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,
        // right hand
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                        KC_TRNS,        KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,
        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS
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
     *                                 | Shift| Caps |------|       |------| AltGr| Space|
     *                                 |      |      | LCtrl|       | RCtrl|      |      |
     *                                 `--------------------'       `--------------------'
     */
    [NEO1] = LAYOUT_ergodox(
        // left hand
        KC_NO,          NEO_1_DEG,      NEO_2_SECT,     KC_3,           NEO_4_RAQUO,    NEO_5_LAQUO,    KC_INS,
        LCTL(KC_X),     KC_X,           KC_V,           KC_L,           KC_C,           KC_W,           KC_DEL,
        LCTL(KC_C),     LGUI_T(KC_U),   LSFT_T(KC_I),   LALT_T(KC_A),   LCTL_T(KC_E),   KC_O,
        LCTL(KC_V),     DE_UDIA,        DE_ODIA,        DE_ADIA,        KC_P,           DE_Z,           KC_TAB,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_LGUI,
                                                                                        KC_NO,          KC_NO,
                                                                                                        KC_LALT,
                                                                        KC_LSFT,        KC_RALT,        KC_LCTL,
        // right hand
        KC_ESC,         NEO_6_DLLR,     NEO_7_EURO,     NEO_8_BDQUO,    NEO_9_LDQUO,    NEO_0_RDQUO,    NEO_MINS_EMDASH,
        KC_BSPC,        KC_K,           KC_H,           KC_G,           KC_F,           KC_Q,           DE_SS,
                        KC_S,           RCTL_T(KC_N),   LALT_T(KC_R),   RSFT_T(KC_T),   RGUI_T(KC_D),   DE_Y,
        KC_ENT,         KC_B,           KC_M,           NEO_COMM_ENDASH,NEO_DOT_BULLET, KC_J,           TG(NUMPAD),
                                        MO(NUMFN),      KC_F4,          KC_NO,          KC_NO,          RCS(KC_F12),
        KC_NO,          KC_NO,
        KC_NO,
        KC_RCTL,        MO(NEO3),       LT(ARRW, KC_SPC)
    ),
    /* NEO3: Poor Man's Neo layer 3 */
    [NEO3] = LAYOUT_ergodox(
        // left hand
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        KC_NO,          NEO_ELL,        DE_UNDS,        DE_LBRC,        DE_RBRC,        DE_CIRC,        KC_TRNS,
        KC_NO,          DE_BSLS,        DE_SLSH,        DE_LCBR,        DE_RCBR,        DE_ASTR,
        KC_NO,          DE_HASH,        DE_DLR,         DE_PIPE,        DE_TILD,        DE_GRV,         KC_TRNS,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                        KC_NO,          KC_NO,
                                                                                                        KC_NO,
                                                                        KC_NO,          KC_NO,          KC_NO,
        // right hand
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_TRNS,        DE_EXLM,        DE_LABK,        DE_RABK,        DE_EQL,         DE_AMPR,        KC_NO,
                        DE_QUES,        DE_LPRN,        DE_RPRN,        DE_MINS,        DE_COLN,        DE_AT,
        KC_TRNS,        DE_PLUS,        DE_PERC,        DE_DQUO,        DE_QUOT,        DE_SCLN,        KC_TRNS,
                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,
        KC_NO,
        KC_NO,          KC_TRNS,        KC_NO
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
        KC_TRNS,        KC_NO,          LCTL(KC_PMNS),  LCTL(KC_PPLS),  KC_NO,          KC_NO,          KC_NO,
                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        KC_NO,          KC_NO,
        KC_TRNS,        KC_HOME,        KC_PGDN,        KC_PGUP,        KC_END,         KC_NO,          KC_NO,
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,
        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS
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
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        KC_NO,          KC_LGUI,        KC_LSFT,        KC_LALT,        KC_LCTL,        KC_NO,
        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                        KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,
        // right  hand
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_TRNS,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TD(TD_MINS_GRAVE),
                        KC_NO,          KC_RCTL,        KC_LALT,        KC_RSFT,        KC_RGUI,        KC_NO,
        KC_TRNS,        KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,
        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS
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
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        KC_TRNS,        KC_LGUI,        KC_LSFT,        KC_LALT,        KC_LCTL,        KC_NO,
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        EE_CLR,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                        KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,
        // right  hand
        KC_TRNS,        KC_NO,          KC_NUM,         KC_PSLS,        KC_PAST,        KC_NO,          KC_TRNS,
        KC_TRNS,        KC_NO,          KC_P7,          KC_P8,          KC_P9,          KC_PMNS,        KC_TRNS,
                        KC_NO,          KC_P4,          KC_P5,          KC_P6,          KC_PPLS,        TG(NEO1),
        KC_TRNS,        KC_NO,          KC_P1,          KC_P2,          KC_P3,          KC_PENT,        KC_TRNS,
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,
        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_P0
    ),
};

void neo_layer1_shifted(uint8_t unshifted, uint8_t shifted) {
    uint8_t kc = get_mods() & MOD_MASK_SHIFT ? shifted : unshifted;
    tap_code(kc);
}

void neo_layer1_unshifted(uint8_t unshifted, uint16_t shifted) {
    uint8_t mods = get_mods();
    if (mods & MOD_MASK_SHIFT) {
        unregister_mods(mods);
        tap_code16(shifted);
        register_mods(mods);
    } else {
        tap_code(unshifted);
    }
}

void neo_layer1_macro(uint8_t unshifted, char* shifted) {
    uint8_t mods = get_mods();
    if (mods & MOD_MASK_SHIFT) {
        unregister_mods(mods);
        SEND_STRING (shifted);
        register_mods(mods);
    } else {
        tap_code(unshifted);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CAPS:
            if (record->event.pressed) {
                layer_on(NOHRM);
            } else {
                layer_off(NOHRM);
            }
            return true; // pass the key on

        case NEO_ELL:
            if (record->event.pressed) SEND_STRING (ALT_CODE("0133"));
            return false;

        case NEO_1_DEG:
            if (record->event.pressed) neo_layer1_shifted(KC_1, DE_CIRC);
            return false;
        case NEO_2_SECT:
            if (record->event.pressed) neo_layer1_shifted(KC_2, DE_3);
            return false;
        case NEO_4_RAQUO:
            if (record->event.pressed) neo_layer1_macro(KC_4, ALT_CODE("0187"));
            return false;
        case NEO_5_LAQUO:
            if (record->event.pressed) neo_layer1_macro(KC_5, ALT_CODE("0171"));
            return false;
        case NEO_6_DLLR:
            if (record->event.pressed) neo_layer1_shifted(KC_6, KC_4);
            return false;
        case NEO_7_EURO:
            if (record->event.pressed) neo_layer1_unshifted(KC_7, DE_EURO);
            return false;
        case NEO_8_BDQUO:
            if (record->event.pressed) neo_layer1_macro(KC_8, ALT_CODE("0132"));
            return false;
        case NEO_9_LDQUO:
            if (record->event.pressed) neo_layer1_macro(KC_9, ALT_CODE("0147"));
            return false;
        case NEO_0_RDQUO:
            if (record->event.pressed) neo_layer1_macro(KC_0, ALT_CODE("0148"));
            return false;
        case NEO_MINS_EMDASH:
            if (record->event.pressed) neo_layer1_macro(DE_MINS, ALT_CODE("0151"));
            return false;
        case NEO_COMM_ENDASH:
            if (record->event.pressed) neo_layer1_macro(KC_COMM, ALT_CODE("0150"));
            return false;
        case NEO_DOT_BULLET:
            if (record->event.pressed) neo_layer1_macro(KC_DOT, ALT_CODE("0149"));
            return false;

        case VRSN:
            if (record->event.pressed) SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
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

const uint16_t PROGMEM er_del[] = { KC_E,         KC_R,         COMBO_END };
const uint16_t PROGMEM df_tab[] = { LALT_T(KC_D), LCTL_T(KC_F), COMBO_END };
const uint16_t PROGMEM cv_ins[] = { KC_C,         KC_V,         COMBO_END };
const uint16_t PROGMEM ui_bsp[] = { KC_U,         KC_I,         COMBO_END };
const uint16_t PROGMEM jk_ent[] = { RCTL_T(KC_J), LALT_T(KC_K), COMBO_END };
const uint16_t PROGMEM mc_esc[] = { KC_M,         KC_COMM,      COMBO_END };
const uint16_t PROGMEM qwer_boot[] = { KC_Q, KC_W, KC_E, KC_R,  COMBO_END };

combo_t key_combos[] = {
    COMBO(er_del, KC_DEL),
    COMBO(df_tab, KC_TAB),
    COMBO(cv_ins, KC_INS),
    COMBO(ui_bsp, KC_BSPC),
    COMBO(jk_ent, KC_ENT),
    COMBO(mc_esc, KC_ESC),
    COMBO(qwer_boot, QK_BOOT),
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_MINS_GRAVE]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL),  // - -> `
    [TD_SZLIG_ACUTE] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC), // ß -> ´
};

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
