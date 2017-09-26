// Receiving end for the DigiConnect Cable

#include <SoftSerial_INT0.h>
#include "DigiKeyboard.h"

int DIGICONNECT_TX   = 1;
int DIGICONNECT_RX   = 2;
int DIGICONNECT_BAUD = 19200;


SoftSerial digiconnect(DIGICONNECT_RX, DIGICONNECT_TX);

void setup() {
  pinMode(0, OUTPUT);

  digiconnect.begin(DIGICONNECT_BAUD);

  DigiKeyboard.delay(2000); // Wait 2 sec to let the system fully boot
  DigiKeyboard.sendKeyStroke(0);

  digitalWrite(0, HIGH);
}

void loop() {
  if( digiconnect.available() ){
    char data = digiconnect.read();
    DigiKeyboard.print(data);
  }
}
