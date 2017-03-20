/*
 * Motion Lights
 * 
 * A bootstrap code (Example Neo-pixel code + Example PIR sensor code) to make a motion detected light strip. It uses Neo-pixels and a PIR sensor from Adafruit.
 * 
 */




#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUMPIXELS 60

int ledPin = 13;                // choose the pin for the LED
int inputPin = 4;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int brightness = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    strip.begin();
    strip.show(); //Sets strip to blank

  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
}


void loop() {
    
  int mode = 5;
  val = digitalRead(inputPin);  // read input value

  if (val == HIGH) {            // check if the input is HIGH    
    if (pirState == LOW) {
      rainbowCycle(1);
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH){
       for (int i = 0; i<NUMPIXELS; i++) {
          strip.setPixelColor(i, strip.Color(0,0,0));
       }
      strip.show();
      pirState = LOW;
    }
  }
}





void rainbow(uint8_t wait) {
    uint16_t i, j;
  
    for(j=0; j<256; j++) {
      for(i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, Wheel((i+j) & 255));
      }
      strip.show();
      delay(wait);
    }
  }


// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
    uint16_t i, j;
  
    for(j=0; j<256*2; j++) { // 3 cycles of all colors on wheel
      for(i=0; i< strip.numPixels(); i++) {
        strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
      }
      strip.show();
      delay(wait);
    }
}


//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
