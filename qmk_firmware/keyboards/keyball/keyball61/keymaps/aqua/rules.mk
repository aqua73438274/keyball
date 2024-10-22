RGBLIGHT_ENABLE = yes

OLED_ENABLE = no

# for debug
#CONSOLE_ENABLE = yes



# aqua settings
#ALT_KEYMAP_DISEBLE #for use qwerty layout
ACHORDION_ENABLE = no
COMBO_ENABLE = yes
SRC += features/translate_ansi_to_jis.c

CAPS_WORD_ENABLE ?= yes

ACHORDION_ENABLE ?= yes
ifeq ($(strip $(ACHORDION_ENABLE)), yes)
	OPT_DEFS += -DACHORDION_ENABLE
	SRC += features/achordion.c
endif

