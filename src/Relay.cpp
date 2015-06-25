/**
 * Relay library
 *
 * @author sekdiy
 * @date 18.06.2015
 * @version 1
 */
 
// Compatibility with the Arduino 1.0 library standard
#if defined(ARDUINO) && ARDUINO >= 100  
#include "Arduino.h"  
#else  
#include "WProgram.h"   
#endif

#include "Relay.h"

/**
 * Relay constructor
 *
 * default: active low, off
 *
 * @version 1
 */
Relay::Relay(int pin, int state, int mode)
{
  this->_mode = mode;              // assign mode
  this->_pin = pin;                // assign pin number
  pinMode(pin, OUTPUT);      // set mode to output

  setState(HIGH == state ? HIGH : LOW); // set and update relay state
}

/*
 * Turn relay on
 *
 * @version 1
 */
void Relay::on(void) 
{
  setState(HIGH);
}

/*
 * Turn relay off
 *
 * @version 1
 */
void Relay::off(void)
{
  setState(LOW);
}

/*
 * Toggle relay state
 *
 * @version 1
 */
void Relay::toggle(void)
{
  setState(1 ^ getState());
}

/*
 * Get relay state (LOW/HIGH)
 *
 * @version 1
 * @return int
 */
int Relay::getState(void)
{
  return this->_state;
}

/*
 * Set relay state (LOW/HIGH)
 *
 * @version 1
 */
void Relay::setState(int state) {
  this->_state = state;
  digitalWrite(this->_pin, (this->_mode ? this->_state : !this->_state)); 
}

/*
 * Returns TRUE iff the relay is on
 *
 * @version 1
 */
boolean Relay::isOn(void)
{
  return (HIGH == getState());
}

/*
 * Returns TRUE iff the relay is off
 *
 * @version 1
 */
boolean Relay::isOff(void)
{
  return (LOW == getState());
}

