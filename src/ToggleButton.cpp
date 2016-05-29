#include "ToggleButton.h"

ToggleButton::ToggleButton() : ToggleButton("tic toc") {
  // do something useful here
}

ToggleButton::ToggleButton(std::string name) : Selectable(name, TOGGLE_BUTTON) {
  // do something useful here
  setValue (0);
  setGridID(-1,-1);
}

ToggleButton::~ToggleButton() {
  // clean up here
}

void ToggleButton::draw() {
  drawAt(0,0);
}


void ToggleButton::drawAt(int x, int y) {
  ofPushStyle();

  // display background
  ofSetColor(128);
  ofDrawRectangle(x + posx, y + posy, width, height);

  // display state
  if (on) {
    ofSetColor(128,0,0);
  } else {
    ofSetColor(40,40,40);
  }
  ofDrawCircle(x + posx + width/2, y + posy + height/2, (width*40) / 100);

  ofPopStyle();
}


void ToggleButton::toggle() {
  on = !on;
}



// interface function for usage in grid 

void ToggleButton::setValue (float v) {
  value = v;
}

float ToggleButton::getValue() {
  return value;
}


void ToggleButton::setGridID(int c, int r) {
  col = c;
  row = r;
}

int ToggleButton::getGridCol() {
  return col;
}

int ToggleButton::getGridRow() {
  return row;
}

