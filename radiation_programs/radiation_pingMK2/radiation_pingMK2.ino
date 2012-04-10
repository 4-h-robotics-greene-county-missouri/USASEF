/*
 *  ------Geiger Tube board (Arduino Code) Example--------
 *
 *  Explanation: This example shows how to get the signal from the Geiger Tube
 *  in Arduino, we use one of the Arduino interrupt pins (PIN2).
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


// Conversion factor - CPM to uSV/h
#define CONV_FACTOR 0.00812

// Variables
int geiger_input = 2;
int cpm = 0;
volatile long count = 0;

void setup(){
  pinMode(geiger_input, INPUT);
  digitalWrite(geiger_input,HIGH);

  Serial.begin(19200);

  attachInterrupt(0,countPulse,FALLING);

}

void loop(){
  count = 0;
  delay(2500);              // wait for 2.5 seconds
  cpm = count*24;
  Serial.print("Counts Per Minute = ");
  Serial.println(cpm);
  count = 0;
  }

                           

void countPulse(){
  detachInterrupt(0);
  count++;
  while(digitalRead(2)==0){
  }
  //Serial.println(count);                           
  attachInterrupt(0,countPulse,FALLING);
}



























