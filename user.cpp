#include <Arduino_FreeRTOS.h>
#include "user.h"


void user_init(void){
  
  xTaskCreate(TaskMenu, "Menu", 64, NULL, 1, NULL);
  xTaskCreate(TaskNRF, "NRF", 64, NULL, 1, NULL);
  xTaskCreate(TaskSensor, "Sensor", 64, NULL, 1, NULL);
  
}




void TaskMenu(void *pvParameters){
  (void) pvParameters;

  for(;;){
    
  }
}

void TaskNRF(void *pvParameters){
  (void) pvParameters;

  for(;;){
    
  }
}

void TaskSensor(void *pvParameters){
  (void) pvParameters;

  for(;;){
    
  }
}
