#include "GuiHelper.h"

// set scope for statc variables
ofTrueTypeFont GuiHelper::standardFont;
ofTrueTypeFont GuiHelper::smallFont;
CS* GuiHelper::colors = NULL;

GuiHelper::GuiHelper() : Selectable ("Help, I need somebody", GUI_HELPER){
  GuiHelper::standardFont.load("Courier-Sans.ttf", 28);
  GuiHelper::smallFont.load("Courier-Sans.ttf", 18);

  //setColorScheme(new CSBlue());
  setColorScheme(new CSRed());
}

GuiHelper::~GuiHelper() {
  // clean up here 
}

void GuiHelper::setColorScheme (CS* c) {
  GuiHelper::colors = c;
}

void GuiHelper::stringLAt (std::string s, int x, int y) {
  GuiHelper::smallFont.drawString(s, x, y );
}

void GuiHelper::stringRAt (std::string s, int x, int y) {
  ofRectangle box = smallFont.getStringBoundingBox(s,0,0);
  
  GuiHelper::smallFont.drawString(s, 
				  x - box.getWidth(), 
				  y);
}

void GuiHelper::stringLCAt (std::string s, int x, int y) {
  ofRectangle box = smallFont.getStringBoundingBox(s,0,0);
  
  GuiHelper::smallFont.drawString(s, x, y + (box.getHeight()/2) );
}

void GuiHelper::stringRCAt (std::string s, int x, int y) {
    ofRectangle box = smallFont.getStringBoundingBox(s,0,0);

    GuiHelper::smallFont.drawString(s, 
				    x - box.getWidth(), 
				    y  + (box.getHeight()/2));

}

void GuiHelper::stringCCAt (std::string s, int x, int y) {
    ofRectangle box = smallFont.getStringBoundingBox(s,0,0);

    GuiHelper::smallFont.drawString(s, 
				    x - (box.getWidth()/2), 
				    y + (box.getHeight()/2));

}

// color functions

ofColor GuiHelper::BG0() {
  return GuiHelper::colors->getDkBck();
}

ofColor GuiHelper::BG1() {
  return GuiHelper::colors->getMdBck();
}

ofColor GuiHelper::BG2() {
  return GuiHelper::colors->getLtBck();
}

ofColor GuiHelper::BG3() {
  return GuiHelper::colors->getLtrBck();
}

ofColor GuiHelper::BG4() {
  return GuiHelper::colors->getFlBck();
}

ofColor GuiHelper::FG0() {
  return GuiHelper::colors->getDkFor();
}

ofColor GuiHelper::FG1() {
  return GuiHelper::colors->getMdFor();
}

ofColor GuiHelper::FG2() {
  return GuiHelper::colors->getLtFor();
}

ofColor GuiHelper::FG3() {
  return GuiHelper::colors->getLtrFor();
}

ofColor GuiHelper::FG4() {
  return GuiHelper::colors->getFlFor();
}

ofColor GuiHelper::TXT0() {
  return GuiHelper::colors->getTextCol();
}



