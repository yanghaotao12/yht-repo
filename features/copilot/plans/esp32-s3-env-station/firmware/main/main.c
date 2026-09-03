# Updated main.c - integrate additional sensors and modules

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_log.h"

#include "mqtt_wrapper.h"
#include "bme280.h"
#include "sgp30.h"
#include "pms7003.h"
#include "ds18b20.h"
#include "ota_wrapper.h"
#include "webui.h"

static const char *TAG = "env_main";

void app_main(void)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        nvs_flash_erase();
        nvs_flash_init();
    }

    // init network (simplified)
    esp_netif_init();
    esp_event_loop_create_default();

    // init sensors
    bme280_init(I2C_NUM_0, 21, 22);
    sgp30_init(I2C_NUM_0, 21, 22);
    pms7003_init(UART_NUM_1, 17, 16);
    ds18b20_init(GPIO_NUM_4);

    // start webui
    start_webserver();

    // start mqtt (demo URI - set via menuconfig or NVS)
    mqtt_start("mqtts://broker.example.com:8883", "demo_user", "demo_pass");

    // sensor task
    xTaskCreate([](void *pv) {
        while (1) {
            float temp, hum, pres, water_temp;
            uint16_t tvoc, eco2;
            uint16_t pm1, pm25, pm10;
            bme280_read(&temp, &hum, &pres);
            sgp30_read(&tvoc, &eco2);
            pms7003_read(&pm1, &pm25, &pm10);
            ds18b20_read(&water_temp);

            char payload[512];
            snprintf(payload, sizeof(payload),
             "{\"ts\":%lld,\"temp\":%.2f,\"hum\":%.2f,\"pres\":%.2f,\"tvoc\":%u,\"eco2\":%u,\"pm2_5\":%u,\"water_temp\":%.2f}",
             esp_timer_get_time()/1000, temp, hum, pres, tvoc, eco2, pm25, water_temp);
            mqtt_publish("device/DEV001/telemetry", payload);
            vTaskDelay(pdMS_TO_TICKS(10000));
        }
    }, "sensor_task", 8192, NULL, 5, NULL);
}
