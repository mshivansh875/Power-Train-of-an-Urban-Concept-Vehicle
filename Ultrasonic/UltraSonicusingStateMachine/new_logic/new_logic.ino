#include <NewPing.h>

const int trigPin = 12;
const int echoPin = 13;
const float obstacle_distance = 4;  // in cm
#define MAX_DISTANCE 10  
NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

bool prevstate = false;
bool currstate = false;

unsigned long time1 = 0, time2 = 0;
int rpm = 0;
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
  if(distance>0 && distance <5){
    currstate = true;
  }else{
    currstate = false;
  }
  if(currstate == true && prevstate == false){
    time2 = millis();
    if (time1 != 0 && (time2 - time1) > minTimeDiff) {
      unsigned long timeDiff = time2 - time1;
      int exact_rpm = (60000.0 / timeDiff);
      rpm = (exact_rpm -(exact_rpm%10));
      
      Serial.print("RPM: ");
      Serial.println(rpm);
    }
    time1 = time2;
  }
  prevstate = currstate;
}
