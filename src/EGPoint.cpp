#include "EGPoint.h"

EGPoint::EGPoint(int id, std::string n, 
		 float startL, float endL, 
		 float dur, float maxD, 
		 TYPE t) {
  ID = id;
  setStartLevel(startL);
  setEndLevel(endL);

  maxDuration = maxD; // must be set before duration
  setDuration(fmin(dur, maxD));

  type = t;
  name = n;
}

EGPoint::~EGPoint() {
  // clean up here
}


// setter
void EGPoint::setStartLevel(float l) {
  startLevel = l;
  startLevel = fmax(0, startLevel);
  startLevel = fmin(1, startLevel);
}

void EGPoint::setEndLevel(float l) {
  endLevel = l;
  endLevel = fmax(0, endLevel);
  endLevel = fmin(1, endLevel);
}

void EGPoint::setDuration(float dur) {
  duration = fmin(dur, maxDuration);
}


// getter
float EGPoint::getID() {
  return ID;
}

float EGPoint::getStartLevel() {
  return startLevel;
}

float EGPoint::getEndLevel() {
  return endLevel;
}

float EGPoint::getDuration() {
  return duration;
}

float EGPoint::getMaxDuration() {
  return maxDuration;
}

float EGPoint::getType() {
  return type;
}

std::string EGPoint::getName() {
  return name;
}

