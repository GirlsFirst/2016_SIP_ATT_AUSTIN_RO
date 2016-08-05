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
    digitalWrite(LEDPIN1, LOW);
    digitalWrite(LEDPIN1, HIGH);
    delay(320);

  
}
