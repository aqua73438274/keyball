#ifndef _AQUA_H_
#define _AQUA_H_

enum layeLs {
  BASE,
  SYM,
  NUM,
  WIN,
  FUN,
};

// Short aliases for home row mods and other tap-hold keys.
enum {
     HOM_E  = LT(SYM, KC_E)
    ,HOM_I  = LALT_T(KC_I)
    ,HOM_A  = LSFT_T(KC_A)
    ,HOM_O  = LCTL_T(KC_O)
    ,HOM_T  = RCTL_T(KC_T)
    ,HOM_N  = RSFT_T(KC_N)
    ,HOM_S  = LALT_T(KC_S)
    ,HOM_H  = LT(SYM, KC_H)
    ,HOM_Z  = LGUI_T(KC_Z)
    ,HOM_MS = RGUI_T(KC_SCLN)

    ,NUM_V   = LT(NUM, KC_V)
    ,WIN_AT = LT(WIN, KC_AT)

    ,WIN_DW  = LT(WIN, KC_DOWN)
    ,WIN_UP = LT(WIN, KC_UP)
    ,SFT_SP  = LSFT_T(KC_SPC)
    ,NUM_MN  = LT(NUM, KC_MINS)
    ,NUM_BS = LT(NUM, KC_BSPC)
    ,WIN_ET = LT(WIN, KC_ENT)

};

//aliases for setting combos easily
enum {
    //Left
    B_1_L1= KC_DLR, B_1_L2= KC_Q  , B_1_L3= KC_Y  , B_1_L4= KC_U    , B_1_L5=KC_COMM, B_1_L6= KC_DOT
   ,B_2_L1= KC_TAB, B_2_L2= HOM_E , B_2_L3= HOM_I , B_2_L4= HOM_A   , B_2_L5= HOM_O , B_2_L6= KC_L
   ,B_3_L1= WIN_AT, B_3_L2= HOM_Z , B_3_L3= KC_X  , B_3_L4= KC_C    , B_3_L5= NUM_V , B_3_L6= KC_SLSH
   ,B_4_L1= KC_NO , B_4_L2= WIN_DW, B_4_L3= WIN_UP, B_4_L4= KC_LGUI , B_4_L5= SFT_SP, B_4_L6= NUM_MN

    //Right
   ,B_1_R1= KC_F  , B_1_R2= KC_W  , B_1_R3= KC_M      , B_1_R4= KC_R  , B_1_R5= KC_P       , B_1_R6= KC_GRAVE
   ,B_2_R1= KC_K  , B_2_R2= HOM_T , B_2_R3= HOM_N     , B_2_R4= HOM_S , B_2_R5= HOM_H      , B_2_R6= KC_B
   ,B_3_R1= KC_G  , B_3_R2= KC_D  , B_3_R3= KC_MS_BTN1, B_3_R4= KC_J  , B_3_R5= HOM_MS     , B_3_R6= KC_QUOT
   ,B_4_R1= NUM_BS, B_4_R2= WIN_ET, B_4_R3= KC_NO     , B_4_R4= KC_NO , B_4_R5= KC_MS_BTN2 , B_4_R6= KC_NO
};

#endif // _AQUA_H_