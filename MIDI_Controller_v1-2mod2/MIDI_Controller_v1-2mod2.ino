#include <MIDI.h>
#include "Controller.h"

MIDI_CREATE_DEFAULT_INSTANCE();
#define B1 4
#define B2 5
#define B3 6
#define B4 7
#define B5 8
#define B6 9
#define B7 10
#define B8 11
#define B9 12
#define B10 13
#define ptc1 A5
#define ptc2 A6
#define ptc3 A14
//pins
// button number
byte NUMBER_BUTTONS = 10;
// potentiometers number
byte NUMBER_POTS = 3;

//Pot (Pin Number, Command, CC Control, Channel Number)

Pot PO1(ptc1, 0, 1, 1);
Pot PO2(ptc2, 0, 10, 1);
Pot PO3(ptc3, 0, 22, 1);


//array 
Pot *POTS[] {&PO1,&PO2,&PO3};


//Button (Pin Number, Command, Note Number, Channel, Debounce Time)
//Command parameter 0=NOTE  1=CC  2=Toggle CC 

Button BU1(B1, 0, 60, 1, 5 ); //60 means C4 of keyboard
Button BU2(B2, 0, 62, 1, 5 );//62 means D4 of keyboard
Button BU3(B3, 0, 64, 1, 5 );//...
Button BU4(B4, 0, 65, 1, 5 );
Button BU5(B5, 0, 67, 1, 5 );
Button BU6(B6, 0, 69, 1, 5 );//69 means A4 of keyboard
Button BU7(B7, 0, 71, 1, 5 );
Button BU8(B8, 0, 72, 1, 5 );//72 means C% of keyboard
Button BU9(B9, 0, 74, 1, 5 );
Button BU10(B10, 0, 76, 1, 5 );

//array 
Button *BUTTONS[] {&BU1, &BU2, &BU3, &BU4, &BU5, &BU6, &BU7, &BU8,&BU9,&BU10};

void setup() {
  MIDI.begin(MIDI_CHANNEL_OFF);
}

void loop() {
  if (NUMBER_BUTTONS != 0) updateButtons();
  if (NUMBER_POTS != 0) updatePots();

}

void updateButtons() {

  // Cycle through Button array
  for (int i = 0; i < NUMBER_BUTTONS; i = i + 1) {
    byte message = BUTTONS[i]->getValue();

    //  Button is pressed
    if (message == 0) {
      switch (BUTTONS[i]->Bcommand) {
        case 0: //Note
          MIDI.sendNoteOn(BUTTONS[i]->Bvalue, 127, BUTTONS[i]->Bchannel);
          break;
        case 1: //CC
          MIDI.sendControlChange(BUTTONS[i]->Bvalue, 127, BUTTONS[i]->Bchannel);
          break;
        case 2: //Toggle
          if (BUTTONS[i]->Btoggle == 0) {
            MIDI.sendControlChange(BUTTONS[i]->Bvalue, 127, BUTTONS[i]->Bchannel);
            BUTTONS[i]->Btoggle = 1;
          }
          else if (BUTTONS[i]->Btoggle == 1) {
            MIDI.sendControlChange(BUTTONS[i]->Bvalue, 0, BUTTONS[i]->Bchannel);
            BUTTONS[i]->Btoggle = 0;
          }
          break;
      }
    }

    //  Button is not pressed
    if (message == 1) {
      switch (BUTTONS[i]->Bcommand) {
        case 0:
          MIDI.sendNoteOff(BUTTONS[i]->Bvalue, 0, BUTTONS[i]->Bchannel);
          break;
        case 1:
          MIDI.sendControlChange(BUTTONS[i]->Bvalue, 0, BUTTONS[i]->Bchannel);
          break;
      }
    }
  }
}
void updatePots() {
  for (int i = 0; i < NUMBER_POTS; i = i + 1) {
    byte potmessage = POTS[i]->getValue();
    if (potmessage != 255) MIDI.sendControlChange(POTS[i]->Pcontrol, potmessage, POTS[i]->Pchannel);
  }
}

