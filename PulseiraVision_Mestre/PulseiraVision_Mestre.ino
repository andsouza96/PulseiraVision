
//kkkkkkkkkkkkkkkkkkkkkkkkkk

#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>
#include <AltSoftSerial.h>

AltSoftSerial BTserial;

File myFile;

const int rxpin = 7;
const int txpin = 8;
SoftwareSerial bluetooth(rxpin, txpin);

void setup(){

//    /*****************armazena em uma variável o valor de leitura do arquivo txt************/
//    myFile = SD.open("test.txt");
//  if (myFile) {
//    Serial.println("test.txt:");
//
//    // read from the file until there's nothing else in it:
//    while (myFile.available()) {
//      Serial.write(myFile.read());
//    }
//    // close the file:
//    myFile.close();
//  } else {
//    // if the file didn't open, print an error:
//    Serial.println("error opening test.txt");
//  }
}

void loop(){

  //laço de conectividade (deseja-se que dentro de loop monitore dispositivos nas proximidades a cada x segundos)
    Serial.begin(9600);
  bluetooth.begin(9600); // inicializa a porta serial
  Serial.println("Serial ready");
  bluetooth.println("Bluetooth ready");
  BTSerial.print ( "AT + ROLE1" ) ; //Configura para modo Mestre
  delay(1000);
  BTSerial.print ( "AT + IMME1" ); //Configura para conectar manualmente
  delay(1000);
  /*****************lê os dispositivos da proximidade************/
  BTSerial.print ( "AT + DISC?" ); 
  delay(1000);  
  /*****************conectar ao dispositivo mais próximo************/
  BTSerial.print ( "AT + CONN0" ); 
  delay(1000);  

  
  if (bluetooth.available()){
    char c = (char)bluetooth.read(); //leitura do dispositivo conectado
    Serial.write(c);                 //exibir o que foi recebido
    
    /*****************comparar se o deficiente quer saber o nome da loja************/
//    if((char)bluetooth.read() == sim){
//      //enviar o arquivo de audio;
//     bluetooth.write(a);           
//    }
  }
  
  if (Serial.available()) {
    char c = (char)Serial.read(); //leitura do que foi digitado
    bluetooth.write(c);           //envio do que foi digitado
  }


  
} //end loop
