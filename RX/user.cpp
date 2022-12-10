#include "Arduino.h"
#include <Arduino_FreeRTOS.h>
#include "user.h"
#include "SPI.h"
#include <nRF24L01.h>
#include <RF24.h>


int pesan[1];
RF24 radio(9,10); //pin yang dideklarasikan untuk chip enable, chip selector
const uint64_t pipe = 0xE8E8F0F0E1LL;
int LED = 2; //nama alias untuk pin.2 yaitu LED

void user_init(void){
    xTaskCreate(Task01, "Task01", 64, NULL, 1, NULL);
    xTaskCreate(Task02, "Task02", 64, NULL, 1, NULL);
}

void Task01(void *pvParameters){
  (void) pvParameters;
  Serial.begin(9600); //menggunakan serial monitor pada 9600bps
   radio.begin(); //instruksi prosedur mulai pembacaan module
   radio.openReadingPipe(1,pipe);
   radio.startListening();
  for(;;){
    if (radio.available()){ //jika terbaca data di module
        radio.read(pesan, 1); 
        Serial.println(pesan[0]); //menuliskan informasi di serial monitor
        if (pesan[0] == 111){
         delay(10);digitalWrite(LED, HIGH);
        } //jika sesuai data, maka LED akan menyala
         else {
           digitalWrite(LED, LOW);
        }
        vTaskDelay( 10 / portTICK_PERIOD_MS );
      } //nilai tunda 10 ms untuk pembacaan data berikutnya
    else{
      Serial.println("No radio available");
    }
    vTaskDelay( 200 / portTICK_PERIOD_MS );
  }
}
void Task02(void *pvParameters){
  (void) pvParameters;

  for(;;){
    vTaskDelay( 200 / portTICK_PERIOD_MS );
  }
}
