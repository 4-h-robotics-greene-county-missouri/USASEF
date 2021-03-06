/*************************************************************************
R.O.B.O.T.
Robot Onboard Binary Overlord Task

Based on example http://arduino.cc/en/Tutorial/SerialEvent
By Gunther Krueger (aka. DemonMidget) gunther@ozarkhomestead.com
*************************************************************************/
#define LEFT_CENTER 90
#define RIGHT_CENTER 90
#include <Servo.h>

#define LEFTSERVOPIN  10  
#define RIGHTSERVOPIN  9
#define MOTOR_ENABLE_PIN 4

#define MAXSPEED 90  //due to the way continuous rotation servos work maximum speed is reached at a much lower value than 90 (this value will change depending on your servos) (for Parallax servos)

#define DELAY_TIME 2500

float rpm;
int geiger_input = 2;
int cpm = 0;
volatile long count = 0;

Servo leftServo; 
Servo rightServo; 

unsigned long nextPrint;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


  
void setup() {
 serbSetup(); // adds the servos and prepares all SERB related variables
  // initialize serial:
  Serial.begin(57600);
  Serial.println("# R.O.B.O.T Mk.2");
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  pinMode(MOTOR_ENABLE_PIN,OUTPUT);
  digitalWrite(MOTOR_ENABLE_PIN, HIGH);
  attachInterrupt(0,countPulse,FALLING);
}

void motorCommand (String cmd)
{ 
 // Parsing the motor command string. 
 // example: 'm+90+90'
 
 
 char leftMotorCmd[4];
 leftMotorCmd[0]=cmd[1];
 leftMotorCmd[1]=cmd[2];
 leftMotorCmd[2]=cmd[3];
 leftMotorCmd[3]=0;
 char rightMotorCmd[4];
 rightMotorCmd[0]=cmd[4];
 rightMotorCmd[1]=cmd[5];
 rightMotorCmd[2]=cmd[6];
 rightMotorCmd[3]=0;
 int leftMotorSpeed = atoi(leftMotorCmd);
 int rightMotorSpeed = atoi(rightMotorCmd);
 //Serial.println(leftMotorCmd);
 //Serial.println(rightMotorCmd);
 setSpeedLeft(leftMotorSpeed);
 setSpeedRight(rightMotorSpeed);
 
 
}

void loop() {
  // print the string when a newline arrives:
  radiationCalc();
  if (stringComplete) {
    char inByte = inputString[0];
    switch (inByte) {
    case 'm':    
      motorCommand(inputString);
      break;
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

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
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
/*
 * sets up your arduino to address your SERB using the included routines
*/
void serbSetup(){
  pinMode(LEFTSERVOPIN, OUTPUT);     //sets the left servo signal pin 
                                     //to output
  pinMode(RIGHTSERVOPIN, OUTPUT);    //sets the right servo signal pin 
                                     //to output
  leftServo.attach(LEFTSERVOPIN);    //attaches left servo
  setSpeedLeft(0);  
  rightServo.attach(RIGHTSERVOPIN);  //attaches right servo
  setSpeedRight(0);
}




void setSpeedRight(int rightSpeed){
  int speedval = RIGHT_CENTER - rightSpeed;
  //Serial.print("right=");
  //Serial.println(speedval);
  rightServo.write(speedval);
  //rightServo.write(RIGHT_CENTER - rightSpeed);             //sends the new value to the servo
}


void setSpeedLeft(int leftSpeed){
  int speedval = LEFT_CENTER + leftSpeed;
  //Serial.print("left=");
  //Serial.println(speedval);
  leftServo.write(speedval);
}


void countPulse(){
  detachInterrupt(0);
  count++;
  while(digitalRead(2)==0){
  }
  //Serial.println(count);                           
  attachInterrupt(0,countPulse,FALLING);
}

void radiationCalc()
    {
      unsigned long mnow = millis();
  if (nextPrint <= mnow)
    {
  cpm = count*24;
  rpm = cpm*1.353e-8;
  rpm = rpm*1000000.0;
  Serial.print("# Micro-rads Per Minute = ");
  Serial.println(rpm);
  //Serial.print("# Counts Per Minute = ");
  //Serial.println(cpm);
  count = 0;
  nextPrint = mnow + DELAY_TIME;
    }  
}


void relayControl(char cmd)
    {
      if (cmd == '1')
        {
            digitalWrite(MOTOR_ENABLE_PIN, HIGH);
            Serial.println("# Servo-power on.");
        }
      
      else
          {
              digitalWrite(MOTOR_ENABLE_PIN, LOW);
              Serial.println("# Servo-power off.");
          }  
    }
