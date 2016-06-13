#include "EGSpan.h"

EGSpan::EGSpan(int id, std::string n,
	       EGPoint p1, EGPoint p2,
	       float maxDrtn,
	       TYPE t
	       ) {
  ID = id;
  name = n;
  startPoint = p1;
  endPoint = p2;
  maxDuration = maxDrtn;

  // duration setzen und normalisieren
  duration = fmin(fabs(p2.getTime()-p1.getTime()), maxDuration);
  duration = fmax(0, duration);

  type = t;
}

EGSpan::~EGSpan() {
  // clean up here
}


// setter
void EGSpan::setStartLevel(float l) {
  startPoint.setLevel(l);
}

void EGSpan::setEndLevel(float l) {
  endPoint.setLevel(l);
}

void EGSpan::setDuration(float dur) {
  duration = fmin(dur, maxDuration);
  duration = fmax(0, duration);
}

void EGSpan::setStartTime(float st) {
  startPoint.setTime(st);
  updateDuration();
}

void EGSpan::setEndTime(float et) {
  endPoint.setTime(et);
  updateDuration();
}

float EGSpan::getEndTime() {
  return endPoint.getTime();
}


// getter
float EGSpan::getID() {
  return ID;
}

float EGSpan::getStartLevel() {
  return startPoint.getLevel();
}

float EGSpan::getEndLevel() {
  return endPoint.getLevel();
}

float EGSpan::getDuration() {
  return duration;
}

float EGSpan::getMaxDuration() {
  return maxDuration;
}

int EGSpan::getTypeStart() {
  return startPoint.getType();
}

int EGSpan::getTypeEnd() {
  return endPoint.getType();
}

std::string EGSpan::getName() {
  return name;
}


// helper

void EGSpan::updateDuration() {
  setDuration(fabs(endPoint.getTime() - startPoint.getTime()));
}


