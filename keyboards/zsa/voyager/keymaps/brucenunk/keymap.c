// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include "keymap_us.h"
#include "process_key_override.h"
#include QMK_KEYBOARD_H

// Home row mods.
#define HRM_S LGUI_T(KC_S)
#define HRM_C LALT_T(KC_C)
#define HRM_N LCTL_T(KC_N)
#define HRM_T LSFT_T(KC_T)
#define HRM_A RSFT_T(KC_A)
#define HRM_E RCTL_T(KC_E)
#define HRM_I LALT_T(KC_I)
#define HRM_H RGUI_T(KC_H)

// Key overrides; used for shift overrides.
const key_override_t shift_at_override           = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_HASH);
const key_override_t shift_dot_override          = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLON);
const key_override_t shift_slash_override        = ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_ASTERISK);
const key_override_t shift_double_quote_override = ko_make_basic(MOD_MASK_SHIFT, KC_DQUO, KC_QUESTION);
const key_override_t shift_single_quote_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOTE, KC_EXCLAIM);
const key_override_t shift_comma_override        = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SEMICOLON);
const key_override_t shift_minus_override        = ko_make_basic(MOD_MASK_SHIFT, KC_MINUS, KC_PLUS);

const key_override_t *key_overrides[] = {
    // "@" -> "#"
    &shift_at_override,
    // "." -> ":"
    &shift_dot_override,
    // "/" -> "*"
    &shift_slash_override,
    // '"' -> "?
    &shift_double_quote_override,
    // "'" -> "!"
    &shift_single_quote_override,
    // "," -> ";"
    &shift_comma_override,
    // "-" -> "+"
    &shift_minus_override};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Alpha: Hands Down Vibranium (https://sites.google.com/alanreiser.com/handsdown/home/hands-down-neu#h.twknhghfz1x0)
    [0] = LAYOUT(
        KC_GRAVE,  KC_1, KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQUAL,
        KC_ESCAPE, KC_X, KC_W,    KC_M,    KC_G,    KC_J,                         KC_AT,   KC_DOT,  KC_SLASH,KC_DQUO, KC_QUOTE,KC_PIPE,
        KC_TAB,    HRM_S,HRM_C,   HRM_N,   HRM_T,   KC_K,                         KC_COMMA,HRM_A,   HRM_E,   HRM_I,   HRM_H,   KC_DOLLAR,
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
