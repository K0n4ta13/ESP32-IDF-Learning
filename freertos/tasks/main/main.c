#include <esp_log.h>
#include <stdio.h>
#include <freertos/FreeRTOS.h>

void task1(void *params) {
    const int *digits = (int *) params;

    while (true) {
        for (int i = 0; i < 5; i++) {
            ESP_LOGI("task1", "reading temperature %d", digits[i]);
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void task2(void *params) {
    while (true) {
        ESP_LOGI("task2", "reading humidity");
        vTaskDelay(2000 / portTICK_PERIOD_MS);

    }
}

void app_main(void)
{

    TaskHandle_t myTaskHandle;

    int *digits = malloc(5 * sizeof(int));
    if (digits == NULL)
    {
        printf("Failed to allocate memory\n");
        return;
    }

    digits[0] = 10; digits[1] = 20; digits[2] = 30;
    digits[3] = 40; digits[4] = 50;

    xTaskCreate(task1, "task: temperature", 2048, digits, 2, NULL);
    xTaskCreatePinnedToCore(task2, "task: humidity", 2048, NULL, 2, &myTaskHandle, 1);

    //vTaskDelay(3000 / portTICK_PERIOD_MS);
    //vTaskDelete(myTaskHandle);
}