#include <avr/wdt.h>

int PIEZOPIN = 5;

int note = 0;
int beat = 0;

//notes
int note_C4 = 261.63;
int note_Eb4 = 311.13;
int note_F4 = 349.23;
int note_G4 = 392.00;
int note_Ab4 = 415.30;
int note_Bb4 = 466.16;
int note_C5 = 523.25;
int note_Db5 = 554.37;
int note_F5 = 698.46;

//note lengths (beats)
int bpm = 116;
int quarter = 60000 / bpm;  // (miliseconds in a minute) divided by (beats in a minute) equals (delay time in miliseconds)
int whole = quarter * 4;
int half = quarter * 2;
int eighth = whole / 8;
int sixteenth = whole / 16;
int dottedEighth = eighth + sixteenth;

//array for notes and lengths in measure 4
int notesM4[3][2] = {
  {note_F4, quarter},
  {note_F4, quarter},
  {0, whole}, //this is the hack to make it not play a weird note
};

int lenM4 = sizeof(notesM4);


//-------------------------FUNCTIONS-------------------------

//reset function
void softwareReset( uint8_t prescaller) {
  // start watchdog with the provided prescaller
  wdt_enable( prescaller);
  // wait for the prescaller time to expire
  // without sending the reset signal by using
  // the wdt_reset() method
  while(1) {}
}


//setup function: initialize pin, serial printer
void setup() {
  pinMode(PIEZOPIN, OUTPUT);
  Serial.begin(9600);
}

//function for measure 4 (M4)
void playM4() {
  delay((whole * 2) + half + (whole * 2));
  for (int d=0; d<(lenM4-1); d++) {
    note = notesM4[d][0];
    beat = notesM4[d][1];    
    tone(PIEZOPIN, note, (beat * 0.9)); //multiply by 0.9 to create a staccato effect
    delay(beat);
    Serial.println(note);
    if ((note==258) || (note==387) || (note == 517) || (note >= 800) || (note <= 100)) {
    //this is just a hack and i know it's hard code but it works for now. i need to figure out if i can access an array
      noTone(PIEZOPIN);
      softwareReset(WDTO_60MS);
    }
  }
}

//play the M4 function
void loop() {
  playM4();
}

