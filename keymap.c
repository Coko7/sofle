 /* Copyright 2021 Dane Evans
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
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
	{1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_NUMPAD(hsv)     \
	{35+15, 5, hsv},\
	  {35+22, 3, hsv},\
	  {35+27, 3, hsv}
#define SET_NUMROW(hsv) \
	{10, 2, hsv}, \
		{20, 2, hsv}, \
		{30, 2, hsv}, \
	  {35+ 10, 2, hsv}, \
	  {35+ 20, 2, hsv}, \
	  {35+ 30, 2, hsv}
#define SET_INNER_COL(hsv)	\
	{33, 4, hsv}, \
	  {35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
	{7, 4, hsv}, \
	  {35+ 7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
	{25, 2, hsv}, \
	  {35+ 25, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
		{1, 6, hsv}, \
    {35+1, 6, hsv}, \
		{7, 4, hsv}, \
	  {35+ 7, 4, hsv}, \
		{25, 2, hsv}, \
	  {35+ 25, 2, hsv}

enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    // _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD,
    _SWITCH
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    // KC_COLEMAK,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_D_MUTE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,     XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                    KC_LGUI, KC_LALT, KC_LCTL, MO(1), KC_ENT,      KC_SPC,  MO(2),   KC_RCTL, KC_RALT, KC_RGUI
),

/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
// [_COLEMAK] = LAYOUT(
//   KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
//   KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                              KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_BSPC,
//   KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                              KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_QUOT,
//   KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,         XXXXXXX, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
//                     KC_LGUI, KC_LALT, KC_LCTL, TL_LOWR, KC_ENT,          KC_SPC,  TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
// ),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |ADJST | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                    _______, _______, _______, _______, _______,       _______, MO(3),   _______, _______, _______
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    | CLeft|      |      |CRight| DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------| Left | Down |  Up  | Right|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------| Home | PGdn | PGup | End  |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |ADJST | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______,    _______, _______, _______,    _______,    _______,
  _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                         C(KC_LEFT), XXXXXXX, XXXXXXX, C(KC_RGHT), C(KC_BSPC), KC_BSPC,
  _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                         KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT,    KC_DEL,     KC_BSPC,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, _______,       _______, KC_HOME,    KC_PGDN, KC_PGUP, KC_END,     XXXXXXX,    _______,
                    _______, _______, _______, MO(3),   _______,       _______, _______,    _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    | RGB P| RGB B| RGB R|RGB SW|RGB SN| RGB K|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QKBOOT|      |      |      | CGTOG|      |                    |      | RGBM-| RGBTg| RGBM+|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ROMCLR|      | CGTOG|      |      |      |-------.    ,-------|      | VOL- | MUTE | VOL+ |      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         RGB_M_P, RGB_M_B,  RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K,
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, CG_TOGG, XXXXXXX,                         XXXXXXX, RGB_RMOD, RGB_TOG, RGB_MOD,  XXXXXXX,  XXXXXXX,
  EE_CLR,  XXXXXXX, CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, KC_VOLD,  KC_MUTE, KC_VOLU,  XXXXXXX,  XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, KC_MPRV,  KC_MPLY, KC_MNXT,  XXXXXXX,  XXXXXXX,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
) };

#ifdef RGBLIGHT_ENABLE

char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_RED)

);
const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PINK)
);

// _NUM,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_TEAL)

);
// _SYMBOL,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_BLUE)

    );
// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PURPLE)
);

//_NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_INDICATORS(HSV_ORANGE),
    SET_UNDERGLOW(HSV_ORANGE),
	SET_NUMPAD(HSV_BLUE),
    {7, 4, HSV_ORANGE},
    {25, 2, HSV_ORANGE},
    {35+6, 4, HSV_ORANGE},
    {35+25, 2, HSV_ORANGE}
    );

// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_GREEN),
	SET_NUMROW(HSV_GREEN)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
	layer_num_lights,// overrides layer 1
	layer_symbol_lights,
    layer_command_lights,
	layer_numpad_lights,
	layer_switcher_lights  // Overrides other layers
	// layer_colemakdh_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));
	rgblight_set_layer_state(7, layer_state_cmp(state, _DEFAULTS));// && layer_state_cmp(default_layer_state,_COLEMAKDH));


	rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
	// rgblight_set_layer_state(4, layer_state_cmp(state, _NUMPAD));
	// rgblight_set_layer_state(5, layer_state_cmp(state, _SWITCH));
    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

	rgblight_mode(10); // haven't found a way to set this in a more useful way
}

#endif

#ifdef OLED_ENABLE

 static void render_logo(void) {
     static const char PROGMEM qmk_logo[] = {
         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
     };

     oled_write_P(qmk_logo, false);

     // static const char PROGMEM raw_logo[] = {
     //     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,224,240,240,248,248,248,248,248,248,248,248,248,248,248,248,240,224,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,224,224,224,224,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     //     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,255,255,255,127,127, 63, 63, 63, 63, 63, 63,255,255,255,255,255,255,255,254,  0,  0,  0,  0,  0,  0,  0,  0,  0,240,252,254, 14,  7,  7,  3,131,131,135,135,135,134,  0,  0,  0,112,112, 48, 48, 48,112,240,224,128,  0,  0,  0,243,243,  0,  0,  0,  0,240,240, 96,112, 48,112,240,224,192, 96,112, 48,112,240,240,192,  2,  2,198,230,246,118, 54, 54,118,246,230,198,  2,  2,  0,240,240, 96,112, 48, 48,112,243,227,  1,  0, 12, 78,102, 32, 32,  0,  0,  0,  0,
     //     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  7, 15,159,223,207, 24,254,249,233,207,207,207,233,249,255, 57,131,223,143,  7,  3,  0,  0,  0,  0,  0, 96,252,184, 16,128,135, 31, 63, 56,112,112, 96, 97, 97,113,113, 63, 63,  0,  0, 62,126,119,103, 99, 99, 99,115,127, 63,  0,  0,  0,127,127,  0,  0,  0,  0,127,127,  0,  0,  0,  0,  0,127,127,  0,  0,  0,  0,  0,127,127,  0,  0, 31, 63,120,112, 98, 98,112,120, 63, 31,  0,  0,  0,127,127,  0,  0,  0,  0,  0,127,127,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     //     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0, 19, 31, 31, 31, 15, 15, 31, 31, 31, 23,  0,  0,  1,  1,  0,  0,  0,  0,  0,  0,  0, 24, 28, 15,  5,  7, 13, 24, 28, 14, 12,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     // };
     // oled_write_raw_P(raw_logo, sizeof(raw_logo));
 }

 static void print_status_narrow(void) {
     // Print current mode
     oled_write_P(PSTR("\n\n"), false);

     oled_write_ln_P(PSTR("coko7"), false);
     oled_write_ln_P(PSTR("-----"), false);

     oled_write_ln_P(PSTR(""), false);

     //snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)

     switch (get_highest_layer(default_layer_state)) {
         case _QWERTY:
             oled_write_ln_P(PSTR("Qwrt"), false);
             break;
         case _COLEMAK:
             oled_write_ln_P(PSTR("Clmk"), false);
             break;
         // case _COLEMAKDH:
         //     oled_write_ln_P(PSTR("CmkDH"), false);
         //     break;

         default:
             oled_write_ln_P(PSTR("Undef"), false);
     }

     oled_write_P(PSTR("\n\n"), false);
     // Print current layer
     oled_write_ln_P(PSTR("LAYER"), false);

     switch (get_highest_layer(layer_state)) {
         // case _COLEMAK:
         case _QWERTY:
             // case _COLEMAKDH:
             oled_write_P(PSTR("Base\n"), false);
             break;
         case _RAISE:
             oled_write_P(PSTR("Raise"), false);
             break;
         case _LOWER:
             oled_write_P(PSTR("Lower"), false);
             break;
         case _ADJUST:
             oled_write_P(PSTR("Adj\n"), false);
             break;
         // case _NUMPAD:
         //     oled_write_P(PSTR("Nump\n"), false);
         //     break;
         // case _SWITCH:
         //     oled_write_P(PSTR("Swit\n"), false);
         //     break;
         default:
             oled_write_ln_P(PSTR("Undef"), false);
     }
 }

 // QMK function
 oled_rotation_t oled_init_user(oled_rotation_t rotation) {
     // if (is_keyboard_master()) {
     //     return OLED_ROTATION_270;
     // }
     // if (!is_keyboard_master()) {
     //     return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
     // }

     return rotation;
 }


 // QMK function
 bool oled_task_user(void) {
     if (is_keyboard_master()) {
         print_status_narrow();
     } else {
         render_logo();
     }
     return false;
 }

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     switch (keycode) {
         case KC_QWERTY:
             if (record->event.pressed) {
                 set_single_persistent_default_layer(_QWERTY);
             }
             return false;
         // case KC_COLEMAK:
         //     if (record->event.pressed) {
         //         set_single_persistent_default_layer(_COLEMAK);
         //     }
         //     return false;
         // case KC_COLEMAKDH:
         //     if (record->event.pressed) {
         //         set_single_persistent_default_layer(_COLEMAKDH);
         //     }
         //     return false;
         case KC_LOWER:
             if (record->event.pressed) {
                 layer_on(_LOWER);
                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
             } else {
                 layer_off(_LOWER);
                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
             }
             return false;
         case KC_RAISE:
             if (record->event.pressed) {
                 layer_on(_RAISE);
                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
             } else {
                 layer_off(_RAISE);
                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
             }
             return false;
         case KC_ADJUST:
             if (record->event.pressed) {
                 layer_on(_ADJUST);
             } else {
                 layer_off(_ADJUST);
             }
             return false;
         case KC_D_MUTE:
             if (record->event.pressed) {
                 register_mods(mod_config(MOD_MEH));
                 register_code(KC_UP);
             } else {
                 unregister_mods(mod_config(MOD_MEH));
                 unregister_code(KC_UP);
             }
     }
     return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
     if (index == 0) {
         if (clockwise) {
             tap_code(KC_VOLU);
         } else {
             tap_code(KC_VOLD);
         }
     } else if (index == 1) {
         // switch (get_highest_layer(layer_state)) {
         //     case _COLEMAK:
         //     case _QWERTY:
         //         // case _COLEMAKDH:
         //         if (clockwise) {
         //             tap_code(KC_PGDN);
         //         } else {
         //             tap_code(KC_PGUP);
         //         }
         //     break;
         //     case _RAISE:
         //     case _LOWER:
         //         if (clockwise) {
         //             tap_code(KC_DOWN);
         //         } else {
         //             tap_code(KC_UP);
         //         }
         //     break;
         //     default:
         //         if (clockwise) {
         //             tap_code(KC_WH_D);
         //         } else {
         //             tap_code(KC_WH_U);
         //         }
         //     break;
         // }
     }
     return true;
}

#endif
