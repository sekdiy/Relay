/**
 * Relay library
 *
 * @author sekdiy
 * @date 18.06.2015
 * @version 1
 */

#ifndef RELAY_H
#define RELAY_H

// Compatibility with the Arduino 1.0 library standard
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/**
 * Relay
 *
 * @version 1
 */
class Relay
{
  public:
    Relay(int pin = LED_BUILTIN, int state = LOW, int mode = LOW); // Constructor

    void on();                    // Turn relay on
    void off();                   // Turn relay off
    void toggle();                // Toggle relay state
    int getState();               // Get relay state (LOW/HIGH)
    boolean isOn();               // Returns TRUE iff the relay is on
    boolean isOff();              // Returns TRUE iff the relay is off

  protected:
    int _mode;                    // control mode (noninverted/inverted)
    int _state;                   // state model
    int _pin;                     // pin model
    void setState(int state);     // Set relay state (LOW/HIGH)
};

#endif   // RELAY_H

