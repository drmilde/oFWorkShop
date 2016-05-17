#include "HorizontalSlider.h"

HorizontalSlider::HorizontalSlider() : Slider ("hslider") {
  // do something useful here
}

HorizontalSlider::~HorizontalSlider() {
  // clean up here
}

void HorizontalSlider::draw() {
  ofPushStyle();
  ofDrawRectangle(posx, posy, width, height);
  ofPopStyle();
}

