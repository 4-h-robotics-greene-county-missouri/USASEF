

#include <Servo.h>

#define SWITCH_PIN 3

#define MOTOR_ENABLE_PIN 4

#define LEFTSERVOPIN 10
#define RIGHTSERVOPIN 9

#define MOTOR_VOLTAGE_PIN A0
#define LOGIC_VOLTAGE_PIN A1

#define ULTRASONIC_PIN A2

#define VREF 4.98
#define SENSOR_MAX 1024

Servo leftServo;
Servo rightServo;

void serbSetup(){
  pinMode(LEFTSERVOPIN, OUTPUT); //sets the left servo signal pin
                                     //to output
  pinMode(RIGHTSERVOPIN, OUTPUT); //sets the right servo signal pin
                                     //to output
  leftServo.attach(LEFTSERVOPIN); //attaches left servo
  leftServo.write(0);
  rightServo.attach(RIGHTSERVOPIN); //attaches right servo
  rightServo.write(0);
}

void setup() 
    {
        Serial.begin(57600);
        Serial.println("motor control board test");
        serbSetup();
        pinMode(MOTOR_ENABLE_PIN,OUTPUT);
        digitalWrite(MOTOR_ENABLE_PIN, LOW);

        pinMode(SWITCH_PIN,INPUT);
        pinMode(MOTOR_VOLTAGE_PIN, INPUT);
        pinMode(LOGIC_VOLTAGE_PIN, INPUT);
        pinMode(ULTRASONIC_PIN, INPUT);
        
    }

void loop()
    {
        digitalWrite(MOTOR_ENABLE_PIN, HIGH);
        delay(3000);
        digitalWrite(MOTOR_ENABLE_PIN, LOW);
        delay(3000);

/* leftServo.write(15);
 rightServo.write(15);
 delay(1000);
 leftServo.write(0);
 rightServo.write(0);
*/
      readVoltage("motor", MOTOR_VOLTAGE_PIN);
      readVoltage("logic", LOGIC_VOLTAGE_PIN);

    }
    
float readVoltage(String label, int pin)
{
  int sensorValue = analogRead(pin);    
  float voltage = ((sensorValue * VREF) / SENSOR_MAX) * 2.0;
  //float voltage = map(sensorValue, 0, 1024, 0, 10.0);
  
  Serial.print(label);
  Serial.print("=");
  Serial.print(sensorValue);
  Serial.print(" V=");
  Serial.println(voltage);
  return voltage;
}  
  


