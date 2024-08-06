#include "oled.h"

#define SCL 5
#define SDA 4

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /*clock=*/SCL, /*data=*/SDA, /*reset=*/U8X8_PIN_NONE);

void oled_init(void)
{
    u8g2.begin();
    u8g2.enableUTF8Print(); // u8g2库字体使能
}

void oled_weather_task(void *pvParameters)
{
    uint32_t count;

    while(1){
    // 清除显示
    u8g2.clearBuffer();
    // 切换中文GB字体
    u8g2.setFont(u8g2_font_wqy14_t_gb2312);
    u8g2.setFontDirection(0);
    // 设置光标位置并显示数据
    u8g2.setCursor(0, 15);
    u8g2.print("十堰 ");
    u8g2.print("温度：");
    u8g2.print(temp);
    u8g2.print("℃");
    u8g2.setCursor(0, 35);
    u8g2.print("天气：");
    u8g2.print(info);
    u8g2.setCursor(0, 55);
    u8g2.print("空气指数：");
    u8g2.print(aqi);
    // 选择字体大小并绘制图案
    u8g2.setFont(u8g2_font_open_iconic_weather_4x_t);
    u8g2.drawGlyph(90, 60, 0x0045);
    // 显示绘制内容
    u8g2.sendBuffer();
    
    count++;
    if(count%60 ==1)  
    Get_weather();      //一分钟更新一次天气
    if(count > 3600)
    count = 0;          //防止溢出

    vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

#define SUN	0
#define SUN_CLOUD  1
#define CLOUD 2
#define RAIN 3
#define THUNDER 4

