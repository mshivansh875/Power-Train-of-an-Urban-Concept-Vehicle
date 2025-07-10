#define sensing_pin 9
unsigned long int time1 = 0,time2 = 0;
volatile bool currstate = LOW;
volatile bool prevstate = LOW;
volatile float rpm = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(sensing_pin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor_value = digitalRead(sensing_pin);
  if(sensor_value) currstate = HIGH;
  else currstate = LOW;
  if(currstate == HIGH && prevstate == LOW){
    time2 = millis();
    if (time1 != 0) {
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
