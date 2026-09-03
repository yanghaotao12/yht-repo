/*
 * SGP30 driver skeleton (i2c)
 */

#ifndef SGP30_H
#define SGP30_H

#include "esp_err.h"

esp_err_t sgp30_init(i2c_port_t port, int sda_gpio, int scl_gpio);
esp_err_t sgp30_read(uint16_t *tvoc_ppb, uint16_t *eco2_ppm);

#endif // SGP30_H
