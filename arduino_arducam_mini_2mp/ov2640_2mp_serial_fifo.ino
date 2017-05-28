// ArduCAM demo (C)2014 Lee
// web: http://www.ArduCAM.com
// This program is a demo of how to use most of the functions
// of the library with a supported camera modules.
//
// This demo was made for Omnivision OV2640 sensor.
// 1. Set the sensor to JPEG output mode.
// 2. Capture and buffer the image to FIFO. 
// 3. Transfer the captured JPEG image back to host via Arduino board USB port.
// 4. Resolution can be changed by myCAM.OV2640_set_JPEG_size() function.
// This program requires the ArduCAM V3.0.1 (or above) library and Rev.C ArduCAM shield
// and use Arduino IDE 1.5.2 compiler


/**************************************************************
 * Thomas Han did not write this, but he took Lee’s           *
 * work from his library, so it can work with his project.     *
 **************************************************************/

#include <UTFT_SPI.h>
#include <Wire.h>
#include <ArduCAM.h>
#include <SPI.h>
#include <SD.h>
#include "memorysaver.h"

// set pin 10 as the slave select for the digital pot:
const int SPI_CS = 10;


ArduCAM myCAM(OV2640,10);
UTFT myGLCD(SPI_CS);

void setup()
{
  uint8_t vid,pid;
  uint8_t temp;
  #if defined (__AVR__)
    Wire.begin(); 
  #endif
  #if defined(__arm__)
    Wire1.begin(); 
  #endif
  Serial.begin(115200);

  // set the SPI_CS as an output:
  pinMode(SPI_CS, OUTPUT);

  // initialize SPI:
  SPI.begin(); 

  myCAM.write_reg(ARDUCHIP_TEST1, 0x55);
  temp = myCAM.read_reg(ARDUCHIP_TEST1);
  
  myCAM.set_mode(MCU2LCD_MODE);

  myCAM.rdSensorReg8_8(OV2640_CHIPID_HIGH, &vid);
  myCAM.rdSensorReg8_8(OV2640_CHIPID_LOW, &pid);
  
  //Change to JPEG capture mode and initialize the OV2640 module	
  myCAM.set_format(JPEG);
  myCAM.InitCAM();
  myCAM.OV2640_set_JPEG_size(OV2640_160x120);
}

void loop()
{
  uint8_t temp,temp_last;
  uint8_t start_capture = 0;

  if (Serial.read() == 0x10) {
      start_capture = 1; 
      myCAM.flush_fifo();
  }
  //start_capture = 1;
  if(start_capture) {
    //Clear the capture done flag 
    myCAM.clear_fifo_flag();	 
    //Start capture
    myCAM.start_capture();	 
  }
  if(myCAM.get_bit(ARDUCHIP_TRIG,CAP_DONE_MASK)) {
    while( (temp != 0xD9) | (temp_last != 0xFF) ) {
        temp_last = temp;
	temp = myCAM.read_fifo();
	Serial.write(temp);
    }
  

    //Clear the capture done flag 
    myCAM.clear_fifo_flag();
    start_capture = 0;
  }
}

   


