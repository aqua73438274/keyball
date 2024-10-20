// Keycodes to use jis keycode in us keymap

#pragma once

typedef union {
  uint8_t raw;
  struct {
    bool is_jis_mode: 1;
  };
} user_config_t;

void init_user_config(void);

bool is_jis_mode(void);
void set_jis_mode(bool is_jis_mode);

bool process_record_user_a2j(uint16_t keycode, keyrecord_t *record);