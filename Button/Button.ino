

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 4; 
//const int buttonPin = 5; 
//const int buttonPin = 6; 
//const int buttonPin = 7; 
//const int buttonPin = 8; 
//const int buttonPin = 9; 
//const int buttonPin = 10; 
//const int buttonPin = 11; 
//const int buttonPin = 12; 
                              // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
