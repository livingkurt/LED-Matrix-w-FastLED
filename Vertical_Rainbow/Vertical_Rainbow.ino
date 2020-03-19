#include <FastLED.h>
#define LED_PIN 5
#define NUM_LEDS 100
#define BRIGHTNESS 255
#define LED_TYPE WS2811
#define COLOR_ORDER RGB
#define RATE 10
#define GAP 10
#define NUM_X 10

CRGB leds[NUM_LEDS];

#define BRIGHTNESS 255
#define FRAMES_PER_SECOND 120

int start_hue;
int delta_hue = 20;
int i = 0;

int ROW = NUM_LEDS / NUM_X;

void setup()
{
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  Serial.begin(9600);
  FastLED.setBrightness(BRIGHTNESS);
}
int toLinear(int x, int y)
{
  int result = 0;
  if (y % 2 == 0)
  { // even
    result = ROW * y + (ROW - 1 - x);
  }
  else
  { //odd
    result = ROW * y + x;
  }
  return result;
}

void loop()
{
  start_hue = -1 * millis() / RATE;
  for (int y = 0; y < ROW; y++)
  {
    for (int x = 0; x < ROW; x++)
    {

      int index = toLinear(x, y);
      leds[index] = CHSV(start_hue, 255, 255);
    }

    start_hue += delta_hue;
    FastLED.show();
  };
}
