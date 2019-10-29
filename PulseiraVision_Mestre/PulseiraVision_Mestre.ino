#include <SoftwareSerial.h>
#include <PCM.h>

const int rxpin = 2;
const int txpin = 3;
SoftwareSerial bluetooth(rxpin, txpin);

const unsigned char sample[] PROGMEM = {};
int a;
int i;
int tamanhovetor;
char c ;




void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600); // initialize the software serial port
  //bluetooth.begin(38400);
  Serial.println("Serial ready");
  bluetooth.println("Bluetooth ready");
  //  startPlayback(sample,sizeof(sample));
  bluetooth.print("AT");
  delay(500);
  bluetooth.print("AT+ROLE1");
  delay(500);
  bluetooth.print("AT+IMME1");
  delay(500);
  bluetooth.print("AT+DISC?");
  delay(500);
  bluetooth.print("AT+CONN0");
  delay(500);  
  bluetooth.flush();
}

void tocar( char c, int d ) {
  startPlayback(c, d);
}

void loop() {


  bluetooth.print('a'); //envia um sinal identificando que está pronto para receber O TAMANHO DO VETOR
  
  //*******************recebe o tamanho do vetor**********
  if (bluetooth.available()) {
    c = bluetooth.read(); //recebe um char no bluetooth
    //bluetooth.print(c);
    tamanhovetor = c;
    //delay(400);
    Serial.print(tamanhovetor);
  }

  bluetooth.print('y'); //envia um sinal identificando que está pronto para receber O VETOR

    //*******************recebe o vetor**********
  if (bluetooth.available()) {
    c = bluetooth.read();
    tocar(c, sizeof(c));
  }

  ////      sample[i] = teste[i] + c;    //armazenando cada char em um vetor
  //    }
  //    for (int a =0; a < tamanhovetor; a++) {
  //      tocar(c,d);
  //      //Serial.print(teste[a]); // imprime na tela o vetor
  //    }
  //} //end bluetooth available


    if (bluetooth.available()){
      char c = (char)bluetooth.read();
      Serial.write(c); //leitura do que está recebendo
  
    }

}
