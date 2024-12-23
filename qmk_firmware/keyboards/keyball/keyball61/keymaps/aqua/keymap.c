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
      KC_ESC ,G(KC_TAB),KC_F2  , KC_F3  , KC_F4  , KC_F5 
    , B_1_L1 , B_1_L2 , B_1_L3 , B_1_L4 , B_1_L5 , B_1_L6
    , B_2_L1 , B_2_L2 , B_2_L3 , B_2_L4 , B_2_L5 , B_2_L6
    , B_3_L1 , B_3_L2 , B_3_L3 , B_3_L4 , B_3_L5 , B_3_L6 , B_3_L7
    , B_4_L1 , B_4_L2 , B_4_L3 , B_4_L4 , B_4_L5 , B_4_L6 , B_4_L7

    ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11
    ,                   B_1_R1 , B_1_R2 , B_1_R3 , B_1_R4 , B_1_R5 , B_1_R6
    ,                   B_2_R1 , B_2_R2 , B_2_R3 , B_2_R4 , B_2_R5 , B_2_R6
    ,          B_3_R0 , B_3_R1 , B_3_R2 , B_3_R3 , B_3_R4 , B_3_R5 , B_3_R6
    ,          B_4_R0 , B_4_R1 , KC_NO  , KC_NO  , KC_NO  , B_4_R5 , B_4_R6
  )

  ,[MOS] = LAYOUT_universal(
      _______, _______, _______, _______, _______, _______
    , _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    , _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_TAB
    , _______, KC_LGUI, XXXXXXX, KC_LCTL, XXXXXXX, XXXXXXX , XXXXXXX
    , _______, _______, _______, _______, _______, TO(BASE), _______
   
    ,                   _______, _______  , _______  , _______  , _______ , _______
    ,                  XXXXXXX , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX
    ,                  KC_BTN5 , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX
    ,         _______ ,KC_BTN4 , KC_BTN3  , KC_BTN1  , KC_BTN2  , _______ , _______
    ,         LLOCK   , NAV_ET , XXXXXXX  , XXXXXXX  , _______  , _______ , _______
  )

  ,[SYM] = LAYOUT_universal(
      _______, _______, _______, _______, _______, _______
    , _______, KC_GRV , KC_LABK, KC_RABK, KC_DQT , KC_CIRC
    ,GS(KC_S), KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH
    , _______, _______, KC_SLSH, KC_ASTR, KC_BSLS, UPDIR  , _______
    , _______, _______, _______, _______, _______, _______, _______
   
    ,                   _______, _______, _______, _______, _______, _______
    ,                   KC_AMPR, KC_QUOT, KC_LBRC, KC_RBRC, KC_PERC, _______
    ,                   KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, _______
    ,         _______ , KC_TILD, KC_DLR , KC_LCBR, KC_RCBR, KC_AT  , _______
    ,         _______ , _______, XXXXXXX, XXXXXXX, _______, _______, _______
  )

  ,[NUM] = LAYOUT_universal(
      _______, _______, _______, _______, _______, _______
    , _______, XXXXXXX, KC_D   , KC_E   , KC_F   , XXXXXXX
    , _______, XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, KC_X
    , _______, KC_LGUI, KC_A   , KC_B   , KC_C   , XXXXXXX , XXXXXXX
    , _______, _______, _______, _______, KC_LCTL, _______ , TO(BASE)
   
    ,                   _______, _______, _______, _______, _______, _______
    ,                   KC_TAB , KC_7   , KC_8   , KC_9   , KC_PLUS, KC_SLSH
    ,                   KC_COLN, KC_1   , KC_2   , KC_3   , KC_MINS, KC_ASTR
    ,         _______ , KC_COMM, KC_4   , KC_5   , KC_6   , KC_DOT , _______
    ,         LLOCK   , KC_0   , XXXXXXX, XXXXXXX, _______, _______, _______
  )

  ,[WIN] = LAYOUT_universal(
      _______, _______, _______, _______, _______, _______
    , _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    , _______, XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX
    , _______, KC_LGUI, XXXXXXX, KC_LCTL, XXXXXXX, XXXXXXX , XXXXXXX
    , _______, _______,  _______, _______, _______, _______, _______
   
    ,                   _______, _______  , _______  , _______  , _______ , _______
    ,                   XXXXXXX, G(KC_7)  , G(KC_8)  , G(KC_9)  , XXXXXXX , XXXXXXX
    ,               GS(KC_LEFT), G(KC_1)  , KC_F11   , G(KC_3)  ,GS(KC_RGHT), XXXXXXX
    ,       _______ ,S(C(KC_T)),C(KC_PGUP), KC_F5    ,C(KC_PGDN), KC_VOLD , KC_VOLU
    ,       LLOCK   ,  C(KC_W) , _______  , _______  , _______  , _______ , _______
  )

  ,[FUN] = LAYOUT_universal(
      _______, _______, _______, _______, _______, _______
    , OUT_TOG, AML_TO , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    , _______, XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX
    , _______, KC_LGUI, XXXXXXX, KC_LCTL, XXXXXXX, XXXXXXX , XXXXXXX
    , _______, _______, _______, _______, _______, TO(BASE), _______
   
    ,                   _______, _______, _______, _______, _______, _______
    ,                   XXXXXXX, KC_F7  , KC_F8  , KC_F9  , KC_F10 , XXXXXXX
    ,                   XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F11 , XXXXXXX
    ,         _______ , XXXXXXX, KC_F4  , KC_F5  , KC_F6  , KC_F12 , _______
    ,         _______ , _______, XXXXXXX, XXXXXXX, _______, _______, _______
  )

  ,[NAV] = LAYOUT_universal(
      _______   , _______, _______  , _______ , _______  , _______
    , _______   , XXXXXXX, XXXXXXX  , XXXXXXX , XXXXXXX  , XXXXXXX
    , _______   , KC_LGUI, KC_LALT  , KC_LSFT , KC_LCTL  , KC_TAB
    , _______   , KC_LGUI, XXXXXXX  , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX
    , KC_PGUP   , KC_LEFT,  KC_RGHT , KC_PGDN ,C(KC_PGUP), _______ ,C(KC_PGDN)

    ,                   _______, _______, _______, _______, _______ , _______
    ,                   XXXXXXX, KC_BSPC, KC_UP  , KC_DEL , XXXXXXX ,  GC(KC_F4)
    ,                   KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END  ,  GC(KC_D)
    ,         _______ , KC_ENT , KC_PGUP, KC_APP , KC_PGDN,GC(KC_LEFT),GC(KC_RGHT)
    ,         _______ , _______, XXXXXXX, XXXXXXX, _______, G(KC_TAB), _______
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
