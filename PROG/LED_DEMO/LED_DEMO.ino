#include <OctoWS2811.h>

const int ledsPerStrip = 66; //39+39+60+60;

DMAMEM int displayMemory[ledsPerStrip*6];
int drawingMemory[ledsPerStrip*6];

const int config = WS2811_GRB | WS2811_800kHz;

OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);

void setup() {
  leds.begin();
  leds.show();
  Serial.begin(9600);
  Serial.println( leds.numPixels());
}

#define RED    0xFF0000
#define GREEN  0x0000FF
#define BLUE   0x00FF00
#define YELLOW 0xFF00FF
#define PINK   0xFF8810
#define ORANGE 0xE00058
#define WHITE  0xFFFFFF

void loop() {
int microsec = 500000 / ledsPerStrip;  // change them all in 2 seconds
//int microsec = 1;


  colorWipe(BLUE, microsec);
  colorWipe(GREEN, microsec);
  colorWipe(BLUE, microsec);
  colorWipe(YELLOW, microsec);
  colorWipe(PINK, microsec);
  colorWipe(ORANGE, microsec);
  colorWipe(WHITE, microsec);
}

void colorWipe(int color, int wait)
{
  for (int i=0; i < ledsPerStrip; i++) {
    leds.setPixel(i, color);
    leds.show();
    Serial.println("lightling up a led groups !");
    delayMicroseconds(wait);
  }
  Serial.println("\rNEXT COLOR");
}
