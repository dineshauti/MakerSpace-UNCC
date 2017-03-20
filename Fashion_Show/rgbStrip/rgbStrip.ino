// Adafruit_NeoPixel-master - Version: Latest 
#include <Adafruit_NeoPixel.h>

/*
File:        neopixel_example.ino
Author:      Chirag Patel
Description: This sketch allows users to view some examples of what you can do with an WS2812B LED RGB LED Strip
             using the Adafruit NeoPixel library.

*/

#define PIN 2
#define NUMPIXELS 60
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    strip.begin();
    //strip.show(); //Sets strip to blank
}

void loop() {
  /* Here are the different modes, change the number below to set the mode */
  /*    Modes                     */
  /*      1 - All blue            */
  /*      2 - All green           */
  /*      3 - All red             */
  /*      4 - Brightness ramp     */
  /*      5 - "Party Mode"        */
  /*      6 - Twinkle             */
  /*                              */
    int mode = 5;
    
    
    
    switch(mode) {
      case 1: {
        //Set color to blue
        for (int i = 0; i<NUMPIXELS; i++) {
          strip.setPixelColor(i, strip.Color(0,0,255));
        }
        strip.show();
        break;}
      case 2: {
        //Set color to green
        for (int i = 0; i<NUMPIXELS; i++) {
          strip.setPixelColor(i, strip.Color(0,255,0));
        }
        strip.show();
        break;}
      case 3: {
        //Set color to red
        for (int i = 0; i<NUMPIXELS; i++) {
          strip.setPixelColor(i, strip.Color(255,0,0));
        }
        strip.show();
        break;}
      case 4: {
        //Ramps brightness across strip
        int brightness = 0;
        for (int i = 0; i<NUMPIXELS; i++) {
          strip.setPixelColor(i, strip.Color(brightness,brightness,brightness));
          brightness+=2;
        }
        strip.show();
        delay(1000);
        brightness = 0;
        for (int i = 0; i<NUMPIXELS; i++) {
          strip.setPixelColor(i, strip.Color(0,brightness,brightness));
          brightness+=2;
        }
        strip.show();
        delay(1000);
        brightness = 0;
        for (int i = 0; i<NUMPIXELS; i++) {
          strip.setPixelColor(i, strip.Color(0,0,brightness));
          brightness+=2;
        }
        strip.show();
        delay(1000);
        brightness = 0;
        for (int i = 0; i<NUMPIXELS; i++) {
          strip.setPixelColor(i, strip.Color(brightness,0,0));
          brightness+=2;
        }
        strip.show();
        delay(1000);
        brightness = 0;
        for (int i = 0; i<NUMPIXELS; i++) {
          strip.setPixelColor(i, strip.Color(brightness,brightness,0));
          brightness+=2;
        }
        strip.show();
        delay(1000);
        brightness = 0;
        for (int i = 0; i<NUMPIXELS; i++) {
          strip.setPixelColor(i, strip.Color(brightness,0,brightness));
          brightness+=2;
        }
        strip.show();
        break;}
      case 5: {
        int timer = 0;
        do {
          for(int x = 0; x < NUMPIXELS; x++) {
            strip.setPixelColor(x, strip.Color(0,0,0));
            x+=random(1,5); //Change this to change how much "randomness" there is to the gap between the leds
            if (x >59) x = 0;
            strip.setPixelColor(x, strip.Color((random(0,2)*255), (random(0,2)*255), (random(0,2)*255)));
          }
          strip.show();
          delay(50);
          timer++;
        } while(timer < 5000);
        break;}
        case 6:{
        int timer = 0;
        do {
          for(int x = 0; x < NUMPIXELS; x++) {
            strip.setPixelColor(x, strip.Color(0,0,0));
            x+=random(2,5); //Change this to change how much "randomness" there is to the gap between the leds
            if (x >59) x = 0;
            int brightness = random(20,150);
            strip.setPixelColor(x, strip.Color(brightness,brightness,brightness));
          }
          strip.show();
          delay(1000);
          timer++;
        } while(timer < 5000);
        break;}
    }
  
    
    
    
}

