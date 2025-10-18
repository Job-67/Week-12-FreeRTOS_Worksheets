#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"

static const char *TAG = "DUAL_CORE";

void core_info_task(void *parameter)
{
    int core_id = xPortGetCoreID();
    const char* core_name = (core_id == 0) ? "PRO_CPU" : "APP_CPU";
    
    ESP_LOGI(TAG, "Task running on Core %d (%s)", core_id, core_name);
    
    while (1) {
        ESP_LOGI(TAG, "Core %d: Task executing", core_id);
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void app_main(void)
{
    ESP_LOGI(TAG, "ESP32 Dual-Core FreeRTOS Demo");
    ESP_LOGI(TAG, "Main task running on Core %d", xPortGetCoreID());
    
    // Create tasks without affinity (can run on either core)
    xTaskCreate(core_info_task, "CoreTask1", 2048, NULL, 5, NULL);
    xTaskCreate(core_info_task, "CoreTask2", 2048, NULL, 5, NULL);
    xTaskCreate(core_info_task, "CoreTask3", 2048, NULL, 5, NULL);
    xTaskCreate(core_info_task, "CoreTask4", 2048, NULL, 5, NULL);
    
    ESP_LOGI(TAG, "Tasks created - they will distribute across cores");
}