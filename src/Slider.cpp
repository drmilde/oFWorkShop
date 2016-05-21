#include "Slider.h"

Slider::Slider(std::string name) : Slider (name, 0, 1) {
  // do something useful here
}

Slider::Slider(std::string name, 
	       float min, float max) : Selectable (name) {
  low = min;
  high = max;  
  smallFont.load("Courier-Sans.ttf", 18);
}

Slider:: ~Slider() {
  // clean up here
}

void Slider::changeValue(float delta) {
  setValue(value + delta);
}

void Slider::setValue(float v) {
  value = v;
  value = min(value, high); // restrict value to [low, high]
  value = max(value, low);
}


void Slider::drawValueStringAt (int x, int y) {
  std::string out = ofToString(fabs(value),3);
  if (value >= 0) {
    out = "+" + out;
  } else {
    out = "-" + out;
  }
  smallFont.drawString(out,x,y);
}

void Slider::drawNameStringAt (int x, int y) {
  smallFont.drawString(name,x,y);
}

