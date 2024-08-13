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

String Rxdata = ""; // 声明字符串变量

void loop()
{

  // 如果串口有数据可读
  while (Serial.available() > 0)
  {
    char c = (char)Serial.read(); // 读取一个字符

    if (c == '\n') // 当读取到换行符，表示一条完整的数据已接收
    {
      int data = std::atoi(Rxdata.c_str()); // 将字符串转换为整数
      Serial.printf("\nvalue: %d\n", data);   // 输出数据
      if(data<=180 && data >=0)
      Servo_target[0] = data;
      else
      Serial.println("Invalid data");

      Rxdata = ""; // 清空缓冲区，准备接收下一条数据
    }
    else
    {
      Rxdata += c; // 继续拼接数据
      Serial.printf("-%d", c);
    }
  }


  
  if (loop_count % 50 == 0) // 延时
    blue_control();

  if (loop_count % 20 == 0)
    Servo_control();

  if (loop_count > 600000) // 防止溢出
    loop_count = 0;
  else
    loop_count++;

  delay(1);
}
