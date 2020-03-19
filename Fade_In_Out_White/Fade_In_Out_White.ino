#include <FastLED.h>
#define LED_PIN 5
#define NUM_LEDS 100
#define BRIGHTNESS 255
#define LED_TYPE WS2811
#define COLOR_ORDER RGB
#define STROBE 1

CRGB leds[NUM_LEDS];

#define BRIGHTNESS 255

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
void loop()
{
  for (int i = 50; i < BRIGHTNESS; i++)
  {
    fill_solid(leds, NUM_LEDS, CHSV(0, 0, i)); // Set all to Off.
    FastLED.delay(STROBE);
    FastLED.show();
  }

  for (int i = BRIGHTNESS; i > 50; i--)
  {
    fill_solid(leds, NUM_LEDS, CHSV(0, 0, i)); // Set all to Off.
    FastLED.delay(STROBE);
    FastLED.show();
  }
}
