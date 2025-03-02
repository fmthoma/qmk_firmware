#include "quantum.h"
#include "fmthoma.h"

#define NEO_LAYER1_MACRO(unshifted, shifted) ({\
    uint8_t mods = get_mods(); \
    if (mods & MOD_MASK_SHIFT) { \
        unregister_mods(mods); \
        shifted; \
        register_mods(mods); \
    } else { \
        tap_code(unshifted); \
    } \
})

char* os_specific_fallback(char* linux, char* windows, char* fallback) {
    switch (detected_host_os()) {
        case OS_LINUX:
            return linux;
        case OS_WINDOWS:
            return windows;
        default:
            return fallback;
    }
}

char* os_specific(char* linux, char* windows) {
    return os_specific_fallback(linux, windows, linux);
}

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
    if (!process_record_keymap(keycode, record)) return false;

    switch (keycode) {
        case KC_CAPS:
            if (record->event.pressed) layer_on(NOHRM);
            else layer_off(NOHRM);
            return true; // pass the key on
        case KC_LSFT:
            if (layer_state_is(NEO1)) {
                if (record->event.pressed) layer_on(NEO2);
                else layer_off(NEO2);
            }
            return true; // pass the key on

        case OSKC_CUT:
            if (record->event.pressed) WINDOWS(tap_code16(C(KC_X)), tap_code16(S(KC_DEL)));
            return false;
        case OSKC_COPY:
            if (record->event.pressed) WINDOWS(tap_code16(C(KC_C)), tap_code16(C(KC_INS)));
            return false;
        case OSKC_PSTE:
            if (record->event.pressed) WINDOWS(tap_code16(C(KC_V)), tap_code16(S(KC_INS)));
            return false;

        case NEO_ELL:
            if (record->event.pressed) WINDOWS(
                SEND_STRING (ALT_CODE("0133")),
                register_unicode(0x2026));
            return false;
        case NEO_RDA:
            if (record->event.pressed) WINDOWS(
                SEND_STRING (ALT_CODE("26")), // Just a single arrow, but better than nothing
                register_unicode(0x21D2));
            return false;
        case NEO_LDA:
            if (record->event.pressed) WINDOWS(
                SEND_STRING (ALT_CODE("27")), // Just a single arrow, but better than nothing
                register_unicode(0x21D0));
            return false;
        case NEO_LRDA:
            if (record->event.pressed) WINDOWS(
                SEND_STRING (ALT_CODE("29")), // Just a single arrow, but better than nothing
                register_unicode(0x21D4));
            return false;

        case ALPHA:
            if (record->event.pressed) WINDOWS(
                SEND_STRING (ALT_CODE("224")),
                register_unicode(0x03B1));
            return false;
        case EPSILON:
            if (record->event.pressed) WINDOWS(
                SEND_STRING (ALT_CODE("238")),
                register_unicode(0x03B5));
            return false;

        case NEO_1_DEG:
            if (record->event.pressed) neo_layer1_shifted(KC_1, DE_CIRC);
            return false;
        case NEO_2_SECT:
            if (record->event.pressed) neo_layer1_shifted(KC_2, DE_3);
            return false;
        case NEO_4_RAQUO:
            if (record->event.pressed) NEO_LAYER1_MACRO(KC_4, WINDOWS(
                SEND_ALT_CODE("0187"),
                register_unicode(0x00BB)));
            return false;
        case NEO_5_LAQUO:
            if (record->event.pressed) NEO_LAYER1_MACRO(KC_5, WINDOWS(
                SEND_ALT_CODE("0171"),
                register_unicode(0x00AB)));
            return false;
        case NEO_6_DLLR:
            if (record->event.pressed) neo_layer1_shifted(KC_6, KC_4);
            return false;
        case NEO_7_EURO:
            if (record->event.pressed) neo_layer1_unshifted(KC_7, DE_EURO);
            return false;
        case NEO_8_BDQUO:
            if (record->event.pressed) NEO_LAYER1_MACRO(KC_8, WINDOWS(
                SEND_ALT_CODE("0132"),
                register_unicode(0x201E)));
            return false;
        case NEO_9_LDQUO:
            if (record->event.pressed) NEO_LAYER1_MACRO(KC_9, WINDOWS(
                SEND_ALT_CODE("0147"),
                register_unicode(0x201C)));
            return false;
        case NEO_0_RDQUO:
            if (record->event.pressed) NEO_LAYER1_MACRO(KC_0, WINDOWS(
                SEND_ALT_CODE("0148"),
                register_unicode(0x201D)));
            return false;
        case NEO_MINS_EMDASH:
            if (record->event.pressed) NEO_LAYER1_MACRO(DE_MINS, WINDOWS(
                SEND_ALT_CODE("0151"),
                register_unicode(0x2014)));
            return false;
        case NEO_COMM_ENDASH:
            if (record->event.pressed) NEO_LAYER1_MACRO(KC_COMM, WINDOWS(
                SEND_ALT_CODE("0150"),
                register_unicode(0x2013)));
            return false;
        case NEO_DOT_BULLET:
            if (record->event.pressed) NEO_LAYER1_MACRO(KC_DOT, WINDOWS(
                SEND_ALT_CODE("0149"),
                register_unicode(0x2022)));
            return false;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, NEO2, NEO3, NEO5);
    state = update_tri_layer_state(state, NEO3, NEO4, NEO6);
    return state;
}

const uint16_t PROGMEM er_del[]        = { KC_E,         KC_R,            COMBO_END };
const uint16_t PROGMEM df_tab[]        = { LSFT_T(KC_D), LCTL_T(KC_F),    COMBO_END };
const uint16_t PROGMEM cv_ins[]        = { KC_C,         KC_V,            COMBO_END };
const uint16_t PROGMEM ui_bsp[]        = { KC_U,         KC_I,            COMBO_END };
const uint16_t PROGMEM jk_ent[]        = { RCTL_T(KC_J), RSFT_T(KC_K),    COMBO_END };
const uint16_t PROGMEM mc_esc[]        = { KC_M,         KC_COMM,         COMBO_END };
const uint16_t PROGMEM neo_er_del[]    = { KC_L,         KC_C,            COMBO_END };
const uint16_t PROGMEM neo_df_tab[]    = { LSFT_T(KC_A), LCTL_T(KC_E),    COMBO_END };
const uint16_t PROGMEM neo_cv_ins[]    = { DE_ADIA,      KC_P,            COMBO_END };
const uint16_t PROGMEM neo_ui_bsp[]    = { KC_H,         KC_G,            COMBO_END };
const uint16_t PROGMEM neo_jk_ent[]    = { RCTL_T(KC_N), RSFT_T(KC_R),    COMBO_END };
const uint16_t PROGMEM neo_mc_esc[]    = { KC_M,         NEO_COMM_ENDASH, COMBO_END };

const uint16_t PROGMEM rt_del[]        = { KC_R,         KC_T,            COMBO_END };
const uint16_t PROGMEM fg_tab[]        = { LCTL_T(KC_F), KC_G,            COMBO_END };
const uint16_t PROGMEM vb_ins[]        = { KC_V,         KC_B,            COMBO_END };
const uint16_t PROGMEM zu_bsp[]        = { DE_Z,         KC_U,            COMBO_END };
const uint16_t PROGMEM hj_ent[]        = { KC_H,         RCTL_T(KC_J),    COMBO_END };
const uint16_t PROGMEM nm_esc[]        = { KC_N,         KC_M,            COMBO_END };
const uint16_t PROGMEM neo_rt_del[]    = { KC_C,         KC_W,            COMBO_END };
const uint16_t PROGMEM neo_fg_tab[]    = { LCTL_T(KC_E), KC_O,            COMBO_END };
const uint16_t PROGMEM neo_vb_ins[]    = { KC_P,         DE_Z,            COMBO_END };
const uint16_t PROGMEM neo_zu_bsp[]    = { KC_K,         KC_H,            COMBO_END };
const uint16_t PROGMEM neo_hj_ent[]    = { KC_S,         RCTL_T(KC_N),    COMBO_END };
const uint16_t PROGMEM neo_nm_esc[]    = { KC_B,         KC_M,            COMBO_END };

const uint16_t PROGMEM qwer_boot[]     = { KC_Q, KC_W, KC_E, KC_R,        COMBO_END };
const uint16_t PROGMEM neo_qwer_boot[] = { KC_X, KC_V, KC_L, KC_C,        COMBO_END };

combo_t key_combos[] = {
    COMBO(er_del, KC_DEL),
    COMBO(df_tab, KC_TAB),
    COMBO(cv_ins, KC_INS),
    COMBO(ui_bsp, KC_BSPC),
    COMBO(jk_ent, KC_ENT),
    COMBO(mc_esc, KC_ESC),
    COMBO(neo_er_del, KC_DEL),
    COMBO(neo_df_tab, KC_TAB),
    COMBO(neo_cv_ins, KC_INS),
    COMBO(neo_ui_bsp, KC_BSPC),
    COMBO(neo_jk_ent, KC_ENT),
    COMBO(neo_mc_esc, KC_ESC),

    COMBO(rt_del, KC_DEL),
    COMBO(fg_tab, KC_TAB),
    COMBO(vb_ins, KC_INS),
    COMBO(zu_bsp, KC_BSPC),
    COMBO(hj_ent, KC_ENT),
    COMBO(nm_esc, KC_ESC),
    COMBO(neo_rt_del, KC_DEL),
    COMBO(neo_fg_tab, KC_TAB),
    COMBO(neo_vb_ins, KC_INS),
    COMBO(neo_zu_bsp, KC_BSPC),
    COMBO(neo_hj_ent, KC_ENT),
    COMBO(neo_nm_esc, KC_ESC),

    COMBO(qwer_boot, QK_BOOT),
    COMBO(neo_qwer_boot, QK_BOOT),
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_MINS_GRAVE]  = ACTION_TAP_DANCE_DOUBLE(DE_SS,   DE_ACUT), // - -> `
    [TD_SZLIG_ACUTE] = ACTION_TAP_DANCE_DOUBLE(DE_UDIA, DE_PLUS), // ß -> ´
};
