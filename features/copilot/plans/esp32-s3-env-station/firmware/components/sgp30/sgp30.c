// sgp30.c - simplified SGP30 driver skeleton
#include "sgp30.h"
#include "driver/i2c.h"
#include "esp_log.h"

static const char *TAG = "sgp30";
static i2c_port_t sgp30_port = I2C_NUM_0;
static uint8_t sgp30_addr = 0x58;

esp_err_t sgp30_init(i2c_port_t port, int sda_gpio, int scl_gpio)
{
    sgp30_port = port;
    // Similar i2c init as bme280_init; leave as stub
    ESP_LOGI(TAG, "SGP30 init stub");
    return ESP_OK;
}

esp_err_t sgp30_read(uint16_t *tvoc_ppb, uint16_t *eco2_ppm)
{
    // Return stub values for demo
    if (tvoc_ppb) *tvoc_ppb = 120;
    if (eco2_ppm) *eco2_ppm = 450;
    return ESP_OK;
}
