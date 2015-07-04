/**
 * Relay library
 *
 * A no-frills, easy to use Arduino relay library for shields or modules.
 *
 * @author sekdiy (https://github.com/sekdiy/Relay)
 * @date 4.07.2015
 * @version See git comments for changes.
 */

#ifndef RELAY_H
#define RELAY_H

// Compatibility with the Arduino 1.0 library standard
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Relay
{
  public:
    static const unsigned int ON = 1;      //!< Relay state: on.
    static const unsigned int OFF = 0;     //!< Relay state: off.

    Relay(unsigned int pin = LED_BUILTIN,  //!< Arduino pin that the Relay is connected to (default: pin 13, usually the built-in LED)
          unsigned int state = OFF,        //!< Initial state (default: off).
          unsigned int mode = HIGH         //!< Logic mode (default: high-active, i.e. high level means on).
         );                                //!< Initializes instance attributes, making sure the relay is in a sensible default state.

    void on();                             //!< Turns the relay on.
    void off();                            //!< Turns the relay off.
    void toggle();                         //!< Toggles the relay state.
    boolean isOn();                        //!< @return True iff the relay is on.
    boolean isOff();                       //!< @return True iff the relay is off.

    unsigned int getState();               //!< @return The current relay state (Relay::OFF or Relay::ON).
    void setState(unsigned int state       //!< The new state to switch to (Relay::OFF or Relay::ON).
                 );                        //!< Sets a relay state.

  protected:
    unsigned int _mode;                    //!< control mode (noninverted/inverted)
    unsigned int _state;                   //!< state model
    unsigned int _pin;                     //!< pin model
};

#endif   // RELAY_H

