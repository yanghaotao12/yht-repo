# ota_wrapper.h

#ifndef OTA_WRAPPER_H
#define OTA_WRAPPER_H

#include "esp_err.h"

esp_err_t ota_start(const char *url);

#endif // OTA_WRAPPER_H
