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


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoLeft.attach(12);
  servoRight.attach(13);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
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
void circle(){
  servoRight.writeMicroseconds(1700);
  servoLeft.writeMicroseconds(1300);
}

void BingBing(){
    backward();
    delay(sixteenth);
    backward();
    delay(sixteenth);
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
 delay(half);
 tantan();
 delay(half);
 right();
 delay(sixteenth );
}
for (int i =0; i<2; i++){
  left();
 delay(sixteenth);
 right();
 delay(sixteenth);
 right();
 delay(sixteenth);
 left();
 delay(sixteenth);
 right();
 delay(sixteenth);
 right();
 delay(sixteenth);
}
for(int i=0; i<1; i++){
forward();
delay(sixteenth);
forward();
delay(sixteenth);
}
for(int i=0; i<4; i++ ){
forward();
delay(quarter);
backward();
delay(quarter);
right();
delay(quarter);
}
for(int i=0; i<2; i++){
left();
 delay(sixteenth);
 right();
 delay(sixteenth);
 right();
 delay(sixteenth);
}
for(int i=0; i<4; i++ ){
forward();
delay(quarter);
right();
delay(quarter);
backward();
delay(quarter);
left();
delay(quarter);
right();
delay(quarter);
}
for (int i= 0; i<2; i++){
  forward();
  delay(quarter);
}
for (int i= 0; i<2; i++){
  backward();
  delay(quarter);
}





   

  // put your main code here, to run repeatedly:
  
}
