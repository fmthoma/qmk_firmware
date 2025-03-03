#include "tap_dance.h"

td_state_t cur_dance(tap_dance_state_t *state) {
    switch (state->count) {
        case 1:
            if (!state->pressed) return TD_SINGLE_TAP;
            return TD_SINGLE_HOLD;
        case 2:
            if (!state->pressed) return TD_DOUBLE_TAP;
            return TD_DOUBLE_HOLD;
        case 3:
            if (!state->pressed) return TD_TRIPLE_TAP;
            return TD_TRIPLE_HOLD;
        default:
            return TD_UNKNOWN;
    }
}

static td_state_t gui_tap_state = TD_NONE;

void gui_tap_finished(tap_dance_state_t *state, void *user_data) {
    gui_tap_state = cur_dance(state);
    switch (gui_tap_state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD: register_code(KC_LGUI); break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD: register_code(KC_LGUI); register_code(KC_LCTL); break;
        case TD_TRIPLE_TAP:
        case TD_TRIPLE_HOLD: register_code(KC_LGUI); register_code(KC_LCTL); register_code(KC_LSFT); break;
        default: break;
    }
}

void gui_tap_reset(tap_dance_state_t *state, void *user_data) {
    switch (gui_tap_state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD: unregister_code(KC_LGUI); break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD: unregister_code(KC_LGUI); unregister_code(KC_LCTL); break;
        case TD_TRIPLE_TAP:
        case TD_TRIPLE_HOLD: unregister_code(KC_LGUI); unregister_code(KC_LCTL); unregister_code(KC_LSFT); break;
        default: break;
    }
}

static td_state_t esc_caps_tap_state = TD_NONE;

void esc_caps_tap_finished(tap_dance_state_t *state, void *user_data) {
    esc_caps_tap_state = cur_dance(state);
    switch (esc_caps_tap_state) {
        case TD_SINGLE_TAP:  register_code(KC_ESC);  break;
        case TD_SINGLE_HOLD: register_code(KC_CAPS); break;
        default: break;
    }
}

void esc_caps_tap_reset(tap_dance_state_t *state, void *user_data) {
    switch (esc_caps_tap_state) {
        case TD_SINGLE_TAP:  unregister_code(KC_ESC);  break;
        case TD_SINGLE_HOLD: unregister_code(KC_CAPS); break;
        default: break;
    }
}
