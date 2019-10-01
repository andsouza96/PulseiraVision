#include <SoftwareSerial.h>

const int rxpin = 2;
const int txpin = 3;
SoftwareSerial bluetooth(rxpin, txpin);

void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600); // initialize the software serial port
  //bluetooth.begin(38400);
  Serial.println("Serial ready");
  bluetooth.println("Bluetooth ready");
}

void loop(){
  if (bluetooth.available()){
    char c = (char)bluetooth.read();
    Serial.write(c);
    //bluetooth.print("10");
  }
  if (Serial.available()) {
    char c = (char)Serial.read();
    bluetooth.write(c);
   // bluetooth.print("10");
  }
}
