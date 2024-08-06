#include "ble_config.h"
#include <Arduino.h>

// 定义BLE服务和特征值的UUID
#define SERVICE_UUID        "12345678-1234-5678-1234-56789abcdef0"
#define CHARACTERISTIC_UUID "abcdef12-3456-7890-1234-56789abcdef0"

void bluetooth_init(void)
{

 BLEDevice::init("ESP32_BLE");
 BLEServer *pServer = BLEDevice::createServer();
 BLEService *pService = pServer->createService(SERVICE_UUID);
 BLECharacteristic *pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_READ |BLECharacteristic::PROPERTY_WRITE);
 pCharacteristic->setValue("Hello World");
 pService->start();
 BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
 pAdvertising->addServiceUUID(SERVICE_UUID);
 pAdvertising->setScanResponse(true);
 pAdvertising->setMinPreferred(0x06);  // 函数间隔，该值越小功耗越高
 pAdvertising->setMinPreferred(0x12);
 BLEDevice::startAdvertising();
 Serial.println("BLE服务已启动");

}
