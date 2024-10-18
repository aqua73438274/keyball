/* Copyright 2023 kamidai (@d_kamiichi)
 *
 * 参考ページ
 * 公式：https://docs.qmk.fm/#/ja/feature_combo?id=%e3%82%b3%e3%83%b3%e3%83%9c
 *
 * 注意： 以下の設定が必要です
 * rules.mk: COMBO_ENABLE = yes
 * config.h: #define COMBO_COUNT 2（=実際に設定するコンボ数）
 */

enum combos {
  // Begin paste from spreadsheet `def 2`
  COMBO_LANG1,
  COMBO_LANG2,
  COMBO_f10_1,
  COMBO_f10_2,
  COMBO_f1_1,
  COMBO_f2_1,
  COMBO_f3_1,
  COMBO_f4_1,
  COMBO_f5_1,
  COMBO_f6_1,
  COMBO_f7_1,
  COMBO_f7_2,
  COMBO_f8_1,
  COMBO_f9_1,
  COMBO_f11_1,
  COMBO_cut_1,
  COMBO_copy_1,
  COMBO_paste_1,
  COMBO_slsh_1,
  COMBO_dcs_1,
  COMBO_undo_1,
  COMBO_selAll_1,
  COMBO_dce_1,
  COMBO_hat_1,
  COMBO_cln_1,
  COMBO_nlu_1,
  COMBO_pgup_1,
  COMBO_pgdn_1,
  COMBO_selLine_1,
  COMBO_esc_1,
  COMBO_del_1,
  COMBO_delwd_1,
  COMBO_eisu_1,
  COMBO_kana_1,
  COMBO_bksp_1,
  COMBO_bkspwd_1,
  COMBO_dash_1,
  COMBO_f12_1,
  COMBO_amp_1,
  COMBO_pipe_1,
  COMBO_at_1,
  COMBO_unds_1,
  // COMBO_mcrec_1,
  // COMBO_mcply_1,
  COMBO_save_1,
  COMBO_tab_1,
  COMBO_ent_1,
  COMBO_nld_1,
  COMBO_up_1,
  COMBO_dn_1,
  COMBO_home_1,
  COMBO_end_1,
  COMBO_spc_1,
  COMBO_delall_1,
  COMBO_scln_1,
  COMBO_lft_1,
  COMBO_rgt_1,
  COMBO_lftwd_1,
  COMBO_rgtwd_1,
  COMBO_app_1,
  // End paste from spreadsheet `def 2`
};

typedef const uint16_t combo_keys_t[];

static PROGMEM combo_keys_t
  f10_combo_1 = {KC_Q,SFT_T(KC_E), COMBO_END},
  f1_combo_1 = {KC_Y,CTL_T(KC_I), COMBO_END},
  f2_combo_1 = {KC_U,ALT_T(KC_A), COMBO_END},
  f3_combo_1 = {KC_COMM,GUI_T(KC_O), COMBO_END},
  f4_combo_1 = {KC_DOT,KC_SCLN, COMBO_END},
  
  f5_combo_1 = {KC_F,KC_K, COMBO_END},
  f6_combo_1 = {KC_W,GUI_T(KC_T), COMBO_END},
  f7_combo_1 = {KC_M,ALT_T(KC_N), COMBO_END},
  f8_combo_1 = {KC_R,CTL_T(KC_S), COMBO_END},
  f9_combo_1 = {KC_P,SFT_T(KC_H), COMBO_END},
  
  f11_combo_1 = {KC_Y,SFT_T(KC_E), COMBO_END},
  copy_combo_1 = {KC_U,CTL_T(KC_I), COMBO_END},
  paste_combo_1 = {KC_U,GUI_T(KC_O), COMBO_END},
  SLSH_combo_1 = {KC_COMM,KC_SCLN, COMBO_END},
  
  DCS_combo_1 = {KC_Q,KC_Y, COMBO_END},
  undo_combo_1 = {KC_U,KC_Y, COMBO_END},
  selAll_combo_1 = {KC_U,KC_COMM, COMBO_END},
  DCE_combo_1 = {KC_COMM,KC_DOT, COMBO_END},

  hat_combo_1 = {KC_W,KC_R, COMBO_END},
  scln_combo_1 = {KC_W,KC_M, COMBO_END},
  CLN_combo_1 = {KC_R,KC_M, COMBO_END},

  NLU_combo_1 = {KC_W,KC_K, COMBO_END},
  PGUP_combo_1 = {KC_M,GUI_T(KC_T), COMBO_END},
  PGDN_combo_1 = {KC_M,CTL_T(KC_S), COMBO_END},
  
  selLine_combo_1 = {SFT_T(KC_E),CTL_T(KC_I), COMBO_END},
  esc_combo_1 = {ALT_T(KC_A),CTL_T(KC_I), COMBO_END},
  del_combo_1 = {ALT_T(KC_A),GUI_T(KC_O), COMBO_END},
  cut_combo_1 = {GUI_T(KC_O),CTL_T(KC_I), COMBO_END},
  DELwd_combo_1 = {GUI_T(KC_O),ALT_T(KC_A),CTL_T(KC_I), COMBO_END},

  lng2_combo = {KC_K ,GUI_T(KC_T) ,ALT_T(KC_N) , COMBO_END},
  lng1_combo = {KC_K ,GUI_T(KC_T) , COMBO_END},
  BKSP_combo_r1 = {GUI_T(KC_T),ALT_T(KC_N), COMBO_END},
  BKSPwd_combo_1 = {GUI_T(KC_T),ALT_T(KC_N),CTL_T(KC_S), COMBO_END},
  app_combo_1 = {GUI_T(KC_T),CTL_T(KC_S), COMBO_END},
  dash_combo_1 = {ALT_T(KC_N),CTL_T(KC_S), COMBO_END},

  f12_combo_1 = {ALT_T(KC_A),KC_C, COMBO_END},
  amp_combo_1 = {KC_V,GUI_T(KC_O), COMBO_END},
  pipe_combo_1 = {KC_L,KC_SLSH, COMBO_END},

  at_combo_1 = {KC_K,KC_G, COMBO_END},
  // unds_combo_1 = {GUI_T(KC_T),KC_G, COMBO_END},

  // mcRec_combo_1 = {SFT_T(KC_E),KC_X, COMBO_END},
  // mcPly_combo_1 = {KC_Z,CTL_T(KC_I), COMBO_END},
  save_combo_1 = {ALT_T(KC_A),KC_X , COMBO_END},
  tab_combo_1 = {ALT_T(KC_A),KC_V, COMBO_END},
  ENT_combo_1 = {GUI_T(KC_O),KC_SLSH, COMBO_END},

  NLD_combo_1 = {KC_G,GUI_T(KC_T), COMBO_END},
  up_combo_1 = {ALT_T(KC_N),KC_D, COMBO_END},
  dn_combo_1 = {ALT_T(KC_N),KC_J, COMBO_END},

  home_combo_1 = {KC_C,KC_X, COMBO_END},
  end_combo_1 = {KC_V,KC_C, COMBO_END},
  f7_combo_2 = {KC_V,KC_SLSH, COMBO_END},
  delAll_combo_1 = {KC_X,KC_C,KC_V, COMBO_END},
  
  f10_combo_2= {KC_G,KC_D, COMBO_END},
  lft_combo_1 = {KC_D,KC_MS_BTN1, COMBO_END},
  rgt_combo_1 = {KC_J,KC_MS_BTN1, COMBO_END},
  lftWd_combo_1 = {KC_D,KC_MS_BTN1,KC_J, COMBO_END},
  rgtWd_combo_1 = {KC_MS_BTN1,KC_J,LT(3,_______), COMBO_END},
  unds_combo_1 = {KC_D,KC_J, COMBO_END};

// const uint16_t PROGMEM f14_combo[] = {KC_DOWN, KC_I, COMBO_END};
// const uint16_t PROGMEM f15_combo[] = {G(KC_C), KC_UP, COMBO_END};
// const uint16_t PROGMEM combo_layer_1[] = {KC_F, KC_D, COMBO_END};
// const uint16_t PROGMEM combo_layer_2[] = {KC_R, KC_K, COMBO_END};
// const uint16_t PROGMEM combo_layer_3[] = {KC_D, KC_S, COMBO_END};
// const uint16_t PROGMEM combo_layer_3[] = {KC_S, KC_A, COMBO_END};

// const uint16_t PROGMEM combo_BRC[] = {KC_LBRC, KC_RBRC, COMBO_END};
// const uint16_t PROGMEM combo_semlect_BRC[] = {KC_LBRC, S(KC_EQUAL), COMBO_END};

// const uint16_t PROGMEM combo_S9_S0[] = {S(KC_9), S(KC_0), COMBO_END};
// const uint16_t PROGMEM combo_select_S9_S0[] = {S(KC_9), KC_MINUS, COMBO_END};

// const uint16_t PROGMEM combo_S_BRC[] = {S(KC_LBRC), S(KC_RBRC), COMBO_END};
// const uint16_t PROGMEM combo_select_S_BRC[] = {S(KC_LBRC), KC_RBRC, COMBO_END};

// const uint16_t PROGMEM combo_sumitsuki_BRC[] = {SFT_T(KC_GRAVE), KC_LBRC, COMBO_END};
// const uint16_t PROGMEM combo_select_sumitsuki_BRC[] = {SFT_T(KC_GRAVE), S(KC_0), COMBO_END};

// const uint16_t PROGMEM combo_MINUS_SPACE[] = {KC_RBRC, S(KC_EQUAL), COMBO_END};tk

combo_t key_combos[COMBO_COUNT] = {
  // [COMBO_mcrec_1] = COMBO(a_alt_1_combo, DYN_REC_START1),
  [COMBO_bksp_1] = COMBO(BKSP_combo_r1, KC_BSPC),
  [COMBO_home_1] = COMBO(home_combo_1, KC_HOME),
  [COMBO_delall_1] = COMBO_ACTION(delAll_combo_1),
  [COMBO_scln_1] = COMBO(scln_combo_1, KC_SCLN),
  [COMBO_end_1] = COMBO(end_combo_1, KC_END),
  [COMBO_rgt_1] = COMBO(rgt_combo_1, KC_RGHT),
  [COMBO_rgtwd_1] = COMBO_ACTION(rgtWd_combo_1),
  [COMBO_pipe_1] = COMBO(pipe_combo_1, KC_PIPE),
  [COMBO_dn_1] = COMBO(dn_combo_1, KC_DOWN),
  [COMBO_up_1] = COMBO(up_combo_1, KC_UP),
  [COMBO_selAll_1] = COMBO_ACTION(selAll_combo_1),
  [COMBO_f2_1] = COMBO(f2_combo_1, KC_F2),
  [COMBO_paste_1] = COMBO_ACTION(paste_combo_1),
  [COMBO_f4_1] = COMBO(f4_combo_1, KC_F4),
  [COMBO_at_1] = COMBO(at_combo_1, KC_AT),
  [COMBO_dash_1] = COMBO(dash_combo_1, KC_MINS),
  [COMBO_f5_1] = COMBO(f5_combo_1, KC_F5),
  [COMBO_nlu_1] = COMBO_ACTION(NLU_combo_1),
  [COMBO_f6_1] = COMBO(f6_combo_1, KC_F6),
  // [COMBO_l_u_1] = COMBO(l_u_1_combo, KC_INS),
  [COMBO_lft_1] = COMBO(lft_combo_1, KC_LEFT),
  [COMBO_lftwd_1] = COMBO_ACTION(lftWd_combo_1),
  [COMBO_app_1] = COMBO(app_combo_1, KC_APP),
  [COMBO_bksp_1] = COMBO(BKSP_combo_r1, KC_BSPC),
  [COMBO_bkspwd_1] = COMBO_ACTION(BKSPwd_combo_1),
  [COMBO_nld_1] = COMBO_ACTION(NLD_combo_1),
  [COMBO_unds_1] = COMBO(unds_combo_1, KC_UNDS),
  [COMBO_slsh_1] = COMBO(SLSH_combo_1, KC_INT1),
  [COMBO_dce_1] = COMBO_ACTION(DCE_combo_1),
  [COMBO_f3_1] = COMBO(f3_combo_1, KC_F3),
  [COMBO_f9_1] = COMBO(f9_combo_1, KC_F9),
  // [COMBO_mcply_1] = COMBO(r_ctrl_1_combo, DYN_MACRO_PLAY1),
  [COMBO_copy_1] = COMBO_ACTION(copy_combo_1),
  [COMBO_esc_1] = COMBO(esc_combo_1, KC_ESC),
  [COMBO_delwd_1] = COMBO_ACTION(DELwd_combo_1),
  [COMBO_cut_1] = COMBO_ACTION(cut_combo_1),
  [COMBO_save_1] = COMBO_ACTION(save_combo_1),
  [COMBO_f12_1] = COMBO(f12_combo_1, KC_F12),
  [COMBO_del_1] = COMBO(del_combo_1, KC_DEL),
  [COMBO_tab_1] = COMBO(tab_combo_1, KC_TAB),
  [COMBO_ent_1] = COMBO(ENT_combo_1, KC_ENT),
  [COMBO_selLine_1] = COMBO_ACTION(selLine_combo_1),
  [COMBO_amp_1] = COMBO(amp_combo_1, KC_AMPR),
  [COMBO_f7_1] = COMBO(f7_combo_1, KC_F7),
  [COMBO_f7_2] = COMBO(f7_combo_2, KC_F7),
  [COMBO_pgdn_1] = COMBO(PGDN_combo_1, KC_PGDN),
  [COMBO_pgup_1] = COMBO(PGUP_combo_1, KC_PGUP),
  [COMBO_cln_1] = COMBO(CLN_combo_1, KC_COLN),
  // [COMBO_spc_1] = COMBO(spc_combo_1, KC_SPC),
  [COMBO_f11_1] = COMBO(f11_combo_1, KC_F11),
  [COMBO_undo_1] = COMBO_ACTION(undo_combo_1),
  [COMBO_hat_1] = COMBO(hat_combo_1, KC_CIRC),
  [COMBO_f1_1] = COMBO(f1_combo_1, KC_F1),
  [COMBO_f8_1] = COMBO(f8_combo_1, KC_F8),
  [COMBO_LANG1] = COMBO(lng1_combo, KC_LNG1),
  [COMBO_LANG2] = COMBO(lng2_combo, KC_LNG2),
  [COMBO_f10_1] = COMBO(f10_combo_1, KC_F10),
  [COMBO_f10_2] = COMBO(f10_combo_2, KC_F10),
  [COMBO_dcs_1] = COMBO_ACTION(DCS_combo_1),
  // End paste from spreadsheet `def 3`
};

void process_combo_event(uint16_t combo_index, bool p) {
  switch(combo_index) {
    // Begin paste from spreadsheet `def 4`
    case COMBO_delall_1: if (p) {SEND_STRING(SS_LCTL("a")SS_TAP(X_DEL));}  break;
    case COMBO_rgtwd_1: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_RGHT));} else {SEND_STRING(SS_UP(X_RGHT)SS_UP(X_LCTL));} break;
    case COMBO_selAll_1: if (p) {SEND_STRING(SS_LCTL("a"));}  break;
    case COMBO_paste_1: if (p) {SEND_STRING(SS_LCTL("v"));}  break;
    case COMBO_nlu_1: if (p) {SEND_STRING(SS_TAP(X_HOME)SS_TAP(X_ENT)SS_TAP(X_UP));}  break;
    case COMBO_lftwd_1: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LEFT));} else {SEND_STRING(SS_UP(X_LEFT)SS_UP(X_LCTL));} break;
    case COMBO_bkspwd_1: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_BSPC));} else {SEND_STRING(SS_UP(X_BSPC)SS_UP(X_LCTL));} break;
    case COMBO_nld_1: if (p) {SEND_STRING(SS_TAP(X_END)SS_TAP(X_ENT));}  break;
    case COMBO_dce_1: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_END)SS_UP(X_LCTL));}  break;
    case COMBO_copy_1: if (p) {SEND_STRING(SS_LCTL("c"));}  break;
    case COMBO_delwd_1: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_DEL));} else {SEND_STRING(SS_UP(X_DEL)SS_UP(X_LCTL));} break;
    case COMBO_cut_1: if (p) {SEND_STRING(SS_LCTL("x"));}  break;
    case COMBO_save_1: if (p) {SEND_STRING(SS_LCTL("s"));}  break;
    case COMBO_selLine_1: if (p) {SEND_STRING(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT));}  break;
    case COMBO_undo_1: if (p) {SEND_STRING(SS_LCTL("z"));}  break;
    case COMBO_dcs_1: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_HOME)SS_UP(X_LCTL));}  break;
    // End paste from spreadsheet `def 4`
  }
};