#include <FastLED.h>
#define LED_PIN 5
#define NUM_LEDS 100
#define BRIGHTNESS 255
#define LED_TYPE WS2811
#define COLOR_ORDER RGB
#define RATE 10
#define GAP 10
CRGB leds[NUM_LEDS];

int start_hue;
int delta_hue;
int h = 0;
int j = 0;

void setup()
{
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    Serial.begin(9600);
    // FastLED.clear();
    // FastLED.show();
}

void loop()
{
    delta_hue = 2;
    start_hue = -1 * millis() / RATE;
    for (int i = 0; i < NUM_LEDS/2; i++)
    {
        leds[i] = CHSV(start_hue, 255, 255);
        leds[NUM_LEDS - 1 - i] = CHSV(start_hue, 255, 255);
        start_hue += delta_hue;
    };
    FastLED.show();
}
