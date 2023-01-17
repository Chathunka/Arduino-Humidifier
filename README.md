  # Humidifier

  Library for generating ultrahigh frequencies
  for liquid atomization using AVR microcontrollers.
  Created by Chathunka J. Tennakoon (CJT), November 2, 2020.
  Released into the public domain.

  Most AVR microcontrollers have Timer units and they can be used to generate
  square waves with specific frequency and duty cycle.Here we have used the timer 1 of the microcontroller
  to generate the required signals.

  For atmega328p use either pin 9 or 10 for getting the signal.

  By generating the specific wave from the microcontroller,
  users will be able to generate high voltage signals required for atomizing liquid particles
  with minimum external circuitaries.

  With a proper capacitor inductor tank circuit (F resonant = 1/(2π√LC)), high voltage signals
  required for piezoelectric transducers to atomize liquid can be obtained.
 
  If you want to know what pins of the microcontroller are used for timer1,
  check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products
