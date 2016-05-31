#include "TextButton.h"

TextButton::TextButton() : TextButton("message in a bottle") {
  // do something useful here
}
TextButton::TextButton(std::string text) : Selectable(text, TEXT_BUTTON) {
  smallFont.load("Courier-Sans.ttf", 18);
  label = text;

}

TextButton::~TextButton() {
  // clean up here
}


void TextButton::draw() {
  ofPushStyle();

  ofSetColor(127);
  ofDrawRectangle(posx, posy, width, height);

  ofSetColor(255);

  ofRectangle box = smallFont.getStringBoundingBox(label,0,0);  
  smallFont.drawString(label, 
		       posx + (width - box.getWidth())/2 , 
		       posy + (height + box.getHeight())/2
		       );

  ofPopStyle();
}
