#include "ultrasonic.h"
#include "Arduino.h"

//float distance;
int duration;



// inisialisasi sensor ultrasonic
void ultrasonic_init(void){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


// fungsi untuk mendapatkan jarak
float getDistance(void){
  digitalWrite(trigPin, LOW);delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // perhitungan jarak

  return duration/58.2;

}
