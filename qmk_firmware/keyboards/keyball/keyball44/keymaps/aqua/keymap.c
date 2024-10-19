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
   
    ,                  B_1_R1 , B_1_R2 , B_1_R3 , B_1_R4 , B_1_R5 , B_1_R6
    ,                  B_2_R1 , B_2_R2 , B_2_R3 , B_2_R4 , B_2_R5 , B_2_R6
    ,                  B_3_R1 , B_3_R2 , B_3_R3 , B_3_R4 , B_3_R5 , B_3_R6
    ,         B_4_R1 , B_4_R2 , KC_NO  , KC_NO  , B_4_R5
  ),

  [SYM] = LAYOUT_universal(
      RGB_TOG  , _______  , _______  , _______  , _______  , _______ 
    , RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI 
    , RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SCRL_DVD
    ,                       QK_BOOT  , KBC_RST  , _______  , _______  , _______     
   
    ,                      RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    ,                      RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    ,                      CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
    ,            _______ ,  _______ , _______  , KBC_RST  , QK_BOOT
  ),
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
