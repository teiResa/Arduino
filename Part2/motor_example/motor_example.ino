/*
    Motor Example

    from page 124 (PDF 139) of Arduino For Dummies, 2nd Edn
    Part 2, Chapter 7: Getting Physical with Arduino

    Copy: 2023-02-11
*/

int motorPin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
  }

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(motorPin, HIGH);
  delay(1000);

  digitalWrite(motorPin, LOW);
  delay(1000);

}
