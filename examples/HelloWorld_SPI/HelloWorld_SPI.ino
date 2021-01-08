/*
  ShiftedLCD Library - Hello World
 
 Demonstrates the use a 16x2 LCD display with a Shift Register.
 Library works with LCD displays that are modified to use 
 595 Shift Register (in this case 74HC595) pin compatible.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
 You can easily add Shift Register to your LCD
 Please refer below link for pinouts and modifing your LCD
 https://github.com/kovge/ShiftedLCD
 forked from:
 https://github.com/omersiar/ShiftedLCD

 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 12 Feb 2012
 by Juan Hernandez
 modified 16 Nov 2016
 by Ömer Şiar Baysal
 modified 08 Jan 2021
 by Gergely Kovács
 
 This example code is in the public domain.

 Default Hookup Between Arduino and 74HC595: 
 Arduino D9 -> latch pin/ST_CP of 74HC595 (12)
 Arduino D13 -> clock pin/SH_CP of 74HC595 (11)
 Arduino D11 -> data pin/DS of 74HC595 (14)

 Hookup Between LCD and 74HC595: 
 shiftRegister pins 1,2,3,4,5,6,7 represent rs, rw, enable, d4-7 in that order
 but we are not using RW so RW it's zero or 255
*/

// include the library code:
#include <ShiftedLCD.h>



// You can initialize it only with latchPin (default clockPin is 13, default dataPin is 11):
// LiquidCrystal lcd(9);
// or with all the pins: latchPin, clockPin, dataPin
LiquidCrystal lcd(9,13,11);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);
  // lets wait a bit 
  delay(100);
}
