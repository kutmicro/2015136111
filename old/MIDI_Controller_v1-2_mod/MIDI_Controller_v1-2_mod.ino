#include <MIDI.h>
#include <Wire.h>
#include "Controller.h"

/*************************************************************
  MIDI CONTROLLER

  by Notes and Volts
  www.notesandvolts.com

  Version 1.2 **Arduino UNO ONLY!**
 *************************************************************/

MIDI_CREATE_DEFAULT_INSTANCE();

//************************************************************
//***SET THE NUMBER OF CONTROLS USED**************************
//************************************************************
//---How many buttons are connected directly to pins?---------
//byte NUMBER_BUTTONS = 0;
//---How many potentiometers are connected directly to pins?--
byte NUMBER_POTS = 3;

//************************************************************


//***DEFINE DIRECTLY CONNECTED POTENTIOMETERS************************
//Pot (Pin Number, Command, CC Control, Channel Number)
//**Command parameter is for future use**
//edited--pin num,cc
int PO[3]={A5,A6,A7};

int potout1=0;
int potout2=0;
int potout3=0;

/*
 int PO1=A0, 0, 3, 1);
int PO2=A1, 0, 9, 1);
int PO3=A2, 0, 14, 1);
int PO4=A3, 0, 15, 1);
int PO5=A4, 0, 20, 1);
int PO6=A5, 0, 21, 1);
int PO7=A6, 0, 22;
int PO8=A7, 0, 23,;

Pot PO1(A0, 0, 1, 1);
Pot PO2(A1, 0, 10, 1);
Pot PO3(A2, 0, 22, 1);
Pot PO4(A3, 0, 118, 1);
Pot PO5(A4, 0, 30, 1);
Pot PO6(A5, 0, 31, 1);
Pot PO7(A6, 0,  , 1);
Pot PO8(A7, 0,  , 1);*/
//*******************************************************************
//Add pots used to array below like this->  Pot *POTS[] {&PO1, &PO2, &PO3, &PO4, &PO5, &PO6};
//Pot *POTS[] {&PO1,&PO2,&PO3,&PO4,&PO5,&PO6,&PO7,&PO8};
//*******************************************************************




void setup() {
  Serial.begin(9600);
}

void loop() {
  if (NUMBER_POTS != 0) updatePots();
}



//***********************************************************************
void updatePots() {
  for (int i = 0; i < NUMBER_POTS; i = i + 1) {
    
  potOut=analogRead(pot);
    if (potmessage != 1024) Serial.write(PO[i]=potout[i]);
    delay(2000);
  }
}

