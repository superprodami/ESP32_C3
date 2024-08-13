#include "CMNT_uart.h"
#include <Arduino.h>
#include "driver/uart.h"

#define CMNT_LONG 4 // 通信长度

// 中断处理函数
// void Serial1ISR()
// {
//     Serial.println("interrupt");
//     // 检查是否有可用数据从 ESP32 的串口1 接收
//     // if (Serial.available())
//     // {
//     //     // uint8_t receivedData[CMNT_LONG];
//     //     // // 读取字节到 receivedData 数组中
//     //     // Serial.readBytes(receivedData, CMNT_LONG);

//     //     // 输出接收到的数据
//     //     Serial.print("Received data: ");
//     //     // for (int i = 0; i < CMNT_LONG; i++)
//     //     // {
//     //     //     Serial.print(receivedData[i], HEX);
//     //     //     Serial.print(" ");
//     //     // }
//     //     // Serial.println();

//     // }
// }

void Serial_init(void)
{
    // 初始化串口
    Serial.begin(115200);
    Serial1.begin(115200);

// const uart_port_t uart_num = UART_NUM_1;
// uart_config_t uart_config = {
//     .baud_rate = 115200,
//     .data_bits = UART_DATA_8_BITS,
//     .parity = UART_PARITY_DISABLE,
//     .stop_bits = UART_STOP_BITS_1,
//     .flow_ctrl = UART_HW_FLOWCTRL_CTS_RTS,
//     .rx_flow_ctrl_thresh = 122,
// };
// Configure UART parameters
//ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));
    // 配置串口1的RX引脚为中断模式

    // pinMode(20, INPUT_PULLUP);
    // attachInterrupt(digitalPinToInterrupt(20), Serial1ISR, FALLING);
}


