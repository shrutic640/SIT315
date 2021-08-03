const byte led_pin1 = 8;
const byte led_pin2 = 7;
const byte pir_pin1 = 2;
const byte pir_pin2 = 3;
volatile byte state1 = LOW;
volatile byte state2 = LOW;



void setup() {
  Serial.begin(9600);
  pinMode(led_pin1,OUTPUT);
  pinMode(led_pin2,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pir_pin1),interrupt_routine1,RISING);
  attachInterrupt(digitalPinToInterrupt(pir_pin2),interrupt_routine2,RISING);
}


void IR1(){
  if (state1 == HIGH){
    digitalWrite(led_pin1,HIGH);
    delay(500);
    
  }
  if (state1 == HIGH) {
    Serial.println("low1");
    state1 = LOW;
    digitalWrite(led_pin1,LOW);
  }
}


void IR2(){
  if (state2 == HIGH){
    digitalWrite(led_pin2,HIGH);
    delay(500);
    
  }
  if (state2 == HIGH) {
    Serial.println("low2");
    state2 = LOW;
    digitalWrite(led_pin2,LOW);
  }
}

void loop() {
  
}

void interrupt_routine1(){
  state1 = HIGH;
  Serial.println("interrupt1");
}

void interrupt_routine2(){
  state2 = HIGH;
  Serial.println("interrupt2");
}