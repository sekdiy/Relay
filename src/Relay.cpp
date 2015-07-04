/*
 * Relay library
 *
 * Author: sekdiy (https://github.com/sekdiy/Relay)
 */

// Compatibility with the Arduino 1.0 library standard
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Relay.h"

Relay::Relay(unsigned int pin, unsigned int state, unsigned int mode) :
  _pin(pin),                                                       //!< store pin number
  _mode(HIGH == mode ? HIGH : LOW)                                 //!< store logic mode (high- or low-active)
{
  pinMode(pin, OUTPUT);                                            //!< set port pin to be an output
  this->setState(state);                                           //!< set state
}

void Relay::on(void)
{
  this->setState(ON);                                              //!< explicitly set to ON
}

void Relay::off(void)
{
  this->setState(OFF);                                             //!< explicitly set to OFF
}

void Relay::toggle(void)
{
  this->setState(HIGH ^ this->_state);                             //!< invert the state
}

unsigned int Relay::getState(void)
{
  return this->_state;                                             //!< get stored state
}

void Relay::setState(unsigned int state)
{
  if (this->_state != state) {                                     //!< check for actual state change
    this->_state = (OFF == state ? OFF : ON);                      //!< store new state, explicitly 'casting' to ON or OFF
    digitalWrite(this->_pin, (HIGH ^ this->_mode) ^ this->_state); //!< apply logic mode and set pin state
  }
}

boolean Relay::isOn(void)
{
  return (ON == this->getState());                                 //!< is the state ON?
}

boolean Relay::isOff(void)
{
  return (OFF == this->getState());                                //!< is the state OFF?
}

