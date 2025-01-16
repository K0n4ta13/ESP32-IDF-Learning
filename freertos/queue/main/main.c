#include <stdbool.h>
#include <stdio.h>
#include <freertos/FreeRTOS.h>

static QueueHandle_t queue_handle;

void listen_http(void *params) {
    uint32_t count = 0;
    while (true) {
        count++;
        printf("received http message\n");
        if (xQueueSend(queue_handle, &count, 1000 / portTICK_PERIOD_MS)) {
            printf("added message to queue\n");
        } else {
            printf("queue full\n");
        }
        vTaskDelay(3000 / portTICK_PERIOD_MS);
    }
}

void task1(void *params) {
    while (true) {
        uint32_t count;
        if (xQueueReceive(queue_handle, &count, 1000 / portTICK_PERIOD_MS)) {
            printf("received message from queue %ld\n", count);
            printf("doing something with http\n");
        } else {
            printf("queue is empty\n");
        }
    }
}

void app_main(void)
{
    queue_handle = xQueueCreate(3, sizeof(uint32_t));
    xTaskCreate(listen_http, "listen_http", 2048, NULL, 1, NULL);
    xTaskCreate(task1, "so something with http", 2048, NULL, 1, NULL);
}

