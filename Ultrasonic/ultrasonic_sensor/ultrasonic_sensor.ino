#include <NewPing.h>

const int trigPin = 9;
const int echoPin = 10;
const float obstacle_distance = 4;  // in cm
#define MAX_DISTANCE 10  
NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

unsigned long time1 = 0, time2 = 0;
float rpm = 0;
const unsigned long minTimeDiff = 80; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(15);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned int distance = sonar.ping_cm();
  if (distance <= obstacle_distance && distance > 0) {
    time2 = millis();
    if (time1 != 0 && (time2 - time1) > minTimeDiff) {
      unsigned long timeDiff = time2 - time1;
      rpm = (60000.0 / timeDiff);
      
      Serial.print("RPM: ");
      Serial.println(rpm);
    }
    time1 = time2;
  }
}
