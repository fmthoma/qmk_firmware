__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

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
            if (record->event.pressed) {
                layer_on(NOHRM);
            } else {
                layer_off(NOHRM);
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

        case VRSN:
            if (record->event.pressed) SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
    }
    return true;
}
