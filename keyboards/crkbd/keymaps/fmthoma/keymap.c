/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "fmthoma.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.    ,-------------------------------------------------------------.
     OSKC_CUT,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_DEL,    KC_BSPC ,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,SS_ACUTE,
  //|--------+--------+--------+--------+--------+--------+-------|    |-------+--------+--------+--------+--------+--------+--------|
    OSKC_COPY,   HRM_A,   HRM_S,   HRM_D,   HRM_F,    KC_G, KC_TAB,     KC_ENT ,    KC_H,   HRM_J,   HRM_K,   HRM_L,HRM_ODIA, DE_ADIA,
  //|--------+--------+--------+--------+--------+--------+-------'    `-------+--------+--------+--------+--------+--------+--------|
    OSKC_PSTE,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, DE_MINS,TG(NUMPAD),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              GUI, KC_LSFT,INS_RALT,   ESC_CAPS,SPC_ARRW,  ESC_FN
                                      //`--------------------------'  `--------------------------'
  ),
    [NOHRM] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.    ,-------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______,_______,     _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+-------|    |-------+--------+--------+--------+--------+--------+--------|
      _______,    KC_A,    KC_S,    KC_D,    KC_F, _______,_______,     _______, _______,    KC_J,    KC_K,    KC_L, DE_ODIA, _______,
  //|--------+--------+--------+--------+--------+--------+-------'    `-------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
    [NEO1] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.    ,-------------------------------------------------------------.
     OSKC_CUT,    KC_X,    KC_V,    KC_L,    KC_C,    KC_W, KC_DEL,     KC_BSPC,    KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,   DE_SS,
  //|--------+--------+--------+--------+--------+--------+-------|    |-------+--------+--------+--------+--------+--------+--------|
    OSKC_COPY, HRM_N_U, HRM_N_I, HRM_N_A, HRM_N_E,    KC_O, KC_TAB,      KC_ENT,    KC_S, HRM_N_N, HRM_N_R, HRM_N_T, HRM_N_D,    DE_Y,
  //|--------+--------+--------+--------+--------+--------+-------'    `-------+--------+--------+--------+--------+--------+--------|
    OSKC_PSTE, DE_UDIA, DE_ODIA, DE_ADIA,    KC_P,    DE_Z,                KC_B,    KC_M,NEO_COMM_ENDASH,NEO_DOT_BULLET,KC_J,TG(NUMPAD),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              GUI, KC_LSFT,N_INS_M4,   N_ESC_M3,SPC_ARRW,  ESC_FN
                                      //`--------------------------'  `--------------------------'
  ),
    [NEO2] = LAYOUT_split_3x6_3_ex2( // Fully transparent layer, purely to make tri-layer state work
  //,-------------------------------------------------------------.    ,-------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______,_______,     _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+-------|    |-------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,_______,     _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+-------'    `-------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, XXXXXXX,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
    [NEO3] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.    ,-------------------------------------------------------------.
      XXXXXXX, NEO_ELL, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,_______,     _______, DE_EXLM, DE_LABK, DE_RABK,  DE_EQL, DE_AMPR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+-------|    |-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,_______,     _______, DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN,   DE_AT,
  //|--------+--------+--------+--------+--------+--------+-------'    `-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, DE_HASH,  DE_DLR, DE_PIPE, DE_TILD,  DE_GRV,                      DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, _______,    _______, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'

  ),
    [NEO4] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.    ,-------------------------------------------------------------.
      XXXXXXX, KC_PGUP, KC_BSPC,   KC_UP,  KC_DEL, KC_PGDN,_______,     _______,    TODO,   KC_P7,   KC_P8,   KC_P9, KC_PLUS,    TODO,
  //|--------+--------+--------+--------+--------+--------+-------|    |-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,_______,     _______,    TODO,   KC_P4,   KC_P5,   KC_P6, KC_COMM,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------+-------'    `-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_ESC,   KC_TAB,  KC_INS,  KC_ENT, KC_UNDO,                      DE_COLN,   KC_P1,   KC_P2,   KC_P3, DE_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______,   KC_P0, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [NEO5] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.    ,-------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+-------|    |-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,   ALPHA, EPSILON, XXXXXXX,_______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+-------'    `-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    _______, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [NEO6] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.    ,-------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+-------|    |-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+-------'    `-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      NEO_LDA,NEO_LRDA, NEO_RDA, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [ARRW] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.    ,-------------------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,     _______, XXXXXXX,ZOOM_OUT, ZOOM_IN, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+-------|    |-------+--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI, KC_LSFT, KC_LALT, KC_LCTL, XXXXXXX,_______,     _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+-------'    `-------+--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
    [NUMFN] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.    ,-------------------------------------------------------------.
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,_______,     _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,MINS_GRV,
  //|--------+--------+--------+--------+--------+--------+-------|    |-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LSFT, KC_LALT, KC_LCTL, XXXXXXX,_______,     _______, XXXXXXX, KC_RCTL, KC_LALT, KC_RSFT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+-------'    `-------+--------+--------+--------+--------+--------+--------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
    [NUMPAD] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.    ,-------------------------------------------------------------.
     TG(NEO1), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,     _______,  KC_NUM,   KC_P7,   KC_P8,   KC_P9, KC_PMNS, KC_PSLS,
  //|--------+--------+--------+--------+--------+--------+-------|    |-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LSFT, KC_LALT, KC_LCTL, XXXXXXX,_______,     _______, XXXXXXX,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_PAST,
  //|--------+--------+--------+--------+--------+--------+-------'    `-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_P1,   KC_P2,   KC_P3, KC_PENT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,   KC_P0, _______
                                      //`--------------------------'  `--------------------------'
  ),
};

/* Empty Layer:
  //,-------------------------------------------------------------.    ,-------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+-------|    |-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+-------'    `-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
*/

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

uint16_t layer_colors[][3] = {
    [BASE]   = { RGB_OFF },
    [NOHRM]  = { RGB_OFF },

    [NEO1]   = { 0x20, 0x00, 0x00 },
    [NEO2]   = { 0x20, 0x00, 0x00 },
    [NEO3]   = { 0x20, 0x00, 0x00 },
    [NEO4]   = { 0x20, 0x00, 0x00 },
    [NEO5]   = { 0x00, 0xFF, 0x00 },
    [NEO6]   = { 0x00, 0x00, 0xFF },

    [ARRW]   = { 0x80, 0x40, 0x40 },
    [NUMFN]  = { 0x40, 0x40, 0x80 },
    [NUMPAD] = { 0x40, 0x80, 0x40 },
};

void rgb_matrix_set_color_p(int index, uint16_t color[]) {
    rgb_matrix_set_color(index, color[0], color[1], color[2]);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t layer = 0; layer <= get_highest_layer(layer_state); layer++) {
        if (!layer_state_is(layer)) continue;
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                    keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color_p(index, layer_colors[layer]);
                }
            }
        }
    }
    return false;
}

void keyboard_post_init_user(void) {
    // disable matrix glow effect, only use layer indicators
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}
