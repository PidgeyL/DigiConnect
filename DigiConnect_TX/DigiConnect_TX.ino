// Receiving end for the DigiConnect Cable

#include <SoftSerial_INT0.h>
#include <DigiCDC.h>

int DIGICONNECT_TX   = 1;
int DIGICONNECT_RX   = 2;
int DIGICONNECT_BAUD = 19200;


SoftSerial digiconnect(DIGICONNECT_RX, DIGICONNECT_TX);

void setup() {
  pinMode(0, OUTPUT);

  digiconnect.begin(DIGICONNECT_BAUD);
  SerialUSB.begin();

  digitalWrite(0, HIGH);
}

void loop() {
  SerialUSB.refresh();
  if( SerialUSB.available() ){
    int data = SerialUSB.read();
    digiconnect.write(data);
  }
}
