#include "VerticalSlider.h"

VerticalSlider::VerticalSlider() : VerticalSlider ("hackl george") {
  // do something useful here 
}


VerticalSlider::VerticalSlider(std::string name) : VerticalSlider (name, 
								   0, 0, 1) {
  // do something useful here
  imgHandle.load("switch-stripe.png");
}

VerticalSlider::VerticalSlider(std::string name,
				   float value, float min, float max
				   ): Slider (name) {
  low = min;
  high = max;
  setValue(low);
}


VerticalSlider::~VerticalSlider() {
  // clean up here
}

void VerticalSlider::setClickPosition(int y) {
  // remap screen position to interval
  setValue(ofMap(y, posy, posy + height, high, low));
}


void VerticalSlider::setValue(float value) {
  Slider::setValue(value);
  changeValue(0);
}

void VerticalSlider::changeValue(float delta) {
  Slider::changeValue(delta);
  handleY = (int)ofMap(value, high, low, posy, posy + height);
}


void VerticalSlider::draw() {
  ofPushStyle();
  ofDrawRectangle(posx, posy, width, height);
  imgHandle.draw((posx - (imgHandle.getWidth()/2) + width/2),
		 handleY - (imgHandle.getHeight()/2));

  drawNameStringAt(posx - 35, posy - 22 ); // MAGIC NUMBER: distance = 35/22;
  drawValueStringAt(posx - 35, posy + height + (imgHandle.getHeight()/2) + 22 ); // MAGIC NUMBER: distance = 35/25;
  ofPopStyle();

  //Selectable::draw();
}

