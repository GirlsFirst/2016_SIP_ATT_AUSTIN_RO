//THIS IS THE CODE FOR MEASURE 4 (THE "BEEP BEEP" PART OF CRAZY FROG). REFERED TO AS M4

//piezo element
int PIEZOPIN = 5;

//led digital pins
int LEDPIN = 3;
int LEDPIN1 = 13;

//initialize variables
int note = 0;
int beat = 0;

//note frequencies in Hz
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

//2-D array for notes and lengths in measure 4
int notesM4[4][2] = {
  {note_F4, half},
  {note_F4, quarter},
  {note_F4, quarter},
  {0, 0}, //this is the hack to make it not play a weird note
};

int lenM4 = sizeof(notesM4);


//-------------------------FUNCTIONS-------------------------

//setup function: initialize pin, leds, serial printer
void setup() {
  pinMode(PIEZOPIN, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(LEDPIN1, OUTPUT);
  Serial.begin(9600);
}

//function for sounds and lights for measure 4
void playM4() {
  digitalWrite(LEDPIN, LOW);
  digitalWrite(LEDPIN1, LOW);
  int d = 0;
  for (int d=0; d<(lenM4-1); d++) { //this is part of the hack that stops the weird sound from playing
    note = notesM4[d][0];
    beat = notesM4[d][1];
    tone(PIEZOPIN, note);
    digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN1, HIGH);
    delay(beat / 2);
    noTone(PIEZOPIN);
    digitalWrite(LEDPIN, LOW);
    digitalWrite(LEDPIN1, LOW);
    delay(beat / 2);
    Serial.println(note);
    if ((note==258) || (note==0) || (note==387) || (note == 517) || (note >= 800) || (note <= 100)) {  //these were the weird frequencies that played
      noTone(PIEZOPIN);
      delay(whole * 3);
      d = -1;
    }
  }
}

//play the M4 function
void loop() {
  noTone(PIEZOPIN);
  delay(whole * 3);
  for (int i=0; i<10; i++) {
    playM4();
  }
}

