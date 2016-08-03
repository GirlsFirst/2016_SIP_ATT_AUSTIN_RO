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

//list of notes and values for measures 1 and 2

//list of notes
int notesM1M2[] {
  note_F4,
  note_Ab4,
  note_F4,
  note_F4,
  note_Bb4,
  note_F4,
  note_Eb4
};

int beatsM1M2[] {
  quarter,
  dottedEighth,
  eighth,
  sixteenth,
  eighth,
  eighth,
  eighth,
};

int lenNotesM1M2 = sizeof(notesM1M2);
int lenBeatsM1M2 = sizeof(beatsM1M2);

//HERE IS THE FUNCTION FOR MEASURES 1 AND 2:
/*
void playM1M2() {
  delay(whole * 2);
  for (int a=0; a<lenNotesM1M2; a++) {
    note = notesM1M2[a][0];
    beat = notesM1M2[a][1];
    
    tone(PIEZOPIN, note, (beat * 0.9)); //multiply by 0.9 to create a staccato effect
    delay(beat);
    Serial.println(note);
  }
}
*/

void setup() {
  for (int note = 0; note<lenNotesM1M2; note++) { //counter of Notes (54 limit the array)
    int beat = beatsM1M2[note];//Adjust duration with the pace of music
    tone(8, notesM1M2[note],beat); //Play note

// to distinguish the notes, set a minimum time between them.
    delay(beat*1.2);
  }
}

void loop() {
  //to repeat song, push reset button.
}
//End of Sketch
