#include <Adafruit_DotStar.h>
#include <SPI.h>      


// Define total number of pixels in the matrix
#define NUMPIXELS 64 

// DIN and CIN ports
#define DATAPIN    4
#define CLOCKPIN   5

// Construct the specifics of the strip object
Adafruit_DotStar strip(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);


void setup() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

  // Start and configure the matrix
  strip.begin(); 
  strip.setBrightness(1);
  strip.show();  
}

// Illuminate an entire half of the matrix
void setHalf(String side) {
  if (side.equals("left")) {
    for (int i = 0; i <= 31; i++) {
      strip.setPixelColor(i, strip.Color(255, 255, 255));
    }
  } else if (side.equals("right")) {
    for (int i = 0; i <= 31; i++) {
      strip.setPixelColor(i + 32, strip.Color(255, 255, 255));
    }
  }
}

// Set specifc LED in a row or column. -1 makes the whole row/column turn on
void setLed(int row, int column) {
  if (row == -1) {
    for (int i = 0; i < 8; i++) {
      strip.setPixelColor((column - 1) * 8 + i, 255, 255 , 255);
    }
  } else if (column == -1) {
    for (int i = 0; i < 8; i++) {
      strip.setPixelColor(i * 8 + (row-1), strip.Color(255, 255, 255));
    }
  } else {
    strip.setPixelColor((column-1)*8+(row-1), strip.Color(255, 255, 255));
  }


}

// Shuts off Leds
void turnOffLeds() {
  for (int i = 0; i <= 64; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
}

void loop() {
  // Reset LEds before pattern is drawn
  turnOffLeds();

  // Displays a plus pattern
  setLed(-1, 4);
  setLed(-1, 5);
  setLed(4, -1);
  setLed(5, -1);

  // Draw the pattern on the matrix
  strip.show();        
}


