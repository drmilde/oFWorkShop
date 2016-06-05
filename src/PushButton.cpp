#include "PushButton.h"

PushButton::PushButton() : Selectable("Push the button", PUSH_BUTTON) {
  // do something useful here
}


PushButton::~PushButton() {
  // clean up here
}

void PushButton::draw() {
  ofPushStyle();

  if (count > 0) {
    ofSetColor(128);
    count--;;
  } else {
    ofSetColor(128,0,0);
    count = 0;
  }
  ofDrawRectangle(posx, posy, width, height);

  ofSetColor(255);
  GuiHelper::drawStringCCAt ("Push ME",
			     posx + width/2,
			     posy + height/2);
  ofPopStyle();
}

void PushButton::pushed() {
  setPushed(true);
}

void PushButton::setPushed(bool p) {
  hit = p;
  count = 50;
}

