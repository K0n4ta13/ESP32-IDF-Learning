#include <stdbool.h>
#include <stdio.h>
#include <freertos/FreeRTOS.h>

static SemaphoreHandle_t semaphore;

void listen_http(void *params) {
    while (true) {
        printf("received http message\n");
        printf("processed http message\n");
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        xSemaphoreGive(semaphore);
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}

void task1(void *params) {
    while (true) {
        xSemaphoreTake(semaphore, portMAX_DELAY);
        printf("doing something with http\n");
    }
}

void app_main(void)
{
    semaphore = xSemaphoreCreateBinary();
    xTaskCreate(listen_http, "listen_http", 2048, NULL, 1, NULL);
    xTaskCreate(task1, "so something with http", 2048, NULL, 1, NULL);
}

