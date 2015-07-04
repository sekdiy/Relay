#include <Relay.h>     // https://github.com/sekdiy/Relay

// create a couple of Relay instances
Relay Speaker = Relay(1);
Relay Lamp    = Relay(2);
Relay Heater  = Relay(3);
Relay Fan     = Relay(4);

void setup() {
  // set the mood
  Speaker.on();
}

void loop() {
  // trigger some madness
  Lamp.toggle();

  if (Lamp.isOn()) {
    Heater.toggle();
  } else {
    Fan.setState(Heater.getState());
  }

  // never switch a relay at high rates!
  delay(1000);
}
