/*
Author: Jason Huang
Date: 22-Sep-23 
Rev: 01

Purpose: Utilize ESP32-C3 on my custom board, to send acquired gyro data via BLE

*/

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <Wire.h>
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/
// Or set my own here - not encouraged 
#define SERVICE_UUID        "12345678-1234-5678-1234-56789abcdef0"
#define CHARACTERISTIC_UUID_1 "12345678-1234-5678-1234-56789abcdef1"
#define CHARACTERISTIC_UUID_2 "12345678-1234-5678-1234-56789abcdef2"
#define CHARACTERISTIC_UUID_3 "12345678-1234-5678-1234-56789abcdef3"

BLECharacteristic pCharacteristic_x(CHARACTERISTIC_UUID_1, BLECharacteristic::PROPERTY_READ);
BLECharacteristic pCharacteristic_y(CHARACTERISTIC_UUID_2, BLECharacteristic::PROPERTY_READ);
BLECharacteristic pCharacteristic_z(CHARACTERISTIC_UUID_3, BLECharacteristic::PROPERTY_READ);  

float x, y, z;
bool deviceConnected = false;

void setup() {
  Serial.begin(115200);

  Wire.begin(1, 0); // (GPIO1 - SDA, GPIO0 - SCL)
  
  byte status = mpu.begin();
  while(status!=0){ } // stop everything if could not connect to MPU6050
  //Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done calibration for MPU6050");

  Serial.println("Starting BLE!");

  BLEDevice::init("ESP32-C3 BLE test");

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  pService->addCharacteristic(&pCharacteristic_x);
  pService->addCharacteristic(&pCharacteristic_y);
  pService->addCharacteristic(&pCharacteristic_z);

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

  static char x_roll[6];
  static char y_pitch[6];
  static char z_yaw[6];

  mpu.update();
  x = mpu.getAngleX();
  y = mpu.getAngleY();
  z = mpu.getAngleZ();

  dtostrf(x, 6, 2, x_roll);
  dtostrf(y, 6, 2, y_pitch);
  dtostrf(z, 6, 2, z_yaw);

  pCharacteristic_x.setValue(x_roll);
  pCharacteristic_y.setValue(y_pitch);
  pCharacteristic_z.setValue(z_yaw);

  Serial.println(x_roll);
  //Serial.print("\t");
  Serial.println(y_pitch);
  //Serial.print("\t");
  Serial.println(z_yaw);

  delay(200);

}