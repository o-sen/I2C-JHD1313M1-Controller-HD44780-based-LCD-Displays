

#include <Wire.h>
#include "JHD1313M1_ARDUINO.h"

JHD1313M1_ARDUINO lcd(0x7c) ;
JHD1313M1_ARDUINO lcd2(0x7e) ;
JHD1313M1_ARDUINO lcd3(0x6c) ;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;


void Init(JHD1313M1_ARDUINO * mlcd)
{
   // set up the LCD's number of columns and rows:
    //mlcd->begin(16, 2);
    
    //mlcd->setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    mlcd->print("hello, world!");

    delay(1000);

}

void Affichage1(JHD1313M1_ARDUINO * mlcd)
{
  // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    mlcd->setCursor(0, 1);
    // print the number of seconds since reset:
    mlcd->print(millis()/1000);

    delay(100);
}

void Affichage2(JHD1313M1_ARDUINO * mlcd)
{
  // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    mlcd->setCursor(0, 1);
    // print half the number of seconds since reset:
    mlcd->print(millis()/2000);

    delay(100);
}
void Affichage3(JHD1313M1_ARDUINO * mlcd)
{
  // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    mlcd->setCursor(0, 1);
    // print quarter the number of seconds since reset:
    mlcd->print(millis()/4000);

    delay(100);
}
void setup() 
{
   Init(&lcd) ;
   Init(&lcd2);
   Init(&lcd3);
}

void loop() 
{
    
    Affichage1(&lcd);
    Affichage2(&lcd2);
    Affichage3(&lcd3);
    
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
