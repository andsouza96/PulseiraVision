#include <SoftwareSerial.h>

const int rxpin = 2;
const int txpin = 3;

int botao_liga = 9;
int botao_desliga = 8;
int led_liga = 7;
int led_desliga = 6;
int led_recebe = 5;

int estado_botao_liga = 0;
int estado_botao_desliga = 0;

SoftwareSerial bluetooth(rxpin, txpin);

void setup() {
  pinMode(botao_liga, INPUT);
  pinMode(botao_desliga, INPUT);
  pinMode(led_liga, OUTPUT);
  pinMode(led_desliga, OUTPUT);
  pinMode(led_recebe, OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Serial ready");
  bluetooth.print("AT+ROLE0");
  bluetooth.print("AT+IMME0");
}

void loop() {
  digitalWrite(led_recebe, LOW);
  while (bluetooth.available()) {

    //  char c = (char)bluetooth.read();
    String teste[10];
    int i = 1;
    for (i; i < 10; i++) {
      
    //  Serial.println(sizeof(bluetooth.available())); //tamanho do byte recebido (cada char)
      digitalWrite(led_recebe, HIGH);
      delay(1000);
      char c = bluetooth.read();
      bluetooth.print(c);
      Serial.println(c);
     
      teste[i] = teste[i] + c;    //armazenando cada char em um vetor
    }
    for (int a =0; a < 10; a++) {
      Serial.print(teste[a]); // imprime na tela o vetor
    }

    estado_botao_liga = digitalRead(botao_liga);
    if (estado_botao_liga == HIGH) {
      digitalWrite(led_liga, HIGH);
    }
    else if (estado_botao_liga == LOW) {
      digitalWrite(led_liga, LOW);
    }
    //        char c = (char)bluetooth.read();
    //      Serial.write(c);
    bluetooth.print("10");
  }
}
