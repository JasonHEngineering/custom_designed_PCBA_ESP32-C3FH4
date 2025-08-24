#include "Wire.h"
#include <MPU6050_light.h>

MPU6050 mpu(Wire);
unsigned long timer = 0;

void setup() {
  Serial.begin(19200);
  Wire.begin(1, 0); // (GPIO1 - SDA, GPIO0 - SCL)
  
  byte status = mpu.begin();
  //Serial.print(F("MPU6050 status: "));
  //Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050
  
  //Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  //Serial.println("Done!\n");
}

void loop() {
  mpu.update();
  
  if((millis()-timer)>50){ // print data every 50ms

	//Serial.print("X : ");
	Serial.print(mpu.getAngleX());
	Serial.print("\t");
  //Serial.print("Y : ");
	Serial.println(mpu.getAngleY());
	timer = millis();  

  }
}