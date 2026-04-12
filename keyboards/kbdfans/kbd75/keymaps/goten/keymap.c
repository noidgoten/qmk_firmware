// Copyright 2022 Goten (@noidgoten)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_75_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT_75_ansi(
        _______, KC_CALC, KC_MSEL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, UG_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, EE_CLR,           _______,
        _______, _______, UG_VALU, UG_SATU, UG_HUEU, UG_NEXT, UG_SPDU, _______, _______, _______, _______, _______, _______, QK_BOOT,          _______,
        _______, UG_VALD, UG_SATD, UG_HUED, UG_PREV, UG_SPDD, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, KC_MSTP, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT
    ),
};
// clang-format on

const rgblight_segment_t PROGMEM goten_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  1, HSV_RED},
    {15, 1, HSV_RED}
);

const rgblight_segment_t* const PROGMEM goten_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    goten_capslock_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = goten_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}
