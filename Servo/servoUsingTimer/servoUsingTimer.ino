volatile int pwmWidth=1500;
volatile int lowerAngle=600;
volatile int higherAngle= 2400;
volatile bool forward = false;
#define pwmpin 9
void setup(){
  pinMode(pwmpin, OUTPUT);
  Serial.begin(9600);

  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 5000;
  TCCR1B |= (1<<WGM12);
  TCCR1B |= (1<<CS11)|(1<<CS10);
  TIMSK1 |= (1<<OCIE1A);
  sei();
}
ISR(TIMER1_COMPA_vect){
  digitalWrite(pwmpin,HIGH);
  delayMicroseconds(pwmWidth);
  digitalWrite(pwmpin, LOW);
}
int i = 0;
void loop(){
  while(Serial.available()==0){
    
  }
  if(i==0){
    angleCalculator();
    i=1;
  }

  pwmWidthCalculator();
  delay(20);
}

void angleCalculator(){
  if(Serial.available() >= 0){
    Serial.println("Input the lower angle to set: ");
    lowerAngle = Serial.parseInt();
    lowerAngle = lowerAngle*10 + 600;
    Serial.println("Input the Higher angle to set: ");
    higherAngle = Serial.parseInt();
    higherAngle = higherAngle*10 + 600;
    pwmWidth = (lowerAngle + higherAngle)/2;
  }
}

void pwmWidthCalculator(){
  if(forward){
    pwmWidth += 100;
    if(pwmWidth>= higherAngle){
      forward = false;
    }
  }
  else{
    pwmWidth -= 100;
    if(pwmWidth<= lowerAngle){
      forward = true;
    }
  }
  
}
