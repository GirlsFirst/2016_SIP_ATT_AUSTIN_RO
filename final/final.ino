int LEDPIN = 3;
int LEDPIN1 = 13;

void setup(){
    pinMode(LEDPIN, OUTPUT);
    pinMode(LEDPIN1, OUTPUT);
   
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN1, HIGH);
    delay(140);
    digitalWrite(LEDPIN1,LOW);
    digitalWrite(LEDPIN, LOW);
    delay(140);
    digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN1, HIGH);
    delay(500);
    
   
    }
    
