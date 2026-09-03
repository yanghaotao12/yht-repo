# firmware/main/main.c - improved skeleton with Wi-Fi and MQTT initialization

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_wifi.h"

#include "mqtt_wrapper.h"
#include "bme280.h"

static const char *TAG = "env_main";

void wifi_init_sta(void)
{
    // Basic Wi-Fi station init using default config - replace with proper event handlers & provisioning
    esp_netif_init();
    esp_event_loop_create_default();
    esp_netif_create_default_wifi_sta();
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);
    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_start();
    ESP_LOGI(TAG, "wifi started (no provisioning in skeleton)");
}

void sensors_task(void *pv)
{
    float t,h,p;
    while (1) {
        bme280_read(&t,&h,&p);
        char payload[256];
        snprintf(payload, sizeof(payload), "{\"ts\":%lld,\"temp\":%.2f,\"hum\":%.2f,\"pres\":%.2f}", esp_timer_get_time()/1000, t, h, p);
        mqtt_publish("device/DEV001/telemetry", payload);
        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}

void app_main(void)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        nvs_flash_erase();
        nvs_flash_init();
    }

    wifi_init_sta();

    // init sensors
    bme280_init(I2C_NUM_0, 21, 22);

    // start mqtt (replace URI and creds via menuconfig or NVS)
    mqtt_start("mqtts://broker.example.com:8883", "demo_user", "demo_pass");

    xTaskCreate(&sensors_task, "sensors", 4096, NULL, 5, NULL);
}
