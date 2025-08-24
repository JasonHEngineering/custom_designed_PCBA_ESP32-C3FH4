#define LED_1_PIN 3
#define LED_2_PIN 10

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
 pinMode(LED_1_PIN, OUTPUT);
 pinMode(LED_2_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED_1_PIN, LOW);
digitalWrite(LED_2_PIN, HIGH);
Serial.println("Toggle 1");
delay(250);

digitalWrite(LED_1_PIN, HIGH);
digitalWrite(LED_2_PIN, LOW);
delay(250);
Serial.println("Toggle 2");

}
