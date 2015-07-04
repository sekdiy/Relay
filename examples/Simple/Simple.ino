#include <Relay.h>  // https://github.com/sekdiy/Relay

// create a regular relay on pin 13
Relay Lamp = Relay();

void setup() {
  // set up serial communication
  Serial.begin(9600);
}

void loop() {
  // flip around
  Lamp.toggle();

  // tell the current state
  Serial.print("The lamp is ");
  Serial.println(Lamp.isOn() ? "on." : "off.");

  // wait a sec
  delay(1000);
}
