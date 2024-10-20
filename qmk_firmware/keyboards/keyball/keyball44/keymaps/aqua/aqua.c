#ifndef _AQUA_C_
#define _AQUA_C_

#include "config_aqua.h"

#include "features/combo.h"
#include "a2j/translate_ansi_to_jis.h"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  ...

  if (!is_jis_mode()) {
    return true;
  }

  return process_record_user_a2j(keycode, record);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  // レイヤーが1または3の場合、スクロールモードが有効になる
  keyball_set_scroll_mode(get_highest_layer(state) == 1 || get_highest_layer(state) == MOS);
  // keyball_set_scroll_mode(get_highest_layer(state) == 1);

  // レイヤーとLEDを連動させる
  switch (get_highest_layer(state)) {
    case MOS:
      rgblight_sethsv(HSV_WHITE);
      break;
    case 1:
      rgblight_sethsv(HSV_RED);
      break;
    case 2:
      rgblight_sethsv(HSV_YELLOW);
      break;
    case 3:
      rgblight_sethsv(HSV_GREEN);
      break;

    default:
      rgblight_sethsv(HSV_OFF);
  }

  return state;
}

#endif // _AQUA_C_
