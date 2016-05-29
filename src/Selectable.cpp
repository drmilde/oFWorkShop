#include "Selectable.h"

Selectable::Selectable(std::string n, TYPE t) : GuiDrawable(n, 0,0,0,0) {
  // do something useful here
  setBoundingBox(0,0,0,0); // no bounding box;
  type = t;
}

Selectable::~Selectable() {
  // clean up here
}

void Selectable::setBoundingBox (int x, int y, int w, int h) {
  setBoundingBox(x,y,w,h,1,1);
}


void Selectable::setBoundingBox (int x, int y, int w, int h, int fx, int fy) {
  GuiDrawable::setBoundingBox(x,y,w,h);
  box = ofRectangle(posx, posy, width, height);
  sensitiveField = ofRectangle(posx, posy, width*fx, height*fy);
}

void Selectable::setSelected(bool sel) {
  selected = sel;
}

bool Selectable::isSelected() {
  return selected;
}

bool Selectable::inside(int x, int y) {
  selected = sensitiveField.inside(x,y);
  return selected;
}

bool Selectable::insideAt(int x, int y, int ox, int oy) {
  sensitiveAtField = ofRectangle(sensitiveField.x + ox, 
				 sensitiveField.y + oy, 
				 sensitiveField.getWidth(), 
				 sensitiveField.getHeight());
  selected = sensitiveAtField.inside(x,y);
  return selected;
}


Selectable::TYPE Selectable::getType() {
  return type;
}

void Selectable::draw() {
  ofPushStyle();

  ofNoFill();
  ofSetColor(255,255,255);
  if (selected) {
    ofSetColor(255,0,0);
  }

  ofDrawRectangle(box);
  ofDrawRectangle(sensitiveField);
  
  ofPopStyle();
}


