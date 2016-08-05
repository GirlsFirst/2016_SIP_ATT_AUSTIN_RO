//THIS IS THE CODE FOR MEASURES 1 AND 2 OF "CRAZY FROG" ("AXEL F". REFERRED TO AS M1M2

//piezo element
int PIEZOPIN = 5;

//leds
int LEDPIN = 3;

//initialize variables
int note = 0;
int beat = 0;
int led = 0;

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

//list of notes and values for measures 1 and 2
int dataM1M2[15][2] = {
  //m1
  {note_F4, quarter},
  {note_Ab4, dottedEighth},
  {note_F4, eighth},
  {note_F4, sixteenth},
  {note_Bb4, eighth},
  {note_F4, eighth},
  {note_Eb4, eighth},
  //m2
  {note_F4, quarter},
  {note_C5, dottedEighth},
  {note_F4, eighth},
  {note_F4, sixteenth},
  {note_Db5, eighth},
  {note_C5, eighth},
  {note_Ab4, eighth},
  {0, 0}, //this is the hack to make it not play a weird note
};

int lenM1M2 = sizeof(dataM1M2);


//-------------------------FUNCTIONS-------------------------

//setup function: initialize piezo, led lights, serial printer
void setup() {
  pinMode(PIEZOPIN, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);
}

//function for measures 1 and 2 (M1M2)
void playM1M2() {
  for (int a=0; a<(lenM1M2-1); a++) { //this is part of the hack that stops the weird sound from playing
    note = dataM1M2[a][0];
    beat = dataM1M2[a][1];
    digitalWrite(LEDPIN, LOW);
    tone(PIEZOPIN, note);
    digitalWrite(LEDPIN, HIGH);
    delay(beat / 2);
    Serial.println(note);
    noTone(PIEZOPIN);
    digitalWrite(LEDPIN, LOW);
    delay(beat / 2);
    if ((note==258) || (note==387) || (note == 517) || (note >= 800) || (note <= 100)) {  //by printing to the serial moniter, i saw that these frequencies always played at the end of the function
      noTone(PIEZOPIN);
      digitalWrite(LEDPIN, LOW);
      delay(whole * 2);
      a = -1;
    }
  }
}

//play the M1M2 function
void loop() {
  playM1M2();
}

