# Setup

- copy libraries in 'arduino_libraries' folder into your 'sketchbook/libraries' folder
- load 'non-latching.ino' code onto Feather 32u4 with 'Non-Latching Relay' shield soldered
- connect 'Signal' pin to pin defined by 'arduinoRELAY' variable in 'non-latching.ino'

# Usage

- **Note**: firmware defaults to relay=on when microcontroller is powered on
- Sending 'ON' via serial port turns relay on  
- Sending 'OFF' via serial port turns relay off  
- Sending 'SLEEP waitSeconds sleepSeconds' via serial port will wait for waitSeconds seconds then turn relay off for sleepSeconds seconds, then turn relay on.


# Example Python script 

To use 'sleep.py' to connect to the Feather on port /dev/ttyACMO at 9600 baud, wait for 10 seconds, then turn off the relay for 10 seconds before turning it back on again:


``` bash
sudo python ./sleep.py -d /dev/ttyACM0 -r 9600 -w 10 -s 100
```

 
