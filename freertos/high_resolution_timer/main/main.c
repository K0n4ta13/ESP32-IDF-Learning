#include <esp_timer.h>
#include <stdio.h>
#include <freertos/FreeRTOS.h>

void timer_callback(void* args) {
}

void app_main(void)
{
    const esp_timer_create_args_t timer_args = {
    .callback = timer_callback,
    .arg = NULL,
    .dispatch_method = ESP_TIMER_TASK,
    .name = "my-timer"
    };

    esp_timer_handle_t timer;
    esp_timer_create(&timer_args, &timer);

    //esp_timer_start_once(timer, 5000);
    esp_timer_start_periodic(timer, 5000);

    uint8_t x = 0;
    while (1) {
        esp_timer_dump(stdout);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        if (x++ == 5) {
            esp_timer_stop(timer);
            esp_timer_delete(timer);
        }
    }
}

