#include <esp_log.h>
#include <esp_vfs_fat.h>
#include <stdio.h>

#define TAG "store"
#define BASE_PATH "/store"

void write_file(char *path, char *content);
void read_file(char *path);

void app_main(void)
{
    wl_handle_t wl_handle = WL_INVALID_HANDLE;
    const esp_vfs_fat_mount_config_t mount_config = {
        .allocation_unit_size = CONFIG_WL_SECTOR_SIZE,
        .max_files = 5,
        .format_if_mount_failed = true,
        .use_one_fat = false,
    };

    ESP_ERROR_CHECK(esp_vfs_fat_spiflash_mount_rw_wl(BASE_PATH, "storage", &mount_config, &wl_handle));
    // esp_vfs_fat_spiflash_mount_ro(BASE_PATH, "storage", &mount_config);

    read_file("/store/some.txt");
    write_file("/store/some.txt", "Super secret information.");
    read_file("/store/some.txt");

    ESP_ERROR_CHECK(esp_vfs_fat_spiflash_unmount_rw_wl(BASE_PATH, wl_handle));
    // esp_vfs_fat_spiflash_unmount_ro(BASE_PATH, "storage");
}

void read_file(char *path) {
    ESP_LOGI(TAG, "Reading file %s", path);
    FILE *file = fopen(path, "r");
    char buffer[100];
    fgets(buffer, 99, file);
    fclose(file);
    ESP_LOGI(TAG, "file content: %s", buffer);
}

void write_file(char *path, char *content) {
    ESP_LOGI(TAG, "Writing %s to %s", path, content);
    FILE *file = fopen(path, "w");
    fputs(content, file);
    fclose(file);
}