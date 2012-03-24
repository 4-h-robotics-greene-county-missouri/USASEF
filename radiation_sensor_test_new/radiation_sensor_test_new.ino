/*
 *  ------Geiger Tube board (Arduino Code) Example--------
 *
 *  Explanation: This example shows how to get the signal from the Geiger Tube
 *  in Arduino, we use one of the Arduino interrupt pins (PIN2).
 *  We count the time (ms) between two pulses of the Geiger tube.
 *
 *  Copyright (C) 2011 Libelium Comunicaciones Distribuidas S.L.
 *  http://www.libelium.com
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 * 
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Version:		0.3
 *  Design:		Marcos Yarza, David Gascon
 *  Implementation:	Marcos Yarza
 */

// Threshold values for the led bar
#define TH1 45
#define TH2 95
#define TH3 200
#define TH4 400
#define TH5 600

// Conversion factor - CPM to uSV/h
#define CONV_FACTOR 0.00812

// Variables
int ledArray [] = {3,4,5,6,7};
int geiger_input = 2;
long count = 0;
long countPerMinute = 0;
long timePrevious = 0;
long timePreviousMeassure = 0;
long time = 0;
long countPrevious = 0;
float radiationValue = 0.0;

void setup(){
  pinMode(geiger_input, INPUT);
  digitalWrite(geiger_input,HIGH);
  for (int i=0;i<5;i++){
    pinMode(ledArray[i],OUTPUT);
  }

  Serial.begin(19200);

  attachInterrupt(0,countPulse,FALLING);

}

void loop(){
  if (millis()-timePreviousMeassure > 1000){
    countPerMinute = 60*count;
    radiationValue = countPerMinute * CONV_FACTOR;
    timePreviousMeassure = millis();
    Serial.print("cpm = "); 
    Serial.print(countPerMinute,DEC);
    Serial.print(" - ");
    Serial.print("uSv/h = ");
    Serial.println(radiationValue,4);      

    //led var setting  
    if(countPerMinute <= TH1) ledVar(0);
    if((countPerMinute <= TH2)&&(countPerMinute>TH1)) ledVar(1);
    if((countPerMinute <= TH3)&&(countPerMinute>TH2)) ledVar(2);
    if((countPerMinute <= TH4)&&(countPerMinute>TH3)) ledVar(3);
    if((countPerMinute <= TH5)&&(countPerMinute>TH4)) ledVar(4);
    if(countPerMinute>TH5) ledVar(5);

    count = 0;

  }

}

void countPulse(){
  detachInterrupt(0);
  count++;
  while(digitalRead(2)==0){
  }
  Serial.println(count);  
  attachInterrupt(0,countPulse,FALLING);
}

void ledVar(int value){
  if (value > 0){
    for(int i=0;i<=value;i++){
      digitalWrite(ledArray[i],HIGH);
    }
    for(int i=5;i>value;i--){
      digitalWrite(ledArray[i],LOW);
    }
  }
  else {
    for(int i=5;i>=0;i--){
      digitalWrite(ledArray[i],LOW);
    }
  }
}


























