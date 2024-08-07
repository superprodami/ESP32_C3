#include <Arduino.h>
// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h>
//  #include "wifi_config.h"
// #include "oled.h"
// #include "bluetooth.h"

// TaskHandle_t WeatherHandle;
// __weak_symbol void oled_task(void *pvParameters);

// void setup()
// {
//   Serial.begin(115200);

//   // WIFI
//   // wifi_init();

//   //oled
//   oled_init();
//   //蓝牙
//   bluetooth_init();

//   // 创建任务
//   xTaskCreate(oled_task, "Task1", 10000, NULL, 1, &WeatherHandle);
// }

// void loop()
// {
//   blue_control_led();
// }

// 此程序通过BLE广播，其他设备接受广播，手机通过nRF Connet软件连接，
// 手机下发字符 1 点亮LED,字符 0 关闭LED

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLEService.h>
#include <BLECharacteristic.h>
#define SERVICE_UUID "b408e1a0-3d8a-11ed-b878-0242ac120002"        // 服务UUID
#define CHARACTERISTIC_UUID "dfd84064-3d8a-11ed-b878-0242ac120002" // 特征UUID
#define CONTROL_UUID "de045162-3d97-11ed-b878-0242ac120002"        // 控制特征UUID

const int led = 12;
char state = 48;

BLECharacteristic controlCharacteristic(CONTROL_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);

// 设置服务器所需要的配置
void setup()
{
  Serial.begin(115200);
  BLEDevice::init("BLE_ESP");                                  // 创建设备
  BLEServer *pServer = BLEDevice::createServer();              // 设置为服务器
  BLEService *pService = pServer->createService(SERVICE_UUID); // 使用上面的服务UUID创建服务
  // 添加一个带有对象名（官方UUID）的特征，不带对象，这个特征不会改变
  BLECharacteristic *nameCharacteristic = pService->createCharacteristic(BLEUUID((uint16_t)0x2A00), BLECharacteristic::PROPERTY_READ);
  nameCharacteristic->setValue("LED");                 // 显示特征名
  pService->addCharacteristic(&controlCharacteristic); // 增加一个控制LED的特性
  controlCharacteristic.setValue(&state);

  // 设置特征， 使用上面的特征UUID，需要将特征的属性作为参数传递。此情况下是读或写
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID,
      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);
  pCharacteristic->setValue("Hello HWD!!!"); // 创建完特征后，可以使用setValue()方法为其在此赋值
  // 此值可以是其他传感器的值
  pService->start();
  // 下面是启动服务和广播，以便其他BLE设备找到此 BLE 设备
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising(); // BLE广播
  pAdvertising->addServiceUUID(SERVICE_UUID);                 // 广播添加服务 UUID
  pAdvertising->setScanResponse(true);                        // 广播扫描响应
  pAdvertising->setMinPreferred(0x06);                        // 广播设置最小首选
  pAdvertising->setMinPreferred(0x12);                        // 广播设置最小首选
  BLEDevice::startAdvertising();                              // BLE 设备启动广播，特征已经定义，可以在手机中读取它
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.println("Characteristic defined! Now you can read it in your phone!"); // 提示消息
}

void loop()
{
  std::string controlValue = controlCharacteristic.getValue(); // 字符串控件获取特征值
  if (controlValue[0] != state)
  {
    state = controlValue[0];
    if (state == 48)
    {
      digitalWrite(led, LOW);
    }
    else if (state == 49)
    {
      digitalWrite(led, HIGH);
    }
  }
  delay(1);
}
