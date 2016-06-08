#include "TextButton.h"

TextButton::TextButton() : TextButton("message in a bottle", "sting") {
  // do something useful here
}

TextButton::TextButton(std::string text, 
		       std::string text1) : Selectable(text, TEXT_BUTTON) {
  label = text;
  label1 = text1;
}

TextButton::~TextButton() {
  // clean up here
}

void TextButton::toggle() {
  if (state >= 1) {
    state = 0;
  } else {
    state = 1;
  }
}


void TextButton::draw() {
  ofPushStyle();


  ofSetColor(GuiHelper::TXT0());
  if (state <= 0) {
    ofSetColor(GuiHelper::FG2());
    ofDrawRectangle(posx, posy, width, height);

    ofSetColor(GuiHelper::TXT0());
    GuiHelper::drawStringCCAt(label, 
			      posx + (width/2),
			      posy + (height/2));
  }

  if (state >= 1) {
    ofSetColor(GuiHelper::BG2());
    ofDrawRectangle(posx, posy, width, height);

    ofSetColor(GuiHelper::TXT0());
    GuiHelper::drawStringCCAt(label1, 
			      posx + (width/2),
			      posy + (height/2));
  }
			    

  ofPopStyle();
}
