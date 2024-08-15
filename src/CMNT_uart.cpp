#include "CMNT_uart.h"
#include <Arduino.h>
#include "Servo.h"
#include "driver/uart.h"

String Rxdata = ""; // 声明字符串变量

void Serial_init(void)
{
    // 初始化串口
    Serial.begin(115200);
    Serial1.begin(115200);
    Serial1.setPins(01, 00);
}

void cmnt_uart(void)
{
    while (Serial1.available() > 0)
    {
        char c = (char)Serial1.read(); // 读取一个字符

        if (c == '\n') // 当读取到换行符，表示一条完整的数据已接收
        {
            int data = std::atoi(Rxdata.c_str());     // 将字符串转换为整数
            Serial.printf("\nvalue: %d\n", data); // 输出数据
            if (data <= 180 && data >= 0)
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
}
