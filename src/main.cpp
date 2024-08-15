#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "wifi_config.h"
#include "oled.h"
#include "bluetooth.h"
#include "Servo.h"
#include "CMNT_uart.h"

#include <iostream>
#include <string>

TaskHandle_t WeatherHandle;
__weak_symbol void oled_task(void *pvParameters);

void setup()
{
  // 串口
  Serial_init();

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

  //串口通信(阻塞式)
  cmnt_uart();

  
  if (loop_count % 50 == 0) 
    blue_control();

  if (loop_count % 20 == 0)
    Servo_control();

  if (loop_count > 600000) // 防止溢出
    loop_count = 0;
  else
    loop_count++;

  delay(1);
}
