Custom PCBA design

I have designed and fabricated a custom board with ESP32-C3 with the following key hardware features:

- Using ESP32-C3FH4 (embedded flash memory)
- Power management from USB as well as from (maximum) 12 V source (LDO: AMS1117-3.3 and L78L05ABUTR)
- Stepper motor driver (DRV8825)
- Accelerometer + Gyro unit (MPU6050)
- Built-in 2.4 GHz inverted F antenna (reference)
- CAN transceiver (TJA1051T/CM,118)

Project Layout build from KiCad 6:
Refer to folder "KiCad Project Schematics and Gerbers"

Layout snapshot

<img width="668" height="563" alt="image" src="https://github.com/user-attachments/assets/4ea44bd7-cf59-4813-adb9-faa273aa7002" />

Actual 

<img width="627" height="510" alt="image" src="https://github.com/user-attachments/assets/fe470d92-b999-4f19-9379-06d3e6f514a4" />

Scope of sample codes under folder names:
BLE_Advertising_example_V1 - BLE advertising example
BLE_Gyro_example_V2 - Gyro data sent over BLE from custom board to phone with nRF app
Custom_ESP32_DRV8825_V1 - Stepper motor driving with on board DRV8825
ESP32_custom_board_LED_flash_V1 - Initial program sanity check if the MCU is working
MP6050_trial_V2 - Grab data from gyroscope/accelrometer
SimpleWiFiServer - Becomes a web server to trigger a GPIO action (e.g. LED)
Wifi_scan_example - Scan the wifi network and check for RSSI signal strength 

Example GIFs:

![InShot_20230917_184955720](https://github.com/user-attachments/assets/2dfa7e15-1841-4f13-a897-50a13fdb003a)

![InShot_20230919_152650873](https://github.com/user-attachments/assets/a42fa128-f163-4287-ad61-54f691dff7d0)

![InShot_20230919_204007445](https://github.com/user-attachments/assets/973962b2-b6eb-4189-8930-403008e88488)

![InShot_20230922_123716818](https://github.com/user-attachments/assets/43f7b40a-9c82-4177-9599-bf74891a49ad)
