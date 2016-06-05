#include "PushButton.h"

PushButton::PushButton() : Selectable("Push the button", PUSH_BUTTON) {
  // do something useful here
}


PushButton::~PushButton() {
  // clean up here
}

void PushButton::draw() {
  ofPushStyle();
  
  ofSetColor(128,0,0);

  long m = pulse.getMillis();
  if (m < 500) {
    if (pulse.isRunning()) {
      ofSetColor(128);
    }
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
  pulse.start();
}

