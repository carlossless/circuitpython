#include "supervisor/board.h"
#include "mpconfigboard.h"
#include "shared-bindings/busio/I2C.h"
#include "shared-bindings/displayio/I2CDisplay.h"
#include "shared-bindings/microcontroller/Pin.h"
#include "shared-module/displayio/__init__.h"

#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 32

displayio_fourwire_obj_t board_display_obj;

// Sequence from page 19 here: https://cdn-shop.adafruit.com/datasheets/UG-2864HSWEG01+user+guide.pdf
uint8_t display_init_sequence[] = {
    0xAE, 0x00,        // DISPLAY_OFF
    0x20, 0x01, 0x10,  // set memory addressing to page mode.
    0x81, 0x01, 0xcf,  // set contrast control
    0xA1, 0x00,        // column 127 is segment 0
    0xA6, 0x00,        // normal display
    0xc8, 0x00,        // normal display
    0xA8, 0x01, DISPLAY_HEIGHT - 1,  // mux ratio is 1/64
    0xd5, 0x01, 0x80,  // set divide ratio
    0xd9, 0x01, 0xf1,  // set pre-charge period
    0xda, 0x01, 0x12,  // set com configuration
    0xdb, 0x01, 0x30,  // set vcom configuration
    0x8d, 0x01, 0x14,  // enable charge pump
    0xAF, 0x00         // DISPLAY_ON
};

void board_init(void) {
    // USB
    common_hal_never_reset_pin(&pin_GPIO19);
    common_hal_never_reset_pin(&pin_GPIO20);

    // display
    busio_i2c_obj_t *i2c = &displays[0].i2cdisplay_bus.inline_bus;
    common_hal_busio_i2c_construct(
        i2c,
        &pin_GPIO7,  // SCL
        &pin_GPIO8,  // SDA
        100000,      // frequency
        255          // timeout
    );

    displayio_i2cdisplay_obj_t *bus = &displays[0].i2cdisplay_bus;
    bus->base.type = &displayio_i2cdisplay_type;

    common_hal_displayio_i2cdisplay_construct(
        bus,
        i2c,
        0x3C,
        NULL
    );

    displayio_display_obj_t *display = &displays[0].display;
    display->base.type = &displayio_display_type;

    common_hal_displayio_display_construct(
        display,
        bus,
        DISPLAY_WIDTH,  // width (after rotation)
        DISPLAY_HEIGHT, // height (after rotation)
        0,              // column start
        0,              // row start
        0,              // rotation
        1,              // color depth
        true,           // grayscale
        false,          // pixels in a byte share a row. Only valid for depths < 8
        1,              // bytes per cell. Only valid for depths < 8
        false,          // reverse_pixels_in_byte. Only valid for depths < 8
        true,           // reverse_pixels_in_word
        0x21,           // set column command
        0x22,           // set row command
        0x2c,           // write memory command
        display_init_sequence,
        sizeof(display_init_sequence),
        NULL,           // backlight pin
        0x81,           // brightness command
        1.0f,           // brightness
        false,          // auto_brightness
        true,           // single_byte_bounds
        true,           // data_as_commands
        true,           // auto_refresh
        60,             // native_frames_per_second
        true,           // backlight_on_high
        true            // SH1107_addressing
    );
}

bool board_requests_safe_mode(void) {
    return false;
}

void reset_board(void) {

}

void board_deinit(void) {
}
