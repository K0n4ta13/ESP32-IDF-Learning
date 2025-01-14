#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include <freertos/task.h>

#define TAG "keyboard_input"

void app_main(void) {
    char c = 0;
    char str[100] = {0};

    while (c != '\n') {
        c = getchar();
        if (c != 0xff) {
            str[strlen(str)] = c;
            printf("%c", c);
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }

    printf("Input: %s", str);
    printf("Input: %d\n", strlen(str));
}

