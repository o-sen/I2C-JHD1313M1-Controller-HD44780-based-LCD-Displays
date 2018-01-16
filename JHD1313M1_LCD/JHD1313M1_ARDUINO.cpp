/*
  JHD1313M1_ARDUINO.cpp
  2018 Copyright (c)  informatique-et-numerique.org   All right reserved.

  Author:o-senn
  2018-1-15

  -add support to specify i2c controller address in the C++ derived class constructor  @ 2018-1-15
  -this class is intended for use in proteus,  suited only for software simulation works  @ 2018-1-15
  -don't use this class outside of proteus  @ 2018-1-15
  
  
  The MIT License (MIT)

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.1  USA
*/

#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <Wire.h>

#include "JHD1313M1_ARDUINO.h"



JHD1313M1_ARDUINO::JHD1313M1_ARDUINO(uint8_t Address)
{
  mAddress = Address ;
}

void JHD1313M1_ARDUINO::i2c_transmettre_octet(unsigned char dta)
{
    Wire.beginTransmission(mAddress>>1);        // transmit to device #4
    Wire.write(dta);                            // sends five bytes
    Wire.endTransmission();                     // stop transmitting
}

void JHD1313M1_ARDUINO::i2c_transmettre_octetS(unsigned char *dta, unsigned char len)
{
    Wire.beginTransmission(mAddress>>1);        // transmit to device #4
    for(int i=0; i<len; i++)
    {
        Wire.write(dta[i]);
    }
    Wire.endTransmission();                     // stop transmitting
}


void JHD1313M1_ARDUINO::setCursor(uint8_t col, uint8_t row)
{

    col = (row == 0 ? col|0x80 : col|0xc0);
    unsigned char dta[2] = {0x80, col};

    i2c_transmettre_octetS(dta, 2);

}


// send command
inline void JHD1313M1_ARDUINO::command(uint8_t value)
{
    unsigned char dta[2] = {0x80, value};
    i2c_transmettre_octetS(dta, 2);
}

// clear display
void JHD1313M1_ARDUINO::clear()
{
    command(LCD_CLEARDISPLAY);        // clear display, set cursor position to zero
    delayMicroseconds(2000);          // this command takes a long time!
}
// send data
inline size_t JHD1313M1_ARDUINO::write(uint8_t value)
{

    unsigned char dta[2] = {0x40, value};
    i2c_transmettre_octetS(dta, 2);
    return 1; // assume sucess
}

