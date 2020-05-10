// This DigiSpark script opens up Rick Astley's - Never Gonna Give You Up and also a
// fake Windows update screen and then maximizes it using f 
#include "DigiKeyboard.h"
void setup() {
  //empty
}
void loop() {
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);    //opens the spotlight search
  DigiKeyboard.delay(600);
  DigiKeyboard.print("terminal");                         //opens the terminal
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.print("open /Applications/safari.app");    //opens safari 
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("https://youtu.be/dQw4w9WgXcQ?t=43s");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.sendKeyStroke(KEY_N, MOD_GUI_LEFT);        //opens a new safari window
  DigiKeyboard.delay(500);
  DigiKeyboard.print("https://www.youtube.com/watch?v=Ho3Lw90kzrY");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);
  DigiKeyboard.sendKeyStroke(KEY_F);                      //full screen on YT
  DigiKeyboard.delay(5000);
  
  for(;;){ /*empty*/ }
}
