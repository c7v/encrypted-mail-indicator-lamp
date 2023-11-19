#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <FastLED.h>

#define NUM_LEDS 30
#define PIN_LEDS 4
CRGB leds[NUM_LEDS];

const char* ssid = "Артём 2.4";
const char* password = "*****";

byte bright = 50; // яркость LED светодиодов
byte baza = 0;     // изменение оттенка LED


void setup() {
  Serial.begin(115200);

  FastLED.addLeds<NEOPIXEL, PIN_LEDS>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  for(int i = 0; i < NUM_LEDS; i++) 
  { 
    leds[i] = CRGB::DodgerBlue; FastLED.setBrightness(255); FastLED.show();
  }
  delay(5000);
  for(int i = 255; i > 0; i--) 
  {
    FastLED.setBrightness(i); FastLED.show(); delay(1);
  }
  delay(2000);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    for(int i = 0; i < NUM_LEDS; i++) 
    { 
      leds[i] = CRGB::Yellow; FastLED.show();
    }
    for(int i = 0; i < 255; i++) 
    {
      FastLED.setBrightness(i); FastLED.show(); delay(1);
    }
    for(int i = 255; i > 0; i--) 
    {
      FastLED.setBrightness(i); FastLED.show(); delay(1);
    }
  }
  FastLED.setBrightness(0); FastLED.show();


  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi connected");
  } else {
    Serial.println("No connection to WiFi");
  }

  for(int i = 0; i < NUM_LEDS; i++) 
  { 
    leds[i] = CRGB::Fuchsia; FastLED.show();
  }
  FastLED.setBrightness(100);
}