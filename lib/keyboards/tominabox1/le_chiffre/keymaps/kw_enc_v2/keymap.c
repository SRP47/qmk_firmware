/* Copyright 2020 tominabox1
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

enum layers{
  _BASE,
  _NUM_SYM,
  _NAV
};

enum combo_events {
  COMBO_ENT,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
  COMBO_F1,
  COMBO_F2,
  COMBO_F3,
  COMBO_F4,
  COMBO_F5,
  COMBO_F6,
  COMBO_F7,
  COMBO_F8,
  COMBO_F9,
  COMBO_F10,
  COMBO_F11,
  COMBO_F12,
};

#define KC_NUM_SPC LT(_NUM_SYM, KC_SPC)
#define KC_GA LGUI_T(KC_A)
#define KC_AS LALT_T(KC_S)
#define KC_CD LCTL_T(KC_D)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
#define KC_CK RCTL_T(KC_K)
#define KC_AL RALT_T(KC_L)
#define KC_GSCLN RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,  KC_MPLY,  KC_Y,   KC_U,    KC_I,   KC_O,     KC_P,
   KC_GA,  KC_AS,  KC_CD,  KC_SF,   KC_G,            KC_H,  KC_SJ,   KC_CK,  KC_AL, KC_GSCLN,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,            KC_N,   KC_M, KC_COMM, KC_DOT,  KC_SLSH,
                         KC_LCTL, KC_BSPC,            KC_NUM_SPC, MO(_NAV)
  ),

  [_NUM_SYM] = LAYOUT(
        KC_1,  KC_2,     KC_3,     KC_4,      KC_5,  KC_TRNS,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    KC_EXLM,  KC_AT,  KC_HASH,   KC_DLR,   KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR, KC_EQUAL,  KC_MINS,
    KC_BSLS,KC_LCBR,  KC_LBRC,  KC_LPRN,   KC_UNDS,            KC_RPRN,  KC_RBRC,  KC_RCBR,   KC_DOT,   KC_QUOTE,
                                KC_CAPS,   KC_DEL,            KC_TRNS,  KC_TRNS
  ),

  [_NAV] = LAYOUT(
      RESET,  _______,  AG_NORM,  AG_SWAP,  DEBUG, KC_TRNS,   KC_GRV,  KC_HOME,    KC_UP,  KC_END,  KC_SCLN,
    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_NO,           KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGUP,
    RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_NO,           KC_MINS,    KC_RO,  KC_COMM,   KC_DOT,  KC_BSLS,
                                  KC_TRNS,KC_ENT,           KC_TRNS,  KC_TRNS
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
          if (layer_state_is(_NUM_SYM)) {               
            tap_code(KC_LEFT);
          } else if (layer_state_is(_NAV)) {
            tap_code16(LSFT(KC_TAB));
          } else {
            tap_code(KC_VOLD);
          }
        } else {
          if (layer_state_is(_NUM_SYM)) {
            tap_code(KC_RIGHT);
          } else if (layer_state_is(_NAV)) {
            tap_code(KC_TAB);
          } else {
            tap_code(KC_VOLU);
          }
        }
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_NUM_SPC:
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
}


#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_ent[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo_f1[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_f2[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo_f3[] = {KC_3, KC_4, COMBO_END};
const uint16_t PROGMEM combo_f4[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM combo_f5[] = {KC_6, KC_7, COMBO_END};
const uint16_t PROGMEM combo_f6[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM combo_f7[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo_f8[] = {KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM combo_f9[] = {KC_BSLS, KC_LCBR, COMBO_END};
const uint16_t PROGMEM combo_f10[] = {KC_LCBR, KC_LBRC, COMBO_END};
const uint16_t PROGMEM combo_f11[] = {KC_LBRC, KC_LPRN, COMBO_END};
const uint16_t PROGMEM combo_f12[] = {KC_LPRN, KC_UNDS, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_ENT] = COMBO(combo_ent,KC_ENT),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),
  [COMBO_F1] = COMBO(combo_f1,KC_F1),
  [COMBO_F2] = COMBO(combo_f2,KC_F2),
  [COMBO_F3] = COMBO(combo_f3,KC_F3),
  [COMBO_F4] = COMBO(combo_f4,KC_F4),
  [COMBO_F5] = COMBO(combo_f5,KC_F5),
  [COMBO_F6] = COMBO(combo_f6,KC_F6),
  [COMBO_F7] = COMBO(combo_f7,KC_F7),
  [COMBO_F8] = COMBO(combo_f8,KC_F8),
  [COMBO_F9] = COMBO(combo_f9,KC_F9),
  [COMBO_F10] = COMBO(combo_f10,KC_F10),
  [COMBO_F11] = COMBO(combo_f11,KC_F11),
  [COMBO_F12] = COMBO(combo_f12,KC_F12),
};
#endif
