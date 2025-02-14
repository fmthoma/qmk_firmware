#include QMK_KEYBOARD_H
#include "version.h"

enum custom_layers {
    BASE,   // default layer
    ARRW,   // Arrow keys
    NUM,    // Num pad

    NEO1,   // Poor man's Neo layer 1

    SYMB,   // symbols
    MDIA,   // media keys
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
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_INS,
        LSFT(KC_DEL),   KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_DEL,
        LCTL(KC_INS),   KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        LSFT(KC_INS),   KC_NUBS,      KC_X,   KC_C,   KC_V,   KC_B,   KC_TAB,
        KC_NO,          KC_NO,        KC_NO,  KC_LGUI,
                                                      KC_NO,  KC_NO,
                                                              KC_LALT,
                                              KC_LSFT,KC_CAPS,KC_LCTL,
        // right hand
             KC_ESC,      KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
             KC_BSPC,     KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             KC_ENT,      KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,          TG(2),  
                                  MO(1), KC_F4,  KC_NO,  KC_NO,            MEH(KC_12),
             KC_NO,       KC_NO,
             KC_NO,
             KC_RCTRL,KC_RALT,KC_SPC
    ),
/* Keymap 1: Arrow and function keys
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   F1    |  F2  |  F3  |  F4  |  F5  |  F6  |      |           |      |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------| Left | Down |  Up  | Right|      |        |
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
       // left hand
       KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       EE_CLR, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       LM_TOGG, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Num keys
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |  Num |   /  |   *  |   -  |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   +  |        |
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
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_P7,  KC_P8,   KC_P9,   KC_PPLS, KC_TRNS,
                KC_TRNS, KC_P4,  KC_P5,   KC_P6,   KC_PPLS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_P1,  KC_P2,   KC_P3,   KC_PENT, KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_P0
),
/* Keymap 3: Poor man's Neo, layer 1. Based on German layout.
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ^    |   1  |   2  |   3  |   4  |   5  | Ins  |           | Esc  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Cut    |   X  |   V  |   L  |   C  |   W  | Del  |           | Bksp |   K  |   H  |   G  |   F  |   Q  |   ẞ    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Copy   |   U  |   I  |   A  |   E  |   O  |------|           |------|   S  |   N  |   R  |   T  |   D  |   Y    |
 * |--------+------+------+------+------+------| Tab  |           | Enter|------+------+------+------+------+--------|
 * | Paste  |   Ü  |   Ö  |   Ä  |   P  |   Z  |      |           |      |   B  |   M  |   ,  |   .  |   J  |  NUM   |
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
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[NEO1] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        DE_CIRC,        KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_INS,
        LCTL(KC_X),     KC_X,         KC_V,   KC_L,   KC_C,   KC_W,   KC_DEL,
        LCTL(KC_C),     KC_U,         KC_I,   KC_A,   KC_E,   KC_O,
        LCTL(KC_V),     DE_UDIA,      DE_ODIA,DE_ADIA,KC_P,   KC_Z,   KC_TAB,
        KC_NO,          KC_NO,        KC_NO,  KC_LGUI,
                                                      KC_NO,  KC_NO,
                                                              KC_LALT,
                                              KC_LSFT,KC_CAPS,KC_LCTL,
        // right hand
             KC_ESC,      KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             DE_MINS,
             KC_BSPC,     KC_K,   KC_H,  KC_G,   KC_F,   KC_Q,             DE_SS,
                          KC_S,   KC_N,  KC_R,   KC_T,   KC_D,             DE_Y,
             KC_ENT,      KC_B,   KC_M,  KC_COMM,KC_DOT, KC_J,             TG(2),  
                                  MO(1), KC_F4,  KC_NO,  KC_NO,            MEH(KC_12),
             KC_NO,       KC_NO,
             KC_NO,
             KC_RCTRL,KC_RALT,KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |EE_CLR |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       EE_CLR, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       LM_NEXT,KC_TRNS,
                                               KC_TRNS,
                               LM_BRID,LM_BRIU,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       LM_TOGG, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
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
