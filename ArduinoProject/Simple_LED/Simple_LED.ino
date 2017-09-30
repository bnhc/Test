/// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      288


// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 5; // delay for half a second
int brightness = 5;

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
  //pixels.setBrightness(brightness);
}

uint32_t a[] = { pixels.Color(255, 0, 0), pixels.Color(0, 255, 0), pixels.Color(0, 0, 255)};

void loop() {
  
  for (int i = 0; i < 3; i++) {
    test(a[i]);
  }
  //setMarquee(pixels.Color(127, 0, 0));
  
}

void setMarquee(uint32_t c) {
  for (int i = 0; i < NUMPIXELS; i++) {
    if (i != 0) {
      pixels.setPixelColor(i - 1, pixels.Color(0, 0, 0));
    } else {
      pixels.setPixelColor(NUMPIXELS - 1, pixels.Color(0, 0, 0));
    }
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, c); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
  }
}

void setAllON(uint32_t c) {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, c);
  }
}

void test(uint32_t c) {
  setMarquee(c);
  delay(200);
  //setAllON(c);
  //if (brightness < 100) {
  //  pixels.setBrightness(brightness+=5);
  //} else {
  //  pixels.setBrightness(brightness-=5);
  //}
}





