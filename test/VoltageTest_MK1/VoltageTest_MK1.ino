int incomingByte = 0;

void setup() {
Serial.begin(57600);
Serial.println("# Voltage test Mk1";
}

void loop() {
  
}

void serialEvent(){
if (Serial.available() > 0) {
  incomingByte = Serial.read();
  }  
if String
}
