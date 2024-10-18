#include QMK_KEYBOARD_H
#include "keymap_jp.h"

static bool process_jp_symbols_impl(uint16_t keycode, bool pressed) {
    if (!pressed) {
        return true;
    }
    uint8_t shift = keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
    if (!shift) {
        return true;
    }
    uint16_t s;
    switch (keycode) {
        // Replace Shift-Symbols like ANSI for JIS.
        case JP_2:    s = JP_AT; break;
        case JP_6:    s = JP_CIRC; break;
        case JP_7:    s = JP_AMPR; break;
        case JP_8:    s = JP_ASTR; break;
        case JP_9:    s = JP_LPRN; break;
        case JP_0:    s = JP_RPRN; break;
        case JP_GRV:  s = JP_TILD; break;
        case JP_EQL:  s = JP_PLUS; break;
        case JP_MINS: s = JP_UNDS; break;
        case JP_QUOT: s = JP_DQUO; break;
        case JP_SCLN: s = JP_COLN; break;
        default: return true;
    }
    unregister_mods(shift);
    tap_code16(s);
    register_mods(shift);
    return false;
}

bool process_jp_symbols(uint16_t keycode, keyrecord_t *record) {
    return process_jp_symbols_impl(keycode, record->event.pressed);
}

void tap_code16jp(uint16_t keycode) {
    if (process_jp_symbols_impl(keycode, true)) {
        tap_code16(keycode);
    }
}