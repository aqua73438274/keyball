/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "aqua.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for development
  [BASE] = LAYOUT_universal(
      B_1_L1 , B_1_L2 , B_1_L3 , B_1_L4 , B_1_L5 , B_1_L6
    , B_2_L1 , B_2_L2 , B_2_L3 , B_2_L4 , B_2_L5 , B_2_L6
    , B_3_L1 , B_3_L2 , B_3_L3 , B_3_L4 , B_3_L5 , B_3_L6
    ,                   B_4_L2 , B_4_L3 , B_4_L4 , B_4_L5 , B_4_L6
   
    ,                   B_1_R1 , B_1_R2 , B_1_R3 , B_1_R4 , B_1_R5 , B_1_R6
    ,                   B_2_R1 , B_2_R2 , B_2_R3 , B_2_R4 , B_2_R5 , B_2_R6
    ,                   B_3_R1 , B_3_R2 , B_3_R3 , B_3_R4 , B_3_R5 , B_3_R6
    ,          B_4_R1 , B_4_R2 , KC_NO  , KC_NO  , B_4_R5
  )

  ,[SYM] = LAYOUT_universal(
      _______, _______, KC_LABK, KC_RABK, KC_BSLS, KC_GRV 
    , _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH
    , _______, _______, KC_SLSH, KC_ASTR, KC_CIRC, _______
    ,                   _______, _______, _______, _______, _______
   
    ,                   KC_AMPR, _______, KC_LBRC, KC_RBRC, _______, _______
    ,                   KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_PERC, _______
    ,                   KC_TILD, KC_DLR , KC_LCBR, KC_RCBR, _______, _______
    ,         _______ , _______, _______, _______, _______
  )

  ,[NUM] = LAYOUT_universal(
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    , _______, XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX
    , _______, KC_LGUI, XXXXXXX, KC_LCTL, XXXXXXX, XXXXXXX
    ,                   _______, _______, _______, _______, _______
   
    ,                   KC_TAB , KC_8   , KC_9   , KC_4   , KC_PLUS, KC_SLSH
    ,                   KC_COLN, KC_1   , KC_2   , KC_3   , KC_MINS, KC_ASTR
    ,                   KC_COMM, KC_7   , KC_6   , KC_5   , KC_DOT , _______
    ,         _______ , _______, _______, _______, _______
  )

  ,[WIN] = LAYOUT_universal(
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    , _______, XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX
    , _______, KC_LGUI, XXXXXXX, KC_LCTL, XXXXXXX, XXXXXXX
    ,                   _______, _______, _______, _______, _______
   
    ,                 G(KC_TAB), G(KC_8), G(KC_9), G(KC_4), XXXXXXX, XXXXXXX
    ,             G(S(KC_LEFT)), G(KC_1), G(KC_2), G(KC_3), G(S(KC_RGHT)), XXXXXXX
    ,                   XXXXXXX, G(KC_7), G(KC_6), G(KC_5), KC_VOLD , KC_VOLU
    ,         _______ , _______, _______, _______, _______
  )

  ,[FUN] = LAYOUT_universal(
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    , _______, XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX
    , _______, KC_LGUI, XXXXXXX, KC_LCTL, XXXXXXX, XXXXXXX
    ,                   _______, _______, _______, _______, _______
   
    ,                   XXXXXXX, KC_F8  , KC_F9  , KC_F4  , KC_F10 , XXXXXXX
    ,                   XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F11 , XXXXXXX
    ,                   XXXXXXX, KC_F7  , KC_F6  , KC_F5  , KC_F12 , _______
    ,         _______ , _______, _______, _______, _______

  ,[NAV] = LAYOUT_universal(
      _______, XXXXXXX, KC_BSPC, KC_UP  , KC_DEL , XXXXXXX
    , _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
    , _______, KC_LGUI, KC_ENT , KC_PGUP, KC_APP , KC_PGDN
    ,                   _______, _______, _______, _______, _______
   
    ,                   XXXXXXX, KC_BSPC, KC_UP  , KC_DEL , XXXXXXX , XXXXXXX
    ,                   KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END  , XXXXXXX
    ,                   KC_ENT , KC_PGUP, KC_APP , KC_PGDN, XXXXXXX , _______
    ,         _______ , _______, _______, _______, _______
  )
};
// clang-format on

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
