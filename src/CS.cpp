#include "CS.h"

CS::CS() : CS ("dark star") {
  // do something useful here
}

CS::CS(std::string name) {
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

CS::~CS() {
  // clean up here
}


// get the colors

ofColor CS::getDkBck() {
  return darkBackground;
}

ofColor CS::getMdBck() {
  return middleBackground;
}

ofColor CS::getLtBck() {
  return lightBackground;
}

ofColor CS::getLtrBck() {
  return lighterBackground;
}

ofColor CS::getFlBck() {
  return fullBackground;
}

ofColor CS::getDkFor() {
  return darkForeground;
}

ofColor CS::getMdFor() {
  return middleForeground;
}

ofColor CS::getLtFor() {
  return lightForeground;
}

ofColor CS::getLtrFor() {
  return lighterForeground;
}

ofColor CS::getFlFor() {
  return fullForeground;
}

ofColor CS::getTextCol() {
  return textColor;
}



