#pragma once

#include "fmthoma.h"

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

td_state_t cur_dance(tap_dance_state_t *state);

void gui_tap_finished(tap_dance_state_t *state, void *user_data);
void gui_tap_reset(tap_dance_state_t *state, void *user_data);

void esc_caps_tap_finished(tap_dance_state_t *state, void *user_data);
void esc_caps_tap_reset(tap_dance_state_t *state, void *user_data);
