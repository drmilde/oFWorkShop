#include "BinarySwitch.h"

BinarySwitch::BinarySwitch(std::string name) : BinarySwitch (name,0,1,
							     "OFF", "ON") {
  // do something useful here
}

BinarySwitch::BinarySwitch(std::string name, 
			   float low, float hi, 
			   std::string lowStrng, 
			   std::string hiStrng) : Selectable(name, BINARY_SWITCH) {
  lowString = lowStrng;
  hiString = hiStrng;
  lowValue = low;
  hiValue = hi;

  smallFont.load("Courier-Sans.ttf", 18);
  imgSwitch.load("switch-stripe.png");
  imgSwitch.load("switch-grey.png");

}


BinarySwitch::~BinarySwitch() {
  // clean up here
}

void BinarySwitch::draw() {
  ofPushStyle();

  // draw background
  ofSetColor(88);
  ofFill();
  ofDrawRectangle(posx, posy, width, height);
  ofSetColor(33);
  ofFill();
  ofDrawRectangle(posx+1, posy+1, width-2, height-2);
  
  // draw text
  ofSetColor(255);
  smallFont.drawString(lowString, posx + width + 10, posy + 20);
  smallFont.drawString(hiString, posx + width + 10, posy - 5 + height);

  imgOffsetX = (imgSwitch.getWidth() - width) / 2;
  // draw image
  if (value <= lowValue) {
    imgSwitch.draw(posx - imgOffsetX, posy);
  }
  if (value >= hiValue) {
    imgSwitch.draw(posx - imgOffsetX, posy + height -imgSwitch.getHeight());
  }
  ofPopStyle();

  //Selectable::draw();

}


void BinarySwitch::setValue(float v) {
  value = v;
  value = fmin (value, hiValue); 
  value = fmax (value, lowValue); 
}

void BinarySwitch::toggle() {
  if (value >= hiValue) {
    setValue(lowValue);
  } else {
    setValue(hiValue);
  }
}
