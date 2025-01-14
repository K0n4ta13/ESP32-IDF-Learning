#include <stdio.h>
#include "esp_log.h"

static const char* TAG = "logging";

void app_main(void)
{
  // This function can't raise the CONFIG_LOG_MAXIMUM_LEVEL in sdkconfig
  esp_log_level_set(TAG, ESP_LOG_WARN);

  ESP_LOGE(TAG, "This is an error");
  ESP_LOGW(TAG, "This is a warning");
  ESP_LOGI(TAG, "This is an info");
  ESP_LOGD(TAG, "This is a debug");
  ESP_LOGV(TAG, "This is a verbose");
}

