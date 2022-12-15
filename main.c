#include <MIDI.h> // include the MIDI library

MIDI_CREATE_DEFAULT_INSTANCE(); // create a MIDI instance

void setup() {
  // initialize MIDI interface
  MIDI.begin(31250);
  // register callback function to handle incoming MIDI messages
  MIDI.setHandleNoteOn(handleNoteOn);
}

void loop() {
  MIDI.read(); // read incoming MIDI messages
}

// this function is called whenever a MIDI note-on message is received
void handleNoteOn(byte channel, byte note, byte velocity) {
  if (note == 60) { // if the note is C4
    digitalWrite(2, HIGH); // turn on the solenoid on pin 2
  }
}
