#include "XYSelect.h"

XYSelect::XYSelect() : XYSelect("Ede Zimmermann") {
  // do something useful here
}

XYSelect::XYSelect(std::string name) : Selectable(name) {
  // do something useful here
  smallFont.load("Courier-Sans.ttf", 18);
}

XYSelect::~XYSelect() {
  // clean up ressources
}


void XYSelect::draw() {
  ofPushStyle();
  // draw the background
  ofSetColor(88,88,88);
  ofDrawRectangle(posx, posy, width, height);

  // draw the cross
  ofSetColor(255,0,0);
  ofDrawLine(posx, posy + relY , posx + width, posy + relY);
  ofDrawLine(posx + relX, posy, posx + relX, posy + height);

  // draw the strings
  drawValueStringAt(posx + relX, posy -5, valX);
  drawValueStringAt(posx, posy + relY + 25, valY);
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


void XYSelect::drawValueStringAt (int x, int y, float value) {
  std::string out = ofToString(fabs(value),2);
  if (value >= 0) {
    out = "+" + out;
  } else {
    out = "-" + out;
  }
  smallFont.drawString(out,x,y);
}

void XYSelect::drawNameStringAt (int x, int y) {
  smallFont.drawString(name,x,y);
}
