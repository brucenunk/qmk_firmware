// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "action.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "modifiers.h"
#include "process_combo.h"
#include "process_key_override.h"
#include QMK_KEYBOARD_H

//
//    Base (alpha) Layer  Hands Down Vibranium-vf (HRMs /+ thumb mods)
//      ╭─────────────────────╮                 ╭─────────────────────╮
//      │  X   W   M   G   J  │                 │  @#  .:  /*  "?  '! │
//      │  S   C   N   T   K  |                 |  ,;   A   E   I   H │
//      │  F   P   L   D   V  │                 │  -+   U   O   Y   B │
//      ╰───────────╮ bsp  R  │                 │ spc  ret ╭──────────╯
//                  ╰─────────╯                 ╰──────────╯
//

// Home row mods.
#define HRM_S LGUI_T(KC_S)
#define HRM_C LALT_T(KC_C)
#define HRM_N LCTL_T(KC_N)
#define HRM_T LSFT_T(KC_T)
#define HRM_A RSFT_T(KC_A)
#define HRM_E RCTL_T(KC_E)
#define HRM_I RALT_T(KC_I)
#define HRM_H RGUI_T(KC_H)

// Digraphs.
enum combo_events {
    COMBO_CH,
    COMBO_GH,
    COMBO_PH,
    COMBO_Q,
    COMBO_SH,
    COMBO_TH,
    COMBO_WH,
    COMBO_Z,
};

// H-digraphs.
const uint16_t PROGMEM combo_ch[] = {HRM_C, HRM_N, COMBO_END};
const uint16_t PROGMEM combo_gh[] = {KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM combo_ph[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo_sh[] = {HRM_S, HRM_C, COMBO_END};
const uint16_t PROGMEM combo_th[] = {HRM_N, HRM_T, COMBO_END};
const uint16_t PROGMEM combo_wh[] = {KC_W, KC_M, COMBO_END};
// Evicted letters - these are too infrequently used to live on the base alpha layout.
const uint16_t PROGMEM combo_q[] = {HRM_C, HRM_T, COMBO_END};
const uint16_t PROGMEM combo_z[] = {KC_W, KC_G, COMBO_END};

combo_t key_combos[] = {
    // "c+n" -> "ch".
    [COMBO_CH] = COMBO_ACTION(combo_ch),
    // "m+g" -> "gh".
    [COMBO_GH] = COMBO_ACTION(combo_gh),
    // "f+p" -> "ph".
    [COMBO_PH] = COMBO_ACTION(combo_ph),
    // "s+c" -> "sh".
    [COMBO_SH] = COMBO_ACTION(combo_sh),
    // "n+t" -> "th".
    [COMBO_TH] = COMBO_ACTION(combo_th),
    // "w+m" -> "wh".
    [COMBO_WH] = COMBO_ACTION(combo_wh),
    // "w+g" -> "q".
    [COMBO_Q] = COMBO_ACTION(combo_q),
    // "c+t" -> "z".
    [COMBO_Z] = COMBO_ACTION(combo_z),
};

// Key overrides; used for shift overrides.
const key_override_t shift_at_hash_override               = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_HASH);
const key_override_t shift_dot_colon_override             = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLON);
const key_override_t shift_slash_asterisk_override        = ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_ASTERISK);
const key_override_t shift_double_quote_question_override = ko_make_basic(MOD_MASK_SHIFT, KC_DQUO, KC_QUESTION);
const key_override_t shift_single_quote_exclaim_override  = ko_make_basic(MOD_MASK_SHIFT, KC_QUOTE, KC_EXCLAIM);
const key_override_t shift_comma_semicolon_override       = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SEMICOLON);
const key_override_t shift_minus_plus_override            = ko_make_basic(MOD_MASK_SHIFT, KC_MINUS, KC_PLUS);

const key_override_t *key_overrides[] = {
    // "@" -> "#"
    &shift_at_hash_override,
    // "." -> ":"
    &shift_dot_colon_override,
    // "/" -> "*"
    &shift_slash_asterisk_override,
    // '"' -> "?
    &shift_double_quote_question_override,
    // "'" -> "!"
    &shift_single_quote_exclaim_override,
    // "," -> ";"
    &shift_comma_semicolon_override,
    // "-" -> "+"
    &shift_minus_plus_override};

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

void process_combo_event(uint16_t combo_index, bool pressed) {
    // Use the `release` event instead to give tap/mods a chance to fire.
    if (pressed) return;

    bool h_digraph = false;

    switch (combo_index) {
        // H-digraphs.
        case COMBO_CH:
            h_digraph = true;
            tap_code(KC_C);
            break;
        case COMBO_GH:
            h_digraph = true;
            tap_code(KC_G);
            break;
        case COMBO_PH:
            h_digraph = true;
            tap_code(KC_P);
            break;
        case COMBO_SH:
            h_digraph = true;
            tap_code(KC_S);
            break;
        case COMBO_TH:
            h_digraph = true;
            tap_code(KC_T);
            break;
        case COMBO_WH:
            h_digraph = true;
            tap_code(KC_W);
            break;
        // Evicted letters.
        case COMBO_Q:
            tap_code(KC_Q);
            break;
        case COMBO_Z:
            tap_code(KC_Z);
            break;
    }

    if (h_digraph) {
        // Unregister `shift` so that we can hold shift and press a h-digraph and it works as expected; ie: `shift+th` should output `Th`.
        unregister_mods(MOD_MASK_SHIFT);
        tap_code(KC_H);
    }
};
