#ifndef _AQUA_C_
#define _AQUA_C_

#include "config_aqua.h"

#include "features/combo.h"
#include "features/translate_ansi_to_jis.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  OUT_TOG = SAFE_RANGE
  ,SRCHSEL
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case OUT_TOG:
      if (record->event.pressed) {
        set_jis_mode(!is_jis_mode());
      }
      return false;
  }


  if (!is_jis_mode()) {
    return true;
  }

  return process_record_user_a2j(keycode, record);
}

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    keyball_set_aml_enable(true)
    set_auto_mouse_layer(MOS);
    set_auto_mouse_enable(true);
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  // レイヤーが1または3の場合、スクロールモードが有効になる
  keyball_set_scroll_mode(get_highest_layer(state) == 1 || get_highest_layer(state) == WIN);
  // keyball_set_scroll_mode(get_highest_layer(state) == 1);

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    keyball_handle_auto_mouse_layer_change(state);
#endif

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

#endif // _AQUA_C_
