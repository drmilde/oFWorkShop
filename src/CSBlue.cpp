#include "CSBlue.h"

CSBlue::CSBlue() : CSBlue ("blue star") {
  // do something useful here
}

CSBlue::CSBlue(std::string name) {
  darkBackground = ofColor(63,63,63);
  middleBackground = ofColor(88,88,88);
  lightBackground = ofColor(127,127,127);
  lighterBackground = ofColor(191,191,192);
  fullBackground = ofColor(255,255,255);
  
  darkForeground = ofColor(0,0,63);
  middleForeground = ofColor(0,0,88);
  lightForeground = ofColor(0,0,127);
  lighterForeground = ofColor(0,0,191);
  fullForeground = ofColor(0,0,255);
  
  textColor = ofColor(255,255,255);
}

CSBlue::~CSBlue() {
  // clean up here
}


// get the colors

ofColor CSBlue::getDkBck() {
  return darkBackground;
}

ofColor CSBlue::getMdBck() {
  return middleBackground;
}

ofColor CSBlue::getLtBck() {
  return lightBackground;
}

ofColor CSBlue::getLtrBck() {
  return lighterBackground;
}

ofColor CSBlue::getFlBck() {
  return fullBackground;
}

ofColor CSBlue::getDkFor() {
  return darkForeground;
}

ofColor CSBlue::getMdFor() {
  return middleForeground;
}

ofColor CSBlue::getLtFor() {
  return lightForeground;
}

ofColor CSBlue::getLtrFor() {
  return lighterForeground;
}

ofColor CSBlue::getFlFor() {
  return fullForeground;
}

ofColor CSBlue::getTextCol() {
  return textColor;
}



