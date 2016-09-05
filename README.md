# Setup

- copy libraries in 'arduino_libraries' folder into your 'sketchbook/libraries' folder

- load 'non-latching.ino' code onto Feather 32u4 with 'Non-Latching Relay' shield soldered

- connect 'Signal' pin to pin defined by 'arduinoRELAY' variable in 'non-latching.ino'

# Usage

- firmware defaults to relay=on when microcontroller is powered on
- 'ON' -- turn relay on
- 'OFF' -- turn relay off
- 'SLEEP waitSeconds sleepSeconds', where waitSeconds = integer number of seconds to wait before turning relay off, and sleepSeconds = integer number of seconds to keep relay off before turning it back on again

# Python script

``` bash
sudo python ./sleep.py -d /dev/ttyACM0 -r 9600 -w 10 -s 100
```

 
