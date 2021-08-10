
const uint16_t timer_start = 0;
const uint16_t timer_threshold = 8000;
const int LED = 4;
const int ledPin = 13;

ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
{
 digitalWrite(LED, !digitalRead(BlueLED));
 Serial.println("Pin D8-D13 Triggerd");
}


void setup()
 {
  pinMode(ledPin, OUTPUT);
  pinMode(LED, OUTPUT);
  // initialize timer1
  //Commence serial communication
  Serial.begin(9600);
  //Reset timer register
  TCCR1A = 0;
  //Set prescaler to 1024
  TCCR1B |= (1 << CS12);
  TCCR1B &= ~(1 << CS11);
  TCCR1B |= (1 << CS10);
  //Reset timer and set timer compare bit
  TCNT1 = timer_start;
  OCR1A = timer_threshold;
  //Enable Timer1 interrupt
  TIMSK1 = (1 << OCIE1A);
  
  //Enabling pin interrupt
  PCICR |= 0b00000111;
  PCMSK0 |=0b00000111;

 //Setting input and outputs
 pinMode(ledPin, OUTPUT);
 pinMode(LED, OUTPUT);
 pinMode(8, INPUT);

 }

ISR(TIMER1_COMPA_vect) {
  digitalWrite(ledPin, !digitalRead(ledPin));
  TCNT1 = timer_start;
}

void loop()
{
}

