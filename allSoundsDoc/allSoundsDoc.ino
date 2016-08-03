int PIEZOPIN = 5;

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

//notes lists
int notesM1M2[14][2] = {
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
  {note_Ab4, eighth}
};

int notesM3[10][2] = {
  {note_F4, eighth},
  {note_C5, eighth},
  {note_F5, eighth},
  {note_F4, sixteenth},
  {note_Eb4, sixteenth},
  {note_Eb4, sixteenth},
  {note_Eb4, sixteenth},
  {note_C4, eighth},
  {note_G4, eighth},
  {note_F4, eighth}
};

int notesM4[3][2] = {
  {note_F4, half},
  {note_F4, quarter},
  {note_F4, quarter},
};

int lenM1M2 = sizeof(notesM1M2);
int lenM3 = sizeof(notesM3);
int lenM4 = sizeof(notesM4);

//HERE'S THE SETUP FUNCTION
void setup() {
  pinMode(PIEZOPIN, OUTPUT);
}


//HERE ARE THE FUNCTIONS FOR THE DIFFERENT MEASURES:
//m1m2
void playM1M2() {
  for (int a=0; a<lenM1M2; a++) {
    tone(PIEZOPIN, notesM1M2[a][0], ((notesM1M2[a][1]) * 0.9)); //multiply by 0.9 to create a staccato effect
    delay(notesM1M2[a][1]);
  }
}

//m3
void playM3() {
  for (int c=0; c<lenM3; c++) {
    tone(PIEZOPIN, notesM3[c][0], ((notesM3[c][1]) * 0.9)); //multiply by 0.9 to create a staccato effect
    delay(notesM3[c][1]);
  }
}

//m4
void playM4() {
  for (int d=0; d<lenM4; d++) {
    tone(PIEZOPIN, notesM4[d][0], ((notesM4[d][1]) * 0.9)); //multiply by 0.9 to create a staccato effect
    delay(notesM4[d][1]);
  }
}


//HERE'S THE CODE TO PLAY ALL THE MEASURES:
void loop() {
  for (int i=0; i<4; i++) {
    playM1M2();
    //playM3();
    //playM4();
  }
  noTone(PIEZOPIN);
}

