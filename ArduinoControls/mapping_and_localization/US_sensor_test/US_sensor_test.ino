#include "NewPing.h"

#define TRIGGER_PIN 10
#define ECHO_PIN 13
#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

float duration, distance;

int iterations = 10;

void setup() {
  Serial.begin(9600);
}

void loop() {
  duration = sonar.ping_median(iterations);

  //343m/s for speed of sounds
  distance = (duration / 2) * 0.0343;
  
  Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2) {
    Serial.println("Out of range");
  }
  else{
    Serial.print(distance);
    Serial.println(" cm");
    delay(100);
  }
  delay(100);
}
