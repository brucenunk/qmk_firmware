/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

// clang-format off


// Left-hand home row mods
#define HOME_S LGUI_T(KC_S)
#define HOME_N LALT_T(KC_N)
#define HOME_T LSFT_T(KC_T)
#define HOME_C LCTL_T(KC_C)

// Right-hand home row mods
#define HOME_H RCTL_T(KC_H)
#define HOME_E RSFT_T(KC_E)
#define HOME_A LALT_T(KC_A)
#define HOME_I RGUI_T(KC_I)


enum layers {
    QWERTY,
    RECURVA,
    _FN1,
    _FN2,
    _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_ansi_61(
        KC_ESC,               KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,               KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        MT(MOD_LCTL, KC_ESC), KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,              KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT,
        KC_LCTL,              KC_LOPT,  KC_LCMD,                            KC_SPC,                             KC_RCMD,  MO(_FN1), MO(_FN3), KC_RCTL),

    [RECURVA] = LAYOUT_ansi_61(
        KC_ESC,               KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,               KC_F,     KC_R,    KC_D,    KC_P,    KC_V,    KC_Q,    KC_J,    KC_U,    KC_O,    KC_Y,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        MT(MOD_LCTL, KC_ESC), HOME_S,   HOME_N, HOME_T,   HOME_C,  KC_B,    KC_DOT,  HOME_H,  HOME_E,  HOME_A,  HOME_I,   KC_SLSH,            KC_ENT,
        KC_LSFT,              KC_X,     KC_K,    KC_G,    KC_W,    KC_Z,    KC_M,    KC_L,    KC_SCLN, KC_QUOT, KC_COMM,            KC_RSFT,
        KC_LCTL,              KC_LOPT,  KC_LCMD,                            KC_SPC,                             KC_RCMD,  MO(_FN1), MO(_FN3), KC_RCTL),

    [_FN1] = LAYOUT_ansi_61(
        KC_GRV,  KC_BRID,  KC_BRIU, KC_NO,   KC_NO,   RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_MOD,
        RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, KC_INS,   KC_PGUP,  KC_HOME,  _______,
        _______, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, KC_UP,   KC_NO,   KC_PGDN,  KC_END,             _______,
        _______,           _______, _______, _______, _______, _______, NK_TOGG, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL,             _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_FN2] = LAYOUT_ansi_61(
        KC_GRV,  KC_BRID,  KC_BRIU, KC_NO,   KC_NO,   RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_MOD,
        RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, KC_APP,  KC_SCRL, KC_INS,   KC_PGUP,  KC_HOME,  _______,
        _______, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, KC_UP,   KC_PSCR, KC_PGDN,  KC_END,             _______,
        _______,           _______, _______, _______, _______, _______, NK_TOGG, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL,             _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_FN3] = LAYOUT_ansi_61(
        KC_TILD, DF(QWERTY), DF(RECURVA), KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,
        RGB_TOG, RGB_MOD,    RGB_VAI,     RGB_HUI,           RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, RGB_RMOD,   RGB_VAD,     RGB_HUD,           RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,            _______,
        _______,             _______,     _______,           _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,    _______,                                 _______,                            _______,  _______,  _______,  _______)
};

// clang-format on
