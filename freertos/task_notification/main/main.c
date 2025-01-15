#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

static TaskHandle_t receiver_handler = NULL;

void sender(void *params) {
    while (true) {
        xTaskNotifyGive(receiver_handler);
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}

void receiver(void *params) {
    while (true) {
        const int count = ulTaskNotifyTake(pdFALSE, portMAX_DELAY);
        printf("received notification %d times\n", count);
    }
}

void app_main(void)
{
    xTaskCreate(receiver, "receiver", 2048, NULL, 2, &receiver_handler);
    xTaskCreate(sender, "sender", 2048, NULL, 2, NULL);
}

