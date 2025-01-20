#include <esp_log.h>
#include <esp_spiffs.h>
#include <esp_task_wdt.h>
#include <stdio.h>
#include <string.h>

#define TAG "spiffs"

void app_main(void)
{
    const esp_vfs_spiffs_conf_t conf = {
        .base_path = "/spiffs",
        .partition_label = NULL,
        .max_files = 5,
        .format_if_mount_failed = true
    };

    ESP_ERROR_CHECK(esp_vfs_spiffs_register(&conf));

    FILE *file = fopen("/spiffs/books/alices_in_wonderland.txt", "r");

    if (file == NULL) {
        ESP_LOGE(TAG, "could not open file");
    } else {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf(line);
        }

        fclose(file);
        ESP_ERROR_CHECK(esp_vfs_spiffs_unregister(conf.partition_label));
    }
}