#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

static TaskHandle_t receiver_handler = NULL;

void sender(void *params) {
    while (true) {
        xTaskNotify(receiver_handler, (1 << 0), eSetValueWithoutOverwrite);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        xTaskNotify(receiver_handler, (1 << 1), eSetValueWithoutOverwrite);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        xTaskNotify(receiver_handler, (1 << 2), eSetValueWithoutOverwrite);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        xTaskNotify(receiver_handler, (1 << 3), eSetValueWithoutOverwrite);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void receiver(void *params) {
    uint32_t state;
    while (true) {
        xTaskNotifyWait(0, 0, &state, portMAX_DELAY);
        printf("received state %ld times\n", state);
    }
}

void app_main(void)
{
    xTaskCreate(receiver, "receiver", 2048, NULL, 2, &receiver_handler);
    xTaskCreate(sender, "sender", 2048, NULL, 2, NULL);
}

