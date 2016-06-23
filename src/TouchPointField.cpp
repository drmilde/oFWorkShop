#include "TouchPointField.h"

TouchPointField::TouchPointField () : TouchPointField("tou tou tou tou tou tou touch me") {
  // do something useful here
}

TouchPointField::TouchPointField (std::string name) : Selectable(name, 
								TOUCH_POINT_FIELD) {
  // do something useful here
}

TouchPointField::~TouchPointField() {
  // clean up here
}

void TouchPointField::draw() {
  ofPushStyle();
  ofSetColor(GuiHelper::BG2());
  ofFill();
  ofDrawRectangle(posx, posy, width, height);

  drawTouchPoints();
  ofPopStyle();
}

void TouchPointField::drawTouchPoints() {
  for (unsigned int i = 0; i < tpoints.size(); i++) {
    TouchPoint* tp = tpoints[i];
    if (tp !=  NULL) {
      tp->draw();
    }
  }
}


// interface routinen

void TouchPointField::addTouchPoint(int id, int x, int y, int r) {
  TouchPoint* tp = new TouchPoint(id, "tpf point");
  tp->setBoundingBox(posx + normX(x) - (r/2), posy + normY(y) - (r/2), r,r);
  tpoints.push_back(tp);
}


int TouchPointField::normX(int x) {
  return (int)(fmin(fmax(0, x), width));
}

int TouchPointField::normY(int y) {
  return (int)(fmin(fmax(0, y), height));
}



