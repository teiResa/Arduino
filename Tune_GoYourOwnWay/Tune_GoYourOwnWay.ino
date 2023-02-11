/* 
  Minuet in G - C. Petzold
  Connect a piezo buzzer or speaker to pin 11 or select a new pin.
  More songs available at https://github.com/robsoncouto/arduino-songs                                            
                                              
                                              Robson Couto, 2019
*/
#include "pitches.h"

// change this to make the song slower or faster
int tempo = 140;

// change this to whichever pin you want to use
int buzzer = 9;

// notes of the moledy followed by the duration.
// a 4 == quarter note, 8 == eighteenth , 16 sixteenth, etc.
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {

  // Go Your Own Way - Fleetwood Mac
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
  //"Loving you; Isn't the right thing to do."                    OK
    REST, 4, NOTE_C4, 8, NOTE_D4, 8, NOTE_E4, 4, REST, 4,
    NOTE_C4, 8, NOTE_D4, 8, NOTE_E4, 4, NOTE_F4, 2, NOTE_E4, 4, REST, 8, NOTE_D4, 8, NOTE_D4, 4,
  
  //"How can I; ever change the things that I feel?"              OK
    REST, 4, NOTE_F4, 4, NOTE_G4, 8, NOTE_A4, 8, REST, 4, 
    NOTE_F4, 4, NOTE_G4, 8, NOTE_A4, 8, NOTE_C4, 8, NOTE_F4, 8, REST, 16,
    NOTE_G4, 4, NOTE_G4, 8, NOTE_G4, 4, REST, 4,


  //"If I could; Maybe I'd give you my world."                   OK
    REST, 4, NOTE_C4, 8, NOTE_D4, 8, NOTE_E4, 4, REST, 2,
    NOTE_C4, 8, NOTE_D4, 8, NOTE_E4, 4, NOTE_F4, 2, NOTE_E4, 4, REST, 8, NOTE_D4, 8, NOTE_D4, 4,
  
  //"How can I; When you won't take it from me?"                 FINE.
    REST, 4, NOTE_F4, 4, NOTE_G4, 8, NOTE_A4, 8, REST, 4, 
  
    NOTE_F4, 4, NOTE_G4, 8, NOTE_A4, 8, NOTE_C5, 4, NOTE_F4, 8, 
    NOTE_G4, 8, NOTE_G4, 4, REST, 4,

    
*/
    

  //~~~~~~~~~~~ CHORUS ~~~~~~~~~~~

  //"You can go your own way"
    REST, 4, NOTE_E4, 8, NOTE_D4, 8, NOTE_E4, 4, NOTE_G4, 4, NOTE_C4, 4, NOTE_D4, 1,REST, 8,

  //"go your own way"
    NOTE_F4, 4, NOTE_D4, 4, NOTE_C4, 4, /* waaaay *//*NOTE_D4, 2, */NOTE_B3, 8, NOTE_A3, 4, REST, 4,

  //"You can call it"
    REST, 4, NOTE_E4, 8, NOTE_D4, 8, NOTE_E4, 4, NOTE_G4, 4, REST, 8,

  //"another lonely day"
     NOTE_C4, 4, NOTE_D4, 2, REST, 16, NOTE_C4, 4, NOTE_D4, 4,/* REST, 8, NOTE_C4, 4,  waaaay *//*NOTE_D4, 2,*/ NOTE_B3, 4, NOTE_A3, 2,

  //"You can go your own way"
    //REST, 4, NOTE_E4, 8, NOTE_D4, 8, NOTE_E4, 4, NOTE_G4, 4, NOTE_C4, 4, NOTE_D4, 2,

  //"go your own way"
    //NOTE_F4, 4, NOTE_D4, 4, NOTE_C4, 4, /* waaaay *//*NOTE_D4, 2, */NOTE_B3, 8, NOTE_A3, 4,
 
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void setup() {
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

void loop() {
  // no need to repeat the melody.
}
