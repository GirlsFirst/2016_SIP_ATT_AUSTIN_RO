#include <Servo.h> 

Servo servoRight;
Servo servoLeft; 

int bpm = 116;
int quarter = 60000 / bpm;  // (miliseconds in a minute) divided by (beats in a minute) equals (delay time in miliseconds)
int whole = quarter * 4;
int half = quarter * 2;
int eighth = whole / 8;
int sixteenth = whole / 16;
int dottedEighth = eighth + sixteenth;
int LEDPIN= 11;
int LEDPIN1= 10;
int LEDPIN2= 8;
int LEDPIN3= 6;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoLeft.attach(12);
  servoRight.attach(13);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  pinMode(LEDPIN,OUTPUT);
  pinMode(LEDPIN1,OUTPUT);
  pinMode(LEDPIN2,OUTPUT);
  pinMode(LEDPIN3,OUTPUT);
}

void stopMove(){
  servoRight.writeMicroseconds(1500);
  servoLeft.writeMicroseconds(1500);
}
void forward(){
  servoRight.writeMicroseconds(1275);
  servoLeft.writeMicroseconds(16225);
}
void backward(){
  servoRight.writeMicroseconds(1625);
  servoLeft.writeMicroseconds(1275);
}
void right(){
  servoRight.writeMicroseconds(1625);
  servoLeft.writeMicroseconds(1625);  
}
void left(){
  servoRight.writeMicroseconds(1275);
  servoLeft.writeMicroseconds(1275);  
}

void tantan(){
   for (int i = 0; i < 2; i++){
   right();
   delay(half); 
   }
}

void loop() {
///making it go in circles 
  for (int i = 0; i < 1; i++){
 tantan();
 digitalWrite(LEDPIN, LOW);
    digitalWrite(LEDPIN1, HIGH);
    digitalWrite(LEDPIN3, HIGH);
     digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN3, LOW);
 delay(half);
 tantan();
 digitalWrite(LEDPIN2,HIGH);
     digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN1, HIGH);
    digitalWrite(LEDPIN, LOW);
    digitalWrite(LEDPIN1, LOW);
 delay(half);
 right();
    digitalWrite(LEDPIN2, LOW); 
    digitalWrite(LEDPIN3, HIGH);
    digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN3, LOW);
 delay(sixteenth );
     
}
for (int i =0; i<2; i++){
  
  left();
  digitalWrite(LEDPIN, LOW);
     digitalWrite(LEDPIN2, HIGH);
     digitalWrite(LEDPIN, HIGH);
 delay(sixteenth);
 right();
  digitalWrite(LEDPIN1, HIGH);
     digitalWrite(LEDPIN, LOW);
     digitalWrite(LEDPIN1, LOW);
     digitalWrite(LEDPIN3, HIGH); 
 delay(sixteenth);
 right();
  digitalWrite(LEDPIN, HIGH);
     digitalWrite(LEDPIN3, LOW);
     digitalWrite(LEDPIN, LOW);
     digitalWrite(LEDPIN, HIGH);  
 delay(sixteenth);
 
 left();
 digitalWrite(LEDPIN3, LOW);
     digitalWrite(LEDPIN, LOW);
 delay(sixteenth);
 right();
    digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN1, HIGH);
    digitalWrite(LEDPIN3, HIGH);
     digitalWrite(LEDPIN, LOW);
    digitalWrite(LEDPIN3, LOW);  
 delay(sixteenth);
 right();
    digitalWrite(LEDPIN2, LOW);
     digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN1, HIGH);
    digitalWrite(LEDPIN, LOW);
    digitalWrite(LEDPIN1, LOW); 
 delay(sixteenth);
  
}
for(int i=0; i<1; i++){
forward();
digitalWrite(LEDPIN2, HIGH);
    digitalWrite(LEDPIN3, HIGH);
    digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN3, LOW); 
delay(sixteenth);
forward();
digitalWrite(LEDPIN, LOW);
     digitalWrite(LEDPIN2, LOW);
     digitalWrite(LEDPIN, HIGH); 
delay(sixteenth);

}
for(int i=0; i<4; i++ ){
forward();
digitalWrite(LEDPIN1, HIGH);
     digitalWrite(LEDPIN, LOW);
     digitalWrite(LEDPIN1, LOW);
     digitalWrite(LEDPIN3, HIGH); 
delay(quarter);
backward();
digitalWrite(LEDPIN, HIGH);
     digitalWrite(LEDPIN3, LOW);
     digitalWrite(LEDPIN, HIGH); 
delay(quarter);
right();
 digitalWrite(LEDPIN3, LOW);
     digitalWrite(LEDPIN, LOW);
delay(quarter);

}
for(int i=0; i<2; i++){
left();
    digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN1, HIGH);
    digitalWrite(LEDPIN3, HIGH);
     digitalWrite(LEDPIN, LOW);
    digitalWrite(LEDPIN3, LOW); 
 delay(sixteenth);
 right();
 digitalWrite(LEDPIN2,HIGH);
     digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN1, HIGH);
    digitalWrite(LEDPIN, LOW);
    digitalWrite(LEDPIN1, LOW); 
 delay(sixteenth);
 right();
    digitalWrite(LEDPIN2, LOW); 
    digitalWrite(LEDPIN3, HIGH);
    digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN3, LOW);
 delay(sixteenth);
}
for(int i=0; i<4; i++ ){
forward();
digitalWrite(LEDPIN, LOW);
     digitalWrite(LEDPIN2, HIGH);
     digitalWrite(LEDPIN, HIGH);
delay(quarter);
right();
digitalWrite(LEDPIN1, HIGH);
     digitalWrite(LEDPIN, LOW);
     digitalWrite(LEDPIN1, LOW);
     digitalWrite(LEDPIN3, HIGH);
delay(quarter);
backward();
digitalWrite(LEDPIN, HIGH);
     digitalWrite(LEDPIN3, LOW);
     digitalWrite(LEDPIN, HIGH);
delay(quarter);
left();
digitalWrite(LEDPIN3, LOW);
     digitalWrite(LEDPIN, LOW);
delay(quarter);
right();
    digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN1, HIGH);
    digitalWrite(LEDPIN3, HIGH);
     digitalWrite(LEDPIN, LOW);
    digitalWrite(LEDPIN3, LOW);
delay(quarter);

    
}
for (int i= 0; i<2; i++){
  forward();
    digitalWrite(LEDPIN2, LOW);
     digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN1, HIGH);
    digitalWrite(LEDPIN, LOW);
    digitalWrite(LEDPIN1, LOW);
  delay(quarter);
   
}
for (int i= 0; i<2; i++){
  backward();
 digitalWrite(LEDPIN2, HIGH);
    digitalWrite(LEDPIN3, HIGH);
    digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN3, LOW);
  delay(quarter);
   
}





   

  // put your main code here, to run repeatedly:
  
}
