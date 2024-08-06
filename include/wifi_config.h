#ifndef __WIFI_CONFIG_H
#define __WIFI_CONFIG_H



#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>


extern uint16_t temp;
extern String info;
extern int aqi;

void wifi_init(void);
void Get_weather(void);


#endif