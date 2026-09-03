// mqtt_wrapper.c - simplified MQTT wrapper using esp-mqtt

#include "mqtt_wrapper.h"
#include "esp_log.h"
#include "mqtt_client.h"

static const char *TAG = "mqtt_wrapper";
static esp_mqtt_client_handle_t mqtt_client = NULL;

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    esp_mqtt_event_handle_t event = event_data;
    switch (event->event_id) {
    case MQTT_EVENT_CONNECTED:
        ESP_LOGI(TAG, "MQTT connected");
        break;
    case MQTT_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "MQTT disconnected");
        break;
    case MQTT_EVENT_PUBLISHED:
        ESP_LOGI(TAG, "MQTT published, msg_id=%d", event->msg_id);
        break;
    default:
        break;
    }
}

esp_err_t mqtt_start(const char *uri, const char *username, const char *password)
{
    if (mqtt_client) return ESP_OK;
    esp_mqtt_client_config_t cfg = {
        .uri = uri,
        .username = username,
        .password = password,
        // For TLS, set .cert_pem to the CA or use system store in menuconfig
    };
    mqtt_client = esp_mqtt_client_init(&cfg);
    if (!mqtt_client) return ESP_FAIL;
    esp_mqtt_client_register_event(mqtt_client, ESP_EVENT_ANY_ID, mqtt_event_handler, mqtt_client);
    esp_mqtt_client_start(mqtt_client);
    return ESP_OK;
}

esp_err_t mqtt_publish(const char *topic, const char *payload)
{
    if (!mqtt_client) return ESP_FAIL;
    int msg_id = esp_mqtt_client_publish(mqtt_client, topic, payload, 0, 1, 0);
    ESP_LOGI(TAG, "sent publish successful, msg_id=%d", msg_id);
    return ESP_OK;
}
