#include "Slider.h"

Slider::Slider(std::string name) : Slider (name, 0, 1) {
  // do something useful here
}

Slider::Slider(std::string name, 
	       float mn, float mx) : Selectable (name) {
  low = mn;
  high = mx;  
}

Slider:: ~Slider() {
  // clean up here
}

void Slider::setValue(float v) {
  value = v;
  value = min(value, high); // restrict value to [low, high]
  value = max(value, low);
}

