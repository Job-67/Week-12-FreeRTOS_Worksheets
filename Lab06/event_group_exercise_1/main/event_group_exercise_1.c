#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_log.h"

static const char *TAG = "EVENT_GROUP";

// Event group handle
EventGroupHandle_t system_event_group;

// Event bit definitions
#define WIFI_CONNECTED_BIT     BIT0
#define TIME_SYNCED_BIT        BIT1
#define SENSORS_READY_BIT      BIT2
#define CONFIG_LOADED_BIT      BIT3
#define CALIBRATION_DONE_BIT   BIT4

// Combined conditions
#define BASIC_SYSTEM_READY     (WIFI_CONNECTED_BIT | CONFIG_LOADED_BIT)
#define FULL_SYSTEM_READY      (BASIC_SYSTEM_READY | TIME_SYNCED_BIT | SENSORS_READY_BIT | CALIBRATION_DONE_BIT)

void app_main(void)
{
    ESP_LOGI(TAG, "Creating system event group...");
    
    // Create event group
    system_event_group = xEventGroupCreate();
    if (system_event_group == NULL) {
        ESP_LOGE(TAG, "Failed to create event group");
        return;
    }
    
    ESP_LOGI(TAG, "Event group created successfully");
    
    // Create system initialization tasks
    xTaskCreate(wifi_init_task, "WiFiInit", 3072, NULL, 6, NULL);
    xTaskCreate(time_sync_task, "TimeSync", 2048, NULL, 5, NULL);
    xTaskCreate(sensor_init_task, "SensorInit", 2048, NULL, 5, NULL);
    xTaskCreate(config_loader_task, "ConfigLoader", 2048, NULL, 5, NULL);
    xTaskCreate(calibration_task, "Calibration", 2048, NULL, 4, NULL);
    
    // Create main application task that waits for system ready
    xTaskCreate(main_app_task, "MainApp", 4096, NULL, 3, NULL);
    
    // Create monitoring task
    xTaskCreate(system_monitor_task, "Monitor", 2048, NULL, 2, NULL);
}