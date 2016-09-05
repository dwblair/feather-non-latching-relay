# Setup

- copy libraries in 'arduino_libraries' folder into your 'sketchbook/libraries' folder

- load 'non-latching.ino' code onto Feather 32u4 with 'Non-Latching Relay' shield soldered

- connect 'Signal' pin to pin defined by 'arduinoRELAY' variable in 'non-latching.ino'

# Usage

- **Note**: firmware defaults to relay=on when microcontroller is powered on
- Sending 'ON' via serial port turns relay on  
- Sending 'OFF' via serial port turns relay off  
- Sending 'SLEEP waitSeconds sleepSeconds' via serial port will first wait for waitSeconds seconds, then turn relay off for sleepSeconds seconds, then turn relay on.


# Example Python script 

To use 'sleep.py':

``` bash
sudo python ./sleep.py -d /dev/ttyACM0 -r 9600 -w 10 -s 100
```

 
