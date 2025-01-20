#include <esp_log.h>
#include <esp_spiffs.h>
#include <sys/dirent.h>
#include <sys/stat.h>

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

    DIR *dir = opendir("/spiffs");
    struct dirent *entry;
    while ((entry = readdir(dir))) {
        char full_path[256];
        sprintf(full_path, "/spiffs/%s", entry->d_name);
        struct stat entry_stat;

        if (stat(full_path, &entry_stat) == -1) {
            ESP_LOGE(TAG, "Failed to stat %s", full_path);
        } else {
            ESP_LOGI(TAG, "full path = %s, file size = %ld", full_path, entry_stat.st_size);
        }
    }

    size_t total = 0, used = 0;
    esp_spiffs_info(NULL, &total, &used);
    ESP_LOGI(TAG, "total = %d, used = %d", total, used);

    FILE *file = fopen("/spiffs/index.html", "r");
    if (!file) {
        ESP_LOGE(TAG, "Failed to open index.html");
    } else {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf(line);
        }

        fclose(file);
    }

    esp_vfs_spiffs_unregister(NULL);
}