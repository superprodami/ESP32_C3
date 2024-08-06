#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "wifi_config.h"
#include "oled.h"


TaskHandle_t WeatherHandle;
__weak_symbol void oled_weather_task(void *pvParameters);

void setup()
{
  Serial.begin(115200);

  // WIFI
  wifi_init();

  //oled
  oled_init();


  // 创建任务
  xTaskCreate(oled_weather_task, "Task1", 10000, NULL, 1, &WeatherHandle);
}

void loop()
{

}





