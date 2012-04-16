int value;

void setup() {
Serial.begin(57600);
Serial.println("Button test.");
digitalWrite(3, HIGH);
}

void loop() {
delay(1000);
value = digitalRead(3);
Serial.println(value);
}
