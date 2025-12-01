// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base
    [0] = LAYOUT_ortho_3x12(
        KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,KC_HOME,KC_PGUP,        KC_Y,      KC_U,        KC_I,        KC_O,        KC_P,
        LALT_T(KC_A),LGUI_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),KC_G,KC_END, KC_PGDN,        KC_H,      RSFT_T(KC_J),RCTL_T(KC_K),RGUI_T(KC_L),RALT_T(KC_COLN),
        KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,KC_BSPC,LT(1,KC_SPC),   LT(2,KC_N),      KC_M,        KC_COMM,     KC_DOT,      KC_SLSH
    ),
    // Fn
    [1] = LAYOUT_ortho_3x12(
        KC_1,        KC_2,        KC_3,        KC_4,        KC_5,   KC_TRNS,KC_VOLU,     KC_6,      KC_7,        KC_8,        KC_9,        KC_0,
        S(KC_1),     S(KC_2),     S(KC_3),     S(KC_4),     S(KC_5),KC_TRNS,KC_VOLD,     S(KC_6),   S(KC_7),     S(KC_8),     KC_EQL,     KC_MINS,
        KC_BSLS,     KC_LCBR,     KC_LBRC,     KC_LPRN,     KC_UNDS,KC_DEL,KC_TRNS,     KC_RPRN,   KC_RBRC,     KC_RCBR,     KC_DOT,      KC_QUOT
    ),
    // Navigation and others
    [2] = LAYOUT_ortho_3x12(
        KC_F1  ,     KC_F2  ,     KC_F3  ,     KC_F4  ,     KC_TRNS,KC_MPRV,KC_MNXT,     KC_GRV,   KC_HOME,KC_UP,KC_END,KC_TRNS,
        KC_F5  ,     KC_F6  ,     KC_F7  ,     KC_F8  ,     KC_TRNS,KC_MPLY,KC_MUTE,     KC_PGUP,   KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,
        KC_F9  ,     KC_F10 ,     KC_F11 ,     KC_F12 ,     KC_TRNS,KC_TRNS,MO(3),     KC_TRNS,   KC_MPRV,KC_MNXT,KC_TRNS,KC_TRNS
    ),
    // Keyboard configuration
    [3] = LAYOUT_ortho_3x12(
        RM_TOGG,     CG_TOGG,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     QK_BOOT,     QK_RBT,
        RM_NEXT,     RM_HUEU,     RM_SATU,     RM_VALU,     RM_SPDU,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
        RM_PREV,     RM_HUED,     RM_SATD,     RM_VALD,     RM_SPDD,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS
    )

};

const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_DOT, KC_SLSH, COMBO_END};

combo_t key_combos[] = {
    COMBO(tab_combo, KC_TAB),
    COMBO(esc_combo, KC_ESC),
    COMBO(ent_combo, KC_ENT),
};
