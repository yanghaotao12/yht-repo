// webui.c - simple HTTP server for device status and config

#include "esp_http_server.h"
#include "esp_log.h"

static const char *TAG = "webui";

static esp_err_t status_get_handler(httpd_req_t *req)
{
    const char *resp = "{\"status\":\"ok\"}";
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, resp, strlen(resp));
    return ESP_OK;
}

httpd_handle_t start_webserver(void)
{
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    httpd_handle_t server = NULL;
    if (httpd_start(&server, &config) == ESP_OK) {
        httpd_uri_t status_uri = {
            .uri = "/status",
            .method = HTTP_GET,
            .handler = status_get_handler,
            .user_ctx = NULL
        };
        httpd_register_uri_handler(server, &status_uri);
    }
    ESP_LOGI(TAG, "webui started");
    return server;
}
