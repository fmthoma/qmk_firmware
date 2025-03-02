#pragma once

#include "quantum.h"
#include "keymap_german.h"

#define TODO KC_NO
#define ALT_CODE(code) (SS_DOWN(X_LALT) code SS_UP(X_LALT))
#define SEND_ALT_CODE(code) (SEND_STRING (ALT_CODE(code)))
#define WINDOWS(code_windows, code_default) \
    (detected_host_os() == OS_WINDOWS ? code_windows : code_default)

#define HRM_A LGUI_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LSFT_T(KC_D)
#define HRM_F LCTL_T(KC_F)
#define HRM_J RCTL_T(KC_J)
#define HRM_K RSFT_T(KC_K)
#define HRM_L LALT_T(KC_L)
#define HRM_ODIA RGUI_T(DE_ODIA)

#define HRM_N_U LGUI_T(KC_U)
#define HRM_N_I LALT_T(KC_I)
#define HRM_N_A LSFT_T(KC_A)
#define HRM_N_E LCTL_T(KC_E)
#define HRM_N_N RCTL_T(KC_N)
#define HRM_N_R RSFT_T(KC_R)
#define HRM_N_T LALT_T(KC_T)
#define HRM_N_D RGUI_T(KC_D)

#define GUI_INS LGUI_T(KC_INS)
#define SPC_ARRW LT(ARRW, KC_SPC)
#define ESC_FN LT(NUMFN, KC_ESC)
#define MINS_GRV TD(TD_MINS_GRAVE)
#define SS_ACUTE TD(TD_SZLIG_ACUTE)

#define ZOOM_OUT LCTL(KC_PMNS)
#define ZOOM_IN  LCTL(KC_PPLS)

enum custom_layers {
    BASE,   // default layer
    NOHRM,  // disabled home row mods, to resolve timing issues with Neo modifiers

    NEO1,   // Poor Man's Neo layer 1
    NEO2,   // Poor Man's Neo layer 2; should be a fully transparent layer that only exists for the tri-layer state for NEO5
    NEO3,   // Poor Man's Neo layer 3
    NEO4,   // Poor Man's Neo layer 4
    NEO5,   // Poor Man's Neo layer 5
    NEO6,   // Poor Man's Neo layer 6

    ARRW,   // Arrow keys
    NUMFN,  // Number row & Fn keys
    NUMPAD, // Num pad
};

enum custom_keycodes {
    VRSN = SAFE_RANGE, // can always be here
    OSKC_CUT,
    OSKC_COPY,
    OSKC_PSTE,
    NEO_ELL,
    NEO_RDA,
    NEO_LDA,
    NEO_LRDA,
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
    ALPHA,
    EPSILON,
};

// Tap Dance
enum {
    TD_MINS_GRAVE,
    TD_SZLIG_ACUTE,
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
