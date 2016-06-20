#include "TouchPoint.h"

TouchPoint::TouchPoint() : TouchPoint("Be gentle, please") {
  // do something useful here
}

TouchPoint::TouchPoint(std::string name) : Selectable(name, TOUCH_POINT) {
  // do something useful here
  setValue (0);
}

TouchPoint::~TouchPoint() {
  // clean up here
}

void TouchPoint::draw() {
  drawAt(posx, posy);
}

void TouchPoint::drawAt(int x, int y) {
  ofPushStyle();

  // display state
  if (on) {
    ofSetColor(GuiHelper::TXT0());
    ofNoFill();
    
    // draw selected circle
    if (isSelected()) {
      ofSetColor(GuiHelper::FG2());
      ofSetLineWidth(3);
      ofDrawCircle(x+(width/2), y+(width/2), width/2);
    } else {
      ofDrawCircle(x+(width/2), y+(width/2), width/2);
    }
  }

  //Selectable::draw();

  ofPopStyle();
}


// getter/setter

float TouchPoint::getValue() {
  return value;
}

void TouchPoint::setValue(float v) {
  value = v;
}

