// bme280.c - simplified driver skeleton (uses esp-idf i2c functions)
#include "bme280.h"
#include "driver/i2c.h"
#include "esp_log.h"

static const char *TAG = "bme280";
static i2c_port_t i2c_port = I2C_NUM_0;
static uint8_t i2c_addr = 0x76; // default

esp_err_t bme280_init(i2c_port_t port, int sda_gpio, int scl_gpio)
{
    i2c_port = port;
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = sda_gpio,
        .scl_io_num = scl_gpio,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = 100000,
    };
    esp_err_t ret = i2c_param_config(i2c_port, &conf);
    if (ret != ESP_OK) return ret;
    return i2c_driver_install(i2c_port, conf.mode, 0, 0, 0);
}

esp_err_t bme280_read(float *temperature, float *humidity, float *pressure)
{
    // NOTE: This is a skeleton. Replace with actual BME280 register sequence or use existing library.
    // For demo, return fixed values and log a warning.
    ESP_LOGW(TAG, "bme280_read: using stub values - replace with real sensor code");
    if (temperature) *temperature = 25.3f;
    if (humidity) *humidity = 48.1f;
    if (pressure) *pressure = 1013.25f;
    return ESP_OK;
}
