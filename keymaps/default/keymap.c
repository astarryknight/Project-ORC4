#include QMK_KEYBOARD_H
bool encoder_flag=false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_7_3x10_5(
        KC_ESC, KC_F5, KC_F12, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_BSPC, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_TAB, KC_ENT, MO(1), KC_LCTL, KC_SPC, KC_RALT, KC_RGUI
    ),
    [1] = LAYOUT_ortho_7_3x10_5(
        KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_PIPE, KC_LBRC, KC_RBRC, KC_EQL, KC_PLUS, KC_SCLN, KC_COLN, KC_DEL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, QK_BOOT, KC_TRNS, KC_DQUO, KC_QUES, KC_SLSH, KC_LABK, KC_RABK, KC_COMM, KC_DOT, KC_TRNS, KC_TRNS, /*MO(_RAISE)*/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0]= {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1]= {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif

bool dip_switch_update_user(uint8_t index, bool active) 
{ 
 switch (index) {
        case 0:		//ENC0_SW
        if(active)         //ENC0 pressed
		{ 
			tap_code(KC_MUTE); //what the press should do in my case cycle through different modes for the encoder to operate
		}
	else //ENC0 released
                {
			//do nothing
		}
            break;
        }
    return true;
};

//credits to https://www.youtube.com/watch?v=GLqSPa_Zc2Q