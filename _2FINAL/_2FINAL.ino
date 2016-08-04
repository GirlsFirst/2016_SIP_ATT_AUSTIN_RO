int LEDPIN= 3;
int LEDPIN1= 13;

void setup() {
  pinMode(LEDPIN,OUTPUT);
  pinMode(LEDPIN1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(LEDPIN, LOW);
    digitalWrite(LEDPIN, HIGH);
    delay(320);
    digitalWrite(LEDPIN1, HIGH);
    delay(320);
    digitalWrite(LEDPIN1,LOW);
    delay(340);
    digitalWrite(LEDPIN1, HIGH);
    delay(320);
     digitalWrite(LEDPIN, LOW);
    delay(340);
    digitalWrite(LEDPIN1, LOW);
    delay(340);
    digitalWrite(LEDPIN1,HIGH);
    delay(320);
    digitalWrite(LEDPIN1, LOW);
     
     digitalWrite(LEDPIN, HIGH);
    delay(350);
    digitalWrite(LEDPIN1, HIGH);
    delay(350);
    digitalWrite(LEDPIN, LOW);
    delay(360);
    digitalWrite(LEDPIN1, LOW);
    delay(320);
    digitalWrite(LEDPIN, HIGH);
    delay(360);
    digitalWrite(LEDPIN, LOW); 
    delay(320);
    digitalWrite(LEDPIN1, HIGH);
    delay(320);
    digitalWrite(LEDPIN, HIGH);
    delay(350);
    digitalWrite(LEDPIN, LOW);
    digitalWrite(LEDPIN1, LOW);
   
    delay(600);
}
