#ifndef _AQUA_C_
#define _AQUA_C_

#include "config_aqua.h"

#ifdef ACHORDION_ENABLE
#include "features/achordion.h"
#endif  // ACHORDION_ENABLE
#ifdef LAYER_LOCK_ENABLE
#include "features/layer_lock.h"
#endif  // LAYER_LOCK_ENABLE
#include "features/combo.h"
#include "features/translate_ansi_to_jis.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case B_2_L4:
    case B_2_R3:
      return TAPPING_TERM + 15;
    default:
      return TAPPING_TERM;
  }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    case B_2_L5:
    case B_2_R2:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}

#ifdef ACHORDION_ENABLE
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Also allow same-hand holds when the other key is in the rows outside the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboards are split.
  uint8_t row = other_record->event.key.row % (MATRIX_ROWS / 2);
  if (!(1 <= row && row <= 3)) { return true; }

  switch (tap_hold_keycode) {
    // Exceptionally allow symbol layer LTs + row 0 in same-hand chords.
    case B_2_L2:
    case B_2_R5:
      if (row == 0) { return true; }
      break;
  }

  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case NAV_ET:  return 200;  // Use a timeout of 800 ms.
    case B_3_R5:  return 200;  // Use a timeout of 800 ms.
    default: return 700;  // Use a timeout of 800 ms.
  }
}

uint16_t achordion_streak_chord_timeout(
    uint16_t tap_hold_keycode, uint16_t next_keycode) {
  // Disable streak detection on LT keys.
  if ((tap_hold_keycode)) {
    return 0;
  }

  // Exceptions so that certain hotkeys don't get blocked as streaks.
  switch (tap_hold_keycode) {
    case B_2_R2:
      if (next_keycode == KC_C || next_keycode == KC_V) {
        return 0;
      }
      break;
    case B_2_L5:
      if (next_keycode == HOM_N) {
        return 0;
      }
      break;
  }

  // Otherwise, tap_hold_keycode is a mod-tap key.
  const uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & MOD_LSFT) != 0) {
    return 100;  // A short streak timeout for Shift mod-tap keys.
  } else {
    return 220;  // A longer timeout otherwise.
  }
}
#endif  // ACHORDION_ENABLE

#ifdef ALT_KEYMAP_ENABLE
// An enhanced version of SEND_STRING: if Caps Word is active, the Shift key is
// held while sending the string. Additionally, the last key is set such that if
// the Repeat Key is pressed next, it produces `repeat_keycode`.
#define MAGIC_STRING(str, repeat_keycode) \
        magic_send_string_P(PSTR(str), (repeat_keycode))
 
static void magic_send_string_P(const char* str, uint16_t repeat_keycode) {
    uint8_t saved_mods = 0;
 
  if (is_caps_word_on()) { // If Caps Word is on, save the mods and hold Shift.
    saved_mods = get_mods();
    register_mods(MOD_BIT(KC_LSFT));
  }
 
  send_string_with_delay_P(str, TAP_CODE_DELAY);  // Send the string.
  set_last_keycode(repeat_keycode); // 2024-03-09 Disabled sending of string for mag-rep / rep-mag consistency.
 
  // If Caps Word is on, restore the mods.
  if (is_caps_word_on()) {
    set_mods(saved_mods);
  }
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) { 
        case LMAGIC:
        case RMAGIC:
            return false;  // Magic keys will ignore the above keycodes.
    }
    return true;  // Other keys can be repeated.
}

static void process_right_magic(uint16_t keycode, uint8_t mods) { // LMAGIC definitions
    switch (keycode) {
        case HOM_A: { MAGIC_STRING("a",         KC_NO); } break;
        case  KC_B: { MAGIC_STRING("m",         KC_NO); } break;
        case  KC_C: { MAGIC_STRING("k",         KC_NO); } break;
        case  KC_D: { MAGIC_STRING("r",         KC_NO); } break;
        case HOM_E: { MAGIC_STRING("e",         KC_NO); } break;
        case  KC_F: { MAGIC_STRING("f",         KC_NO); } break;
        case HOM_G: { MAGIC_STRING("z",         KC_NO); } break;
        case HOM_H: { MAGIC_STRING("l",         KC_NO); } break;
        case HOM_I: { MAGIC_STRING("i",         KC_NO); } break;
        case  KC_J: { MAGIC_STRING("j",         KC_NO); } break;
        case  KC_K: { MAGIC_STRING("c",         KC_NO); } break;
        case  KC_L: { MAGIC_STRING("d",         KC_NO); } break;
        case NUM_M: { MAGIC_STRING("b",         KC_NO); } break;
        case HOM_N: { MAGIC_STRING("n",         KC_NO); } break;
        case  KC_O: { MAGIC_STRING("o",         KC_NO); } break;
        case HOM_P: { MAGIC_STRING("x",         KC_NO); } break;
        case  KC_Q: { MAGIC_STRING("q",         KC_NO); } break;
        case HOM_R: { MAGIC_STRING("d",         KC_NO); } break;
        case HOM_S: { MAGIC_STRING("k",         KC_NO); } break;
        case HOM_T: { MAGIC_STRING("b",         KC_NO); } break;
        case  KC_U: { MAGIC_STRING("u",         KC_NO); } break;
        case  KC_V: { MAGIC_STRING("b",         KC_NO); } break;
        case  KC_W: { MAGIC_STRING("w",         KC_NO); } break;
        case  KC_X: { MAGIC_STRING("p",         KC_NO); } break;
        case  KC_Y: { MAGIC_STRING("y",         KC_NO); } break;
        case  KC_Z: { MAGIC_STRING("v",         KC_NO); } break;
        
        case KC_SPC:{ MAGIC_STRING(" ",         KC_NO); } break;

    }
}
 
static void process_left_magic(uint16_t keycode, uint8_t mods) { // RMAGIC definitions
    switch (keycode) {        
        case HOM_A: { MAGIC_STRING("o",         KC_NO); } break;
        case  KC_B: { MAGIC_STRING("b",         KC_NO); } break;
        case  KC_C: { MAGIC_STRING("c",         KC_NO); } break;
        case  KC_D: { MAGIC_STRING("d",         KC_NO); } break;
        case HOM_E: { MAGIC_STRING("q",         KC_NO); } break;
        case  KC_F: { MAGIC_STRING("y",         KC_NO); } break;
        case HOM_G: { MAGIC_STRING("g",         KC_NO); } break;
        case HOM_H: { MAGIC_STRING("h",         KC_NO); } break;
        case HOM_I: { MAGIC_STRING("u",         KC_NO); } break;
        case  KC_J: { MAGIC_STRING("y",         KC_NO); } break;
        case  KC_K: { MAGIC_STRING("k",         KC_NO); } break;
        case  KC_L: { MAGIC_STRING("l",         KC_NO); } break;
        case NUM_M: { MAGIC_STRING("m",         KC_NO); } break;
        case HOM_N: { MAGIC_STRING("y",         KC_NO); } break;
        case  KC_O: { MAGIC_STRING("a",         KC_NO); } break;
        case HOM_P: { MAGIC_STRING("p",         KC_NO); } break;
        case  KC_Q: { MAGIC_STRING("e",         KC_NO); } break;
        case HOM_R: { MAGIC_STRING("r",         KC_NO); } break;
        case HOM_S: { MAGIC_STRING("s",         KC_NO); } break;
        case HOM_T: { MAGIC_STRING("t",         KC_NO); } break;
        case  KC_U: { MAGIC_STRING("i",         KC_NO); } break;
        case  KC_V: { MAGIC_STRING("v",         KC_NO); } break;
        case  KC_W: { MAGIC_STRING("n",         KC_NO); } break;
        case  KC_X: { MAGIC_STRING("x",         KC_NO); } break;
        case  KC_Y: { MAGIC_STRING("n",         KC_NO); } break;
        case  KC_Z: { MAGIC_STRING("z",         KC_NO); } break;

        case KC_SPC:{ MAGIC_STRING(" ",         KC_NO); } break;

    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {;
#ifdef ACHORDION_ENABLE
  if (!process_achordion(keycode, record)) { return false; }
#endif  // ACHORDION_ENABLE
#ifdef LAYER_LOCK_ENABLE
  if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
#endif  // LAYER_LOCK_ENABLE
  
  if (record->event.pressed) {
    switch (keycode) {
#ifdef A2J_ENABLE
      case OUT_TOG:  set_jis_mode(!is_jis_mode()); return false;
#endif  // A2J_ENABLEm
#ifdef ALT_KEYMAP_ENABLE
      case UPDIR:    SEND_STRING_DELAY("../", TAP_CODE_DELAY); return false;
      case LMAGIC: { process_left_magic(get_last_keycode(), get_last_mods()); set_last_keycode(KC_SPC);} return false;
      case RMAGIC: { process_right_magic(get_last_keycode(), get_last_mods());set_last_keycode(KC_NO);} return false;
#endif
    }
  }

  if (!is_jis_mode()) {
    return true;
  }

#ifdef A2J_ENABLE
  return process_record_user_a2j(keycode, record);
#else
  return true
#endif  // A2J_ENABLE
}

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_layer(MOS);
    set_auto_mouse_enable(true);
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  // レイヤーが1または3の場合、スクロールモードが有効になる
  keyball_set_scroll_mode(get_highest_layer(state) == 1 || get_highest_layer(state) == WIN);
  // keyball_set_scroll_mode(get_highest_layer(state) == 1);

  // checks highest layer other than target layer
  switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
      case WIN:
          // remove_auto_mouse_target must be called to adjust state *before* setting enable
          state = remove_auto_mouse_layer(state, false);
          set_auto_mouse_enable(false);
          break;
      default:
          set_auto_mouse_enable(true);
          break;
  }
  
  // レイヤーとLEDを連動させる
  switch (get_highest_layer(state)) {
    case MOS:
      rgblight_sethsv(HSV_WHITE);
      break;
    case NUM:
      rgblight_sethsv(HSV_RED);
      break;
    case FUN:
      rgblight_sethsv(HSV_ORANGE);
      break;
    case WIN:
      rgblight_sethsv(HSV_CHARTREUSE);
      break;
    case SYM:
      rgblight_sethsv(HSV_YELLOW);
      break;
    case NAV:
      rgblight_sethsv(HSV_GREEN);
      break;

    default:
      rgblight_sethsv(HSV_OFF);
  }

  return state;
}

#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}
#endif  // CAPS_WORD_ENABLE

void matrix_scan_user(void) {
#ifdef ACHORDION_ENABLE
  achordion_task();
#endif  // ACHORDION_ENABLE
#ifdef LAYER_LOCK_ENABLE
  layer_lock_task();
#endif  // LAYER_LOCK_ENABLE
}

#endif // _AQUA_C_
