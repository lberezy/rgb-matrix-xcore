/*
 * rgb-matrix-xcore.h
 *
 *  Created on: May 18, 2014
 *      Author: lucas
 */

#ifndef RGB_MATRIX_XCORE_H_
#define RGB_MATRIX_XCORE_H_


#define RESOLUTION_BITS 2
#define WAIT_PERIOD 5
#define USE_GAMMA 1
#define PANEL_WIDTH 32
#define PANEL_HEIGHT 32
#define PANEL_SCANLINE_DIVISOR 16 // 1/16th of panel can be driven at a time

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} pixel_t;

interface display {
     void setPixel(const uint8_t x, const uint8_t y, const pixel_t pixel);
     pixel_t getPixel(const uint8_t x, const uint8_t y);
};

void refreshDisplay(pixel_t framebuffer[PANEL_WIDTH][PANEL_HEIGHT]);
pixel_t ColorHSV(long hue, uint8_t sat, uint8_t val);
void setPixel( uint8_t x, uint8_t y, const pixel_t pixel);
pixel_t getPixel(const uint8_t x, const uint8_t y);
void display_server(server interface display disp);
void display_client(client interface display disp);


static const int8_t sinetab[256] = {
     0,   2,   5,   8,  11,  15,  18,  21,
    24,  27,  30,  33,  36,  39,  42,  45,
    48,  51,  54,  56,  59,  62,  65,  67,
    70,  72,  75,  77,  80,  82,  85,  87,
    89,  91,  93,  96,  98, 100, 101, 103,
   105, 107, 108, 110, 111, 113, 114, 116,
   117, 118, 119, 120, 121, 122, 123, 123,
   124, 125, 125, 126, 126, 126, 126, 126,
   127, 126, 126, 126, 126, 126, 125, 125,
   124, 123, 123, 122, 121, 120, 119, 118,
   117, 116, 114, 113, 111, 110, 108, 107,
   105, 103, 101, 100,  98,  96,  93,  91,
    89,  87,  85,  82,  80,  77,  75,  72,
    70,  67,  65,  62,  59,  56,  54,  51,
    48,  45,  42,  39,  36,  33,  30,  27,
    24,  21,  18,  15,  11,   8,   5,   2,
     0,  -3,  -6,  -9, -12, -16, -19, -22,
   -25, -28, -31, -34, -37, -40, -43, -46,
   -49, -52, -55, -57, -60, -63, -66, -68,
   -71, -73, -76, -78, -81, -83, -86, -88,
   -90, -92, -94, -97, -99,-101,-102,-104,
  -106,-108,-109,-111,-112,-114,-115,-117,
  -118,-119,-120,-121,-122,-123,-124,-124,
  -125,-126,-126,-127,-127,-127,-127,-127,
  -128,-127,-127,-127,-127,-127,-126,-126,
  -125,-124,-124,-123,-122,-121,-120,-119,
  -118,-117,-115,-114,-112,-111,-109,-108,
  -106,-104,-102,-101, -99, -97, -94, -92,
   -90, -88, -86, -83, -81, -78, -76, -73,
   -71, -68, -66, -63, -60, -57, -55, -52,
   -49, -46, -43, -40, -37, -34, -31, -28,
   -25, -22, -19, -16, -12,  -9,  -6,  -3
};

#endif /* RGB_MATRIX_XCORE_H_ */
