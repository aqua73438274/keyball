RGBLIGHT_ENABLE = yes

OLED_ENABLE = no

# for debug
# CONSOLE_ENABLE = yes



# aqua settings
AUTOCORRECT_ENABLE ?= yes
ALT_KEYMAP_DISEBLE = yes	# for use qwerty layout
COMBO_ENABLE = yes
SRC += features/translate_ansi_to_jis.c

# CAPS_WORD_ENABLE ?= yes

ACHORDION_ENABLE ?= yes
ifeq ($(strip $(ACHORDION_ENABLE)), yes)
	OPT_DEFS += -DACHORDION_ENABLE
	SRC += features/achordion.c
endif