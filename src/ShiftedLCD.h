#ifndef ShiftedLCD_h
#define ShiftedLCD_h

#include <inttypes.h>
#include "Print.h"

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

class LiquidCrystal : public Print {
public:
  //Pins to ShiftRegister 74HC595, in order ST_CP, SH_CP, DS. 74HC595 Pinout in order: 12, 11, 14   ##############
  LiquidCrystal(uint8_t latchPin, uint8_t clockPin, uint8_t dataPin, uint8_t flip); 	// Arduino Pins Hooked up to 74HC595 #####
  //Pins to ShiftRegister 74HC595, in order ST_CP, SH_CP, DS. 74HC595 Pinout in order: 12, 11, 14   ##############
  LiquidCrystal(uint8_t latchPin, uint8_t clockPin, uint8_t dataPin); 	// Arduino Pins Hooked up to 74HC595 #####
  // default clockPin is 13, default dataPin is 11 on Arduino
  LiquidCrystal(uint8_t latchPin);    

  void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);

  void clear();
  void home();

  void noDisplay();
  void display();
  void noBlink();
  void blink();
  void noCursor();
  void cursor();
  void scrollDisplayLeft();
  void scrollDisplayRight();
  void leftToRight();
  void rightToLeft();
  void autoscroll();
  void noAutoscroll();

  void createChar(uint8_t, uint8_t[]);
  void setCursor(uint8_t, uint8_t); 
  virtual size_t write(uint8_t);
  void command(uint8_t);
private:
  void send(uint8_t, uint8_t);
  void spiSendOut();      // SPI ###########################################
  void write4bits(uint8_t);
  void pulseEnable();
  void initSPI();
  
  //SPI #####################################################################
  uint8_t _bitString;	//for SPI  bit0=not used, bit1=RS, bit2=RW, bit3=Enable, bits4-7 = DB4-7
  uint8_t _latchPin;	//Pin connected to ST_CP of 74HC595
  uint8_t _clockPin;	//Pin connected to SH_CP of 74HC595
  uint8_t _dataPin;	//Pin connected to DS of 74HC595

  uint8_t _flip;
  uint8_t _rs_index;
  uint8_t _e_index;
  uint8_t _d_start;
  uint8_t _d_end;
  uint8_t _bit_order;
  
  uint8_t _displayfunction;
  uint8_t _displaycontrol;
  uint8_t _displaymode;

  uint8_t _initialized;

  uint8_t _numlines,_currline;
};

#endif
