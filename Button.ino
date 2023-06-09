/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int current_sensorState = 0;         // variable for reading the pushbutton status
int previous_sensorState = 0;
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  current_sensorState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (current_sensorState == HIGH and previous_sensorState == LOW) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    Serial.write(1);
    previous_sensorState = 1;
  }
  else if (current_sensorState == LOW and previous_sensorState == HIGH){
    // turn LED off:
    digitalWrite(ledPin, LOW);
    Serial.print(0);
   previous_sensorState = 0;
  }
  else {
    digitalWrite(ledPin, LOW);
    Serial.write(1);
  }
  //Serial.println();
  delay(10);
}
