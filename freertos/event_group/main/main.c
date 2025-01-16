#include <stdbool.h>
#include <stdio.h>
#include <freertos/FreeRTOS.h>

static EventGroupHandle_t event_group;
const int http_bit = BIT0;
const int ble_bit = BIT1;

void listen_http(void *params) {
    while (true) {
        xEventGroupSetBits(event_group, http_bit);
        printf("received http message\n");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

void listen_ble(void *params) {
    while (true) {
        xEventGroupSetBits(event_group, ble_bit);
        printf("received BLE message\n");
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}

void task1(void *params) {
    while (true) {
        xEventGroupWaitBits(event_group, http_bit | ble_bit, true, true, portMAX_DELAY);
        printf("received http and BLE message\n");
    }
}

void app_main(void)
{
    event_group = xEventGroupCreate();
    xTaskCreate(listen_http, "listen_http", 2048, NULL, 1, NULL);
    xTaskCreate(listen_ble, "listen_BLE", 2048, NULL, 1, NULL);
    xTaskCreate(task1, "so something with http", 2048, NULL, 1, NULL);
}

