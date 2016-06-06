#include "RectAngleManager.h"

RectAngleManager::RectAngleManager() {
  // do something useful here
}

RectAngleManager::~RectAngleManager() {
  // clean up the pointers
}


void RectAngleManager::addRect(int x, int y, int w, int h) {
  rects.push_back(new ofRectangle(x,y,w,h));
}

void RectAngleManager::draw() { 
  int count = 0;
  std::vector<ofRectangle*>::iterator i;
  CoordinateHelper CH;

  for (i = rects.begin(); i != rects.end(); i++) {
    ofPushMatrix();
    CH.reset();

    ofTranslate ((*i)->getX(), (*i)->getY());
    CH.translate((*i)->getX(), (*i)->getY());

    ofPushStyle();

    ofNoFill();
    ofSetColor(255,255,255);
    if (selected == count) {
      ofSetColor(255,0,0);
    }
    ofDrawRectangle(0,0, (*i)->getWidth(), (*i)->getHeight() );

    ofPopStyle();
    ofPopMatrix(); 

    count++;
  } 
}

int RectAngleManager::inside (int x, int y) {
  int count = 0;

  selected = -1;
  std::vector<ofRectangle*>::iterator i;

  for (i = rects.begin(); i != rects.end(); i++) {
    if ((*i)->inside(x,y)) {
      selected = count;
    }
    count++;
  } 
  return selected;
}
