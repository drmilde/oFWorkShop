#include "PushButton.h"

PushButton::PushButton() : Selectable("Push the button", PUSH_BUTTON) {
  // do something useful here
}

PushButton::~PushButton() {
  // clean up here
}

void PushButton::draw() {
  ofPushStyle();
  
  ofSetColor(GuiHelper::FG2());

  // check timing ... if pushed, light up grey for 200 millis
  if (pulse.getMillis() < 200) {
    if (pulse.isRunning()) {
      ofSetColor(GuiHelper::BG2());
    }
  } 

  ofDrawRectangle(posx, posy, width, height);

  ofSetColor(GuiHelper::TXT0());
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

