#include "TouchPoint.h"

TouchPoint::TouchPoint() : TouchPoint(0, "I wanna feel dirty") {
  // do something useful here
}

TouchPoint::TouchPoint(int id, std::string name) : Selectable(name, TOUCH_POINT) {
  // do something useful here
  ID = id;
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
    // recalculate position/bounding box
    if (move) {
      posx = currentMouseX - (width/2);
      posy = currentMouseY - (height/2);
      setBoundingBox(posx, posy, width, height);
    }

    ofSetColor(GuiHelper::TXT0());
    ofNoFill();
    
    // draw selected circle
    if (isSelected()) {
      // highlight TouchPoint
      ofSetColor(GuiHelper::FG2());
      ofSetLineWidth(3);
      ofDrawCircle(x+(width/2), y+(width/2), width/2);

      // draw drag handle
      if (move) {
	ofSetColor(GuiHelper::BG0());
	ofFill();
	ofDrawCircle(currentMouseX, currentMouseY, 10);
      }
    } else {
      ofDrawCircle(x+(width/2), y+(width/2), width/2);
      move = false;
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

// mouse events

void TouchPoint::drag(int msx, int msy) {
  currentMouseX = msx;
  currentMouseY = msy;
  move = true;
}


void TouchPoint::highlight(int msx, int msy) {
  currentMouseX = msx;
  currentMouseY = msy;
  move = false;
}

bool TouchPoint::near (int x, int y, int d) {
  bool result = false;
  int distx = x - currentMouseX;
  int disty = y - currentMouseY;

  result = (((distx * distx) + (disty * disty)) < (d*d));

  return result;
}


// return current center position

int TouchPoint::getCenterX() {
  return posx + (width/2);
}

int TouchPoint::getCenterY() {
  return posy + (height/2);
}


int TouchPoint::getID() {
  return ID;
}




