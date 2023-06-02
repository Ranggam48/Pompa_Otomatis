#include "Arduino.h"
#include <Arduino_FreeRTOS.h>
#include "user.h"
#include "ultrasonic.h"
#include "nrf24.h"

uint16_t  distance;
char buffTX[4];

// inisialisasi task untuk RTOS
void user_init(void){
  
  xTaskCreate(TaskMenu, "Menu", 64, NULL, 1, NULL);
  xTaskCreate(TaskNRF, "NRF", 128, NULL, 1, NULL);
  xTaskCreate(TaskSensor, "Sensor", 64, NULL, 1, NULL);
  
}



// task untuk membuat tampilan menu
void TaskMenu(void *pvParameters){
  (void) pvParameters;

  for(;;){
    vTaskDelay( 200 / portTICK_PERIOD_MS );
  }
}

// task untuk komunikasi NRF
void TaskNRF(void *pvParameters){
  (void) pvParameters;
  
  nrf24_startTX();
  Serial.begin(9600);
  
  for(;;){
    //sprintf(buffTX, "%d", distance);
    nrf24_Transmite(distance);
    Serial.println("distance=");
    Serial.print(distance);
    Serial.println("cm");
//    Serial.print(buffTX);
//    Serial.println("cm");
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
  }
}


//task untuk pembacaan sensor
void TaskSensor(void *pvParameters){
  (void) pvParameters;

  start_read();
  
  for(;;){    
    distance = getDistance();
    vTaskDelay( 100 / portTICK_PERIOD_MS );
  }
}
