#include "Arduino.h"
#include "SPI.h"
#include <nRF24L01.h>
#include <RF24.h>
#include "nrf24.h"


extern char pesan[4];
int data;
RF24 radio(7,8); //pin yang dideklarasikan untuk chip enable, chip selector


void nrf24_startRX(){
 radio.begin(); //instruksi prosedur mulai pembacaan module
 radio.openReadingPipe(0,pipe);
 radio.setPALevel(RF24_PA_MAX);
 radio.setDataRate(RF24_250KBPS);
 radio.startListening(); 
}


void nrf24_startTX(){
  radio.begin(); //instruksi memulai prosedur pembacaan module
  radio.openWritingPipe(pipe);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
}

void nrf24_Receive(){

      if (radio.available()){ //jika terbaca data di module
        radio.read(&pesan, sizeof(pesan)); 
        Serial.println(pesan);
      }   
    else{
      Serial.println("No radio available");
    }
}

void nrf24_Transmite(int data){
      radio.write(&data, 1);
}
