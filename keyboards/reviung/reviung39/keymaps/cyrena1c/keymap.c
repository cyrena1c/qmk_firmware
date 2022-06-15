/* Copyright 2019 gtips
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE
};

enum combo_names {
    _DF_LCBR,
    _JK_RCBR,
    _FG_LBRC,
    _HJ_RBRC,
    _PBSPC_EQL,
    _LSCLN_MINS
};

enum custom_macros {
    /* Macros required for alt-tab behavior */
    ALT_TAB = SAFE_RANGE,
    CUSTOM_LOWER
};

#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define MOUSE  TG(_MOUSE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung39(
    LALT_T(KC_TAB),  KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    LCTL_T(KC_ESC),  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,         KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT),
                                                      CUSTOM_LOWER,    KC_SPC,    RAISE
  ),

#define CUAUNDO LCTL(KC_Z)
#define CUACUT  LCTL(KC_X)
#define CUACOPY LCTL(KC_C)
#define CUAPAST LCTL(KC_V)
#define XPLCOPY LCTL(KC_INS)
#define XPLPAST LSFT(KC_INS)

  [_LOWER] = LAYOUT_reviung39(
    ALT_TAB,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    _______,   CUAUNDO,  CUACUT,   CUACOPY,  CUAPAST,   KC_PIPE,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_INS,   KC_GRV,
    _______,   KC_ESC,   KC_LGUI,  XPLCOPY,  XPLPAST,   KC_TILD,            KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_PSCR,  RSFT_T(KC_SPC),
                                                       _______,  KC_ENT,   _______
  ),

  [_RAISE] = LAYOUT_reviung39(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    _______,  KC_F13,   KC_F14,   KC_F15,   KC_F16,    KC_BSLS,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
    _______,  KC_ESC,   KC_LGUI,  KC_LALT,  KC_CAPS,   KC_F24,             KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
                                                       _______,  KC_BSPC,  _______
  ),

  [_ADJUST] = LAYOUT_reviung39(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_U,     XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,     XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   RESET,              XXXXXXX,  KC_ACL0,  KC_ACL1,  KC_ACL2,  MOUSE,       XXXXXXX,
                                                       _______,  XXXXXXX,  _______
  ),

  [_MOUSE] = LAYOUT_reviung39(
    KC_LALT,  MOUSE,  MOUSE,  MOUSE,  MOUSE,  MOUSE,                         XXXXXXX,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_U,     XXXXXXX,
    KC_LCTL,  MOUSE,  MOUSE,  MOUSE,  MOUSE,  MOUSE,                         XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,     XXXXXXX,
    KC_LSFT,  MOUSE,  MOUSE,  MOUSE,  MOUSE,  MOUSE,                         XXXXXXX,  KC_ACL0,  KC_ACL1,  KC_ACL2,  MOUSE,       XXXXXXX,
                                                       _______,  KC_BTN1,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
#ifdef RGBLIGHT_ENABLE
    rgblight_set_layer_state(0, layer_state_cmp(state, _MOUSE));
#endif

    return state;
}

/* Combos */
const uint16_t PROGMEM combo_df[] =    {KC_D, KC_F,    COMBO_END};
const uint16_t PROGMEM combo_jk[] =    {KC_J, KC_K,    COMBO_END};
const uint16_t PROGMEM combo_fg[] =    {KC_F, KC_G,    COMBO_END};
const uint16_t PROGMEM combo_hj[] =    {KC_H, KC_J,    COMBO_END};
const uint16_t PROGMEM combo_pbspc[] = {KC_P, KC_BSPC, COMBO_END};
const uint16_t PROGMEM combo_lscln[] = {KC_L, KC_SCLN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [_DF_LCBR]    = COMBO(combo_df,    KC_LCBR),
    [_JK_RCBR]    = COMBO(combo_jk,    KC_RCBR),
    [_FG_LBRC]    = COMBO(combo_fg,    KC_LBRC),
    [_HJ_RBRC]    = COMBO(combo_hj,    KC_RBRC),
    [_PBSPC_EQL]  = COMBO(combo_pbspc, KC_EQL),
    [_LSCLN_MINS] = COMBO(combo_lscln, KC_MINS)
};

/* RGB stuff */
const rgblight_segment_t PROGMEM rgb_mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_WHITE}
);

const rgblight_segment_t* const PROGMEM rgb_all_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_mouse_layer
);

void keyboard_post_init_user() {
    rgblight_layers = rgb_all_layers;
}

/* Alt-tab behavior and other macros */
bool alt_tab_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        /* Required macros for alt-tab behavior */
        case ALT_TAB:
            /* ignore key-up's on ALT_TAB */
            if (!record->event.pressed) {
                return true;
            }
            /* handle key-down depending on alt-tab state */
            if (alt_tab_active) {
                tap_code(KC_TAB);
            } else {
                register_code(KC_LALT);
                tap_code(KC_TAB);
                alt_tab_active = true;
            }
            break;

        case CUSTOM_LOWER:
            /* basically do the same thing as the normal Lower key, */
            /* but also deactivate alt-tab on release */
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
                unregister_code(KC_LALT);
                alt_tab_active = false;
            }
            break;

        /* Insert other custom macros here */
    }
    return true;
}
