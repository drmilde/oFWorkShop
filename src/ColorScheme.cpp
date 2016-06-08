#include "ColorScheme.h"

ColorScheme::ColorScheme() : ColorScheme ("dark star") {
  // do something useful here
}

ColorScheme::ColorScheme(std::string name) : Selectable(name, COLOR_SCHEME) {
  darkBackground = ofColor(63,63,63);
  middleBackground = ofColor(88,88,88);
  lightBackground = ofColor(127,127,127);
  
  darkForeground = ofColor(63,0,0);
  middleForeground = ofColor(88,0,0);
  lightForeground = ofColor(127,0,0);
  
  textColor = ofColor(255,255,255);
}

ColorScheme::~ColorScheme() {
  // clean up here
}


// get the colors

ofColor ColorScheme::getDkBck() {
  return darkBackground;
}

ofColor ColorScheme::getMdBck() {
  return middleBackground;
}

ofColor ColorScheme::getLtBck() {
  return lightBackground;
}

ofColor ColorScheme::getDkFor() {
  return darkForeground;
}

ofColor ColorScheme::getMdFor() {
  return middleForeground;
}

ofColor ColorScheme::getLtFor() {
  return lightForeground;
}

ofColor ColorScheme::getTextCol() {
  return textColor;
}



void ColorScheme::draw() {
  ofPushStyle();

  // background
  ofSetColor(getDkBck());
  ofDrawRectangle(posx + (0*50), posy, 50 , 50);

  ofSetColor(getMdBck());
  ofDrawRectangle(posx + (1*50), posy, 50 , 50);

  ofSetColor(getLtBck());
  ofDrawRectangle(posx + (2*50), posy, 50 , 50);

  // forground
  ofSetColor(getDkFor());
  ofDrawRectangle(posx + (0*50), posy + 50, 50 , 50);

  ofSetColor(getMdFor());
  ofDrawRectangle(posx + (1*50), posy + 50, 50 , 50);

  ofSetColor(getLtFor());
  ofDrawRectangle(posx + (2*50), posy + 50, 50 , 50);

  ofPopStyle();
}

