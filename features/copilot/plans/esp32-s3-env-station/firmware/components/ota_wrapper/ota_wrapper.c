/*
 * ota_wrapper.c - ESP-IDF OTA example using esp_https_ota
 */

#include "ota_wrapper.h"
#include "esp_log.h"
#include "esp_https_ota.h"

static const char *TAG = "ota_wrapper";

esp_err_t ota_start(const char *url)
{
    esp_http_client_config_t config = {
        .url = url,
        .cert_pem = NULL, // use CA from menuconfig or partition
    };
    esp_err_t ret = esp_https_ota(&config);
    if (ret == ESP_OK) {
        ESP_LOGI(TAG, "OTA success, restarting...");
        esp_restart();
    } else {
        ESP_LOGE(TAG, "OTA failed: %d", ret);
    }
    return ret;
}
