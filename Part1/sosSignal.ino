/*
  Blinks the SOS signal from the arduino UNO.

  Use either the LED_BUILTIN or an led with it's anode (+; long leg) in pin 13, and the cathode to GND.

  Has to be pin 13, as it is a built-in pull-down resistor. If you wish to use another of Arduino's pins, you must use a resistor. 220-ohm should be fine.

*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  //5 seconds of light on, followed by 3 seconds off to symbolise the message restarting
    
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(5000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(3000); 

  // S of SOS (is three even dots) . . .
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // dot == 1 second (1000)
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                        // wait half a second (500)
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // dot == 1 second (1000)
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                        // wait half a second (500)
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // dot == 1 second (1000)
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW

  
  delay(3000);                        // THREE second delay between each letter.

  //O of SOS  (is three even dashes) _ _ _
  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2500);                       // dash == 2.5 second (2500)
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                        // wait half a second (500)
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2500);                       // dash == 2.5 second (2500)
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                        // wait half a second (500)
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2500);                       // dash == 2.5 second (2500)
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW 

  delay(3000);                        // THREE second delay between each letter.

  // S of SOS (is three even dots) . . .
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // dot == 1 second (1000)
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                        // wait half a second (500)
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // dot == 1 second (1000)
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                        // wait half a second (500)
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // dot == 1 second (1000)
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW

  delay(3000);                        // THREE second delay between each letter.
  // 
}