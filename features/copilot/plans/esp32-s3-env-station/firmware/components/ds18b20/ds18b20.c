// ds18b20.c - stub: use existing 1-wire libs in production
#include "ds18b20.h"
#include "esp_log.h"

static const char *TAG = "ds18b20";
static gpio_num_t onewire_gpio = GPIO_NUM_4;

esp_err_t ds18b20_init(gpio_num_t gpio)
{
    onewire_gpio = gpio;
    ESP_LOGI(TAG, "DS18B20 init stub on gpio %d", gpio);
    return ESP_OK;
}

esp_err_t ds18b20_read(float *temperature)
{
    if (temperature) *temperature = 24.6f;
    return ESP_OK;
}
