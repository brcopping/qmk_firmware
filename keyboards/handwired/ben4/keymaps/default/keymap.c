#include "kb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(KC_NLCK, KC_P1, KC_P2, KC_P3)

};

void led_set_user(uint8_t usb_led) {

	if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        writePinLow(D5);
    } else {
        writePinHigh(D5);
    }

}
