RGBLIGHT_ENABLE = yes

OLED_ENABLE = no

VIA_ENABLE = no

LTO_ENABLE = yes

### �g���Ă��Ȃ�����
### �ȉ��̓������s���̂��߁AVIA��OFF�ɂ���K�v������
KEY_OVERRIDE_ENABLE = yes
COMBO_ENABLE = yes
TAP_DANCE = yes
# AUTO_SHIFT_ENABLE = yes

# �t�@�[���E�F�A�̃T�C�Y���팸
EXTRAFLAGS += -flto
GRAVE_ESC_ENABLE = no  # 90�o�C�g

#SRC +=  features/twpair_on_jds.c

