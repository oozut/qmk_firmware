/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_bepo.h"
#include "action_layer.h"
#include "quantum_keycodes.h"

#define BP_NDSH_MAC ALGR(KC_8)

// Mac 
#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)

// PC
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LSFT(KC_DELETE)
#define KC_PC_COPY LCTL(KC_INSERT)
#define KC_PC_PASTE LSFT(KC_INSERT)



#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

// Tap Dance declarations
enum {
    TD_ENTER_APP,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ENTER_APP] = ACTION_TAP_DANCE_DOUBLE(KC_ENTER,KC_APPLICATION),
};

enum unicode_names {
    BANG,
    IRONY,
    SNEK,

    // Standard Bepo layout

    // Top Row
    DOLLAR,
    QUOTATION_MARK,
    LESS_THAN,
    MORE_THAN,
    L_PARANTHESIS,
    R_PARANTHESIS,
    COMMERCIAL_AT,
    PLUS_SIGN,
    MINUS_SIGN,
    SOLIDUS,


};



const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍


    // Standard Bepo layout
    
    // Top Row
    [DOLLAR] = 0x0024, // $
    [QUOTATION_MARK] = 0x0022, // "
    [LESS_THAN] = 0x003C, // <
    [MORE_THAN] = 0x003E, // >
    [L_PARANTHESIS] = 0x0028, // (
    [R_PARANTHESIS] = 0x0029, // )
    [COMMERCIAL_AT] = 0x0040, // @
    [PLUS_SIGN] = 0x002B, // +
    [MINUS_SIGN] = 0x002D, // -
    [SOLIDUS] = 0x002F, // /






};

enum unicode_names_shift {
    BANG_S,
    IRONY_S,
    SNEK_S
};
const uint32_t PROGMEM unicode_map_shift[] = {
    [BANG_S]  = 0x203D,  // ‽
    [IRONY_S] = 0x2E2E,  // ⸮
    [SNEK_S]  = 0x1F40D, // 🐍
};

enum unicode_names_altgr {
    BANG_A,
    IRONY_A,
    SNEK_A
};
const uint32_t PROGMEM unicode_map_altgr[] = {
    [BANG_A]  = 0x203D,  // ‽
    [IRONY_A] = 0x2E2E,  // ⸮
    [SNEK_A]  = 0x1F40D, // 🐍
};

enum unicode_names_altgrshift {
    BANG_AS,
    IRONY_AS,
    SNEK_AS
};
const uint32_t PROGMEM unicode_map_altgrshift[] = {
    [BANG_AS]  = 0x203D,  // ‽
    [IRONY_AS] = 0x2E2E,  // ⸮
    [SNEK_AS]  = 0x1F40D, // 🐍
};

enum layers {
    BASE_Q,  // default layer
    MEDIA_NORMAL, // default media layer 
    BEPO_NORMAL,  // bépo layer with bepo support from computer
    BEPO_UNICODE, // bépo layer with unicode
    MEDIA_BEPO, // media layer for bepo layout
};



enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
    RGB_SLD = ML_SAFE_RANGE,
    ST_MACRO_WinLock,
    ST_MACRO_WinLock_bepo,
    ST_MACRO_DZERO,
    HSV_0_255_255,
    HSV_86_255_128,
    HSV_172_255_255,
    BP_LSPO,
    BP_RSPC,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_Q] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    LSFT(KC_DELETE),               OSL(MEDIA_NORMAL),    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, // Top Row
        KC_PC_UNDO,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    LCTL(KC_INSERT),              KC_BSPC,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, // Second Row
        KC_LEAD, LCTL_T(KC_A),    LSFT_T(KC_S),    RALT_T(KC_D),    MT(MOD_MEH,KC_F),    MT(MOD_HYPR,KC_G),   LSFT(KC_INSERT),               LALT_T(KC_NO),     MT(MOD_HYPR,KC_H),    MT(MOD_MEH,KC_J),    RALT_T(KC_K),    RSFT_T(KC_L),    RCTL_T(KC_SCLN), LGUI_T(KC_QUOT), // Principal Row
        KC_LSFT, KC_Z,KC_X,KC_C,    KC_V,       KC_B,                                       KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT, // Third Row
        KC_LCTRL,WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  LALT_T(KC_APP),                             RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(MEDIA_NORMAL), // Bottom Row
                                            LCTL_T(KC_SPACE),       KC_BSPACE,      KC_DELETE,                      KC_ESCAPE,      KC_TAB,         LSFT_T(KC_ENTER) // Thumb Row
    ),
    [MEDIA_NORMAL] = LAYOUT_moonlander(
        KC_WWW_BACK,    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          ST_MACRO_WinLock,                                     RGB_MOD,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
        KC_WWW_HOME,    KC_SYSTEM_POWER,MOON_LED_LEVEL, KC_HOME,        KC_UP,          KC_END,         KC_PGUP,                                        RGB_VAI,        RGB_SAI,        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, KC_F12,         
        KC_CALCULATOR,  KC_SYSTEM_SLEEP,KC_SYSTEM_WAKE, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDOWN,                                                                      RGB_VAD,        RGB_SAD,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_SLASH,    KC_BSPACE, 
        KC_MAIL,        KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_FIND,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_ESCAPE, KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_MINUS,    KC_NUMLOCK,     
        KC_TRANSPARENT, KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    KC_WWW_SEARCH,  KC_MY_COMPUTER,                                                                                                 KC_MEDIA_STOP,  KC_KP_0,        ST_MACRO_DZERO,     KC_KP_DOT,      KC_KP_PLUS,     KC_KP_ENTER, 
        KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,                KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP   
    ),
    [BEPO_NORMAL] = LAYOUT_moonlander(
      BP_DLR,         BP_DQOT,        BP_LDAQ,        BP_RDAQ,        BP_LPRN,        BP_RPRN,        LSFT(KC_DELETE),                                     BP_PERC,        BP_AT,          BP_PLUS,        BP_MINS,        BP_SLSH,        BP_ASTR,        BP_EQL,         
      LCTL(BP_Z),     BP_B,           BP_ECUT,        BP_P,           BP_O,           BP_EGRV,        LCTL(KC_INSERT),                                   BP_DCRC,          BP_W,        BP_V,           BP_D,           BP_L,           BP_J,           BP_Z,           
      KC_LEAD, LCTL_T(BP_A),   LSFT_T(BP_U),   RALT_T(BP_I),   MT(MOD_MEH, BP_E),MT(MOD_HYPR, BP_COMM),LSFT(KC_INSERT),                                                                  LALT_T(KC_NO),      MT(MOD_HYPR, BP_C),MT(MOD_MEH, BP_T),RALT_T(BP_S),   RSFT_T(BP_R),   RCTL_T(BP_N),   BP_M,           
      BP_ECIR,        BP_AGRV,        BP_Y,           BP_X,           BP_DOT,         BP_K,                                           BP_APOS,        BP_Q,           BP_G,           BP_H,           BP_F,           BP_CCED,        
      TT(MEDIA_BEPO),      KC_HOME,        KC_END,         KC_LEFT,        KC_RIGHT,       TD(TD_ENTER_APP),                          KC_INSERT,    KC_UP,       KC_DOWN,        KC_PGUP,        KC_PGDOWN,      KC_RGUI,        
      LCTL_T(KC_SPACE),       KC_BSPACE,      KC_DELETE,                      KC_ESCAPE,      KC_TAB,         LSFT_T(KC_ENTER)
    ),

    [BEPO_UNICODE] = LAYOUT_moonlander(
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_WinLock_bepo,                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
      LCTL(BP_Z),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PC_PASTE,                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
      KC_LEAD, LCTL_T(KC_NO),  LSFT_T(KC_NO),  RALT_T(KC_NO),  MT(MOD_MEH,KC_NO),         MT(MOD_HYPR,KC_NO),        LALT_T(KC_NO),                                                                  KC_PC_CUT,      MT(MOD_HYPR,KC_NO),        MT(MOD_MEH,KC_NO),         RALT_T(KC_NO),  RSFT_T(KC_NO),  RCTL_T(KC_NO),  KC_TRANSPARENT, 
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
      TT(MEDIA_BEPO),      KC_HOME,        KC_END,         KC_LEFT,        KC_RIGHT,       TD(TD_ENTER_APP),                          KC_INSERT,    KC_UP,       KC_DOWN,        KC_PGUP,        KC_PGDOWN,      KC_RGUI,        
      LCTL_T(KC_SPACE),       KC_BSPACE,      KC_DELETE,                      KC_ESCAPE,      KC_TAB,         LSFT_T(KC_ENTER)
    ),

    [MEDIA_BEPO] = LAYOUT_moonlander(
      KC_WWW_BACK,    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          ST_MACRO_WinLock_bepo,                                     RGB_MOD,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
      KC_WWW_HOME,    KC_SYSTEM_POWER,MOON_LED_LEVEL, KC_HOME,        KC_UP,          KC_END,         KC_PGUP,                                        RGB_VAI,        RGB_SAI,        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, KC_F12,         
      KC_CALCULATOR,  KC_SYSTEM_SLEEP,KC_SYSTEM_WAKE, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDOWN,                                                                      RGB_VAD,        RGB_SAD,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_SLASH,    KC_BSPACE, 
      KC_MAIL,        KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_FIND,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_ESCAPE, KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_MINUS,    KC_NUMLOCK,     
      KC_TRANSPARENT, KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    KC_WWW_SEARCH,  KC_MY_COMPUTER,                                                                                                 KC_MEDIA_STOP,  KC_KP_0,        ST_MACRO_DZERO,     KC_KP_DOT,      KC_KP_PLUS,     KC_KP_ENTER,    
      KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,                KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP
    ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void)
{
  rgb_matrix_enable();
}

LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();


    SEQ_TWO_KEYS(KC_T, KC_T) {
      SEND_STRING("test test successfull");
    }

    SEQ_TWO_KEYS(KC_L, KC_B) {
      layer_on(BEPO_NORMAL);
    }
    SEQ_TWO_KEYS(KC_O, KC_M) {
      layer_off(BEPO_NORMAL);
    }
    SEQ_TWO_KEYS(BP_L, BP_Q) {
      layer_off(BEPO_NORMAL);
    }

  }
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][5] = {
    [BASE_Q] = { {0,0,255}, {32,176,255}, {134,255,213}, {0,0,255}, {32,176,255}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {32,176,255}, {32,176,255}, {32,176,255}, {85,203,158}, {85,203,158}, {85,203,158}, {243,222,234}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {32,176,255}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {0,0,255}, {0,0,255}, {10,225,255}, {85,203,158}, {85,203,158}, {85,203,158}, {243,222,234} },
    [MEDIA_NORMAL] = { {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {243,222,234}, {33,255,255}, {10,225,255}, {10,225,255}, {10,225,255}, {32,176,255}, {33,255,255}, {10,225,255}, {10,225,255}, {10,225,255}, {32,176,255}, {33,255,255}, {154,255,255}, {154,255,255}, {10,225,255}, {32,176,255}, {33,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {32,176,255}, {33,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {249,228,255}, {154,255,255}, {154,255,255}, {85,203,158}, {85,203,158}, {85,203,158}, {243,222,234}, {33,255,255}, {33,255,255}, {0,0,0}, {134,255,213}, {134,255,213}, {33,255,255}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {33,255,255}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {33,255,255}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {33,255,255}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {33,255,255}, {105,255,255}, {105,255,255}, {0,205,155}, {105,255,255}, {105,255,255}, {105,255,255}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158} },
    [BEPO_NORMAL] = { {0,0,255}, {32,176,255}, {134,255,213}, {0,0,255}, {32,176,255}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {32,176,255}, {32,176,255}, {32,176,255}, {85,203,158}, {85,203,158}, {85,203,158}, {243,222,234}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {32,176,255}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {0,0,255}, {0,0,255}, {10,225,255}, {85,203,158}, {85,203,158}, {85,203,158}, {243,222,234} },
    [BEPO_UNICODE] = { {0,0,255}, {32,176,255}, {134,255,213}, {0,0,255}, {32,176,255}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {32,176,255}, {32,176,255}, {32,176,255}, {85,203,158}, {85,203,158}, {85,203,158}, {243,222,234}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {32,176,255}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {243,222,234}, {0,0,255}, {0,0,255}, {10,225,255}, {0,0,255}, {0,0,255}, {0,0,255}, {10,225,255}, {85,203,158}, {85,203,158}, {85,203,158}, {243,222,234} },
    [MEDIA_BEPO] = { {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {243,222,234}, {33,255,255}, {10,225,255}, {10,225,255}, {10,225,255}, {32,176,255}, {33,255,255}, {10,225,255}, {10,225,255}, {10,225,255}, {32,176,255}, {33,255,255}, {154,255,255}, {154,255,255}, {10,225,255}, {32,176,255}, {33,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {32,176,255}, {33,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {249,228,255}, {154,255,255}, {154,255,255}, {85,203,158}, {85,203,158}, {85,203,158}, {243,222,234}, {33,255,255}, {33,255,255}, {0,0,0}, {134,255,213}, {134,255,213}, {33,255,255}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {33,255,255}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {33,255,255}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {33,255,255}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {33,255,255}, {105,255,255}, {105,255,255}, {0,205,155}, {105,255,255}, {105,255,255}, {105,255,255}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case BASE_Q:
      set_layer_color(BASE_Q);
      break;
    case BEPO_NORMAL:
      set_layer_color(BEPO_NORMAL);
      break;
    case BEPO_UNICODE:
      set_layer_color(BEPO_UNICODE);
      break;
    case MEDIA_NORMAL:
      set_layer_color(MEDIA_NORMAL);
      break;
    case MEDIA_BEPO:
      set_layer_color(MEDIA_BEPO);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_WinLock:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_L)));
          }
        break;

    case ST_MACRO_WinLock_bepo:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_O)));
          }
        break;

    case ST_MACRO_DZERO:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_KP_0) SS_DELAY(100) SS_TAP(X_KP_0));

        }
      break;

    case BP_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_TRNS, BP_LPRN);
      return false;

    case BP_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_TRNS, BP_RPRN);
      return false;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;

    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;

    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;

    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;

  }
  return true;
}