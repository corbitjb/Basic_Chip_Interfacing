#include <CapacitiveSensor.h>

/* 
 * Adapted from: CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil

int led = 7; // declare pin 7 as the LED control
int threshold = 8000; // adjust depeding on resistor value and electrode size/type

void setup()                    
{
   cs_4_6.set_CS_AutocaL_Millis(0xFFFFFFFF);  // turn off autocalibration, as an example
   pinMode(led,OUTPUT);
   Serial.begin(9600);
}

void loop()                    
{
    //long start = millis();
    long a =  cs_4_6.capacitiveSensor(30);
    Serial.println(a);

    if(a > threshold){
      digitalWrite(led,HIGH);
    }
    else{
      digitalWrite(led,LOW);
    }
    delay(50);                             // arbitrary delay to limit data to serial port 
}
