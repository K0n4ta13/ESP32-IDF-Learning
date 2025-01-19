#include <esp_err.h>
#include <esp_log.h>
#include <nvs_flash.h>

#define TAG "NVS"

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init_partition("custom_nvs"));

    nvs_handle_t nvs_handle;
    ESP_ERROR_CHECK(nvs_open_from_partition("custom_nvs", "store", NVS_READWRITE, &nvs_handle));

    nvs_stats_t nvs_stats;
    ESP_ERROR_CHECK(nvs_get_stats("custom_nvs", &nvs_stats));
    ESP_LOGI(TAG, "NVS stats: \n\t used: %d, \n\t free: %d \n\t available: %d \n\t total: %d \n\t namespaces: %d",
        nvs_stats.used_entries, nvs_stats.free_entries, nvs_stats.available_entries, nvs_stats.total_entries, nvs_stats.namespace_count);

    int32_t value = 0;
    ESP_ERROR_CHECK_WITHOUT_ABORT(nvs_get_i32(nvs_handle, "value", &value));

    ESP_LOGI(TAG, "value: %ld", value);

    value++;
    ESP_ERROR_CHECK(nvs_set_i32(nvs_handle, "value", value));
    ESP_ERROR_CHECK(nvs_commit(nvs_handle));

    nvs_close(nvs_handle);
}