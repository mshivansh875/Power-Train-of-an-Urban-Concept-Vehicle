#include <TinyGPS++.h>
#include <SoftwareSerial.h>

TinyGPSPlus gps;
SoftwareSerial ss(3, 4); // RX, TX

void setup() {
  Serial.begin(9600);
  ss.begin(9600);
  Serial.println("GPS Speed Test");
}

void loop() {
  while (ss.available() > 0) {
    if (gps.encode(ss.read())) {
      if (gps.location.isUpdated()){
        Serial.print("Lattitude: ");
        Serial.print(gps.location.lat(),6);
      }
      if (gps.speed.isValid()) {
        // Speed in km/h
        Serial.print("Speed: ");
        Serial.print(gps.speed.kmph());
        Serial.println(" km/h");
      }
    }
  }
}
