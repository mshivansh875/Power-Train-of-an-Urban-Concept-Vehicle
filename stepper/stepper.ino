#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

#define EN1 3
#define EN2 4
void setup() {
  // put your setup code here, to run once:
  pinMode(IN1,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN1,OUTPUT);

  pinMode(EN1,OUTPUT);
  pinMode(EN2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);

  delayMicroseconds(50);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);

  delayMicroseconds(50);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  delayMicroseconds(50);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);

  delayMicroseconds(50);
}
