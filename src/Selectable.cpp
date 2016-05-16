#include "Selectable.h"

Selectable::Selectable() : GuiDrawable(0,0,0,0) {
  // do something useful here
  setBoundingBox(0,0,0,0); // no bounding box;
}

Selectable::~Selectable() {
  // clean up here
}

void Selectable::setBoundingBox (int x, int y, int w, int h) {
  GuiDrawable::setBoundingBox(x,y,w,h);
  box = ofRectangle(posx, posy, width, height);
}

void Selectable::setSelected(bool sel) {
  selected = sel;
}

bool Selectable::isSelected() {
  return selected;
}

bool Selectable::inside(int x, int y) {
  selected = box.inside(x,y);
  return selected;
}

void Selectable::draw() {
  ofPushStyle();

  ofNoFill();
  ofSetColor(255,255,255);
  if (selected) {
    ofSetColor(255,0,0);
  }

  ofDrawRectangle(box);
  
  ofPopStyle();
}


