/*
  JHD1313M1_ARDUINO.h
  2018 Copyright (c)  informatique-et-numerique.org   All right reserved.

  Author:o-senn
  2018-1-15

  -this class is intended for use in proteus. it is suited only for simulation  @ 2018-1-15
  -don't use this class outside of proteus  @ 2018-1-15
  -add support to specify i2c controller address in the C++ derived class constructor  @ 2018-1-15
  
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

#ifndef HEADER_JHD1313M1_ARDUINO
#define HEADER_JHD1313M1_ARDUINO

#define LCD_CLEARDISPLAY 0x01

// Device I2C Arress
// Default LCD_ADDRESS (inside proteus)   (0x7c)
// Default RGB_ADDRESS (inside proteus)   (0xc4)

class JHD1313M1_ARDUINO :   public Print  {
  public:
  JHD1313M1_ARDUINO(uint8_t Address);

  void setCursor(uint8_t, uint8_t); 
  void command(uint8_t);  // i'm defining command and clear together otherwise it will not work
  void clear() ;
  virtual size_t write(uint8_t);
  void i2c_transmettre_octet(unsigned char dta) ;
  void i2c_transmettre_octetS(unsigned char *dta, unsigned char len) ;
  private : 
  uint8_t mAddress ;

} ;
#endif
