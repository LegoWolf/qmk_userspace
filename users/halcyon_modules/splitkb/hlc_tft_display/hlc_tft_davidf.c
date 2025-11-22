// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "config.h"
#include "hlc_tft_display.h"
#include "hlc_tft_davidf.h"

#include "graphics/davidf/layer-base.qgf.h"
#include "graphics/davidf/layer-navigation.qgf.h"
#include "graphics/davidf/layer-number.qgf.h"
#include "graphics/davidf/layer-super.qgf.h"
#include "graphics/davidf/layer-function.qgf.h"
#include "graphics/davidf/layer-game.qgf.h"
#include "graphics/davidf/led-caps-lock.qgf.h"
#include "graphics/davidf/led-num-lock.qgf.h"
#include "graphics/davidf/led-scroll-lock.qgf.h"
#include "graphics/davidf/modifier-option.qgf.h"
#include "graphics/davidf/modifier-command.qgf.h"
#include "graphics/davidf/modifier-control.qgf.h"
#include "graphics/davidf/modifier-shift.qgf.h"
#include "graphics/davidf/modifier-win.qgf.h"
#include "graphics/davidf/os-mac.qgf.h"
#include "graphics/davidf/os-win.qgf.h"

typedef enum {
    LAYER_BASE,
    LAYER_NAVIGATION,
    LAYER_NUMBER,
    LAYER_FUNCTION,
    LAYER_SUPER,
    LAYER_GAME
} custom_layers_t;

typedef enum {
    WIN,
    MAC
} os_modes_t;

typedef struct {
    uint8_t h;
    uint8_t s;
    uint8_t v;
} color_t;

static color_t color_os_mac = { 0, 0, 160 };
static color_t color_os_win = { 147, 255, 160 };
static color_t color_layer = { 0, 0, 160 };
static color_t color_modifier_on = { 19, 255, 255 };
static color_t color_modifier_off = { 19, 255, 60 };
static color_t color_led_on = { 128, 255, 215 };
static color_t color_led_off = { 128, 255, 30 };

extern os_modes_t os_mode;

static void draw_layer(const uint8_t *gfx_layer, color_t color) {
    painter_image_handle_t layer_number = qp_load_image_mem(gfx_layer);
    qp_drawimage_recolor(lcd_surface, 0, 0, layer_number, color.h, color.s, color.v, HSV_BLACK);
    qp_close_image(layer_number);
}

static void draw_toggle(bool enabled, const uint8_t *gfx_modifier, int x, int y, color_t on, color_t off) {
    color_t c = enabled ? on : off;
    painter_image_handle_t modifier_number = qp_load_image_mem(gfx_modifier);
    qp_drawimage_recolor(lcd_surface, x, y, modifier_number, c.h, c.s, c.v, HSV_BLACK);
    qp_close_image(modifier_number);
}

void update_display_davidf(void) {
    static uint8_t last_modifier_state = 0;
    static led_t last_led_usb_state = {0};
    static layer_state_t last_layer_state = {0};
    static os_modes_t last_os_mode;
    static bool first_run_modifier = false;
    static bool first_run_led = false;
    static bool first_run_layer = false;
    static bool first_run_os = false;

    if(last_layer_state != layer_state || first_run_layer == false) {
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case LAYER_BASE: draw_layer(gfx_layer_base, color_layer); break;
            case LAYER_NAVIGATION: draw_layer(gfx_layer_navigation, color_layer); break;
            case LAYER_NUMBER: draw_layer(gfx_layer_number, color_layer); break;
            case LAYER_FUNCTION: draw_layer(gfx_layer_function, color_layer); break;
            case LAYER_SUPER: draw_layer(gfx_layer_super, color_layer); break;
            case LAYER_GAME: draw_layer(gfx_layer_game, color_layer); break;
        }
        last_layer_state = layer_state;
        first_run_layer = true;
    }

    led_t led_usb_state = host_keyboard_led_state();
    if(last_led_usb_state.raw != led_usb_state.raw || first_run_led == false) {
        draw_toggle(led_usb_state.caps_lock, gfx_led_caps_lock, 0, 150, color_led_on, color_led_off);
        draw_toggle(led_usb_state.num_lock, gfx_led_num_lock, 0, 180, color_led_on, color_led_off);
        draw_toggle(led_usb_state.scroll_lock, gfx_led_scroll_lock, 0, 210, color_led_on, color_led_off);
        last_led_usb_state = led_usb_state;
        first_run_led = true;
    }

    uint8_t modifier_state = get_mods() | get_oneshot_mods();
    if(last_modifier_state != modifier_state || os_mode != last_os_mode || first_run_modifier == false) {
        const uint8_t *gfx_gui = (os_mode == WIN) ? gfx_modifier_win : gfx_modifier_command;
        draw_toggle((modifier_state & MOD_MASK_SHIFT) != 0, gfx_modifier_shift, 0, 120, color_modifier_on, color_modifier_off);
        draw_toggle((modifier_state & MOD_MASK_GUI) != 0, gfx_gui, 34, 120, color_modifier_on, color_modifier_off);
        draw_toggle((modifier_state & MOD_MASK_CTRL) != 0, gfx_modifier_control, 68, 120, color_modifier_on, color_modifier_off);
        draw_toggle((modifier_state & MOD_MASK_ALT) != 0, gfx_modifier_option, 102, 120, color_modifier_on, color_modifier_off);
        last_modifier_state = modifier_state;
        first_run_modifier = true;
    }

    if(os_mode != last_os_mode || first_run_os == false) {
        const uint8_t *gfx_os = (os_mode == WIN) ? gfx_os_win : gfx_os_mac;
        color_t c = (os_mode == WIN) ? color_os_win : color_os_mac;
        painter_image_handle_t os_number = qp_load_image_mem(gfx_os);
        qp_drawimage_recolor(lcd_surface, 34, 150, os_number, c.h, c.s, c.v, HSV_BLACK);
        qp_close_image(os_number);
        last_os_mode = os_mode;
        first_run_os = true;
    }
}