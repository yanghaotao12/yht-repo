// mqtt_wrapper.h - simple wrapper declarations
#ifndef MQTT_WRAPPER_H
#define MQTT_WRAPPER_H

#include "esp_err.h"

esp_err_t mqtt_start(const char *uri, const char *username, const char *password);
esp_err_t mqtt_publish(const char *topic, const char *payload);

#endif // MQTT_WRAPPER_H
