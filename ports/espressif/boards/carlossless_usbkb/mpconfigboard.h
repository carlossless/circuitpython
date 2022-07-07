// Micropython setup

#define MICROPY_HW_BOARD_NAME       "carlossless usbkb"
#define MICROPY_HW_MCU_NAME         "ESP32S2"

#define CIRCUITPY_BOOT_BUTTON (&pin_GPIO0)

#define BOARD_USER_SAFE_MODE_ACTION translate("pressing boot button at start up.\n")

#define AUTORESET_DELAY_MS 500

#define DEFAULT_I2C_BUS_SCL (&pin_GPIO4)
#define DEFAULT_I2C_BUS_SDA (&pin_GPIO3)

#define DEFAULT_SPI_BUS_SCK (&pin_GPIO36)
#define DEFAULT_SPI_BUS_MOSI (&pin_GPIO35)
#define DEFAULT_SPI_BUS_MISO (&pin_GPIO37)
