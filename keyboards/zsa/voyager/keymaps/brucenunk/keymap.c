// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include "keymap_us.h"
#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Alpha: Hands Down Vibranium (https://sites.google.com/alanreiser.com/handsdown/home/hands-down-neu#h.twknhghfz1x0)
    [0] = LAYOUT(
        KC_GRAVE,  KC_1, KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQUAL,
        KC_ESCAPE, KC_X, KC_W,    KC_M,    KC_G,    KC_J,                         KC_AT,   KC_DOT,  KC_SLASH,KC_DQUO, KC_QUOTE,KC_PIPE,
        KC_TAB,    KC_S, KC_C,    KC_N,    KC_T,    KC_K,                         KC_COMMA,KC_A,    KC_E,    KC_I,    KC_H,    KC_DOLLAR,
        KC_TILDE,  KC_F, KC_P,    KC_L,    KC_D,    KC_V,                         KC_MINUS,KC_U,    KC_O,    KC_Y,    KC_B,    KC_AMPERSAND,
                                                        KC_R,    KC_BSPC,                     KC_ENTER,LT(1,KC_SPC)
    ),
    // Symbol
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_CIRC, KC_BSLS, KC_PERC, KC_UNDS, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_LT,   KC_LBRC, KC_LPRN, KC_LCBR, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_GT,   KC_RBRC, KC_RPRN, KC_RCBR, _______,                      _______, _______, _______, _______, _______, _______,
                                                         _______, _______,                      _______, _______
    ),
};
// clang-format on
