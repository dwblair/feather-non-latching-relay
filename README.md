# Overview

'non-latching.ino' is Arduino IDE code for the [Adafruit Feather 32u4](https://www.adafruit.com/product/2771) + [Non-Latching Relay FeatherWing](https://www.adafruit.com/product/2895). 'non-latching.ino' allows for control of a relay via commands sent to the Feather over USB Serial.

The included demo Python script demonstrates interacting with the Feather via the command line.

# Requirements

'non-latching.ino' requires the 'Arduino-SerialCommand' library (included in this repository)

The 'Signal' pin on Non-Latching Relay Featherwing must be connected to a digital pin on the Feather (the pin # can be set in the code; default: pin #6).

# Setup

1. Copy libraries in 'arduino_libraries' folder into your 'sketchbook/libraries' folder
2. Load 'non-latching.ino' code onto Feather 32u4 with 'Non-Latching Relay' shield soldered
3. Connect 'Signal' pin to pin defined by 'arduinoRELAY' variable in 'non-latching.ino'

# Control via Serial Port 

(**Note**: firmware defaults to relay=on when microcontroller is powered on.)

- Sending **ON** via serial port turns relay on  
- Sending **OFF** via serial port turns relay off  
- Sending **SLEEP waitSeconds sleepSeconds** via serial port will 1) wait for waitSeconds seconds; then 2) turn relay off for sleepSeconds seconds; then 3) turn relay on.


# Example Python script 

To use 'sleep.py' to connect to the Feather on port /dev/ttyACMO at 9600 baud, wait for 10 seconds, then turn off the relay for 10 seconds before turning it back on again:


``` bash
sudo python ./sleep.py -d /dev/ttyACM0 -r 9600 -w 10 -s 100
```

 
