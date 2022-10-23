#include <Arduino_FreeRTOS.h>
#include "user.h"
#include "ultrasonic.h"
float distance;

void user_init(void){
  
  xTaskCreate(TaskMenu, "Menu", 64, NULL, 1, NULL);
  xTaskCreate(TaskNRF, "NRF", 64, NULL, 1, NULL);
  xTaskCreate(TaskSensor, "Sensor", 64, NULL, 1, NULL);
  
}




void TaskMenu(void *pvParameters){
  (void) pvParameters;

  for(;;){
    vTaskDelay( 200 / portTICK_PERIOD_MS );
  }
}

void TaskNRF(void *pvParameters){
  (void) pvParameters;

  for(;;){
    vTaskDelay( 200 / portTICK_PERIOD_MS );
  }
}

void TaskSensor(void *pvParameters){
  (void) pvParameters;

  for(;;){
    distance = getDistance();
    vTaskDelay( 200 / portTICK_PERIOD_MS );
  }
}
