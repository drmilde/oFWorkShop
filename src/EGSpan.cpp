#include "EGSpan.h"

EGSpan::EGSpan(int id, std::string n, 
	       float startL, float endL, 
	       float sTime, float dur, float maxD, 
	       TYPE t1, TYPE t2) {
  ID = id;

  // start level setzen und normalisieren
  //setStartLevel(startL);
  startLevel = startL;
  startLevel = fmax(0, startLevel);
  startLevel = fmin(1, startLevel);


  // end level setzen und normalisieren
  //setEndLevel(endL);
  endLevel = endL;
  endLevel = fmax(0, endLevel);
  endLevel = fmin(1, endLevel);

  startTime = sTime;
  maxDuration = maxD; // must be set before duration

  // duration setzen und normalisieren
  // setDuration(fmin(dur, maxD));
  duration = fmin(fmin(dur, maxD), maxDuration);
  duration = fmax(0, duration);

  type1 = t1;
  type2 = t2;
  name = n;
}

EGSpan::~EGSpan() {
  // clean up here
}


// setter
void EGSpan::setStartLevel(float l) {
  if ((type1 == LEVEL) || (type1 == ALL)) {
    startLevel = l;
    startLevel = fmax(0, startLevel);
    startLevel = fmin(1, startLevel);
  }
}

void EGSpan::setEndLevel(float l) {
  if ((type1 == LEVEL) || (type1 == ALL)) {
    endLevel = l;
    endLevel = fmax(0, endLevel);
    endLevel = fmin(1, endLevel);
  }
}

void EGSpan::setDuration(float dur) {
  if ((type1 == TIME) || (type1 == ALL)) {
    duration = fmin(dur, maxDuration);
    duration = fmax(0, duration);
  }
}

void EGSpan::setStartTime(float st) {
  if ((type1 == TIME) || (type1 == ALL)) {
    startTime = fmax(0, st);
  }
}

void EGSpan::setEndTime(float et) {
  if ((type1 == TIME) || (type1 == ALL)) {
    setDuration(et - startTime);
  }
}

float EGSpan::getEndTime() {
  return (startTime + duration);
}



// getter
float EGSpan::getID() {
  return ID;
}

float EGSpan::getStartLevel() {
  return startLevel;
}

float EGSpan::getEndLevel() {
  return endLevel;
}

float EGSpan::getDuration() {
  return duration;
}

float EGSpan::getMaxDuration() {
  return maxDuration;
}

float EGSpan::getTypeStart() {
  return type1;
}

float EGSpan::getTypeEnd() {
  return type2;
}

std::string EGSpan::getName() {
  return name;
}

