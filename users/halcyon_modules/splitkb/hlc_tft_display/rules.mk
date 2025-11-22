SRC += $(USER_PATH)/splitkb/hlc_tft_display/hlc_tft_display.c

POST_CONFIG_H += $(USER_PATH)/splitkb/hlc_tft_display/config.h

# Fonts
SRC += $(USER_PATH)/splitkb/hlc_tft_display/graphics/fonts/Retron2000-27.qff.c \
       $(USER_PATH)/splitkb/hlc_tft_display/graphics/fonts/Retron2000-underline-27.qff.c

# Numbers in image format
SRC += $(USER_PATH)/splitkb/hlc_tft_display/graphics/numbers/0.qgf.c \
	   $(USER_PATH)/splitkb/hlc_tft_display/graphics/numbers/1.qgf.c \
	   $(USER_PATH)/splitkb/hlc_tft_display/graphics/numbers/2.qgf.c \
	   $(USER_PATH)/splitkb/hlc_tft_display/graphics/numbers/3.qgf.c \
	   $(USER_PATH)/splitkb/hlc_tft_display/graphics/numbers/4.qgf.c \
	   $(USER_PATH)/splitkb/hlc_tft_display/graphics/numbers/5.qgf.c \
	   $(USER_PATH)/splitkb/hlc_tft_display/graphics/numbers/6.qgf.c \
	   $(USER_PATH)/splitkb/hlc_tft_display/graphics/numbers/7.qgf.c \
	   $(USER_PATH)/splitkb/hlc_tft_display/graphics/numbers/8.qgf.c \
	   $(USER_PATH)/splitkb/hlc_tft_display/graphics/numbers/9.qgf.c \
	   $(USER_PATH)/splitkb/hlc_tft_display/graphics/numbers/undef.qgf.c

SRC += $(USER_PATH)/splitkb/hlc_tft_display/hlc_tft_davidf.c
SRC += $(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/layer-base.qgf.c \
	$(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/layer-navigation.qgf.c \
	$(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/layer-number.qgf.c \
	$(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/layer-super.qgf.c \
	$(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/layer-function.qgf.c \
	$(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/layer-game.qgf.c \
	$(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/led-caps-lock.qgf.c \
	$(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/led-num-lock.qgf.c \
	$(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/led-scroll-lock.qgf.c \
	$(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/modifier-command.qgf.c \
	$(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/modifier-control.qgf.c \
	$(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/modifier-option.qgf.c \
	$(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/modifier-shift.qgf.c \
	$(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/modifier-win.qgf.c \
	$(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/os-mac.qgf.c \
	$(USER_PATH)/splitkb/hlc_tft_display/graphics/davidf/os-win.qgf.c