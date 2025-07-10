#include <SoftwareSerial.h>

SoftwareSerial mySerial(3,2);

String message = "";

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("initializing");
  Serial.println("device is connected !!");

}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (mySerial.available()){
    char incomingChar = mySerial.read();
    if (incomingChar != '\n'){
      message += String(incomingChar);
    }
    else{
      message = "";
    }
    Serial.write(incomingChar);  
  }
  // Check received message and control output accordingly
  if (message == "on"){
    digitalWrite(13, HIGH);
  }
  else if (message == "off"){
    digitalWrite(13, LOW);
  }
  else if (message == "blink"){
    for(int i = 0; i<=10;i++){
    digitalWrite(13,HIGH);
    delay(200);
    digitalWrite(13,LOW);
    delay(200);}
  }
  delay(20);
}
