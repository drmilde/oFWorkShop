#include "XYSelect.h"

XYSelect::XYSelect() : XYSelect("Ede Zimmermann") {
  // do something useful here
}

XYSelect::XYSelect(std::string name) : Selectable(name, XYSELECT) {
  // do something useful here
  smallFont.load("Courier-Sans.ttf", 18);
}

XYSelect::~XYSelect() {
  // clean up ressources
}


void XYSelect::draw() {
  ofPushStyle();
  // draw the background
  ofSetColor(GuiHelper::BG0());

  ofDrawRectangle(posx, posy, width, height);

  // draw the cross
  ofSetColor(255,0,0);
  ofSetColor(GuiHelper::FG4());
  ofDrawLine(posx, posy + relY , posx + width, posy + relY);
  ofDrawLine(posx + relX, posy, posx + relX, posy + height);

  // draw the x/y strings
  drawValueStringAt("x=",
		    posx + relX, posy -5, 
		    valX, posx+width, posy+height);
  drawValueStringAt("y=", 
		    posx, posy + relY + 25, 
		    valY, posx+width, posy+height);

  // draw name
  ofSetColor(GuiHelper::TXT0());
  drawNameStringAt(posx, posy - 35);
  ofPopStyle();

  //Selectable::draw();
}

void XYSelect::setClickPosition (int x, int y) {
  relX = x - posx;
  relX = max (0, relX);
  relX = min (width, relX);

  relY = y - posy;
  relY = max (0, relY);
  relY = min (height, relY);

  // adjust the values
  valX = ofMap(relX, 0, width, 0, 1);
  valY = ofMap(relY, 0, height, 0, 1);
}


void XYSelect::drawValueStringAt (std::string init, 
				  int x, int y, float value, 
				  int maxX, int maxY) {
  std::string out = ofToString(fabs(value),2);
  if (value >= 0) {
    out = "+" + out;
  } else {
    out = "-" + out;
  }

  // add init
  out = init + out;
  // calculate width/height
  ofRectangle box = smallFont.getStringBoundingBox(out,0,0);

  // dont cross right/lower boundary
  if ((x + box.getWidth()) > maxX) {
    smallFont.drawString(out,maxX - box.getWidth(),y);
  } else {
    if (y > (maxY - box.getHeight())) {
      smallFont.drawString(out,x, maxY - box.getHeight());
    } else {
      smallFont.drawString(out,x,y);
    }
  }

}

void XYSelect::drawNameStringAt (int x, int y) {
  smallFont.drawString(name,x,y);
}
