/*
* Demo for the RF receiver.
* This example is for the new KaKu / Home Easy type of remotes!

* Connect the receiver to pin WiringPi=5, BCM=24, Header=18
*/
#include <iostream>
#include "NewRemoteReceiver.cpp"

#include <iostream>

std::ostream& bold_on(std::ostream& os)
{
    return os << "\e[1m";
}

std::ostream& bold_off(std::ostream& os)
{
    return os << "\e[0m";
}

void showCode(NewRemoteCode receivedCode)
{
    std::cout << "=== Code incoming" << std::endl;
    std::cout << "* Addr: " << bold_on << receivedCode.address << bold_off << std::endl;
    if(receivedCode.groupBit) {
        std::cout << "* Type: "<<bold_on<<"Group" <<bold_off<< std::endl;
    }
    else{
        std::cout << "* Type: "<<bold_on<<"Unit" <<bold_off<< std::endl;
        std::cout << "* Unit number: " <<bold_on<< (int)receivedCode.unit <<bold_off<< std::endl;
    }

    switch(receivedCode.switchType) {
        case NewRemoteCode::off:
            std::cout << "* State: "<<bold_on<<"off" <<bold_off<< std::endl;
            break;
        case NewRemoteCode::on:
            std::cout << "* State: "<<bold_on<<"on" <<bold_off<< std::endl;
            break;
        case NewRemoteCode::dim:
            std::cout << "* State: "<<bold_on<<"dim" <<bold_off<< std::endl;
            break;
    }

    if(receivedCode.dimLevelPresent) {
        std::cout << "* Dim level: " <<bold_on<< receivedCode.dimLevel<<bold_off << std::endl;
    }

    std::cout << "* Period: " <<bold_on<< receivedCode.period << "us." <<bold_off<< std::endl;
    std::cout << "=== End" << std::endl;
    
}
int main(int argc, char **argv)
{
    NewRemoteReceiver::init(5,2,showCode);
    while(true){}
}

