#include "kb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
		KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, 
		KC_P7, KC_P8, KC_P9, 
		KC_P4, KC_P5, KC_P6, KC_PPLS, 
		KC_P1, KC_P2, KC_P3, 
		KC_P0, KC_PDOT, KC_PENT)

};

void led_set_user(uint8_t usb_led) {

	if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        writePinLow(D7);
    } else {
        writePinHigh(D7);
    }

}
