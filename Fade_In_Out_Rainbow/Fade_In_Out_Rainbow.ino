#include <FastLED.h>
#define LED_PIN 5
#define NUM_LEDS 100
#define BRIGHTNESS 255
#define LED_TYPE WS2811
#define COLOR_ORDER RGB
#define STROBE 1

CRGB leds[NUM_LEDS];

#define BRIGHTNESS 255

int rainbow_palette[] = {0, 32, 64, 96, 128, 160, 192, 224};
int numColors = (sizeof(rainbow_palette) / sizeof(rainbow_palette[0]));

int ROW = NUM_LEDS / NUM_X;

void setup()
{
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  Serial.begin(9600);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{
  for (int h = 0; h < numColors; h++) {
    for (int i = 50; i < BRIGHTNESS; i++)
    {
      fill_solid(leds, NUM_LEDS, CHSV(rainbow_palette[h], 255, i)); // Set all to Off.
      FastLED.delay(STROBE);
      FastLED.show();
    }

    for (int i = BRIGHTNESS; i > 50; i--)
    {
      fill_solid(leds, NUM_LEDS, CHSV(rainbow_palette[h], 255, i)); // Set all to Off.
      FastLED.delay(STROBE);
      FastLED.show();
    }
  }
}
