#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define PIN 48

void app_main(void)
{
    gpio_set_direction(PIN, GPIO_MODE_OUTPUT);
    uint32_t in_on = 0;

    while (1) {
        in_on = !in_on;
        gpio_set_level(PIN, in_on);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

