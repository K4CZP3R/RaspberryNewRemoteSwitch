#include "NewRemoteTransmitter.cpp"
#include "NewRemoteReceiver.cpp"

//piHiPri is here for interrupts() and noInterrupts()
//99 means critical (noInterrupts())
//0 means other code (interrupts())

int main(int argc, char **argv)
  // See example ShowReceivedCode for info on this
  NewRemoteReceiver::init(5, 2, retransmitter);
  while(true){}
}

void retransmitter(NewRemoteCode receivedCode) {
  // Disable the receiver; otherwise it might pick up the retransmit as well.
  NewRemoteReceiver::disable();

  // Need interrupts for delay()
  piHiPri(0);
  
  // Wait 5 seconds before sending.
  delay(5000);

  // Create a new transmitter with the received address and period, use digital pin 11 as output pin

  NewRemoteTransmitter transmitter(receivedCode.address, 11, receivedCode.period);

  if (receivedCode.switchType == NewRemoteCode::dim || 
    (receivedCode.switchType == NewRemoteCode::on && receivedCode.dimLevelPresent)) {
    // Dimmer signal received

    if (receivedCode.groupBit) {
      transmitter.sendGroupDim(receivedCode.dimLevel);
    } 
    else {
      transmitter.sendDim(receivedCode.unit, receivedCode.dimLevel);
    }
  } 
  else {
    // On/Off signal received
    bool isOn = receivedCode.switchType == NewRemoteCode::on;

    if (receivedCode.groupBit) {
      // Send to the group
      transmitter.sendGroup(isOn);
    } 
    else {
      // Send to a single unit
      transmitter.sendUnit(receivedCode.unit, isOn);
    }
  }

  NewRemoteReceiver::enable();
}