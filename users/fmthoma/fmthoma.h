#include "keymap_german.h"

#define TODO KC_NO
#define ALT_CODE(code) (SS_DOWN(X_LALT) code SS_UP(X_LALT))
#define SEND_ALT_CODE(code) (SEND_STRING (ALT_CODE(code)))
#define WINDOWS(code_windows, code_default) \
    (detected_host_os() == OS_WINDOWS ? code_windows : code_default)

enum custom_layers {
    BASE,   // default layer
    NOHRM,  // disabled home row mods, to resolve timing issues with Neo modifiers

    NEO1,   // Poor Man's Neo layer 1
    NEO3,   // Poor Man's Neo layer 3
    NEO4,   // Poor Man's Neo layer 4
//    NEO5,   // Poor Man's Neo layer 5
//    NEO6,   // Poor Man's Neo layer 6

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

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

const uint16_t PROGMEM er_del[]        = { KC_E,         KC_R,            COMBO_END };
const uint16_t PROGMEM df_tab[]        = { LALT_T(KC_D), LCTL_T(KC_F),    COMBO_END };
const uint16_t PROGMEM cv_ins[]        = { KC_C,         KC_V,            COMBO_END };
const uint16_t PROGMEM ui_bsp[]        = { KC_U,         KC_I,            COMBO_END };
const uint16_t PROGMEM jk_ent[]        = { RCTL_T(KC_J), LALT_T(KC_K),    COMBO_END };
const uint16_t PROGMEM mc_esc[]        = { KC_M,         KC_COMM,         COMBO_END };
const uint16_t PROGMEM qwer_boot[]     = { KC_Q, KC_W, KC_E, KC_R,        COMBO_END };
const uint16_t PROGMEM neo_er_del[]    = { KC_L,         KC_C,            COMBO_END };
const uint16_t PROGMEM neo_df_tab[]    = { LALT_T(KC_A), LCTL_T(KC_E),    COMBO_END };
const uint16_t PROGMEM neo_cv_ins[]    = { DE_ADIA,      KC_P,            COMBO_END };
const uint16_t PROGMEM neo_ui_bsp[]    = { KC_H,         KC_G,            COMBO_END };
const uint16_t PROGMEM neo_jk_ent[]    = { RCTL_T(KC_N), LALT_T(KC_R),    COMBO_END };
const uint16_t PROGMEM neo_mc_esc[]    = { KC_M,         NEO_COMM_ENDASH, COMBO_END };
const uint16_t PROGMEM neo_qwer_boot[] = { KC_X, KC_V, KC_L, KC_C,        COMBO_END };

combo_t key_combos[] = {
    COMBO(er_del, KC_DEL),
    COMBO(df_tab, KC_TAB),
    COMBO(cv_ins, KC_INS),
    COMBO(ui_bsp, KC_BSPC),
    COMBO(jk_ent, KC_ENT),
    COMBO(mc_esc, KC_ESC),
    COMBO(qwer_boot, QK_BOOT),
    COMBO(neo_er_del, KC_DEL),
    COMBO(neo_df_tab, KC_TAB),
    COMBO(neo_cv_ins, KC_INS),
    COMBO(neo_ui_bsp, KC_BSPC),
    COMBO(neo_jk_ent, KC_ENT),
    COMBO(neo_mc_esc, KC_ESC),
    COMBO(neo_qwer_boot, QK_BOOT),
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_MINS_GRAVE]  = ACTION_TAP_DANCE_DOUBLE(DE_SS,   DE_ACUT), // - -> `
    [TD_SZLIG_ACUTE] = ACTION_TAP_DANCE_DOUBLE(DE_UDIA, DE_PLUS), // ß -> ´
};
