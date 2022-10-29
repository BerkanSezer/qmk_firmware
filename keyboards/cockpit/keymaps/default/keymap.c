/* Copyright 2022 Özkan Çelik -- (github.com/ozkan)
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

enum cockpit_layer {
    _DEFAULT,
    _LOWER,
    _RAISE,
    _ARROW,

    _FNR,
};

enum cockpit_keycodes {
  COLEMAK = SAFE_RANGE,
  COLEMAKDH,

};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define FNR    MO(_FNR)
#define ARROW  MO(_ARROW)



#define LSFT_CAPS  LSFT_T(KC_CAPS)
#define RSFT_ENT   RSFT_T(KC_ENT)

#define FNR_SPC     LT(FNR, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// DEFAULT
// ╭──────┬──────┬──────┬──────┬──────┬──────╮                   ╭──────┬──────┬──────┬──────┬──────┬──────╮
// │  TAB │  Q   │  W   │  F   │  P   │  G   │                   │  J   │  L   │  U   │  Y   │   ;  │ BSPC │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │ CTRL │  A   │  R   │  S   │NAV T │  D   │                   │  H   │  N   │  E   │  I   │  O   │   '  │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │SFT_CL│ALT Z │CTL X │SFT C │  V   │  B   │                   │  K   │  M   │SFT , │CTL . │  /   │ ENT  │
// ╰──────┴──────┴──────┴──────┴──────┴──────┼─────────┬─────────┼──────┴──────┴──────┴──────┴──────┴──────╯
//                                           │   MPLY  │  MUTE   │
//                     ╭──────┬──────┬───────┼─────────┴─────────┼──────┬──────┬──────╮
//                     │  ALT │LOWER │       │                   │ FNR  │RAISE │  WIN │
//                     ╰──────┴──────┴───────┴─────┬──────┬──────┴──────┴──────┴──────╯
//                                                 │  UP  │
//                                          ╭──────┼──────┼──────╮
//                                          │ LEFT │ DOWN │ RIGHT│
//                                          ╰──────┴──────┴──────╯

  [_DEFAULT] = LAYOUT_cockpit(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,                        KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                            KC_MPLY,    KC_MUTE,

                                // KC_LGUI,   LOWER,    MT(KC_RALT, KC_SPC),                           KC_ENT,   RAISE,   KC_RALT,
                                KC_LGUI,   LOWER,     KC_SPC,                           KC_ENT,   RAISE,   KC_RALT,
                                                                    KC_UP,
                                                        KC_LEFT,    KC_DOWN,    KC_RGHT

  ),

// LOWER
// ╭──────┬──────┬──────┬──────┬──────┬──────╮                   ╭──────┬──────┬──────┬──────┬──────┬──────╮
// │ ESC  │      │      │      │      │      │                   │  (   │  )   │  =   │  &   │  |   │ DEL  │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │      │      │      │      │      │                   │  {   │  }   │  _   │  $   │  #   │   "  │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │      │      │      │      │      │                   │  [   │  ]   │  <   │  >   │  \   │ ENT  │
// ╰──────┴──────┴──────┴──────┴──────┴──────┼─────────┬─────────┼──────┴──────┴──────┴──────┴──────┴──────╯
//                                           │  MPRV   │  MNXT   │
//                     ╭──────┬──────┬───────┼─────────┴─────────┼──────┬──────┬──────╮
//                     │  ALT │LOWER │       │                   │ FNR  │RAISE │  WIN │
//                     ╰──────┴──────┴───────┴─────┬──────┬──────┴──────┴──────┴──────╯
//                                                 │  UP  │
//                                          ╭──────┼──────┼──────╮
//                                          │ LEFT │ DOWN │ RIGHT│
//                        /                  ╰──────┴──────┴──────╯

  [_LOWER] = LAYOUT_cockpit(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, C(KC_UP), C(KC_LEFT), C(KC_RIGHT), KC_LEFT, KC_RIGHT,             KC_LEFT,  KC_DOWN,  KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                               KC_MPRV,   KC_MNXT,
                              KC_LGUI,   _______,    KC_SPC,                          KC_ENT,   FNR,   KC_RALT,
                                                                      KC_UP,
                                                         KC_LEFT,    KC_DOWN,  KC_RGHT

  ),


// RAISE
// ╭──────┬──────┬──────┬──────┬──────┬──────╮                   ╭──────┬──────┬──────┬──────┬──────┬──────╮
// │ ESC  │  !   │  @   │  #   │  $   │  %   │                   │  F1  │  F2  │  F3  │  F4  │      │      │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │  ML  │ MTL  │ MTR  │  LF  │  RG  │                   │  F5  │  F6  │  F7  │  F8  │      │      │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │  %   │ MBL  │ MBR  │      │      │                   │  F9  │  F10 │ F11  │  F1  │      │      │
// ╰──────┴──────┴──────┴──────┴──────┴──────┼─────────┬─────────┼──────┴──────┴──────┴──────┴──────┴──────╯
//                                           │  MPLY   │  MUTE   │
//                     ╭──────┬──────┬───────┼─────────┴─────────┼──────┬──────┬──────╮
//                     │  ALT │LOWER │       │                   │ FNR  │RAISE │  WIN │
//                     ╰──────┴──────┴───────┴─────┬──────┬──────┴──────┴──────┴──────╯
//                                                 │  UP  │
//                                          ╭──────┼──────┼──────╮
//                                          │ LEFT │ DOWN │ RIGHT│
//                                          ╰──────┴──────┴──────╯

  [_RAISE] = LAYOUT_cockpit(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, C(A(KC_LEFT)), C(A(KC_U)), C(A(KC_I)), C(A(KC_RIGHT)), XXXXXXX,  KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, C(A(KC_ENT)), C(A(KC_J)), C(A(KC_K)), C(A(KC_ENT)), XXXXXXX,     KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                            KC_MPLY,   KC_MUTE,
                                KC_LGUI,   FNR,    KC_SPC,                          KC_ENT,   _______,   KC_RALT,
                                                                    KC_UP,
                                                        KC_LEFT,    KC_DOWN,  KC_RGHT

  ),


// FNR
// ╭──────┬──────┬──────┬──────┬──────┬──────╮                   ╭──────┬──────┬──────┬──────┬──────┬──────╮
// │ ESC  │      │      │  €   │  £   │  Ğ   │                   │      │      │      │      │      │      │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │  !   │  @   │  Ş   │  ₺   │      │                   │      │      │      │      │      │      │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │      │      │  Ç   │      │      │                   │      │      │      │      │      │      │
// ╰──────┴──────┴──────┴──────┴──────┴──────┼─────────┬─────────┼──────┴──────┴──────┴──────┴──────┴──────╯
//                                           │  MPLY   │  MUTE   │
//                     ╭──────┬──────┬───────┼─────────┴─────────┼──────┬──────┬──────╮
//                     │  ALT │LOWER │       │                   │ FNR  │RAISE │  WIN │
//                     ╰──────┴──────┴───────┴─────┬──────┬──────┴──────┴──────┴──────╯
//                                                 │  UP  │
//                                          ╭──────┼──────┼──────╮
//                                          │ LEFT │ DOWN │ RIGHT│
//                                          ╰──────┴──────┴──────╯


  [_FNR] = LAYOUT_cockpit(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,                  RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,
                                                          KC_MPLY,   KC_MUTE,
                         XXXXXXX,   XXXXXXX,    XXXXXXX,                           XXXXXXX,   XXXXXXX,   XXXXXXX,
                                                                 KC_UP,
                                                    KC_LEFT,    KC_DOWN,  KC_RGHT
  ),


  [_ARROW] = LAYOUT_cockpit(
    _______,  _______,  _______,   _______,  _______,   _______,               KC_MPRV,   KC_PGUP,    KC_UP,      _______,     _______,    _______,
    _______,  _______,  _______,   _______,  _______,   _______,               KC_HOME,   KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_END,     KC_MPLY,
    _______,  _______,  _______,   _______,  _______,   _______,               KC_MNXT,   KC_PGDOWN,  _______,    KC_VOLD,     KC_VOLU,    KC_MUTE,
                                                              KC_MPLY,   KC_MUTE,
                             KC_LALT,   XXXXXXX,    XXXXXXX,                           XXXXXXX,   RAISE,   XXXXXXX,
                                                                     KC_UP,
                                                        KC_LEFT,    KC_DOWN,  KC_RGHT

  ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ARROW);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder: Right encoder */
        if(IS_LAYER_ON(_LOWER)){
          if (clockwise) {
            tap_code(KC_DOWN);
          } else {
              tap_code(KC_UP);
          }
        } else{
          if (clockwise) {
            tap_code(KC_RIGHT);
          } else {
              tap_code(KC_LEFT);
          }
        }

    } else if (index == 1) { /* Second encoder: Left encoder */
        if (IS_LAYER_ON(_LOWER)) {
              if (clockwise) {
                  tap_code(KC_MNXT);
              } else {
                  tap_code(KC_MPRV);
              }
        } else {
              if (clockwise) {
                  tap_code_delay(KC_VOLU, 10);
              } else {
                  tap_code_delay(KC_VOLD, 10);
              }
        }
    }
    return false;
}
