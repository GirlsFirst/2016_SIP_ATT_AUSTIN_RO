//THIS IS THE CODE FOR MEASURE 3 OF "CRAZY FROG" ("AXEL F"). REFERRED TO AS M3

//piezo
int PIEZOPIN = 5;

//leds
int LEDPINYELLOW = 6;

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

//list of notes and values for measure 3
int dataM3[11][2] = {
  {note_F4, eighth},
  {note_C5, eighth},
  {note_F5, eighth},
  {note_F4, sixteenth},
  {note_Eb4, eighth},
  {note_Eb4, sixteenth},
  {note_C4, eighth},
  {note_G4, eighth},
  {note_F4, eighth},
  {0, 0}, //this is the hack to make it not play a weird note
};

int lenM3 = sizeof(dataM3);


//-------------------------FUNCTIONS-------------------------

//setup function: initialize piezo, leds, serial printer
void setup() {
  pinMode(PIEZOPIN, OUTPUT);
  //pinMode(LEDPINRED, OUTPUT);
  pinMode(LEDPINYELLOW, OUTPUT);
  //pinMode(LEDPINGREEN, OUTPUT);
  Serial.begin(9600);
}

//function for measure 3 (M3)
void playM3() {
  for (int c=0; c<(lenM3-1); c++) { //this is part of the hack that stops the weird sound from playing
    note = dataM3[c][0];
    beat = dataM3[c][1];
    tone(PIEZOPIN, note);
    digitalWrite(LEDPINYELLOW, HIGH);
    delay(beat / 2);
    noTone(PIEZOPIN);
    digitalWrite(LEDPINYELLOW, LOW);
    delay(beat / 2);
    Serial.println(note);
    if ((note==258) || (note==387) || (note == 517) || (note >= 800) || (note <= 100)) {  //by printing to the serial moniter, i saw that these frequencies always played at the end of the function
      noTone(PIEZOPIN);
      delay(whole * 3);
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

