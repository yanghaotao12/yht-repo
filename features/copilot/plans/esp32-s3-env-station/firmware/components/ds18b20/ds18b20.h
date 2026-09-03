/*
 * DS18B20 1-Wire driver skeleton
 */

#ifndef DS18B20_H
#define DS18B20_H

#include "esp_err.h"

esp_err_t ds18b20_init(gpio_num_t gpio);
esp_err_t ds18b20_read(float *temperature);

#endif // DS18B20_H
