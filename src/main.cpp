#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "wifi_config.h"
#include "oled.h"
#include "bluetooth.h"
#include "Servo.h"

TaskHandle_t WeatherHandle;
__weak_symbol void oled_task(void *pvParameters);

void setup()
{
  Serial.begin(115200);

  // WIFI
  // wifi_init();

  // oled
  // oled_init();

  // 蓝牙
  bluetooth_init();

  // 舵机
  Servo_init();

  // 创建任务
  // xTaskCreate(oled_task, "Task1", 10000, NULL, 1, &WeatherHandle);
}

uint16_t loop_count = 0;

void loop()
{
  if (loop_count % 5 == 0) // 延时
    blue_control_led();

  if (loop_count % 2 == 0)
    Servo_control();

  if (loop_count > 60000) // 防止溢出
    loop_count = 0;
  else
    loop_count++;

  delay(10);
}
