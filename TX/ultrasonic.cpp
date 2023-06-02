#include "ultrasonic.h"
#include "Arduino.h"
#include <SoftwareSerial.h>

SoftwareSerial sensor(2, 3);

uint8_t buff[4];
uint8_t i;

void start_read(){
  sensor.begin(9600);
}

float getDistance(){
  
  float distance;
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
//           Serial.print("distance=");
//           Serial.print(distance/10);
//           Serial.println("cm");
           return distance;
          }else 
              {
                Serial.println("Below the lower limit");        
              }
      }else Serial.println("ERROR");   
   }
}
