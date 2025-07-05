
#include <MD_MAX72xx.h>
#include <MD_Parola.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 4

#define DIN 23
#define CLK 18
#define CS 5
#define BUTTON 14

MD_Parola p = MD_Parola(HARDWARE_TYPE, DIN, CLK, CS, MAX_DEVICES);
MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DIN, CLK, CS, MAX_DEVICES);

const byte diceFaces[6][8] = {
  { B00000000, B00000000, B00000000, B00011000, B00011000, B00000000, B00000000, B00000000 }, // 1
  { B00000000, B01100000, B01100000, B00000000, B00000000, B00000110, B00000110, B00000000 }, // 2
  { B11000000, B11000000, B00000000, B00011000, B00011000, B00000000, B00000011, B00000011 }, // 3
  { B00000000, B01100110, B01100110, B00000000, B00000000, B01100110, B01100110, B00000000 }, // 4
  { B11000011, B11000011, B00000000, B00011000, B00011000, B00000000, B11000011, B11000011 }, // 5
  { B11000011, B11000011, B00000000, B11000011, B11000011, B00000000, B11000011, B11000011 }  // 6
};

int state = 0;  // ✅ Global variable to track animation state

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(15));  // for random dice

  p.begin();
  p.setIntensity(7);
  pinMode(BUTTON, INPUT_PULLUP);

  p.displayClear();
  p.displayText(" Press Button To Roll ", PA_LEFT, 100, 1000, PA_SCROLL_LEFT, PA_FADE);
}

void loop() {
  p.displayAnimate();  // ✅ Must be called every time to keep scrolling

  // If button is pressed → roll dice
  if (digitalRead(BUTTON) == LOW) {
    delay(200);  // Debounce
    diceAnimation();
    drawDice(random(1, 7), 0);
    drawDice(random(1, 7), 3); 
    delay(3000); 
    p.displayClear(); 
    p.displayText(" Press Button To Roll ", PA_LEFT, 100, 1000, PA_SCROLL_LEFT, PA_FADE);
    state = 1; 
  }

  // If button not pressed & current animation is finished
  else if (p.displayAnimate()) {
    if (state == 0) {
      p.displayText(" No Input Detected ", PA_LEFT, 100, 1000, PA_SCROLL_LEFT, PA_FADE);
      state = 1;
    } else {
      p.displayText(" Press Button To Roll ", PA_LEFT, 100, 1000, PA_SCROLL_LEFT, PA_FADE);
      state = 0;
    }
  }
}

void diceAnimation() {
  mx.begin();
  for (int j = 0; j < 6; j++) {
    for (int i = 0; i < 8; i++) {
      mx.setRow(0, i, diceFaces[j][i]);
      mx.setRow(3, i, diceFaces[j][i]);
      delay(25);
    }
    mx.clear();
  }
}

void drawDice(int value, int module) {
  for (int i = 0; i < 8; i++) {
    mx.setRow(module, i, diceFaces[value - 1][i]);
  }
}
