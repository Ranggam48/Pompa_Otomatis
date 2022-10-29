#include "Arduino.h"
#include <Arduino_FreeRTOS.h>
#include "user.h"
#include "ultrasonic.h"

float distance;


// inisialisasi task untuk RTOS
void user_init(void){
  
  xTaskCreate(TaskMenu, "Menu", 64, NULL, 1, NULL);
  xTaskCreate(TaskNRF, "NRF", 64, NULL, 1, NULL);
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

  for(;;){
    vTaskDelay( 200 / portTICK_PERIOD_MS );
  }
}


//task untuk pembacaan sensor
void TaskSensor(void *pvParameters){
  (void) pvParameters;
  
  for(;;){
    distance = getDistance();
    Serial.println(distance);
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
  }
}
