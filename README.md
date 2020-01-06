# RaspberryNewRemoteSwitch



It is a modified version of NewRemoteSwitch by Randy Simons [http://randysimons.nl](http://randysimons.nl/)
```
It is modified so it can be run on RaspberryPi!
License: GPLv3. See ./NewRemoteSwitch/license.txt
```
## How to use it
You will need WiringPi to make it work  
Execute the following command  
`sudo apt-get install wiringpi`

## How to compile examples
`g++ -o output_example ex_show_received_code.cpp -I/usr/local/include -L/usr/local/lib -lwiringPi`  
The same thing for `ex_light_show.cpp`, just change the name in the command to the selected example name.