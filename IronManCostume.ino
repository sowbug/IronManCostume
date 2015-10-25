#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 0
#define NUM_PIXELS (16)
#define NUM_SPRITES (2)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIN,
                                            NEO_GRB + NEO_KHZ800);

float brightness[NUM_PIXELS] = {0};
float pos[NUM_SPRITES];
float velocity[NUM_SPRITES];

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  Serial.begin(9600);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  for (int i = 0; i < NUM_SPRITES; ++i) {
    pos[i] = float(random(0, 100)) / 100.0;
    velocity[i] = float(random(2, 20)) / 100.0;
    if (random(2) == 1) {
      velocity[i] = -velocity[i];
    }
  }
}

void loop() {
  for (int i = 0; i < NUM_PIXELS; ++i) {
    brightness[i] *= .8;
    if (brightness[i] < 0.05) {
      brightness[i] = 0.05;
    }
  }
  for (int i = 0; i < NUM_SPRITES; ++i) {
    pos[i] += velocity[i];
    if (pos[i] >= 1.0) {
      pos[i] -= 1.0;
    } else {
      if (pos[i] < 0.0) {
        pos[i] += 1.0;
      }
    }
    brightness[(int)(pos[i] * (float)NUM_PIXELS)] = 1.0;
  }

  for (int i = 0; i < NUM_PIXELS; ++i) {
    strip.setPixelColor(i,
                        strip.Color(0, 0, 250.0 * brightness[i]));
  }
  strip.show();

  delay(50);
}

void colorFill(uint32_t c) {
  for (uint16_t i = 0; i < NUM_PIXELS; i++) {
    strip.setPixelColor(i, c);
  }
}
