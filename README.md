# ShiftedLCD Library for Arduino

Allows communication via Shift registers with alphanumerical liquid crystal displays (LCDs). 
This library works with LCD displays that are modified to use 595 Shift Register (in this case 74HC595) pin compatible. 
You can easily add Shift Register to your LCD. Please refer below link for pinouts and modifing your LCD.

As this was the most modern coded LCD shift register library i found at this time on Github, thanks [omersiar](https://github.com/omersiar).
I decided to fork this project to modify it for my project needs. 

I removed here the SPI library, as for me was more important to be free to configure arduino pins and using as less
libraries as possible. The communication type remaind anyway SPI communication, just without all the features and tools, witch are in SPI library included.

This version of the library is modified thatfor to be able to add LCD support to an existing arduino project,
even if there are only a few pin (and resources) left without a choice to change the wiring to free the predefined 13 and 11th pin.

This librarly basicly "compatible" with the original fork in 1 LCD envirolment if no special SPI library supported feature is in use.

This is SPI only library, parallel and other buses (I2C or 1Wire, etc) are not supported.

Download ZIP file from here to Import to Arduino IDE:

https://github.com/kovge/ShiftedLCD/archive/master.zip

Thanks Stan from 42bots.com for great, clean article and illustration.

http://42bots.com/tutorials/arduino-controlled-lcd-using-a-shift-register-and-the-spi-library/

![alt text][logo]

[logo]: http://42bots.com/wp-content/uploads/2013/12/arduino-lcd-liquidcrystal-spi-connections-v3.png "Wiring"

Components:
 * 10K Potentiometer
 * 470 Ohm Resistor
 * 74HC595 Shift register
 * Jumper cables
 * 1602 LCD Module
 * Your favorite Arduino 

What Works?

* We can use all LiquidCrystal commands
* Directly Hooked up with a shift register, pin configurations are completely up on you

## [wiki](https://github.com/kovge/ShiftedLCD/wiki)

== License ==

Copyright (C) 2006-2008 Hans-Christoph Steiner. All rights reserved.

Copyright (c) 2010 Arduino LLC. All right reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
