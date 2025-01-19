#include <esp_err.h>
#include <esp_log.h>
#include <nvs_flash.h>
#include <stdio.h>

#define TAG "NVS"

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());

    nvs_handle_t nvs_handle;
    ESP_ERROR_CHECK(nvs_open("store", NVS_READWRITE, &nvs_handle));

    int32_t value = 0;
    ESP_ERROR_CHECK_WITHOUT_ABORT(nvs_get_i32(nvs_handle, "value", &value));

    ESP_LOGI(TAG, "value: %ld", value);

    value++;
    ESP_ERROR_CHECK(nvs_set_i32(nvs_handle, "value", value));
    ESP_ERROR_CHECK(nvs_commit(nvs_handle));

    nvs_close(nvs_handle);
}