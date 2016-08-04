int LEDPIN = 3;
int LEDPIN1 = 13;

void setup(){
    pinMode(LEDPIN, OUTPUT);
    pinMode(LEDPIN1, OUTPUT);
   
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(LEDPIN, HIGH);
    delay(1000);
    digitalWrite(LEDPIN1, HIGH);
    delay(1000);
    digitalWrite(LEDPIN1,LOW);
    delay(1000);
    digitalWrite(LEDPIN, LOW);
    delay(1000);
   
    }
    
