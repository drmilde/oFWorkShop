#include "CSRed.h"

CSRed::CSRed() : CSRed ("red dwarf") {
  // do something useful here
}

CSRed::CSRed(std::string name) {
  darkBackground = ofColor(63,63,63);
  middleBackground = ofColor(88,88,88);
  lightBackground = ofColor(127,127,127);
  lighterBackground = ofColor(191,191,192);
  fullBackground = ofColor(255,255,255);
  
  darkForeground = ofColor(63,0,0);
  middleForeground = ofColor(88,0,0);
  lightForeground = ofColor(127,0,0);
  lighterForeground = ofColor(191,0,0);
  fullForeground = ofColor(255,0,0);
  
  textColor = ofColor(255,255,255);
}

CSRed::~CSRed() {
  // clean up here
}


// get the colors

ofColor CSRed::getDkBck() {
  return darkBackground;
}

ofColor CSRed::getMdBck() {
  return middleBackground;
}

ofColor CSRed::getLtBck() {
  return lightBackground;
}

ofColor CSRed::getLtrBck() {
  return lighterBackground;
}

ofColor CSRed::getFlBck() {
  return fullBackground;
}

ofColor CSRed::getDkFor() {
  return darkForeground;
}

ofColor CSRed::getMdFor() {
  return middleForeground;
}

ofColor CSRed::getLtFor() {
  return lightForeground;
}

ofColor CSRed::getLtrFor() {
  return lighterForeground;
}

ofColor CSRed::getFlFor() {
  return fullForeground;
}

ofColor CSRed::getTextCol() {
  return textColor;
}



