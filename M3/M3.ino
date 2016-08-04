//THIS IS THE CODE FOR MEASURE 3. REFERRED TO AS M3

//include this library for the reset function (see later on in the code)
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

//note lengths
int bpm = 116;
int quarter = 60000 / bpm;  // (miliseconds in a minute) divided by (beats in a minute) equals (delay time in miliseconds)
int whole = quarter * 4;
int half = quarter * 2;
int eighth = whole / 8;
int sixteenth = whole / 16;
int dottedEighth = eighth + sixteenth;

//list of notes and values for measure 3
int notesM3[11][2] = {
  {note_F4, eighth},
  {note_C5, eighth},
  {note_F5, eighth},
  {note_F4, sixteenth},
  {note_Eb4, eighth},
  {note_Eb4, sixteenth},
  {note_C4, eighth},
  {note_G4, eighth},
  {note_F4, eighth},
  {0, whole}, //this is the hack to make it not play a weird note
};

int lenM3 = sizeof(notesM3);


//-------------------------FUNCTIONS-------------------------
/*
//reset function
void softwareReset( uint8_t prescaller) {
  // start watchdog with the provided prescaller
  wdt_enable( prescaller);
  // wait for the prescaller time to expire
  // without sending the reset signal by using
  // the wdt_reset() method
  while(1) {}
}
*/

//setup function: initialize pin, serial printer
void setup() {
  pinMode(PIEZOPIN, OUTPUT);
  Serial.begin(9600);
}

//function for measure 3 (M3)
void playM3() {
  for (int c=0; c<(lenM3-1); c++) { //testing to see if the weird sound at the end is because of the last list element?
    note = notesM3[c][0];
    beat = notesM3[c][1];
    tone(PIEZOPIN, note, (beat * 0.9)); //multiply by 0.9 to create a staccato effect
    delay(beat);
    Serial.println(note);
    if ((note==258) || (note==387) || (note == 517) || (note >= 800) || (note <= 100)) {
      noTone(PIEZOPIN);
      delay(whole * 3);
      //softwareReset(WDTO_60MS);
      c = -1;
    }
  }
}

//play the M3 function
void loop() {
  noTone(PIEZOPIN);
  delay(whole * 2);
  for (int i=0; i<10; i++) {
    playM3();
  }
}

