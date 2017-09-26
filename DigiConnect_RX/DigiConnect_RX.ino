// Receiving end for the DigiConnect Cable

#include <SoftSerial_INT0.h>
#include "DigiKeyboard.h"

int DIGICONNECT_TX   = 1;
int DIGICONNECT_RX   = 2;
int DIGICONNECT_BAUD = 19200;
bool TRANSMITTING    = false;
String HEAD = "<html><head><script>function r(){l=document.createElement('a');l.setAttribute('id','i');l.download='file';l.href='data:application/octet-stream;charset=utf-8;base64,"
String TAIL = ";document.body.appendChild(l);i=document.getElementById('i');i.click();i.remove()}</script></head><body><button onclick='r()'>Get File</button></body></html>"


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

void head() {
  
}


