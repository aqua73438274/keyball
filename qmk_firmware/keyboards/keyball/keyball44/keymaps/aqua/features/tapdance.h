
// タップダンス状態
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

// タップダンス状態を入れる型
typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// タップダンス定義用の列挙型
enum {
    TD_XXX
};

// タップダンスの状態判断用の関数
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    // 後述
}
td_state_t cur_dance2(qk_tap_dance_state_t *state) {
    // 後述
}

// タップダンス用のインスタンス
static td_tap_t XXX_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// タップダンス判定時の処理
void XXX_finished(qk_tap_dance_state_t *state, void *user_date) {
    XXX_tap_state.state = cur_dance(state);
    // 処理内容
}

// リセット時の処理
void XXX_reset(qk_tap_dance_state_t *state, void *user_date) {
    // 処理内容
}

// 押下時の処理（必要による）
void XXX_each_tap(qk_tap_dance_state_t *state, void *user_date) {
    // 処理内容
}

// タップダンスのアクションの設定
qk_tap_dance_action_t tap_dance_actions[] = {
    // each_tapがない場合
    [TD_XXX] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, XXX_finished, XXX_reset),
    // each_tapがある場合
    [TD_XXX] = ACTION_TAP_DANCE_FN_ADVANCED(XXX_each_tap, XXX_finished, XXX_reset),
};

// キー別名
#define TDD_XXX TD(TD_XXX)