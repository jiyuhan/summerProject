#ifndef MT9M112_REGS_H
#define MT9M112_REGS_H
#include "../ArduCAM.h"
//#include <Wire.h>

const struct sensor_reg MT9M112_QVGA[] PROGMEM =
{
	
	#if 1 //MCLK == 24M
	{0xf0,0x0000},
	{0x66,0x1001},
	{0x67,0x0501},
	{0x65,0xa000},
	{0xff,0x0064},
	{0x65,0x2000},
	{0xff,0x0064},
	#endif
	{0xf0,0x0000},
	{0x0d,0x0009},
	{0xff,0x0020},
	{0x0d,0x0008},
	{0xf0,0x0000},
	{0x01,0x0024},
	{0x03,0x0400},// default value  
	{0x04,0x0500},
	{0x30,0x042a},
	{0xf0,0x0001},
	{0x05,0x000f},
	{0x25,0x004d},// saturation adjustment, default value  0x4d
	{0x3b,0x0430},//0x0436
	{0x3c,0x0400},
	{0x47,0x322e},
	{0x9d,0x3ce0},
	
	{0xf0,0x0002},
	{0x28,0xef02},//0xef3e
	{0x06,0x748e},
	{0x02,0x00ee},// base matrix signs
	{0x15,0x00d9},// delta coefficients signs
	{0x09,0x0067},//k1
	{0x0a,0x009a},//k2
	{0x0b,0x0028},//k3
	{0x0c,0x0030},//k4
	{0x0d,0x00ca},//k5
	{0x0e,0x0037},//k6
	{0x0f,0x001a},//k7
	{0x10,0x0065},//k8
	{0x11,0x0086},//k9
	{0x16,0x005e},//d1  0x0062
	{0x17,0x0084},//d2
	{0x18,0x004d},//d3
	{0x19,0x0024},//d4
	{0x1a,0x001f},//d5
	{0x1b,0x002f},//d6
	{0x1c,0x0004},//d7
	{0x1d,0x0023},//d8
	{0x1e,0x0010},//d9
	{0x03,0x3922},// base matrix scale k1-k5
	{0x04,0x0524},// base matrix scale k6-k9 0x04e4
	{0xf0,0x0002},
	{0x1f,0x0180},
	{0x20,0xc814},//0xdc0c
	{0x21,0x8080},
	{0x22,0x9080},
	{0x23,0x8878},
	{0x26,0x8000},
	{0x27,0x8008},
	{0x2e,0x0c44},// 0x0d20
	{0x3e,0x1cff},
	{0x46,0x00b0},
	{0x5b,0x8002},
	{0x5c,0x110c},
	{0x5d,0x1510},
	{0x5e,0x534c},
	{0x5f,0x2b21},
	{0x24,0x7f40},
	{0x60,0x0002},
	{0x62,0x1010},
	{0x65,0x0000},
	{0xdc,0x0ff8},
	{0xdd,0x0ce0},
	{0xf0,0x0001},
	{0x47,0x202e},
	{0x80,0x0006},// lens correction control
	{0x81,0x0000},// vertical red knee 0 and initial value  0x0009
	{0x82,0xfe05},// vertical red knees 2 and 1
	{0x83,0x0000},// vertical red knees 4 and 30x00ff
	{0x84,0x0c00},// vertical green knee 0 and initial value
	{0x85,0xfe02},// vertical green knees 2 and 1
	{0x86,0x00ff},// vertical green knees 4 and 3
	{0x87,0x0701},// vertical blue knee 0 and initial value 1003
	{0x88,0xfc06},// vertical blue knees 2 and 1
	{0x89,0x00ff},// vertical blue knees 4 and 3
	{0x8a,0x0801},// horizontal red knee 0 and initial value
	{0x8b,0x030e},// horizontal red knees 2 and 1
	{0x8c,0xfefd},// horizontal red knees 4 and 3
	{0x8d,0x00ff},// horizontal red knee 5
	{0x8e,0x0601},// horizontal green knee 0 and initial value
	{0x8f,0x040b},// horizontal green knees 2 and 1
	{0x90,0xfefb},// horizontal green knees 4 and 3
	{0x91,0x00fe},// horizontal green knee 5
	{0x92,0x0600},// horizontal blue knee 0 and initial value
	{0x93,0x040b},// horizontal blue knees 2 and 1
	{0x94,0xfefd},// horizontal blue knees 4 and 3
	{0x95,0x00ff},// horizontal blue knees 5
	{0xb6,0x0204},// lens vertical red knees 6 and 5
	{0xb7,0xfbfa},// lens vertical red knees 8 and 7
	{0xb8,0x0503},// lens vertical green knees 6 and 5
	{0xb9,0xfaf8},// lens vertical green knees 8 and 7
	{0xba,0x0401},// lens vertical blue knees 6 and 5
	{0xbb,0xfef8},// lens vertical blue knees 8 and 7
	{0xbc,0xff01},// lens horizontal red knees 7 and 6
	{0xbd,0xf4ff},// lens horizontal red knees 9 and 8
	{0xbe,0x00fb},// lens horizontal red knee 10
	{0xbf,0x0000},// lens horizontal green knees 7 and 6
	{0xc0,0xf8fd},// lens horizontal green knees 9 and 8
	{0xc1,0x00f7},// lens horizontal green knee 10
	{0xc2,0x01ff},// lens horizontal blue knees 7 and 6
	{0xc3,0xf5fc},// lens horizontal blue knees 9 and 8
	{0xc4,0x00fa},// lens horizontal blue knee 10
	{0x06,0x748e},
	{0x9d,0x3ce0},// defect correction control
	{0xf0,0x0002},
	{0x2e,0x0d3a},// 0x0d32
	{0x37,0x0081},
	{0x36,0x7810},
	{0xf0,0x0001},
	{0x06,0xf48e},
	{0xf0,0x0001},
	{0x06,0x648e},
	{0xf0,0x0002},
	{0x5b,0x0001},//0x0003
	
	{0xf0,0x0000},
	{0x20,0x0102},
	{0x21,0x8000},
	{0x22,0x090d},
	
	{0xf0,0x0000},
	{0x07,0x0374},   //horizontal blank
	{0x08,0x0009},
	{0xf0,0x0002},
	{0xc8,0x0000},
	{0x2f,0xd100},// auto exposure speed A
	{0x57,0x0271},
	{0x58,0x0271},
	{0xf0,0x0000},
	{0x21,0x8400},
	{0x22,0x090d},
	{0x68,0x0070},
	{0xf0,0x0001},   
	{0xa6,0x0500},// horizontal zoom size A
	{0xa7,0x0140},// horizontal output size A   
	{0xa9,0x0400},// vertical zoom size A
	{0xaa,0x00f0},// vertical output size A
	{0x3a,0x0100},// [7:6]:RGB565
	{0x53,0x1105},// gamma start A
	{0x54,0x5d33},
	{0x55,0xad8d},
	{0x56,0xd6c4},
	{0x57,0xf3e6},
	{0x58,0xff00},// gamma end A
	{0xf0,0x0000},

	{0xff, 0xffff},
};

#endif
