/*
Copyright 2025 David Falkner <falkner@martica.org>
*/

#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#include <keymap_canadian_multilingual.h>

typedef enum {
    LAYER_BASE,
    LAYER_NAV,
    LAYER_NUM,
    LAYER_FUNC,
    LAYER_SUPER,
    LAYER_GAME
} custom_layers_t;

typedef enum {
    WIN,
    MAC
} os_modes_t;

typedef enum {
#ifdef VIA_ENABLE
    KC_OSMODE = QK_USER_0,  // QK_USER_0
#else
    KC_OSMODE = SAFE_RANGE,
#endif
    KC_ANIMATE,             // QK_USER_1
    KC_A_CIRCUMFLEX,        // QK_USER_2
    KC_A_DIAERESIS,         // QK_USER_3
    KC_E_CIRCUMFLEX,        // QK_USER_4
    KC_E_DIAERESIS,         // QK_USER_5
    KC_I_CIRCUMFLEX,        // QK_USER_6
    KC_I_DIAERESIS,         // QK_USER_7
    KC_O_CIRCUMFLEX,        // QK_USER_8
    KC_O_DIAERESIS,         // QK_USER_9
    KC_U_CIRCUMFLEX,        // QK_USER_10
    KC_U_DIAERESIS,         // QK_USER_11
} custom_keycodes_t;

#define KC_ANIM KC_ANIMATE
#define KC_ACIR KC_A_CIRCUMFLEX
#define KC_ADIA KC_A_DIAERESIS
#define KC_ECIR KC_E_CIRCUMFLEX
#define KC_EDIA KC_E_DIAERESIS
#define KC_ICIR KC_I_CIRCUMFLEX
#define KC_IDIA KC_I_DIAERESIS
#define KC_OCIR KC_O_CIRCUMFLEX
#define KC_ODIA KC_O_DIAERESIS
#define KC_UCIR KC_U_CIRCUMFLEX
#define KC_UDIA KC_U_DIAERESIS
#define MAX_LAYERS (LAYER_GAME + 1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_corne_hlc(
      KC_ESC,          KC_Q,        KC_W,          KC_E,           KC_R,          KC_T,                KC_Y,             KC_U,          KC_I,          KC_O,          KC_P,          KC_MINS,
      MO(LAYER_SUPER), KC_A,        KC_S,          KC_D,           KC_F,          KC_G,                KC_H,             KC_J,          KC_K,          KC_L,          KC_SCLN,       MO(LAYER_SUPER),
      KC_LSFT,         KC_Z,        KC_X,          KC_C,           KC_V,          KC_B,                KC_N,             KC_M,          KC_COMM,       KC_DOT,        CA_EACU,       KC_RSFT,
                                                   TL_LOWR,        KC_BSPC,       LCTL_T(KC_TAB),      KC_ENTER,         KC_SPACE,      TL_UPPR,
                       KC_NO,       KC_NO,         KC_NO,          KC_NO,         KC_NO,               KC_NO,            KC_NO,         KC_NO,         KC_NO,         KC_NO
  ),

  [LAYER_NAV] = LAYOUT_corne_hlc(
      XXXXXXX,         XXXXXXX,     XXXXXXX,       KC_INS,         KC_DEL,        KC_MUTE,             KC_PGUP,          KC_HOME,       KC_UP,         KC_END,        MS_WHLU,       XXXXXXX,
      XXXXXXX,         KC_MPRV,     KC_MNXT,       KC_VOLD,        KC_VOLU,       KC_MPLY,             KC_PGDN,          KC_LEFT,       KC_DOWN,       KC_RIGHT,      MS_WHLD,       XXXXXXX,
      _______,         KC_APP,      KC_LGUI,       KC_LCTL,        KC_LALT,       KC_RALT,             OSM(MOD_RALT),    OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LGUI), XXXXXXX,       _______,
                                                   _______,        _______,       _______,             _______,          _______,       _______,
                       KC_NO,       KC_NO,         KC_NO,          KC_NO,         KC_NO,               KC_NO,            KC_NO,         KC_NO,         KC_NO,         KC_NO
  ),

  [LAYER_NUM] = LAYOUT_corne_hlc(
      XXXXXXX,         S(KC_1),     S(KC_2),       S(KC_3),        S(KC_4),       S(KC_5),             S(KC_6),          S(KC_7),       S(KC_8),       S(KC_9),       S(KC_0),       XXXXXXX,
      XXXXXXX,         KC_1,        KC_2,          KC_3,           KC_4,          KC_5,                KC_6,             KC_7,          KC_8,          KC_9,          KC_0,          XXXXXXX,
      _______,         XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,       XXXXXXX,             XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       _______,
                                                   _______,        _______,       _______,             _______,          _______,       _______,
                       KC_NO,       KC_NO,         KC_NO,          KC_NO,         KC_NO,               KC_NO,            KC_NO,         KC_NO,         KC_NO,         KC_NO
  ),

  [LAYER_FUNC] = LAYOUT_corne_hlc(
      KC_OSMODE,       KC_F11,      KC_F12,        KC_F13,         KC_F14,        KC_F15,              KC_F16,           KC_BRID,       KC_BRIU,       KC_MCTL,       KC_LPAD,       TG(LAYER_GAME),
      XXXXXXX,         KC_F1,       KC_F2,         KC_F3,          KC_F4,         KC_F5,               KC_F6,            KC_F7,         KC_F8,         KC_F9,         KC_F10,        XXXXXXX,
      _______,         KC_PAUS,     KC_NUM,        KC_SCRL,        KC_PSCR,       UG_TOGG,             UG_NEXT,          UG_HUEU,       UG_SATU,       UG_VALU,       UG_SPDU,       _______,
                                                   _______,        _______,       _______,             _______,          _______,       _______,
                       KC_NO,       KC_NO,         KC_NO,          KC_NO,         KC_NO,               KC_NO,            KC_NO,         KC_NO,         KC_NO,         KC_NO
  ),

  [LAYER_SUPER] = LAYOUT_corne_hlc(
      XXXXXXX,         CA_LABK,     CA_RABK,       CA_EGRV,        CA_DTIL,       S(CA_AGRV),          S(CA_CCED),       CA_UGRV,       CA_GRV,        CA_CIRC,       CA_DIAE,       KC_EQL,
      KC_ADIA,         CA_AGRV,     KC_EDIA,       KC_IDIA,        KC_ODIA,       KC_UDIA,             KC_ACIR,          KC_ECIR,       KC_ICIR,       KC_OCIR,       KC_UCIR,       CA_PLUS,
      _______,         CA_LDAQ,     CA_RDAQ,       CA_CCED,        CA_PIPE,       CA_BSLS,             CA_SLSH,          CA_LCBR,       CA_RCBR,       CA_LBRC,       CA_RBRC,       _______,
                                                   _______,        _______,       _______,             _______,          _______,       _______,
                       KC_NO,       KC_NO,         KC_NO,          KC_NO,         KC_NO,               KC_NO,            KC_NO,         KC_NO,         KC_NO,         KC_NO
  ),

  [LAYER_GAME] = LAYOUT_corne_hlc(
      KC_ESC,          KC_T,        KC_Q,          KC_W,           KC_E,          KC_R,                KC_PSLS,          KC_P7,         KC_P8,         KC_P9,         KC_PPLS,       TG(LAYER_GAME),
      KC_TAB,          KC_G,        KC_A,          KC_S,           KC_D,          KC_F,                KC_P0,            KC_P4,         KC_P5,         KC_P6,         KC_PMNS,       KC_ANIM,
      KC_LSFT,         KC_B,        KC_Z,          KC_X,           KC_C,          KC_V,                KC_PAST,          KC_P1,         KC_P2,         KC_P3,         KC_PCMM,       KC_RSFT,
                                                   KC_LCTL,        KC_ENT,        KC_SPC,              KC_PENT,          KC_PEQL,       KC_PDOT,
                       KC_NO,       KC_NO,         KC_NO,          KC_NO,         KC_NO,               KC_NO,            KC_NO,         KC_NO,         KC_NO,         KC_NO
  )
};

// Keys to highlight in the LED matrix when the game layer is enabled.
#define NUM_HIGHLIGHTS_LEFT 4
static uint8_t highlights_left[NUM_HIGHLIGHTS_LEFT][2] = {
    { 0, 3 }, // E key
    { 1, 2 }, // S key
    { 1, 3 }, // D key
    { 1, 4 }  // F key
};

#define NUM_HIGHLIGHTS_RIGHT 1
static uint8_t highlights_right[NUM_HIGHLIGHTS_RIGHT][2] = {
    { 0, 0 }  // MINUS key
};

// Default key combinations.
#define NUM_COMBOS 1
static const vial_combo_entry_t combos[] = {
    { { KC_LSFT, KC_RSFT, KC_NO, KC_NO }, KC_CAPS }
};

static os_modes_t os_mode = WIN;

static void init_os_mode(void) {
    os_variant_t os = detected_host_os();
    os_mode = (os == OS_MACOS || os == OS_IOS) ? MAC : WIN;
}

static void init_combos(void) {
    for (int i = 0; i < NUM_COMBOS; i++) {
        dynamic_keymap_set_combo(i, combos + i);
    }
}

void keyboard_post_init_user( void ) {
    init_os_mode();
    init_combos();
#ifdef OLED_ENABLE
    update_state();
#endif
}

static void emit_key_event(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code16(keycode);
    } else {
        unregister_code16(keycode);
    }
}

static bool swap_key_event(uint16_t keycode, keyrecord_t *record) {
    if (os_mode == MAC) {
        emit_key_event(keycode, record);
        return false;
    }
    return true;
}

static bool send_deadkey_event(uint16_t deadkeycode, uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        uint8_t mods = get_mods() & (MOD_MASK_SHIFT | MOD_BIT(KC_RALT));
        del_mods(mods);
        tap_code16(deadkeycode);
        add_mods(mods);
        tap_code16(keycode);
    }
    return false;
}

bool rgb_matrix_indicators_user(void) {
    if (get_highest_layer(layer_state) == LAYER_GAME) {
        HSV hsv = {HSV_WHITE};
        uint16_t value = rgb_matrix_get_val() * 2;
        hsv.v = value < 256 ? (uint8_t)value : 255;
        RGB rgb = hsv_to_rgb(hsv);
        uint8_t (*highlights)[2] = highlights_right;
        uint8_t num_highlights = NUM_HIGHLIGHTS_RIGHT;
        if (is_keyboard_master()) {
            highlights = highlights_left; 
            num_highlights = NUM_HIGHLIGHTS_LEFT;
        }
        for (uint8_t i = 0; i < num_highlights; i++) {
            uint8_t j = highlights[i][0];
            uint8_t k = highlights[i][1];
            rgb_matrix_set_color(g_led_config.matrix_co[j][k], rgb.r, rgb.g, rgb.b);
        }
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_OSMODE:
            if (record->event.pressed) {
                // Switch OS mode.
                os_mode = (os_mode == WIN) ? MAC : WIN;
            }
            return false;

        case KC_ANIMATE:
            return false;

        // Single-stroke versions of keys that normally require deadkey composition.
        case KC_A_CIRCUMFLEX: return send_deadkey_event(CA_CIRC, KC_A, record);
        case KC_A_DIAERESIS: return send_deadkey_event(CA_DIAE, KC_A, record);
        case KC_E_CIRCUMFLEX: return send_deadkey_event(CA_CIRC, KC_E, record);
        case KC_E_DIAERESIS: return send_deadkey_event(CA_DIAE, KC_E, record);
        case KC_I_CIRCUMFLEX: return send_deadkey_event(CA_CIRC, KC_I, record);
        case KC_I_DIAERESIS: return send_deadkey_event(CA_DIAE, KC_I, record);
        case KC_O_CIRCUMFLEX: return send_deadkey_event(CA_CIRC, KC_O, record);
        case KC_O_DIAERESIS: return send_deadkey_event(CA_DIAE, KC_O, record);
        case KC_U_CIRCUMFLEX: return send_deadkey_event(CA_CIRC, KC_U, record);
        case KC_U_DIAERESIS: return send_deadkey_event(CA_DIAE, KC_U, record);

        // Mac and Windows swap the placement of KC_NUBS and CA_SLSH under CSA keyboard layout.
        case KC_NONUS_BACKSLASH: return swap_key_event(CA_SLSH, record);
        case S(KC_NONUS_BACKSLASH): return swap_key_event(S(CA_SLSH), record);
        case CA_SLSH: return swap_key_event(KC_NONUS_BACKSLASH, record);
        case S(CA_SLSH): return swap_key_event(S(KC_NONUS_BACKSLASH), record);
        case CA_PIPE: return swap_key_event(RALT(KC_MINUS), record);

        // Suppress keys that confuse the selected OS.
        case KC_PAUSE:
        case KC_SCROLL_LOCK:
            return (os_mode != MAC);
        case KC_MISSION_CONTROL:
        case KC_LAUNCHPAD:
            return (os_mode == MAC);

        case LCTL_T(KC_TAB):
            if (os_mode == MAC && !record->tap.count) {
                // Change the LCTL_L(KC_TAB) key to LGUI_T(KC_TAB) on Mac.
                emit_key_event(KC_LGUI, record);
                return false;
            }
            break;
    }

    return true; // Process all other keycodes normally
}

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C