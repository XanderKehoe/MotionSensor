/*  
    Arduino with PIR motion sensor
    For complete project details, visit: http://RandomNerdTutorials.com/pirsensor
    Modified by Rui Santos based on PIR sensor by Limor Fried
*/

#include <SoftwareSerial.h>

SoftwareSerial hc06(3,4);
 
int led = 13;                // the pin that the LED is atteched to
int motion_sensor = 2;       // the pin that the motion sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the motion sensor status (value)

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(motion_sensor, INPUT);    // initialize motion sensor as an input
  Serial.begin(9600);        // initialize serial
  hc06.begin(9600);         //initialize bluetooth module
}

void loop(){
  val = digitalRead(motion_sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    
    if (state == LOW) {
      //Serial.println("Motion detected!");
      hc06.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
      hc06.write(1);
    }

    delay(100);                // delay 100 milliseconds 
  } 
  else {
      if (state == HIGH){
        //Serial.println("Motion stopped!");
        hc06.println("Motion stopped!");
        digitalWrite(led, LOW); // turn LED OFF
        state = LOW;       // update variable state to LOW
    }
    delay(200);             // delay 200 milliseconds 
  }
}
