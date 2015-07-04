# Relay

## Purpose ##

**Relay** is an Arduino library that provides easy, no-frills access to relays.

Actually, what it does is providing an abstraction from handling digital output port pins yourself. It just so happens that switching a load is a widespread use case. ;)

## Simple Example ##

Using a **Relay** is really straightforward:

```c++
void loop() {
  // flip around
  Lamp.toggle();

  // tell the current state
  Serial.print("The lamp is ");
  Serial.println(Lamp.isOn() ? "on." : "off.");

  // wait a sec
  delay(1000);
}
```

In the above example, a **Relay** object `Lamp` is assumed.
This `Lamp` is toggled every second. Additionally the current state is printed, according to the internal state of the `Lamp` object.

See the [**Simple**](examples/Simple/Simple.ino) example (included with this library) for the complete code.

## Multiple Relays Example ##

You can of course use multiple relays (connected to their respective pins):

```c++
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
```

Relay modules with up to eight channels are very affordable.

Take a look at the [**RelayModule**](examples/RelayModule/RelayModule.ino) example for more.

## Installation ##

Just check out the [**Relay**](https://github.com/sekdiy/Relay) Repository on GitHub (or download the ZIP archive) and copy it to your `libraries/` folder (usually within your Arduino sketchbook).

After (re)launching the Arduino IDE, **Relay** will appear in your Sketchbook/Examples menu.

Alternatively, you can use Arduino's `Add .ZIP Library...` menu option.

## Documentation ##

For further documentation please take a look at the examples and into the source code .

The files [Relay.h](src/Relay.h) and [Relay.cpp](src/Relay.cpp) are documented and contain additional clues that may help to understand the functionality.
