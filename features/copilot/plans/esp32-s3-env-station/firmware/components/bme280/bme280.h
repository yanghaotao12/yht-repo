/*
 * Simple BME280 driver skeleton for ESP-IDF
 * files: bme280.h / bme280.c
 */

#ifndef BME280_H
#define BME280_H

#include "esp_err.h"

esp_err_t bme280_init(i2c_port_t port, int sda_gpio, int scl_gpio);
esp_err_t bme280_read(float *temperature, float *humidity, float *pressure);

#endif // BME280_H
