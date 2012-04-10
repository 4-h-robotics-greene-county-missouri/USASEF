String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

#define MOTOR_ENABLE_PIN 4

void setup() 
    {
 // initialize serial:
  Serial.begin(57600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  Serial.println("Relay_Switch_Serial");
    pinMode(MOTOR_ENABLE_PIN,OUTPUT);
    digitalWrite(MOTOR_ENABLE_PIN, LOW);
    }

void loop() 
    {
      if (stringComplete) {
        char inByte = inputString[0];
        switch (inByte) 
              {
        case 'r':    
          relayControl(inputString[1]);
          break;
        default:
          break;
              }
        // clear the string:
        inputString = "";
        stringComplete = false;
          }
    }
void relayControl(char cmd)
    {
      if (cmd == '1')
        {
            digitalWrite(MOTOR_ENABLE_PIN, HIGH);
        }
      
      else
          {
              digitalWrite(MOTOR_ENABLE_PIN, LOW);
          }  
    }
    
    
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
