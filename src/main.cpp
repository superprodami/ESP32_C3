#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
 #include "wifi_config.h"
#include "oled.h"
#include "bluetooth.h"

TaskHandle_t WeatherHandle;
__weak_symbol void oled_task(void *pvParameters);

void setup()
{
  Serial.begin(115200);

  // WIFI
  // wifi_init();

  //oled
  //oled_init();
 
  //蓝牙
  bluetooth_init();

  // 创建任务
  xTaskCreate(oled_task, "Task1", 10000, NULL, 1, &WeatherHandle);
}

void loop()
{
  blue_control_led();
}



