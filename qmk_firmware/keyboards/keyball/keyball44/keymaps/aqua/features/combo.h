/* 
 *
 * ref：https://docs.qmk.fm/#/ja/feature_combo?id=%e3%82%b3%e3%83%b3%e3%83%9c
 *
 * caution ： need to set below
 * rules.mk: COMBO_ENABLE = yes
 * config.h: #define COMBO_COUNT x（x=number of combos）
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
  COMBO_redo_1,
  COMBO_f2_2,
  COMBO_close_1,
  COMBO_eq_1,
  COMBO_f11_2,
  COMBO_bSlh_1,
  COMBO_dbSlh_1,
  COMBO_dSlsh_1,
  COMBO_find_1,
  COMBO_zomP_1,
  COMBO_zomM_1,
  COMBO_plus_1,
  COMBO_astr_1,
//  COMBO_cpWrd_1,
  COMBO_reTrs_1,
  // End paste from spreadsheet `def 2`
};

typedef const uint16_t combo_keys_t[];

static PROGMEM combo_keys_t
  // left-left 1_1
   DCS_combo_1 =   {B_1_L2,  B_1_L3, COMBO_END}
  ,redo_combo_1 =   {B_1_L2,  B_1_L3,  B_1_L4, COMBO_END}
  ,f2_combo_2 =   {B_1_L2,  B_1_L3,  B_1_L4, B_1_L5, COMBO_END}
  ,undo_combo_1 =  {B_1_L4,  B_1_L3, COMBO_END}
  ,selLine_combo_1 ={B_1_L4,  B_1_L5, COMBO_END}
  ,selAll_combo_1 ={B_1_L3,  B_1_L4,  B_1_L5, COMBO_END}
  ,DCE_combo_1 =   {B_1_L5,  B_1_L6, COMBO_END}
  ,cls_combo_1 =   {B_1_L5,  B_1_L6,  B_1_L4, COMBO_END}

  // right-right 1_1
  ,eq_combo_1 =   {B_1_R2,  B_1_R4, COMBO_END}
  ,scln_combo_1 =  {B_1_R2,  B_1_R3, COMBO_END}
  ,CLN_combo_1 =   {B_1_R4,  B_1_R3, COMBO_END}
  ,app_combo_1 =   {B_1_R5,  B_1_R4, B_1_R3, COMBO_END}
  ,f11_combo_2 =   {B_1_R5,  B_1_R4, B_1_R3, B_1_R2, COMBO_END}

  // left-left 1_2
  ,f10_combo_1 =   {B_1_L2,  B_2_L2, COMBO_END}
  ,f1_combo_1 =    {B_1_L3,  B_2_L3, COMBO_END}
  ,f2_combo_1 =    {B_1_L4,  B_2_L4, COMBO_END}
  ,f3_combo_1 =    {B_1_L5,  B_2_L5, COMBO_END}
  ,f4_combo_1 =    {B_1_L6,  B_2_L6, COMBO_END}
  ,f11_combo_1 =   {B_1_L3,  B_2_L2, COMBO_END}

  // right-right 1_2
  ,f5_combo_1 =    {B_1_R1,  B_2_R1, COMBO_END}
  ,f6_combo_1 =    {B_1_R2,  B_2_R2, COMBO_END}
  ,f7_combo_1 =    {B_1_R3,  B_2_R3, COMBO_END}
  ,f8_combo_1 =    {B_1_R4,  B_2_R4, COMBO_END}
  ,f9_combo_1 =    {B_1_R5,  B_2_R5, COMBO_END}
  ,NLU_combo_1 =   {B_1_R2,  B_2_R1, COMBO_END}
  ,PGUP_combo_1 =  {B_1_R3,  B_2_R2, COMBO_END}
  ,PGDN_combo_1 =  {B_1_R3,  B_2_R4, COMBO_END}
  ,SLSH_combo_1 =  {B_1_R4,  B_2_R5, COMBO_END}
  ,BSLH_combo_1 =  {B_1_R4,  B_2_R3, COMBO_END}
  ,hat_combo_1 =   {B_1_R3,  B_2_R2,  B_2_R4, COMBO_END}
  ,f10_combo_2 =   {B_1_R3,  B_1_R4,  B_2_R2, COMBO_END}
  
  // left-left 2_2
  ,tab_combo_1 = {B_2_L2,  B_2_L3, COMBO_END}
  ,esc_combo_1 =     {B_2_L4,  B_2_L3, COMBO_END}
  ,copy_combo_1 =     {B_2_L4,  B_2_L5, COMBO_END}
  ,find_combo_1  =     {B_2_L5,  B_2_L3, COMBO_END}
  ,zomP_combo_1  = {B_2_L5,  B_2_L6, COMBO_END}
  ,spc_combo_1 =   {B_2_L2,  B_2_L4, B_2_L3, COMBO_END}
  ,paste_combo_1 =   {B_2_L5,  B_2_L4, B_2_L3, COMBO_END}
  ,save_combo_1 =   {B_2_L5,  B_2_L4, B_2_L3, B_2_L2, COMBO_END}

  // right-right 2_2
  ,delAll_combo_1 =      {B_2_R1,  B_2_R2, B_2_R3, COMBO_END}
  ,home_combo_1 =      {B_2_R1,  B_2_R2, COMBO_END}
  ,BKSP_combo_r1 =   {B_2_R2,  B_2_R3, COMBO_END}
  ,BKSPwd_combo_1 =  {B_2_R2,  B_2_R3, B_2_R4, COMBO_END}
  ,dash_combo_1 =     {B_2_R2,  B_2_R4, COMBO_END}
  ,del_combo_1 =    {B_2_R3,  B_2_R4, COMBO_END}
  ,DELwd_combo_1 =  {B_2_R3,  B_2_R4, B_2_R5,  COMBO_END}
  ,plus_combo_1 =    {B_2_R5,  B_2_R4, COMBO_END}
  ,ENT_combo_1 =    {B_2_R2,  B_2_R3, B_2_R4,  B_2_R5, COMBO_END}

  // left-left 2_3
  ,f12_combo_1 =   {B_2_L4,  B_3_L4, COMBO_END}
  ,amp_combo_1 =   {B_2_L5,  B_3_L5, COMBO_END}
  ,pipe_combo_1 =  {B_2_L6,  B_3_L6, COMBO_END}

  // right-right 2_3
  ,at_combo_1 =  {B_2_R1,  B_3_R1, COMBO_END}
  ,NLD_combo_1 = {B_2_R2,  B_3_R1,   COMBO_END}
  ,up_combo_1 =  {B_2_R3,  B_3_R2,   COMBO_END}
  ,dn_combo_1 =  {B_2_R3,  B_3_R4,   COMBO_END}
  ,dSLSH_combo_1 =  {B_2_R4,  B_3_R5, COMBO_END}
  ,dBSLH_combo_1 =  {B_1_R5,  B_2_R4, COMBO_END} 
  ,astr_combo_1 =   {B_2_R3,  B_3_R2,  B_3_R4, COMBO_END}
  ,f7_combo_2 =  {B_2_R3,  B_2_R4,  B_3_R2, COMBO_END}

  // left-left 3_3
  ,lng1_combo =   {B_3_L4,  B_3_L3, COMBO_END}
  ,cut_combo_1 =  {B_3_L5,  B_3_L4, COMBO_END}
  ,zomM_combo_1 = {B_3_L5,  B_3_L6, COMBO_END}
//  ,cpWrd_combo =  {B_3_L3, B_3_L5, COMBO_END}
  ,lng2_combo =   {B_3_L3,  B_3_L4, B_3_L5, COMBO_END}
  
  // right-right 3_3
  ,end_combo_1=    {B_3_R1,  B_3_R2, COMBO_END}
  ,lft_combo_1 =   {B_3_R2,  B_3_R3, COMBO_END}
  ,rgt_combo_1 =   {B_3_R4,  B_3_R3, COMBO_END}
  ,lftWd_combo_1 = {B_3_R2,  B_3_R3, B_3_R4, COMBO_END}
  ,rgtWd_combo_1 = {B_3_R3,  B_3_R4, B_3_R5, COMBO_END}
  ,unds_combo_1 =  {B_3_R2,  B_3_R4, COMBO_END}
  ,reTrs_combo_1 = {B_3_R2,  B_3_R3,  B_3_R4, B_3_R5, COMBO_END}
  ;

combo_t key_combos[COMBO_COUNT] = {
  // [COMBO_mcrec_1] = COMBO(a_alt_1_combo, DYN_REC_START1)
   [COMBO_bksp_1] = COMBO(BKSP_combo_r1, KC_BSPC)
  ,[COMBO_home_1] = COMBO(home_combo_1, KC_HOME)
  ,[COMBO_delall_1] = COMBO_ACTION(delAll_combo_1)
  ,[COMBO_scln_1] = COMBO(scln_combo_1, KC_SCLN)
  ,[COMBO_end_1] = COMBO(end_combo_1, KC_END)
  ,[COMBO_rgt_1] = COMBO(rgt_combo_1, KC_RGHT)
  ,[COMBO_rgtwd_1] = COMBO_ACTION(rgtWd_combo_1)
  ,[COMBO_pipe_1] = COMBO(pipe_combo_1, KC_PIPE)
  ,[COMBO_dn_1] = COMBO(dn_combo_1, KC_DOWN)
  ,[COMBO_up_1] = COMBO(up_combo_1, KC_UP)
  ,[COMBO_selAll_1] = COMBO_ACTION(selAll_combo_1)
  ,[COMBO_f2_1] = COMBO(f2_combo_1, KC_F2)
  ,[COMBO_paste_1] = COMBO_ACTION(paste_combo_1)
  ,[COMBO_f4_1] = COMBO(f4_combo_1, KC_F4)
  ,[COMBO_at_1] = COMBO(at_combo_1, KC_AT)
  ,[COMBO_dash_1] = COMBO(dash_combo_1, KC_MINS)
  ,[COMBO_f5_1] = COMBO(f5_combo_1, KC_F5)
  ,[COMBO_nlu_1] = COMBO_ACTION(NLU_combo_1)
  ,[COMBO_f6_1] = COMBO(f6_combo_1, KC_F6)
  // ,[COMBO_l_u_1] = COMBO(l_u_1_combo, KC_INS)
  ,[COMBO_lft_1] = COMBO(lft_combo_1, KC_LEFT)
  ,[COMBO_lftwd_1] = COMBO_ACTION(lftWd_combo_1)
  ,[COMBO_app_1] = COMBO(app_combo_1, KC_APP)
  ,[COMBO_bksp_1] = COMBO(BKSP_combo_r1, KC_BSPC)
  ,[COMBO_bkspwd_1] = COMBO_ACTION(BKSPwd_combo_1)
  ,[COMBO_nld_1] = COMBO_ACTION(NLD_combo_1)
  ,[COMBO_unds_1] = COMBO(unds_combo_1, KC_UNDS)
  ,[COMBO_slsh_1] = COMBO(SLSH_combo_1, KC_INT1)
  ,[COMBO_dce_1] = COMBO_ACTION(DCE_combo_1)
  ,[COMBO_f3_1] = COMBO(f3_combo_1, KC_F3)
  ,[COMBO_f9_1] = COMBO(f9_combo_1, KC_F9)
  // ,[COMBO_mcply_1] = COMBO(r_ctrl_1_combo, DYN_MACRO_PLAY1)
  ,[COMBO_copy_1] = COMBO_ACTION(copy_combo_1)
  ,[COMBO_esc_1] = COMBO(esc_combo_1, KC_ESC)
  ,[COMBO_delwd_1] = COMBO_ACTION(DELwd_combo_1)
  ,[COMBO_cut_1] = COMBO_ACTION(cut_combo_1)
  ,[COMBO_save_1] = COMBO_ACTION(save_combo_1)
  ,[COMBO_f12_1] = COMBO(f12_combo_1, KC_F12)
  ,[COMBO_del_1] = COMBO(del_combo_1, KC_DEL)
  ,[COMBO_tab_1] = COMBO(tab_combo_1, KC_TAB)
  ,[COMBO_ent_1] = COMBO(ENT_combo_1, KC_ENT)
  ,[COMBO_selLine_1] = COMBO_ACTION(selLine_combo_1)
  ,[COMBO_amp_1] = COMBO(amp_combo_1, KC_AMPR)
  ,[COMBO_f7_1] = COMBO(f7_combo_1, KC_F7)
  ,[COMBO_f7_2] = COMBO(f7_combo_2, KC_F7)
  ,[COMBO_pgdn_1] = COMBO(PGDN_combo_1, KC_PGDN)
  ,[COMBO_pgup_1] = COMBO(PGUP_combo_1, KC_PGUP)
  ,[COMBO_cln_1] = COMBO(CLN_combo_1, KC_COLN)
  ,[COMBO_spc_1] = COMBO(spc_combo_1, KC_SPC)
  ,[COMBO_f11_1] = COMBO(f11_combo_1, KC_F11)
  ,[COMBO_undo_1] = COMBO_ACTION(undo_combo_1)
  ,[COMBO_hat_1] = COMBO(hat_combo_1, KC_CIRC)
  ,[COMBO_f1_1] = COMBO(f1_combo_1, KC_F1)
  ,[COMBO_f8_1] = COMBO(f8_combo_1, KC_F8)
  ,[COMBO_LANG1] = COMBO(lng1_combo, KC_LNG1)
  ,[COMBO_LANG2] = COMBO(lng2_combo, KC_LNG2)
  ,[COMBO_f10_1] = COMBO(f10_combo_1, KC_F10)
  ,[COMBO_f10_2] = COMBO(f10_combo_2, KC_F10)
  ,[COMBO_dcs_1] = COMBO_ACTION(DCS_combo_1)
  ,[COMBO_redo_1] = COMBO_ACTION(redo_combo_1)
  ,[COMBO_f2_2] = COMBO(f8_combo_1, KC_F2)
  ,[COMBO_close_1] = COMBO_ACTION(cls_combo_1)
  ,[COMBO_eq_1] = COMBO(eq_combo_1, KC_EQL)
  ,[COMBO_f11_2] = COMBO(f11_combo_2, KC_F11)
  ,[COMBO_bSlh_1] = COMBO(BSLH_combo_1, KC_BSLS)
  ,[COMBO_dbSlh_1] = COMBO_ACTION(dBSLH_combo_1)
  ,[COMBO_dSlsh_1] = COMBO_ACTION(dSLSH_combo_1)
  ,[COMBO_find_1] = COMBO_ACTION(find_combo_1)
  ,[COMBO_zomP_1] = COMBO_ACTION(zomP_combo_1)
  ,[COMBO_zomM_1] = COMBO_ACTION(zomM_combo_1)
  ,[COMBO_plus_1] = COMBO(plus_combo_1, KC_PLUS)
  ,[COMBO_astr_1] = COMBO(astr_combo_1, KC_ASTR)
//, [COMBO_cpWrd_1] = COMBO(f10_combo_1, KC_F10)//
  ,[COMBO_reTrs_1] = COMBO_ACTION(reTrs_combo_1)
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
    case COMBO_redo_1: if (p) {SEND_STRING(SS_LCTL("y"));}  break;
    case COMBO_find_1: if (p) {SEND_STRING(SS_LCTL("f"));}  break;
    case COMBO_close_1: if (p) {SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_F4)SS_UP(X_LALT));}  break;
    case COMBO_reTrs_1: if (p) {SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_SLASH)SS_UP(X_LGUI));}  break;
    case COMBO_dbSlh_1: if (p) {SEND_STRING("..\\");}  break;
    case COMBO_dSlsh_1: if (p) {SEND_STRING("../");}  break;
    case COMBO_zomP_1: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_KP_PLUS)SS_UP(X_LCTL));}  break;
    case COMBO_zomM_1: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_KP_MINUS)SS_UP(X_LCTL));}  break;
    // End paste from spreadsheet `def 4`
  }
};