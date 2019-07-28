/*
 * start rewrite from:
 * https://github.com/adafruit/Adafruit-GFX-Library.git
 * https://github.com/adafruit/Adafruit-SSD1351-library.git
 */
#ifndef _ARDUINO_SSD1351_H_
#define _ARDUINO_SSD1351_H_

#include "Arduino.h"
#include "Print.h"
#include "Arduino_GFX.h"
#include "Arduino_TFT.h"

#define SSD1351_TFTWIDTH 128  ///< SSD1351 max TFT width
#define SSD1351_TFTHEIGHT 128 ///< SSD1351 max TFT height

#define SSD1351_SETCOLUMN 	  	0x15
#define SSD1351_SETROW    	  	0x75
#define SSD1351_WRITERAM    		0x5C
#define SSD1351_READRAM     		0x5D
#define SSD1351_SETREMAP 	    	0xA0
#define SSD1351_STARTLINE 	  	0xA1
#define SSD1351_DISPLAYOFFSET 	0xA2
#define SSD1351_DISPLAYALLOFF 	0xA4
#define SSD1351_DISPLAYALLON  	0xA5
#define SSD1351_NORMALDISPLAY 	0xA6
#define SSD1351_INVERTDISPLAY 	0xA7
#define SSD1351_FUNCTIONSELECT 	0xAB
#define SSD1351_DISPLAYOFF 	  	0xAE
#define SSD1351_DISPLAYON     	0xAF
#define SSD1351_PRECHARGE 	  	0xB1
#define SSD1351_DISPLAYENHANCE	0xB2
#define SSD1351_CLOCKDIV 	    	0xB3
#define SSD1351_SETVSL 	      	0xB4
#define SSD1351_SETGPIO     		0xB5
#define SSD1351_PRECHARGE2   		0xB6
#define SSD1351_SETGRAY     		0xB8
#define SSD1351_USELUT 	      	0xB9
#define SSD1351_PRECHARGELEVEL  0xBB
#define SSD1351_VCOMH 	        0xBE
#define SSD1351_CONTRASTABC	    0xC1
#define SSD1351_CONTRASTMASTER  0xC7
#define SSD1351_MUXRATIO        0xCA
#define SSD1351_COMMANDLOCK     0xFD
#define SSD1351_HORIZSCROLL     0x96
#define SSD1351_STOPSCROLL      0x9E
#define SSD1351_STARTSCROLL     0x9F

class Arduino_SSD1351 : public Arduino_TFT
{
public:
  Arduino_SSD1351(Arduino_DataBus *bus, int8_t rst = -1, uint8_t r = 0);

  virtual void begin(uint32_t speed = 0);
  virtual void writeAddrColumn(uint16_t x, uint16_t w);
  virtual void writeAddrRow(uint16_t y, uint16_t h);
  virtual void writeAddrMemWrite();

  virtual void setRotation(uint8_t r);
  virtual void invertDisplay(bool);
  virtual void displayOn();
  virtual void displayOff();

protected:
  virtual void tftInit();

private:
};

#endif
