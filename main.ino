#include <MIDI.h>

const int solenoidPin1 = 9;  // * Pin to control solenoid 1... etc
const int solenoidPin2 = 10;  
const int solenoidPin3 = 11;  

MIDI_CREATE_DEFAULT_INSTANCE(); 

void setup() {
  MIDI.begin();  

  // * tell arduino that the pins are outputs
  pinMode(solenoidPin1, OUTPUT);  // set solenoid 1 pin as an output
  pinMode(solenoidPin2, OUTPUT);  // set solenoid 2 pin as an output
  pinMode(solenoidPin3, OUTPUT);  // set solenoid 3 pin as an output
}

void loop() {

  // * read the MIDI messages... i think we need to use some software to basically use the teensy as a midi instrument.. 
  MIDI.read();

	  // * if the MIDI message is a note on message
  if (MIDI.getType() == midi::NoteOn) {
    
	// * get note num and velocity... idk if this is right needs testing
    int note = MIDI.getData1();
    int velocity = MIDI.getData2();


// * Note mapping stuff goes here. Turns solenoid on for 100ms then turns it off when a note is played, idk how to do velocity yet
    if (note == 60) {
      digitalWrite(solenoidPin1, HIGH);
      delay(100);  //* hold it!!!
      digitalWrite(solenoidPin1, LOW);
    } else if (note == 61) {
      digitalWrite(solenoidPin2, HIGH);
      delay(100);
      digitalWrite(solenoidPin2, LOW);
    } else if (note == 62) {
      digitalWrite(solenoidPin3, HIGH);
      delay(100);
      digitalWrite(solenoidPin3, LOW);
    }
  }
}
