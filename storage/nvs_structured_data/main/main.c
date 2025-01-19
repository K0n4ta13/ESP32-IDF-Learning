#include <esp_err.h>
#include <esp_log.h>
#include <nvs_flash.h>
#include <stdio.h>

#define TAG "NVS"

typedef struct {
    char     name[20];
    uint8_t  age;
    uint32_t id;
} Cat;

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());

    nvs_handle_t nvs_handle;
    ESP_ERROR_CHECK(nvs_open("store", NVS_READWRITE, &nvs_handle));

    char cat_key[15];
    Cat cat;
    size_t cat_size = sizeof(Cat);
    for (int i = 0; i < 5; i++) {
        sprintf(cat_key, "cat_%d", i);
        const esp_err_t result = nvs_get_blob(nvs_handle, cat_key, &cat, &cat_size);

        switch (result) {
            case ESP_ERR_NVS_NOT_FOUND:
                ESP_LOGE(TAG, "NVS not found");
                break;
            case ESP_OK:
                ESP_LOGI(TAG, "Cat name: %s, age: %d, id: %ld", cat.name, cat.age, cat.id);
                break;
            default:
                ESP_LOGE(TAG, "NVS error");
        }
    }

    for (int i = 0; i < 5; i++) {
        sprintf(cat_key, "cat_%d", i);
        Cat new_cat;
        sprintf(new_cat.name, "Mr cat %d", i);
        new_cat.age = i + 2;
        new_cat.id = i;
        ESP_ERROR_CHECK(nvs_set_blob(nvs_handle, cat_key, &new_cat, sizeof(Cat)));
        ESP_ERROR_CHECK(nvs_commit(nvs_handle));
    }

    nvs_close(nvs_handle);
}