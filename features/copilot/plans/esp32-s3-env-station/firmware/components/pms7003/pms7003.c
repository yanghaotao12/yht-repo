// pms7003.c - simplified UART parse stub for PMS7003
#include "pms7003.h"
#include "driver/uart.h"
#include "esp_log.h"

static const char *TAG = "pms7003";
static uart_port_t pms_uart = UART_NUM_1;

esp_err_t pms7003_init(uart_port_t port, int tx_gpio, int rx_gpio)
{
    pms_uart = port;
    uart_config_t uart_config = {
        .baud_rate = 9600,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_param_config(pms_uart, &uart_config);
    uart_set_pin(pms_uart, tx_gpio, rx_gpio, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(pms_uart, 1024 * 2, 0, 0, NULL, 0);
    ESP_LOGI(TAG, "PMS7003 UART init stub");
    return ESP_OK;
}

esp_err_t pms7003_read(uint16_t *pm1_0, uint16_t *pm2_5, uint16_t *pm10)
{
    // Stub: return demo values
    if (pm1_0) *pm1_0 = 5;
    if (pm2_5) *pm2_5 = 12;
    if (pm10) *pm10 = 20;
    return ESP_OK;
}
