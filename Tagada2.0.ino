/*
Tagada 2.0 (CC) 2018 Alice Giordani
AtTiny85 + WS2812 + knitted Pressure Sensor
Press it harder to change the color!
*/

#include <Adafruit_NeoPixel.h>

#define SENSORPIN 3
#define PIN 0
#define NUMPIXEL 1

int delayval = 1;

int newSensorValue = 0;
int oldSensorValue = 0;
int state = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXEL, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  //Serial.begin(9600);
  oldSensorValue = analogRead(SENSORPIN);
  strip.begin();
  strip.setBrightness(100);
  strip.show();
}

void loop() {
  newSensorValue = analogRead(SENSORPIN);
  //Serial.println(newSensorValue);

  int diff = newSensorValue - oldSensorValue;
  //Serial.println(diff);

  if (diff > 10 && diff <= 20) {
    state = 1;
  } else if (diff > 20 && diff <= 30) {
    state = 2;
  } else if (diff > 30 && diff <= 40) {
    state = 3;
  } else if (diff > 40 && diff <= 50) {
    state = 4;
  } else if (diff > 50) {
    state = 5;
  } else if (diff < 10) {
    state = 0;
  }
  //Serial.println(state);

  for (int i = 0; i < NUMPIXEL; i++) {
    if (state == 1) {
      strip.setPixelColor(i, 0x99FFCC); 
    } else if (state == 2) {
      strip.setPixelColor(i, 0xCCFF33); 
    } else if (state == 3) {
      strip.setPixelColor(i, 0xFF9900); 
    } else if (state == 4) {
      strip.setPixelColor(i, 0xFF3300); 
    } else if (state == 5) {
      strip.setPixelColor(i, 0xCC0033); 
    } else {
      strip.setPixelColor(i, 0); //off
    }
  }

  strip.show();

  delay(delayval);

}
