int LEDPIN= 13;
int LEDPIN1= 11;
int LEDPIN2= 8;
int LEDPIN3= 6;


 
void setup() {
  pinMode(LEDPIN,OUTPUT);
  pinMode(LEDPIN1,OUTPUT);
  pinMode(LEDPIN2,OUTPUT);
  pinMode(LEDPIN3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(LEDPIN, LOW);
    digitalWrite(LEDPIN, HIGH);
    delay(320);
    digitalWrite(LEDPIN1, HIGH);
    delay(300);
    digitalWrite(LEDPIN1,LOW);
    delay(320);
    digitalWrite(LEDPIN3, HIGH);
    delay(310);
     digitalWrite(LEDPIN, LOW);
    delay(320);
    digitalWrite(LEDPIN3, LOW);
    delay(320);
    digitalWrite(LEDPIN2,HIGH);
    delay(310);
    digitalWrite(LEDPIN2, LOW);
     
     digitalWrite(LEDPIN, HIGH);
    delay(315);
    digitalWrite(LEDPIN1, HIGH);
    delay(320);
    digitalWrite(LEDPIN, LOW);
    delay(330);
    digitalWrite(LEDPIN1, LOW);
    delay(310);
    digitalWrite(LEDPIN2, HIGH);
    delay(320);
    digitalWrite(LEDPIN2, LOW); 
    delay(320);
    digitalWrite(LEDPIN3, HIGH);
    delay(310);
    digitalWrite(LEDPIN, HIGH);
    delay(320);
    digitalWrite(LEDPIN3, LOW);
    digitalWrite(LEDPIN, LOW);
     digitalWrite(LEDPIN2, HIGH);
    delay(320);
     digitalWrite(LEDPIN2, LOW);
    delay(310);
     digitalWrite(LEDPIN, HIGH);
    delay(320);
     digitalWrite(LEDPIN1, HIGH);
    delay(320);
     digitalWrite(LEDPIN, LOW);
    delay(300);
     digitalWrite(LEDPIN1, LOW);
    delay(320);
     digitalWrite(LEDPIN3, HIGH);
    digitalWrite(LEDPIN, HIGH);
    delay(320);
     digitalWrite(LEDPIN3, LOW);
     digitalWrite(LEDPIN, LOW);
    delay(300);
     digitalWrite(LEDPIN, HIGH);
    delay(320);
     digitalWrite(LEDPIN, LOW);
    delay(320);
   
    delay(600);
   
   
    
}
