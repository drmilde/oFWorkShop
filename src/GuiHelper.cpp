#include "GuiHelper.h"

// set scope for statc variables
ofTrueTypeFont GuiHelper::standardFont;
ofTrueTypeFont GuiHelper::smallFont;

GuiHelper::GuiHelper() : Selectable ("Help, I need somebody", GUI_HELPER){
  GuiHelper::standardFont.load("Courier-Sans.ttf", 28);
  GuiHelper::smallFont.load("Courier-Sans.ttf", 18);
}

GuiHelper::~GuiHelper() {
  // clean up here 
}

void GuiHelper::drawStringAt (std::string s, int x, int y) {
  GuiHelper::smallFont.drawString(s, x, y );
}

void GuiHelper::drawSmallStringRightAt (std::string s, int x, int y) {
  ofRectangle box = smallFont.getStringBoundingBox(s,0,0);
  
  GuiHelper::smallFont.drawString(s, 
				  x - box.getWidth(), 
				  y);
}

void GuiHelper::drawSmallStringLeftCenterAt (std::string s, int x, int y) {
  ofRectangle box = smallFont.getStringBoundingBox(s,0,0);
  
  GuiHelper::smallFont.drawString(s, x, y + (box.getHeight()/2) );
}

void GuiHelper::drawSmallStringRightCenterAt (std::string s, int x, int y) {
    ofRectangle box = smallFont.getStringBoundingBox(s,0,0);

    GuiHelper::smallFont.drawString(s, 
				    x - box.getWidth(), 
				    y  + (box.getHeight()/2));

}


void GuiHelper::drawStringCCAt (std::string s, int x, int y) {
    ofRectangle box = smallFont.getStringBoundingBox(s,0,0);

    GuiHelper::smallFont.drawString(s, 
				    x - (box.getWidth()/2), 
				    y + (box.getHeight()/2));

}

