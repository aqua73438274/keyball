/*
 * Copyright 2022 @Yowkees
 * Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)
 * Copyright 2023 kamidai (@d_kamiichi)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------
 *
 * 参考文献：
 * - リポジトリ：
 *   https://github.com/kamiichi99/keyball/tree/main/qmk_firmware/keyboards/keyball/keyball39/keymaps/kamidai
 *
 * - keyballの販売ページ
 *   https://shirogane-lab.com/collections/all
 *
 * コード表：
 * - 公式ファームウェアのキーコード：
 *   KBC_RST(0x5DA5): Keyball 設定のリセット
 *   KBC_SAVE(0x5DA6): 現在の Keyball 設定を EEPROM に保存します
 *   CPI_I100(0x5DA7): CPI を 100 増加させます(最大:12000)
 *   CPI_D100(0x5DA8): CPI を 100 減少させます(最小:100)
 *   CPI_I1K(0x5DA9): CPI を 1000 増加させます(最大:12000)
 *   CPI_D1K(0x5DAA): CPI を 1000 減少させます(最小:100)
 *   SCRL_TO(0x5DAB): タップごとにスクロールモードの ON/OFF を切り替えます
 *   SCRL_MO(0x5DAC): キーを押している間、スクロールモードになります
 *   SCRL_DVI(0x5DAD): スクロール除数を１つ上げます(max D7 = 1/128)← 最もスクロール遅い
 *   SCRL_DVD(0x5DAE): スクロール除数を１つ下げます(min D0 = 1/1)← 最もスクロール速い
 *
 * - オリジナルのキーコード：
 *   KC_BACK_TO_LAYER0_BTN1(0x5DAF): レイヤー0に遷移できるBTN1
 *   KC_DOUBLE_CLICK_BTN1(0x5DB0): 1タップでダブルクリックできるBTN1
 *   KC_TRIPLE_CLICK_BTN1(0x5DB1): 1タップでトリプルクリックできるBTN1
 */

#include QMK_KEYBOARD_H
#include "keymap_japanese.h"
#include "quantum.h"

#include "utils/functions.h"
#include "features/twpair_on_jis.h"
#include "features/swipe_gesture.h"
#include "features/auto_click_layer.h"
// #include "features/back_to_layer0_btn1.h"
// #include "features/one_tap_multi_click.h"
 #include "features/macro_keys.h"

// 容量オーバーのため不使用（VIAをOFFにすれば、使用可能）
#include "features/overrides.h"
#include "features/combo.h"

#define GC(key) RGUI(RCTL(key))

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  #if 0
  // keymap for default
  [0] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_DEL   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_INT3  ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , S(KC_7)  ,
    MO(1)    , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_RBRC  ,              KC_NUHS, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
    _______  , KC_LCTL  , KC_LALT  , KC_LGUI,LT(1,KC_LNG2),LT(2,KC_SPC),LT(3,KC_LNG1),    KC_BSPC,LT(2,KC_ENT),LT(1,KC_LNG2),KC_RGUI, _______ , KC_RALT  , KC_PSCR
  ),

  [1] = LAYOUT_universal(
    S(KC_ESC), S(KC_1)  , KC_LBRC  , S(KC_3)  , S(KC_4)  , S(KC_5)  ,                                  KC_EQL   , S(KC_6)  ,S(KC_QUOT), S(KC_8)  , S(KC_9)  ,S(KC_INT1),
    S(KC_DEL), S(KC_Q)  , S(KC_W)  , S(KC_E)  , S(KC_R)  , S(KC_T)  ,                                  S(KC_Y)  , S(KC_U)  , S(KC_I)  , S(KC_O)  , S(KC_P)  ,S(KC_INT3),
    S(KC_TAB), S(KC_A)  , S(KC_S)  , S(KC_D)  , S(KC_F)  , S(KC_G)  ,                                  S(KC_H)  , S(KC_J)  , S(KC_K)  , S(KC_L)  , KC_QUOT  , S(KC_2)  ,
    _______  , S(KC_Z)  , S(KC_X)  , S(KC_C)  , S(KC_V)  , S(KC_B)  ,S(KC_RBRC),           S(KC_NUHS), S(KC_N)  , S(KC_M)  ,S(KC_COMM), S(KC_DOT),S(KC_SLSH),S(KC_RSFT),
    _______  ,S(KC_LCTL),S(KC_LALT),S(KC_LGUI), _______  , _______  , _______  ,            _______  , _______  , _______  ,S(KC_RGUI), _______  , S(KC_RALT), _______
  ),

  [2] = LAYOUT_universal(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , _______  , KC_7     , KC_8     , KC_9     , _______  ,                                  _______  , KC_LEFT  , KC_UP    , KC_RGHT  , _______  , KC_F12   ,
    _______  , _______  , KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                                  KC_PGUP  , KC_BTN1  , KC_DOWN  , KC_BTN2  , KC_BTN3  , _______  ,
    _______  , _______  , KC_1     , KC_2     , KC_3     ,S(KC_MINS), S(KC_8)  ,            S(KC_9)  , KC_PGDN  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , KC_0     , KC_DOT   , _______  , _______  , _______  ,             KC_DEL  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , _______  , _______  , _______  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , _______  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
    _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , KC_RBRC  ,            KC_RBRC  , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
    KBC_RST    , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,            _______  , KC_BSPC  , _______  , _______  , _______  , _______  , KBC_RST
  ),

  [4] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  ,KC_MS_BTN1, _______  ,KC_MS_BTN2, _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  i, _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______
  ) 
    JP_GRV       , KC_Q      , KC_L      , KC_U      , KC_COMM     , KC_DOT   ,                   JP_F     , JP_W        , KC_R      , KC_Y      ,JP_QUOT    ,JP_DQUO,
    LT(2,JP_COLN),SFT_T(KC_E),CTL_T(KC_I),ALT_T(KC_A),GUI_T(KC_O)  , KC_SCLN  ,                   KC_K     ,GUI_T(KC_T)  ,ALT_T(KC_N),CTL_T(KC_S),SFT_T(KC_H), LT(2,KC_P) ,
    JP_AT        , KC_Z      , KC_X      , KC_C      , KC_V        , KC_SLSH  ,                   KC_G     , KC_D        , KC_M      , KC_J      ,LT(3,KC_B) , KC_INT1   ,

    JP_GRV    , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_INT3  ,
  LT(2,KC_TAB), SFT_T(KC_A),CTL_T(KC_S),ALT_T(KC_D),GUI_T(KC_F), KC_G     ,                             KC_H     ,GUI_T(KC_J),ALT_T(KC_K),CTL_T(KC_L),SFT_T(JP_SCLN), LT(2,JP_QUOT) ,
    JP_AT     , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                  KC_N     , KC_M     , KC_COMM  , KC_DOT   ,LT(3,KC_SLSH), KC_RSFT  ,



  [0] = LAYOUT_universal(
    KC_DLR       , KC_Q      , KC_L      , KC_U      , KC_COMM     , KC_DOT   ,                JP_F     , JP_W        , KC_R        , KC_Y      ,JP_QUOT    ,JP_DQUO,
    LT(2,KC_TAB) ,SFT_T(KC_E),CTL_T(KC_I),ALT_T(KC_A),GUI_T(KC_O)  , KC_SCLN  ,                KC_K     ,GUI_T(KC_T)  , ALT_T(KC_N) ,CTL_T(KC_S),SFT_T(KC_H), LT(2,KC_P) ,
    JP_AT        , KC_Z      , KC_X      , KC_C      , KC_V        , KC_SLSH  ,                KC_G     , KC_D        , KC_M        , KC_J      ,LT(3,KC_B) , KC_INT1   ,
                LT(3,KC_DOWN),LT(3,KC_UP),KC_LGUI    ,SFT_T(KC_SPC),LT(1,KC_MINS),         LT(2,KC_BSPC),LT(3,KC_ENT) ,LT(1,KC_LNG2),KC_RGUI    ,KC_MS_BTN1   
  ),

  [1] = LAYOUT_universal(
    S(KC_DEL), KC_EXLM  , JP_AT    , KC_HASH  , KC_DLR  , KC_PERC  ,                       JP_CIRC   , JP_AMPR  ,JP_ASTR   , JP_LPRN  , JP_RPRN  ,JP_PIPE,
    KC_0     , KC_0     , KC_1     , KC_2     , KC_3    , KC_4     ,                        KC_5     ,    KC_6  ,KC_7      , KC_8     , KC_9     ,KC_0      ,
    _______  , KC_AMPR  , KC_HASH  , KC_COLN  , KC_EQL  , KC_SLSH  ,                        KC_ASTR  , KC_PLUS  ,S(KC_COMM), S(KC_DOT),S(KC_SLSH),S(KC_RSFT),
              S(KC_LALT),S(KC_LGUI), _______  , _______ , _______  ,                        _______  , _______  , _______  ,S(KC_RGUI), _______ 
  ),

  [2] = LAYOUT_universal(
    _______  ,RCS(JP_1) , RCS(JP_3), RCS(JP_2), RCS(JP_9), RCS(JP_7),                      JP_PERC  ,JP_AT     , JP_LCBR  , JP_RCBR  ,JP_EXLM   , JP_BSLS  ,
    RSG(KC_S), _______  , JP_4     , JP_5     , JP_6     ,S(JP_SCLN),                      JP_MINS  , JP_EQL   , JP_LPRN  , JP_RPRN  ,JP_PIPE   , JP_HASH,
    _______  , _______  , JP_1     , JP_2     , JP_3     ,S(JP_MINS),                      JP_ASTR  ,JP_PLUS   , JP_LBRC  , JP_RBRC  ,JP_AMPR   ,JP_QUES,
                KC_LNG1 , KC_LNG2  , _______  , _______  , _______  ,                       KC_DEL  , _______  , _______  , _______  , _______ 
  ),

  [3] = LAYOUT_universal(
  LCA(KC_DEL), KC_F11   , KC_F2    ,LSG(KC_3)  ,LSG(KC_4) ,LSG(KC_5) ,                       KC_END , KC_PGUP   , KC_UP    , KC_PGDN  , KC_END      , _______  ,
    _______  , KC_LSFT  , KC_LCTL  , KC_LALT   , KC_LGUI  ,C(KC_RGHT),                    KC_HOME   , KC_LEFT   , KC_DOWN  , KC_RGHT  ,LCAG(KC_LEFT),LCAG(KC_RGHT)  ,
    _______  , C(KC_Z)  , C(KC_X)  , C(KC_C)   , C(KC_V)  , KC_F11    ,                   KC_HOME   , KC_PGDN   , KC_PGUP  , KC_END   , GC(KC_D)    , GC(KC_F4)  ,
                KC_LEFT , KC_RGHT  , C(KC_PGUP), _______  ,C(KC_PGDN) ,                    _______  , KC_BSPC   , _______  , _______  , _______ 
  ),

  [4] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                       _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , KC_LSFT  , KC_LCTL  , KC_LALT  , KC_LGUI  , _______  ,                      KC_MS_BTN5, _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                      KC_MS_BTN4,KC_MS_BTN3,KC_MS_BTN1,KC_MS_BTN2, _______  , _______  ,
               _______  , _______  , _______  , _______  , _______  ,                       _______  , _______  , _______  , _______  , _______  
  )

#else
  // keymap for default
  [0] = LAYOUT_universal(
    KC_DLR       , KC_Q      , KC_Y      , KC_U      , KC_COMM     , KC_DOT   ,                KC_F     , KC_W        , KC_M        , KC_R      ,KC_P    ,KC_GRAVE,
    LT(2,KC_TAB) ,SFT_T(KC_E),CTL_T(KC_I),ALT_T(KC_A),GUI_T(KC_O)  , KC_L  ,                KC_K     ,GUI_T(KC_T)  , ALT_T(KC_N) ,CTL_T(KC_S),SFT_T(KC_H), LT(2,KC_B) ,
    KC_AT        , KC_Z      , KC_X      , KC_C      , KC_V        , KC_SLSH  ,                KC_G     , KC_D        , KC_MS_BTN1  ,KC_J ,LT(3,_______) , KC_QUOT   ,
                LT(3,KC_DOWN),LT(3,KC_UP),KC_LGUI    ,SFT_T(KC_SPC),LT(1,KC_MINS),         LT(1,KC_BSPC),LT(3,KC_ENT) ,LT(1,KC_LNG2),KC_RGUI    ,KC_MS_BTN2   
  ),

  [1] = LAYOUT_universal(
    S(KC_DEL), KC_F10   , KC_F11   , KC_F2    , KC_F3   , KC_F4    ,                        KC_F5    , KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F11   ,
    KC_0     , KC_0     , KC_1     , KC_2     , KC_3    , KC_4     ,                        KC_5     ,    KC_6  ,KC_7      , KC_8     , KC_9     ,KC_0      ,
    _______  , KC_AMPR  , KC_HASH  , KC_COLN  , KC_EQL  , KC_SLSH  ,                        KC_ASTR  , KC_PLUS  ,S(KC_COMM), S(KC_DOT),S(KC_SLSH),S(KC_RSFT),
              S(KC_LALT),S(KC_LGUI), _______  , _______ , _______  ,                        _______  , _______  , _______  ,S(KC_RGUI), _______ 
  ),

  [2] = LAYOUT_universal(
    _______  ,RCS(KC_1) , RCS(KC_3), RCS(KC_2), RCS(KC_9), RCS(KC_7),                      KC_PERC  ,KC_AT     , KC_LCBR  , KC_RCBR  ,KC_PIPE   , KC_BSLS  ,
    RSG(KC_S), _______  , KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                      KC_MINS  , KC_EQL   , KC_LPRN  , KC_RPRN  ,KC_EXLM   , KC_HASH,
    _______  , _______  , KC_1     , KC_2     , KC_3     ,S(KC_MINS),                      KC_ASTR  ,KC_PLUS   , KC_LBRC  , KC_RBRC  ,KC_AMPR   ,KC_QUES,
                KC_LNG1 , KC_LNG2  , _______  , _______  , _______  ,                       KC_DEL  , _______  , _______  , _______  , _______ 
  ),

  [3] = LAYOUT_universal(
  LCA(KC_DEL), KC_F11   , KC_F2    ,LSG(KC_3)  ,LSG(KC_4) ,LSG(KC_5) ,                       KC_END , KC_PGUP   , KC_UP    , KC_PGDN  , KC_END      , GC(KC_F4)  ,
    _______  , KC_LSFT  , KC_LCTL  , KC_LALT   , KC_LGUI  ,C(KC_RGHT),                    KC_HOME   , KC_LEFT   , KC_DOWN  , KC_RGHT  ,LCAG(KC_LEFT), GC(KC_D)  ,
    _______  , C(KC_Z)  , C(KC_X)  , C(KC_C)   , C(KC_V)  , KC_F11    ,                   KC_HOME   , KC_PGDN   , KC_PGUP  , KC_END   , GC(KC_LEFT), GC(KC_RGHT),
                KC_LEFT , KC_RGHT  , C(KC_PGUP), _______  ,C(KC_PGDN) ,                    _______  , KC_BSPC   , _______  , _______  , _______ 
  ),

  [4] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                       _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , KC_LSFT  , KC_LCTL  , KC_LALT  , KC_LGUI  , _______  ,                      KC_MS_BTN5, _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                      KC_MS_BTN4,KC_MS_BTN3,KC_MS_BTN1,KC_MS_BTN2, _______  , _______  ,
               _______  , _______  , _______  , _______  , _______  ,                       _______  , _______  , _______  , _______  , _______  
  )
#endif

};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
  // レイヤーが1または3の場合、スクロールモードが有効になる
  keyball_set_scroll_mode(get_highest_layer(state) == 1 || get_highest_layer(state) == 3);
  // keyball_set_scroll_mode(get_highest_layer(state) == 1);

  // レイヤーとLEDを連動させる
  switch (get_highest_layer(state)) {
    case click_layer:
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

#ifdef OLED_ENABLE

#include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
  // デバッグ用に変数を表示する
  // oled_write_P(PSTR("Debug:"), false);
  // oled_write(get_u8_str(4, ' '), false);

  keyball_oled_render_keyinfo();   // キー情報を表示
  keyball_oled_render_ballinfo();  // トラックボール情報を表示

  // <Layer>を表示する
  oled_write_P(PSTR("Layer:"), false);
  oled_write(get_u8_str(get_highest_layer(layer_state), ' '), false);

  // <マウス移動量 / クリックレイヤーしきい値>を表示
  // oled_write_P(PSTR(" MV:"), false);
  // oled_write(get_u8_str(mouse_movement, ' '), false);
  // oled_write_P(PSTR("/"), false);
  // oled_write(get_u8_str(to_clickable_movement, ' '), false);

  // <state>を表示
  switch (state) {
    case WAITING:
      oled_write_ln_P(PSTR("  WAITING"), false);
      break;
    case CLICKABLE:
      oled_write_ln_P(PSTR("  CLICKABLE"), false);
      break;
    case CLICKING:
      oled_write_ln_P(PSTR("  CLICKING"), false);
      break;
    case CLICKED:
      oled_write_ln_P(PSTR("  CLICKED"), false);
      break;
    case SWIPE:
      oled_write_ln_P(PSTR("  SWIPE"), false);
      break;
    case SWIPING:
      oled_write_ln_P(PSTR("  SWIPING"), false);
      break;
    case NONE:
      oled_write_ln_P(PSTR("  NONE"), false);
      break;
  }
}
#endif
