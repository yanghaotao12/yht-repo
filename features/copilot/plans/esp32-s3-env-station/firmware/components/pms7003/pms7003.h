/*
 * PMS7003 driver skeleton (UART parsing)
 */

#ifndef PMS7003_H
#define PMS7003_H

#include "esp_err.h"

esp_err_t pms7003_init(uart_port_t port, int tx_gpio, int rx_gpio);
esp_err_t pms7003_read(uint16_t *pm1_0, uint16_t *pm2_5, uint16_t *pm10);

#endif // PMS7003_H
