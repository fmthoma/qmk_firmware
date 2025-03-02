#pragma once

#include "keymap_common.h"
#include "tap_dance.h"

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

layer_state_t layer_state_set_keymap(layer_state_t state);
