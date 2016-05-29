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
			       ): Slider (name, VSLIDER) {
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
  drawAt(0,0);
}

void VerticalSlider::drawAt(int x, int y) {
  ofPushStyle();
  ofDrawRectangle(x + posx, y + posy, width, height);
  imgHandle.draw((x+posx - (imgHandle.getWidth()/2) + width/2),
		 y + handleY - (imgHandle.getHeight()/2));

  drawNameStringAt(x + posx - 35, y + posy - 22 ); // MAGIC NUMBER: distance = 35/22;
  drawValueStringAt(x + posx - 35, y + posy + height + (imgHandle.getHeight()/2) + 22 ); // MAGIC NUMBER: distance = 35/25;
  ofPopStyle();

  //Selectable::draw();
}


