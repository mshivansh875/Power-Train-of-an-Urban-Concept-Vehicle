#define pwmpin 9
#define dirpin 8
#define stepsPerRevolution 3200
#define analogpin A0
volatile int current_angle = 0;
volatile int previous_angle = 0;
volatile bool forward = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(pwmpin,OUTPUT);
  pinMode(dirpin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int stear_input = analogRead(analogpin);
  current_angle = map(stear_input,170,520,0,stepsPerRevolution);
//  while(current_angle == previous_angle){
//    current_angle = map(stear_input,170,520,0,stepsPerRevolution);
//  }
  
  if(previous_angle < current_angle){
  for(int i = previous_angle;i<current_angle;i++){
    digitalWrite(dirpin,HIGH);
    digitalWrite(pwmpin,HIGH);
    delayMicroseconds(100);
    digitalWrite(pwmpin,LOW);
    delayMicroseconds(100);
    previous_angle++;
  }
  }else if(previous_angle>current_angle){
    for(int i = previous_angle;i>current_angle;i--){
    digitalWrite(dirpin,LOW);
    digitalWrite(pwmpin,HIGH);
    delayMicroseconds(100);
    digitalWrite(pwmpin,LOW);
    delayMicroseconds(100);
    previous_angle--;
  }
  }
  
//  for(int i = 0;i<10*stepsPerRevolution;i++){
//    digitalWrite(dirpin,LOW);
//    digitalWrite(pwmpin,HIGH);
//    delayMicroseconds(100);
//    digitalWrite(pwmpin,LOW);
//    delayMicroseconds(100);
//  }
  
  

}
