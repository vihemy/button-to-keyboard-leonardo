/*
  Keyboard Message test
  For the Arduino Leonardo and Micro.
  Sends a text string when a button is pressed.
  The circuit:
  - pushbuttons attached from pin 2 pin 6 connected to Ground
  - Interal Pullups used
  created 24 Oct 2011
  modified 27 Mar 2012
  by Tom Igoe
  modified 11 Nov 2013
  by Scott Fitzgerald
  modified 20 Nov 2018
  by David Grieshammer
  modified by Victor Hempel 11 Aug 2023
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/KeyboardMessage
*/


#include <Keyboard.h>

const int p1Forward = 13;  // input pin for pushbutton
const int p1Right = 12;
const int p1Back = 11;
const int p1Left = 10;
const int p1Button1 = 9;
const int p1Button2 = 8;

const int p2Forward = 7;
const int p2Right = 6;
const int p2Back = 5;
const int p2Left = 4;
const int p2Button2 = 3;
const int p2Button1 = 2;


void setup() {
  // set Pins Input:
  Serial.begin(9600);
  pinMode(p1Forward, INPUT_PULLUP);
  pinMode(p1Right, INPUT_PULLUP);
  pinMode(p1Back, INPUT_PULLUP);
  pinMode(p1Left, INPUT_PULLUP);
  pinMode(p1Button1, INPUT_PULLUP);
  pinMode(p1Button2, INPUT_PULLUP);
  pinMode(p2Forward, INPUT_PULLUP);
  pinMode(p2Right, INPUT_PULLUP);
  pinMode(p2Back, INPUT_PULLUP);
  pinMode(p2Left, INPUT_PULLUP);
  pinMode(p2Button1, INPUT_PULLUP);
  pinMode(p2Button2, INPUT_PULLUP);

  // initialize control over the keyboard:
  Keyboard.begin();
  // Releases all emulated keys, that could have been stuck during startup.
  Keyboard.releaseAll();
}

void loop() {
  //read the pushbutton:
  checkForButtonPress(p1Forward, 'w');
  checkForButtonPress(p1Right, 'd');
  checkForButtonPress(p1Back, 's');
  checkForButtonPress(p1Left, 'a');
  checkForButtonPress(p1Button1, 'r');
  checkForButtonPress(p1Button2, 't');

  checkForButtonPress(p2Forward, 'h');
  checkForButtonPress(p2Right, 'm');
  checkForButtonPress(p2Back, 'n');
  checkForButtonPress(p2Left, 'b');
  checkForButtonPress(p2Button1, 'k');
  checkForButtonPress(p2Button2, 'l');
}


void checkForButtonPress(uint8_t pinName, char key) {
  if (digitalRead(pinName) == HIGH) {
    Keyboard.press(key);
  } else {
    Keyboard.release(key);
  }
}
