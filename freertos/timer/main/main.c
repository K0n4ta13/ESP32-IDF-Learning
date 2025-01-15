#include <esp_timer.h>
#include <stdio.h>
#include <freertos/FreeRTOS.h>

void on_timer(TimerHandle_t pxTimer) {
    printf("Timer expired\n");

}

void app_main(void)
{
    printf("milliseconds since started: %lld\n", esp_timer_get_time() / 1000);
    TimerHandle_t timer = xTimerCreate("timer", pdMS_TO_TICKS(1000), true, NULL, on_timer);
    xTimerStart(timer, 0);
}

