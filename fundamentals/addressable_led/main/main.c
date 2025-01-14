#include <stdio.h>
#include "led_strip.h"

#define BLINK_GPIO 8

void app_main(void)
{
    const led_strip_config_t strip_config = {
        .strip_gpio_num = BLINK_GPIO,
        .max_leds = 1,
        .led_model = LED_MODEL_WS2812,
        .color_component_format = LED_STRIP_COLOR_COMPONENT_FMT_GRB,
        .flags = {
            .invert_out = false,
        }
    };

    const led_strip_rmt_config_t rmt_config = {
        .clk_src = RMT_CLK_SRC_DEFAULT,
        .resolution_hz = 10 * 1000 * 1000,
        .mem_block_symbols = 64,
        .flags = {
            .with_dma = false,
        }
    };

    led_strip_handle_t led_strip;
    ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &led_strip));

    led_strip_clear(led_strip);
    vTaskDelay(pdMS_TO_TICKS(1500));

    while (true)
    {
        led_strip_set_pixel(led_strip, 0, 50, 0, 0);
        led_strip_refresh(led_strip);
        vTaskDelay(pdMS_TO_TICKS(1500));

        led_strip_set_pixel(led_strip, 0, 0, 50, 0);
        led_strip_refresh(led_strip);
        vTaskDelay(pdMS_TO_TICKS(1500));

        led_strip_set_pixel(led_strip, 0, 0, 0, 50);
        led_strip_refresh(led_strip);
        vTaskDelay(pdMS_TO_TICKS(1500));
    }
}

