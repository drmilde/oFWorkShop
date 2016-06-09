#include "EGPoint.h"

EGPoint::EGPoint(int id, float startL, float endL, float maxD, TYPE t) {
  ID = id;
  setStartLevel(startL);
  setEndLevel(endL);
  maxDuration = maxD;
  type = t;
}

EGPoint::~EGPoint() {
  // clean up here
}


// setter
void EGPoint::setStartLevel(float l) {
  startLevel = l;
}

void EGPoint::setEndLevel(float l) {
  endLevel = l;
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

