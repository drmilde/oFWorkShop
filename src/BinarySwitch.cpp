#include "BinarySwitch.h"

BinarySwitch::BinarySwitch(std::string name) : BinarySwitch (name,0,1,
							     "OFF", "ON") {
  // do something useful here
}

BinarySwitch::BinarySwitch(std::string name, 
			   float low, float hi, 
			   std::string lowStrng, 
			   std::string hiStrng) : Selectable(name) {
  lowString = lowStrng;
  hiString = hiStrng;
  lowValue = low;
  hiValue = hi;

  smallFont.load("Courier-Sans.ttf", 18);

}


BinarySwitch::~BinarySwitch() {
  // clean up here
}

void BinarySwitch::draw() {
  ofPushStyle();
  ofSetColor(255);
  ofFill();
  ofDrawRectangle(posx, posy, width, height);
  
  smallFont.drawString(lowString, posx + width + 10, posy + 20);
  smallFont.drawString(hiString, posx + width + 10, posy - 5 + height);
  ofPopStyle();
}
