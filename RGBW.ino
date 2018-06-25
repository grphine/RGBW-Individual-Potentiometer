#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN 2

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_RGBW + NEO_KHZ800); //Light strip declared: (strip width, output pin, strip type)

int pRed = A0; // Input pin for red poteniometer
int pGreen = A1;
int pBlue = A2;
int pWhite = A3;
int readR;  // Store read value for red potentiometer
int readG;
int readB;
int readW;
 

void setup() {
  strip.begin(); //Initialises strip
  strip.show(); //Resets all pixels to 0, turns all lights off
  strip.setBrightness(255); 
  
  pinMode(pRed, INPUT);  //Sets red's defined pin as an input to Arduino
  pinMode(pGreen, INPUT);
  pinMode(pBlue, INPUT);
  pinMode(pWhite, INPUT);
  
  Serial.begin(9600);      //Turn on Serial Port
}
 
void loop() {
  

 readR = analogRead(pRed) / 4;    //Potentiometer value read and stored in readR variable
 readG = analogRead(pGreen) / 4;  // Potentiometer returns value between 0-1023
 readB = analogRead(pBlue) / 4;   //Strip lights only take value between 0-255
 readW = analogRead(pWhite) / 4;  //Divide by four brings within range

 setAll(readR, readG, readB, readW); //Sets all lights simultaneously

//Improvement - only call function if potentiometer change detected. May increase strip lifespan

 Serial.println("---------------------------------");
 Serial.println(readR); //Print value output to strip, for debugging
 Serial.println(readG);
 Serial.println(readB);
 Serial.println(readW);

}

int setAll(int R, int G, int B, int W){ //setAll takes RGBW values
  int i = 0;
   for(i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, G, R, B, W); //Iterate through every pixel, set pixel LED intensities to values input to function
    
  }
  strip.show(); //Displays colours to strip
}



