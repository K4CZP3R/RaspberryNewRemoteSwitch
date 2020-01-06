/*
* Demo for the RF transmitter
* Connect the transmitter to pin WiringPi=4, BCM=23, Header=16
*/

#include <iostream>
#include "NewRemoteTransmitter.cpp"



int main(int argc, char **argv)
{
    NewRemoteTransmitter transmitter(123, 4);

    // Switch unit 1 on
    transmitter.sendUnit(1, true);

    // Switch all devices in the group off
    transmitter.sendGroup(false);

    // Set unit 1 to dim-level 3 (range 0-15)
    transmitter.sendDim(1, 3);
}