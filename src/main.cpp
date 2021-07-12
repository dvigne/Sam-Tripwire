#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(11, INPUT);

  TCCR2A = _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(WGM22)  | _BV(CS21);
  OCR2A = 51;
  OCR2B = 26;
}

void loop() {
  if(digitalRead(11) == LOW) {
    Serial.println("Signal Low");
  }
  else {
    Serial.println("Signal High");
  }
}
