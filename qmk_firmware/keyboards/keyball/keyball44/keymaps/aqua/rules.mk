RGBLIGHT_ENABLE = yes

OLED_ENABLE = no

# for debug
#CONSOLE_ENABLE = yes

# for size down
OPT_DEFS += -Os
UNICODE_ENABLE = no
UNICODEMAP_ENABLE = no
UCIS_ENABLE = no
CONSOLE_ENABLE ?= no
GRAVE_ESC_ENABLE ?= no
NKRO_ENABLE ?= no

# aqua settings
COMBO_ENABLE = yes
REPEAT_KEY_ENABLE = yes

ALT_KEYMAP_ENABLE = no #for use qwerty layout
A2J_ENABLE ?= yes
ACHORDION_ENABLE ?= yes
CAPS_WORD_ENABLE ?= yes
LAYER_LOCK_ENABLE = no

A2J_ENABLE ?= yes
ifeq ($(strip $(A2J_ENABLE)), yes)
	OPT_DEFS += -DA2J_ENABLE
	SRC += features/translate_ansi_to_jis.c
endif

ACHORDION_ENABLE ?= yes
ifeq ($(strip $(ACHORDION_ENABLE)), yes)
	OPT_DEFS += -DACHORDION_ENABLE
	SRC += features/achordion.c
endif

LAYER_LOCK_ENABLE ?= yes
ifeq ($(strip $(LAYER_LOCK_ENABLE)), yes)
	OPT_DEFS += -DLAYER_LOCK_ENABLE
	SRC += features/layer_lock.c
endif