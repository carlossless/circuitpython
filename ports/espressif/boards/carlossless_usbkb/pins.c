// This file is part of the CircuitPython project: https://circuitpython.org
//
// SPDX-License-Identifier: MIT

#include "shared-bindings/board/__init__.h"

#include "shared-module/displayio/__init__.h"

static const mp_rom_map_elem_t board_global_dict_table[] = {
    CIRCUITPYTHON_BOARD_DICT_STANDARD_ITEMS

    {MP_ROM_QSTR(MP_QSTR_D0), MP_ROM_PTR(&pin_GPIO0)},

    {MP_ROM_QSTR(MP_QSTR_D3), MP_ROM_PTR(&pin_GPIO3)},
    {MP_ROM_QSTR(MP_QSTR_SDA), MP_ROM_PTR(&pin_GPIO3)},

    {MP_ROM_QSTR(MP_QSTR_D4), MP_ROM_PTR(&pin_GPIO4)},
    {MP_ROM_QSTR(MP_QSTR_SCL), MP_ROM_PTR(&pin_GPIO4)},

    {MP_ROM_QSTR(MP_QSTR_D5), MP_ROM_PTR(&pin_GPIO5)},
    {MP_ROM_QSTR(MP_QSTR_D6), MP_ROM_PTR(&pin_GPIO6)},
    {MP_ROM_QSTR(MP_QSTR_D7), MP_ROM_PTR(&pin_GPIO7)},

    {MP_ROM_QSTR(MP_QSTR_D8), MP_ROM_PTR(&pin_GPIO8)},
    {MP_ROM_QSTR(MP_QSTR_A5), MP_ROM_PTR(&pin_GPIO8)},

    {MP_ROM_QSTR(MP_QSTR_D9), MP_ROM_PTR(&pin_GPIO9)},
    {MP_ROM_QSTR(MP_QSTR_D10), MP_ROM_PTR(&pin_GPIO10)},
    {MP_ROM_QSTR(MP_QSTR_D11), MP_ROM_PTR(&pin_GPIO11)},
    {MP_ROM_QSTR(MP_QSTR_D12), MP_ROM_PTR(&pin_GPIO12)},

    {MP_ROM_QSTR(MP_QSTR_LED), MP_ROM_PTR(&pin_GPIO13)},
    {MP_ROM_QSTR(MP_QSTR_D13), MP_ROM_PTR(&pin_GPIO13)},
    {MP_ROM_QSTR(MP_QSTR_L), MP_ROM_PTR(&pin_GPIO13)},

    {MP_ROM_QSTR(MP_QSTR_D14), MP_ROM_PTR(&pin_GPIO14)},
    {MP_ROM_QSTR(MP_QSTR_A4), MP_ROM_PTR(&pin_GPIO14)},

    {MP_ROM_QSTR(MP_QSTR_D15), MP_ROM_PTR(&pin_GPIO15)},
    {MP_ROM_QSTR(MP_QSTR_A3), MP_ROM_PTR(&pin_GPIO15)},

    {MP_ROM_QSTR(MP_QSTR_D16), MP_ROM_PTR(&pin_GPIO16)},
    {MP_ROM_QSTR(MP_QSTR_A2), MP_ROM_PTR(&pin_GPIO16)},

    {MP_ROM_QSTR(MP_QSTR_D17), MP_ROM_PTR(&pin_GPIO17)},
    {MP_ROM_QSTR(MP_QSTR_A1), MP_ROM_PTR(&pin_GPIO17)},

    {MP_ROM_QSTR(MP_QSTR_D18), MP_ROM_PTR(&pin_GPIO18)},
    {MP_ROM_QSTR(MP_QSTR_A0), MP_ROM_PTR(&pin_GPIO18)},

    {MP_ROM_QSTR(MP_QSTR_NEOPIXEL_POWER), MP_ROM_PTR(&pin_GPIO21)},
    {MP_ROM_QSTR(MP_QSTR_NEOPIXEL), MP_ROM_PTR(&pin_GPIO33)},

    {MP_ROM_QSTR(MP_QSTR_D35), MP_ROM_PTR(&pin_GPIO35)},
    {MP_ROM_QSTR(MP_QSTR_MOSI), MP_ROM_PTR(&pin_GPIO35)},

    {MP_ROM_QSTR(MP_QSTR_D36), MP_ROM_PTR(&pin_GPIO36)},
    {MP_ROM_QSTR(MP_QSTR_SCK), MP_ROM_PTR(&pin_GPIO36)},

    {MP_ROM_QSTR(MP_QSTR_D37), MP_ROM_PTR(&pin_GPIO37)},
    {MP_ROM_QSTR(MP_QSTR_MISO), MP_ROM_PTR(&pin_GPIO37)},

    {MP_ROM_QSTR(MP_QSTR_D38), MP_ROM_PTR(&pin_GPIO38)},
    {MP_ROM_QSTR(MP_QSTR_RX), MP_ROM_PTR(&pin_GPIO38)},

    {MP_ROM_QSTR(MP_QSTR_D39), MP_ROM_PTR(&pin_GPIO39)},
    {MP_ROM_QSTR(MP_QSTR_TX), MP_ROM_PTR(&pin_GPIO39)},

    {MP_ROM_QSTR(MP_QSTR_I2C), MP_ROM_PTR(&board_i2c_obj)},
    {MP_ROM_QSTR(MP_QSTR_SPI), MP_ROM_PTR(&board_spi_obj)},

    { MP_ROM_QSTR(MP_QSTR_DISPLAY), MP_ROM_PTR(&displays[0].display)}
};
MP_DEFINE_CONST_DICT(board_module_globals, board_global_dict_table);
