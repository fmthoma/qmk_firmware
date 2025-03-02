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

static td_tap_t lgui_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void lgui_tap_finished(tap_dance_state_t *state, void *user_data) {
    lgui_tap_state.state = cur_dance(state);
    switch (lgui_tap_state.state) {
        case TD_SINGLE_TAP:  register_code(KC_INS);  break;
        case TD_SINGLE_HOLD: register_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD: register_code(KC_LGUI); register_code(KC_LCTL); break;
        case TD_TRIPLE_HOLD: register_code(KC_LGUI); register_code(KC_LCTL); register_code(KC_LSFT); break;
        default: break;
    }
}

void lgui_tap_reset(tap_dance_state_t *state, void *user_data) {
    switch (lgui_tap_state.state) {
        case TD_SINGLE_TAP:  unregister_code(KC_INS);  break;
        case TD_SINGLE_HOLD: unregister_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LGUI); unregister_code(KC_LCTL); break;
        case TD_TRIPLE_HOLD: unregister_code(KC_LGUI); unregister_code(KC_LCTL); unregister_code(KC_LSFT); break;
        default: break;
    }
}

