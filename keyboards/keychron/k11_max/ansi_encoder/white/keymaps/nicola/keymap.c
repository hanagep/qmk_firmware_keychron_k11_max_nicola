/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"
#include <keymap_japanese.h>
#include "users/nicola/nicola.h"
#include "us_emulation.h"

enum layers{
    MAC_BASE,
    WIN_BASE,
    _NICOLA,
    FN1,
};

enum custom_keycodes {
    KC_KANA  = NEW_SAFE_RANGE,
    KC_EISU,
    KC_WIN_SHFT_LEFT,
    KC_TEAM_MUTE,
    TG_JP,
    EISU_FN1,
    KANA_FN1,
    KC_MDN_PRV
};

bool us_emu_enabled = false;

// --- Tap Dance Implementation ---
void fn_ime_finished (tap_dance_state_t *state, void *user_data);
void fn_ime_reset (tap_dance_state_t *state, void *user_data);

enum {
  TD_FN_IME,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_FN_IME] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fn_ime_finished, fn_ime_reset)
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_69_ansi(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,     KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,             KC_BSPC, KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_WIN_SHFT_LEFT,
        KC_LCTL, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,  KC_DEL,
        KC_LSFT, KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,     KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT,  KC_UP,
        KC_ESC,  KC_LOPTN, KC_LCMMD,          KC_SPC,  EISU_FN1, KANA_FN1, KC_SPC,           KC_TEAM_MUTE,                         KC_LEFT,  KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_69_ansi(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,     KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,             KC_BSPC, KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_WIN_SHFT_LEFT,
        KC_LCTL, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,  KC_DEL,
        KC_LSFT, KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,     KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT,  KC_UP,
        KC_ESC,  KC_LWIN,  KC_LALT,           KC_SPC,  EISU_FN1, KANA_FN1, KC_SPC,           KC_TEAM_MUTE,                         KC_LEFT,  KC_DOWN, KC_RGHT),

    [_NICOLA] = LAYOUT_69_ansi(
        KC_GRV,  NG_1,     NG_2,     NG_3,    NG_4,    NG_5,     NG_Q,     NG_W,    NG_E,    NG_R,    NG_T,    KC_MINS,  KC_EQL,             KC_BSPC, KC_MUTE,
        KC_TAB,  NG_Q,     NG_W,     NG_E,    NG_R,    NG_T,               NG_Y,    NG_U,    NG_I,    NG_O,    NG_P,     NG_LBRC,  NG_RBRC,  KC_BSLS, KC_WIN_SHFT_LEFT,
        KC_TRNS, NG_A,     NG_S,     NG_D,    NG_F,    NG_G,               NG_H,    NG_J,    NG_K,    NG_L,    NG_SCLN,  NG_QUOT,            KC_ENT,  KC_DEL,
        KC_LSFT, NG_Z,     NG_X,     NG_C,    NG_V,    NG_B,     NG_B,     NG_N,    NG_M,    NG_COMM, NG_DOT,  NG_SLSH,            NG_SHFTR, KC_UP,
        KC_ESC,  KC_TRNS,  KC_TRNS,           NG_SHFTL,EISU_FN1, KANA_FN1, NG_SHFTR,         KC_TEAM_MUTE,                         KC_LEFT,  KC_DOWN, KC_RGHT),

    [FN1] = LAYOUT_69_ansi(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,            _______, BL_TOGG,
        KC_KANA, _______,  KC_HOME,  KC_UP,   KC_END,  _______,            _______, _______, _______, _______,  _______,  KC_PSCR,  _______, _______, _______,
        KC_CAPS, LALT(KC_GRV), KC_LEFT, KC_DOWN, KC_RGHT, _______,         KC_VOLU, KC_INS,  KC_HOME, KC_PGUP,  KC_BSPC,  _______,  _______,          _______,
        _______, _______,  BT_HST1, BT_HST2, BT_HST3, BAT_LVL, KC_MDN_PRV, KC_VOLD, KC_DEL,  KC_END,  KC_PGDN,  _______,            _______, BL_UP,
        TG_JP, _______,  _______,             _______, _______,  _______,  _______,          _______,                               BL_TOGG, BL_DOWN, BL_STEP)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [_NICOLA]  = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [FN1]      = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif // ENCODER_MAP_ENABLE
// clang-format on

void matrix_init_user(void) {
    set_nicola(_NICOLA);
}

void keyboard_post_init_user(void) {
    us_emu_enabled = false;
    nicola_off();
}

static uint16_t eisu_fn1_timer;
static uint16_t kana_fn1_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    if (record->event.pressed) {
        switch (keycode) {
            case EISU_FN1:
                eisu_fn1_timer = timer_read();
                layer_on(FN1);
                return false;
            case KANA_FN1:
                kana_fn1_timer = timer_read();
                layer_on(FN1);
                return false;
            case KC_WIN_SHFT_LEFT:
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                wait_ms(100);
                tap_code(KC_LEFT);
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
                return false;
            case KC_TEAM_MUTE:
                register_code(KC_LGUI);
                register_code(KC_LALT);
                wait_ms(100);
                tap_code(KC_K);
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
                return false;
            case KC_MDN_PRV:
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                wait_ms(100);
                tap_code(KC_V);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
                return false;
            case TG_JP:
                us_emu_enabled = !us_emu_enabled;
                return false;
            case KC_KANA:
                if (nicola_state()) {
                    layer_off(_NICOLA);
                    nicola_off();
                    tap_code(KC_LNG2); // IME OFF
                } else {
                    layer_on(_NICOLA);
                    nicola_on();
                    tap_code(KC_LNG1); // IME ON
                }
                return false;
            case KC_EISU:
                layer_off(_NICOLA);
                nicola_off();
                tap_code(KC_LNG2);
                return false;
        }
    } else {
        switch (keycode) {
            case EISU_FN1:
                layer_off(FN1);
                if (timer_elapsed(eisu_fn1_timer) < TAPPING_TERM) {
                    layer_off(_NICOLA);
                    nicola_off();
                    tap_code(KC_LNG2);
                }
                return false;
            case KANA_FN1:
                layer_off(FN1);
                if (timer_elapsed(kana_fn1_timer) < TAPPING_TERM) {
                    /*
                    if (nicola_state()) {
                        layer_off(_NICOLA);
                        nicola_off();
                        tap_code(KC_LNG2); // IME OFF
                    
                    } else {
                    */
                        layer_on(_NICOLA);
                        nicola_on();
                        tap_code(KC_LNG1); // IME ON
                    //}
                }
                return false;
        }
    }

    if (us_emu_enabled && (get_highest_layer(layer_state) == MAC_BASE || get_highest_layer(layer_state) == WIN_BASE)) {
        if (!process_us_emulation(keycode, record)) {
            return false;
        }
    }

    if (key_process_guard) {
        return true;
    }

    nicola_mode(keycode, record);
    if (nicola_state()) {
        if (!process_nicola(keycode, record)) {
            return false;
        }
    }

    return true;
}

// Keep Tap Dance code for compilation but it is no longer used in keymap layers
void fn_ime_finished (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->pressed) {
            layer_on(FN1);
        } else {
            layer_off(_NICOLA);
            nicola_off();
            tap_code(KC_LNG2);
        }
    } else if (state->count == 2) {
        layer_on(_NICOLA);
        nicola_on();
        tap_code(KC_LNG1);
    }
}

void fn_ime_reset (tap_dance_state_t *state, void *user_data) {
    layer_off(FN1);
}
