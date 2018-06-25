#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN 2

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_RGBW + NEO_KHZ800);

int pRed = A0;
int pGreen = A1;
int pBlue = A2;
//int pWhite = A3;
int readR;  // Use this variable to read Potentiometer
int readG;
int readB;
int readW;
int val = 0;
 

void setup() {
  strip.begin();
  strip.show(); //resets all pixels to 0
  strip.setBrightness(255);
  
  pinMode(pRed, INPUT);  //set potPin to be an input
  pinMode(pGreen, INPUT);
  pinMode(pBlue, INPUT);
  //pinMode(pWhite, INPUT);
  Serial.begin(9600);      // turn on Serial Port
}
 
void loop() {
  

 readR = analogRead(pRed) / 4;
 readG = analogRead(pGreen) / 4;
 readB = analogRead(pBlue) / 4;
 //readW = analogRead((255./1023.) * pWhite);

 //setAll(readR, readG, readB, readW);
 setAllt(readR, readG, readB);

 Serial.println("---------------------------------");
 Serial.println(readR);
 //Serial.println(pRed);
 //Serial.println(255./1023.);
 Serial.println(readG);
 Serial.println(readB);
 //Serial.println(analogRead(pWhite));

// delay(500);
}

int setAll(int R, int G, int B, int W){
  int i = 0;
   for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, G, R, B, W);
    
  }
  strip.show();
}

int setAllt(int R, int G, int B){
  int i = 0;
   for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, G, R, B);
    
  }
  strip.show();
}


