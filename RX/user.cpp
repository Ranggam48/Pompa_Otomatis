#include "Arduino.h"
#include <Arduino_FreeRTOS.h>
#include "user.h"
#include "nrf24.h"
#include <stdio.h>
#include <string.h>
#include "stdarg.h"

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 20, 4);

char pesan[4];
int distance;


int LED = 2; //nama alias untuk pin.2 yaitu LED

void user_init(void){
    xTaskCreate(Task01, "Task01", 128, NULL, 1, NULL);
    xTaskCreate(Task02, "Task02", 128, NULL, 2, NULL);
}

void Task01(void *pvParameters){
  (void) pvParameters;
  Serial.begin(9600); //menggunakan serial monitor pada 9600bps
  nrf24_startRX(); 
  for(;;){
    nrf24_Receive();
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
  }
}
void Task02(void *pvParameters){
  (void) pvParameters;
  lcd.begin();
  lcd.backlight();
  for(;;){
    sscanf(pesan, "%d", &distance);
    
    vTaskDelay( 200 / portTICK_PERIOD_MS );
  }
}
