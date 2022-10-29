#include "Arduino.h"
#include <Arduino_FreeRTOS.h>
#include "user.h"
#include "ultrasonic.h"
#include <SoftwareSerial.h>

SoftwareSerial sensor(2, 3);

float distance;
uint8_t buff[4];


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
  
  sensor.begin(9600);
  uint8_t i;
  for(;;){    
do{
     for(int i=0;i<4;i++)
     {
        buff[i]=sensor.read();
     }
  }while(sensor.read()==0xff);

 
sensor.flush();  
 
      if(buff[0]==0xff){
      int sum;
      sum=(buff[0]+buff[1]+buff[2])&0x00FF;
      if(sum==buff[3])
      {
        distance=(buff[1]<<8)+buff[2];
        if(distance>280)
          {
           Serial.print("distance=");
           Serial.print(distance/10);
           Serial.println("cm");
          }else 
              {
                Serial.println("Below the lower limit");        
              }
      }else Serial.println("ERROR");   
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
  }
}
}
