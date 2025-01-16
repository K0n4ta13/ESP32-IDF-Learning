#include <esp_types.h>
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

static SemaphoreHandle_t mutex_bus;

void write_to_bus(char *message) {
    printf(message);
}

void task1(void *params) {
    while (true) {
        printf("reading temperature\n");
        if (xSemaphoreTake(mutex_bus, 1000 / portTICK_PERIOD_MS)) {
            write_to_bus("temperature is 25 °C\n");
            xSemaphoreGive(mutex_bus);
        } else {
            printf("reading temperature timed out\n");
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void task2(void *params) {
    while (true) {
        printf("reading humidity\n");
        if (xSemaphoreTake(mutex_bus, 1000 / portTICK_PERIOD_MS)) {
            write_to_bus("humidity is 50%\n");
            xSemaphoreGive(mutex_bus);
        } else {
            printf("reading humidity timed out\n");
        }
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    mutex_bus = xSemaphoreCreateMutex();
    xTaskCreate(task1, "task1", 2048, NULL, 2, NULL);
    xTaskCreate(task2, "task2", 2048, NULL, 2, NULL);
}

