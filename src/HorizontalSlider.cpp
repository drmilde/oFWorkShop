#include "HorizontalSlider.h"

HorizontalSlider::HorizontalSlider() : HorizontalSlider ("hackl george") {
  // do something useful here 
}


HorizontalSlider::HorizontalSlider(std::string name) : HorizontalSlider (name, 
									 0, 0, 1) {
  // do something useful here
  imgHandle.load("switch-stripe.png");
}

HorizontalSlider::HorizontalSlider(std::string name,
				   float value, float min, float max
				   ): Slider (name, HSLIDER) {
  low = min;
  high = max;
  setValue(low);
}


HorizontalSlider::~HorizontalSlider() {
  // clean up here
}

void HorizontalSlider::setClickPosition(int x) {
  // remap screen position to interval
  setValue(ofMap(x, posx, posx + width, low , high));
}


void HorizontalSlider::setValue(float value) {
  Slider::setValue(value);
  changeValue(0);
}

void HorizontalSlider::changeValue(float delta) {
  Slider::changeValue(delta);
  handleX = (int)ofMap(value, low, high, posx, posx + width);
}


void HorizontalSlider::draw() {
  ofPushStyle();
  ofDrawRectangle(posx, posy, width, height);
  imgHandle.draw(handleX - (imgHandle.getWidth()/2), 
		 (posy + (height/2) - (imgHandle.getHeight()/2)
		  ));  

  drawValueStringAt(posx, posy + height + 25); // MAGIC NUMBER: font height = 25;
  ofPopStyle();

  //Selectable::draw();
}

