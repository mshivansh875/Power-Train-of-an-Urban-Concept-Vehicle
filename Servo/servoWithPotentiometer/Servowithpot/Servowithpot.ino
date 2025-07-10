volatile int pwmWidth=600;
volatile int Angle;
#define pwmpin 9
#define potpin A0
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
void loop(){
  int throttle_input = analogRead(potpin);
  pwmWidth = map(throttle_input,0,1023,600,2400);
  delay(20);
}
