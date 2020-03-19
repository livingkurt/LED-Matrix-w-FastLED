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

void setup()
{
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    Serial.begin(9600);

}

void loop()
{
    delta_hue = 1;
    start_hue = -1 * millis() / RATE;
    for (int i = 0; i < NUM_LEDS; i++)

    {
        fadeToBlackBy( leds, NUM_LEDS, 5);
        int pos = beatsin16(10,i,NUM_LEDS);
        leds[pos] += CHSV( start_hue, 255, 255);
        start_hue += delta_hue;
    };

    

    FastLED.show();

}
