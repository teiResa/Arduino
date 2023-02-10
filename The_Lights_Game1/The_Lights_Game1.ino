/*
  The Lights Game (mk 1)

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LEDs (all PWM capable) attached from pins 3, 5, 6, 9, 10, and 11
  to ground through 220 ohm resistors
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2023
  by TeiResa <teiResa.github.io>

  Helpful Examples:
  Fading, button
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
// The PWM capable pins are used for the SIX (6) total LED, labelled 0 through 5.
const int ledPin0 = 3;
const int ledPin1 = 5;
const int ledPin2 = 6;
const int ledPin3 = 9;
const int ledPin4 = 10;
const int ledPin5 = 11;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton state

void setup() {
  // initialize the LED pins as outputs:
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // light up the LEDs one-by-one
    
    //Just using digitalWrite for now, later I intend to maybe update with analog write, unless the PWM is needed for the piezo to make noise. I am 99% sure it does need that. In such case, I would just add more LEDs to make it more fun to watch. Maybe Even update it for use with the 8 displays or the 8*8 or 8*32 matrix displays I have.
    // Side note, I was also thinking about making this with HTML, CSS, and JS for a funsies digital-only verson. Shitty APP idea too? Maybe.
    digitalWrite(ledPin0, HIGH);
    delay(500);                    //1 sec delay before next light changes state.
    digitalWrite(ledPin1, HIGH);
    delay(500);                    
    digitalWrite(ledPin2, HIGH);
    delay(500);                    
    digitalWrite(ledPin3, HIGH);
    delay(500);                    
    digitalWrite(ledPin4, HIGH);
    delay(500);                    
    digitalWrite(ledPin5, HIGH);
    delay(0);                    // NO delay before next light changes state.
  } else {
    // turn LEDs off, but in reverse order.
    digitalWrite(ledPin5, LOW);
    delay(250);                    //1 sec delay before next light changes state.
    digitalWrite(ledPin4, LOW);
    delay(250);
    digitalWrite(ledPin3, LOW);
    delay(250);
    digitalWrite(ledPin2, LOW);
    delay(250);
    digitalWrite(ledPin1, LOW);
    delay(250);
    digitalWrite(ledPin0, LOW);
    delay(0);                    // NO delay before next light changes state.
  }
}