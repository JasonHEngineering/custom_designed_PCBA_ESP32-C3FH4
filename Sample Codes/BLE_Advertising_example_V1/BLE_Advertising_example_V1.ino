#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
 
// These are my custom UUID and characteristic
 
#define SERVICE_UUID        "12345678-1234-5678-1234-56789abcdef0"
#define CHARACTERISTIC_UUID "12345678-1234-5678-1234-56789abcdef1"
 
void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE!");
 
  BLEDevice::init("ESP32-C3 BLE test");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );
 
  pCharacteristic->setValue("ESP32 Test Value");
  pService->start();
  // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Advertising.......");
}
 
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Running.......");
  delay(2000);
}