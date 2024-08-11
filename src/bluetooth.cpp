// 手机下发字符 1 点亮LED,字符 0 关闭LED

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLEService.h>
#include <BLECharacteristic.h>
#include <BLE2902.h>
#include <Arduino.h>
#include "bluetooth.h"

#define SERVICE_UUID "b408e1a0-3d8a-11ed-b878-0242ac120002" // 服务UUID
#define test_UUID "dfd84064-3d8a-11ed-b878-0242ac120002"    // 特征UUID
#define CONTROL_UUID "de045162-3d97-11ed-b878-0242ac120002" // 控制特征UUID

BLECharacteristic *pCharacteristic_test = NULL;

bool deviceConnected = 0;
const int led = 12;
char state = 48;
char test_value[20] = "Hello DAMI!!!";
uint32_t value_1 = 0;

// 回调函数声明
class MyServerCallbacks : public BLEServerCallbacks
{
    void onConnect(BLEServer *pServer)
    {
        Serial.println("有设备接入连接");
        deviceConnected = 1;
    };

    void onDisconnect(BLEServer *pServer)
    {
        Serial.println("有设备断开连接，已重新广播");
        deviceConnected = 0;
        // 在有设备接入后Advertising广播会被停止，所以要在设备断开连接时重新开启广播
        // 不然的话只有重启ESP32后才能重新搜索到
        pServer->startAdvertising(); // 该行效果同 BLEDevice::startAdvertising();
    }
};

class MyCallbacks : public BLECharacteristicCallbacks
{
    void onRead(BLECharacteristic *pCharacteristic)
    { // 客户端读取事件回调函数
        Serial.println("检测到设备读取数据");
    }

    void onWrite(BLECharacteristic *pCharacteristic)
    { // 客户端写入事件回调函数
        Serial.print("写入数据：");
        std::string readValue = pCharacteristic_test ->getValue();
        Serial.printf("%s\n",readValue.c_str());
    }
};

// 设置服务器所需要的配置
void bluetooth_init(void)
{
    BLEDevice::init("BLE_DAMI");                                 // 创建设备
    BLEServer *pServer = BLEDevice::createServer();              // 设置为服务器
    BLEService *pService = pServer->createService(SERVICE_UUID); // 使用上面的服务UUID创建服务

    // 设置特征， 使用上面的特征UUID，
    pCharacteristic_test = pService->createCharacteristic(
        test_UUID,
        BLECharacteristic::PROPERTY_NOTIFY | 
        BLECharacteristic::PROPERTY_WRITE  |
        BLECharacteristic::PROPERTY_READ);
    pCharacteristic_test->setValue(test_value); // 创建完特征后，可以使用setValue()方法为其在此赋值
    pCharacteristic_test->setCallbacks(new MyCallbacks()); //绑定事件回调函数
    pCharacteristic_test->addDescriptor(new BLE2902());
    pService->start();
    // 下面是启动服务和广播，以便其他BLE设备找到此 BLE 设备
    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising(); // BLE广播
    pAdvertising->addServiceUUID(SERVICE_UUID);                 // 广播添加服务 UUID
    pAdvertising->setScanResponse(true);                        // 广播扫描响应
    pAdvertising->setMinPreferred(0x06);                        // 广播设置最小首选
    pAdvertising->setMinPreferred(0x12);                        // 广播设置最小首选
    pServer->setCallbacks(new MyServerCallbacks());             // 绑定回调函数
    BLEDevice::startAdvertising();                              // BLE 设备启动广播，特征已经定义，可以在手机中读取它
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    Serial.println("Characteristic defined! Now you can read it in your phone!"); // 提示消息
}


void blue_control_led(void)
{
    if(deviceConnected)
    {
    //  
    
    // if (readValue.compare(test_value) != 0)
    // {
    //     memcpy(test_value,readValue.data(),20);
        pCharacteristic_test ->setValue((uint8_t*)&value_1, 4);
        pCharacteristic_test ->notify();
        value_1++;
    //     Serial.println(readValue.data());
     
    // }
    }
       delay(10000);
}
