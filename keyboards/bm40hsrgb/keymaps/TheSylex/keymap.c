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

bool w_macro = false;
uint16_t spam_timer = false;
uint16_t spam_interval = 50; // (1000ms == 1s)

enum layers {
  _COLEMAK,
  _QWERTY,
  _NUMBER,
  _SYMBOL,
  _NAVIGATION,
  _FUNCTION,
  _CONFIGURATION
};

#define QWE TG(_QWERTY)

#define NUM MO(_NUMBER)
#define SYM MO(_SYMBOL)
#define NAV MO(_NAVIGATION)
#define FUN MO(_FUNCTION)
#define CON MO(_CONFIGURATION)

enum my_keycodes {
    KC_SPAM_U
};

enum {
    TD_F10_11_12,
    TD_ESC_TLD,
    TD_BSPC
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Esc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LGUI |  Alt | FUN  | SYM  |    Space    |  NUM | NAV  | RAlt | RGUI | RCtrl|
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_mit(
    KC_TAB,      KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    TD(TD_ESC_TLD),
    TD(TD_BSPC), KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,       KC_ENT,
    KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSFT,
    KC_LCTL,     KC_LGUI, KC_LALT, FUN,     SYM,        KC_SPC,        NUM,     NAV,     KC_RALT, KC_RGUI,    KC_RCTL
),

/* 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      |      |      |      |      |      |      |      |      |      | Esc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |      |      |      |      |      |      |      |      |      |      | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LGUI |  Alt |      |      |    Space    |      |      | RAlt | RGUI | RCtrl|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
    KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     TD(TD_ESC_TLD),
    KC_BSPC,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT,
    KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
    KC_LCTL,     KC_LGUI, KC_LALT, FUN,     SYM,        KC_SPC,        NUM,     NAV,     KC_RALT, KC_RGUI,  KC_RCTL
),

/* 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      |      |      |      |      |      |      |      |      |      | Esc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |      |      |      |      |      |      |      |      |      |      | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LGUI |  Alt |      |      |    Space    |      |      | RAlt | RGUI | RCtrl|
 * `-----------------------------------------------------------------------------------'
 */

[_NUMBER] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, CON,       _______,        XXXXXXX, _______, _______, _______, _______
),

/* 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      |      |      |      |      |      |      |      |      |      | Esc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |      |      |      |      |      |      |      |      |   ~  |   '  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LGUI |  Alt |      |      |    Space    |      |      | RAlt | RGUI | RCtrl|
 * `-----------------------------------------------------------------------------------'
 */

[_SYMBOL] = LAYOUT_planck_mit(
    _______, KC_LPRN, KC_LCBR, KC_LBRC, KC_LABK, _______, _______, KC_RABK, KC_RBRC, KC_RCBR, KC_RPRN, _______,
    _______, KC_UNDS, KC_AT,   KC_HASH, KC_DLR,  _______, _______, KC_AMPR, KC_TILD, KC_DQT,  KC_QUOT, _______,
    _______, KC_PLUS, KC_MINS, KC_ASTR, KC_CIRC,_______, _______,  KC_PERC, KC_PIPE, KC_EQL,  KC_EXLM, _______,
    _______, _______, _______, _______, XXXXXXX,     _______,      CON,     _______, _______, _______, _______
),

/* 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_NAVIGATION] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

/* 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_FUNCTION] = LAYOUT_planck_mit(
    _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, _______, _______, _______, KC_DEL,  KC_PSCR, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   TD(TD_F10_11_12),  _______,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, KC_SLEP, KC_PWR,  KC_RSFT,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

/* 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_CONFIGURATION] = LAYOUT_planck_mit(
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,
    DM_RSTP, DM_REC1, DM_PLY1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,
    NK_TOGG, DM_REC2, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_RMOD,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       QWE,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

/* 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/*
[_EMPTY] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
)
*/

void td_f10_11_12(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code(KC_F10);
            reset_tap_dance(state);
            break;
        case 2:
            tap_code(KC_F11);
            reset_tap_dance(state);
            break;
        case 3:
            tap_code(KC_F12);
            reset_tap_dance(state);
            break;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_F10_11_12] = ACTION_TAP_DANCE_FN(td_f10_11_12),
    [TD_ESC_TLD] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
    [TD_BSPC] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, LCTL(KC_BSPC))
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SPAM_U:
            if (record->event.pressed) {
                w_macro = true;
                spam_timer = timer_read();
            } else {
                w_macro = false;
            }
            return false;
            break;
        case KC_BSPC:
            if (get_mods() & MOD_MASK_SHIFT) {
                if (record->event.pressed) {
                    tap_code(KC_CAPS);
                }
                return false;
            }
            return true;
            break;
    }
    return true;
};

void matrix_scan_user(void){
    if (w_macro && timer_elapsed(spam_timer) >= spam_interval){
        tap_code_delay(KC_U, 50);
        spam_timer = timer_read();
    }
}

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}