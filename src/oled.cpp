#include "oled.h"
#include "oled_emoji.h"
#include <U8g2lib.h>
#include "wifi_config.h"

#define SCL 5
#define SDA 4

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /*clock=*/SCL, /*data=*/SDA, /*reset=*/U8X8_PIN_NONE);

void oled_init(void)
{
    u8g2.begin();
    u8g2.enableUTF8Print(); // u8g2库字体使能
}

void oled_task(void *pvParameters)
{

    while (1)
    {

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void oled_emoji(void)
{
    // 清除显示
    u8g2.clearBuffer();
}

void oled_weather(void)
{
    // // 清除显示
    // u8g2.clearBuffer();
    // // 切换中文GB字体
    // u8g2.setFont(u8g2_font_wqy14_t_gb2312);
    // u8g2.setFontDirection(0);
    // // 设置光标位置并显示数据
    // u8g2.setCursor(0, 15);
    // u8g2.print("十堰 ");
    // u8g2.print("温度：");
    // u8g2.print(temp);
    // u8g2.print("℃");
    // u8g2.setCursor(0, 35);
    // u8g2.print("天气：");
    // u8g2.print(info);
    // u8g2.setCursor(0, 55);
    // u8g2.print("空气指数：");
    // u8g2.print(aqi);
    // // 选择字体大小并绘制图案
    // u8g2.setFont(u8g2_font_open_iconic_weather_4x_t);
    // u8g2.drawGlyph(90, 60, 0x0045);
    // // 显示绘制内容
    // u8g2.sendBuffer();

    // Get_weather(); // 一分钟更新一次天气
}

void emoji_normal(void)
{
    u8g2.clearBuffer();          
    u8g2.drawXBM(0, 0, 128, 64, gImage_normal);
    u8g2.sendBuffer();  
}

void emoji_angry(void)
{
    // 显示第一个动画帧
    u8g2.clearBuffer();                         // 清空缓冲区
    u8g2.drawXBM(0, 0, 128, 64, gImage_angry_black); // 在坐标 (0,0) 处显示emoji
    u8g2.sendBuffer();                          // 将缓冲区发送到显示屏
}

void emoji_sad()
{
    u8g2.clearBuffer();          
    u8g2.drawXBM(0, 0, 128, 64, gImage_sad_black);
    u8g2.sendBuffer();            
}


void emoji_happy(void)
{
    u8g2.clearBuffer();          
    u8g2.drawXBM(0, 0, 128, 64, gImage_happy);
    u8g2.sendBuffer();   
}
