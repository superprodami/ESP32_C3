#include <wifi_config.h>


const char *ssid = "Xiaomi";
const char *password = "31415926";
uint16_t temp;
String info;
int aqi,wid;

void wifi_init(void)
{
  WiFi.begin(ssid, password);
  Serial.println("正在连接WiFi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n连接成功");
  Serial.print("IP 地址：");
  Serial.println(WiFi.localIP());
  Serial.println();

}


/*天气*/
void Get_weather(void)
{
  HTTPClient http;

  http.begin("http://apis.juhe.cn/simpleWeather/query?key=9bff731c5eebdc03fd0019bf9ca56513&city=十堰");
  int httpCode = http.GET();
  Serial.printf("天气HTTP 状态码：%d\n", httpCode);
  String response = http.getString();
  http.end();

  DynamicJsonDocument doc(1024);
  deserializeJson(doc, response);
  temp = doc["result"]["realtime"]["temperature"].as<uint16_t>();
  info = doc["result"]["realtime"]["info"].as<String>();
  wid = doc["result"]["realtime"]["wid"].as<int>();
  aqi = doc["result"]["realtime"]["aqi"].as<int>();

  Serial.println("十堰:");
  Serial.printf("温度：%d℃\n", temp);
  Serial.printf("天气：%s\n", info);
  Serial.printf("空气指数：%d\n", aqi);
}

// void Get_weather(void)
// {
//   HTTPClient http;

//   http.begin("http://api.seniverse.com/v3/weather/now.json?key=SDFi25VSq-3ekDy_E&location=Shiyan&language=zh-Hans&unit=c&start=0&days=2");
//   int httpCode = http.GET();
//   Serial.printf("天气HTTP 状态码：%d\n", httpCode);
//   String response = http.getString();
//   http.end();

//   DynamicJsonDocument doc(1024);
//   deserializeJson(doc, response);
//   temp = 
//   info = 
//   wid = 
//   aqi = 

//   Serial.println("十堰:");
//   Serial.printf("温度：%d℃\n", temp);
//   Serial.printf("天气：%s\n", info);
//   Serial.printf("空气指数：%d\n", aqi);
// }






