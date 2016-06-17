#include "EGSpan.h"

EGSpan::EGSpan(int id, std::string n,
	       EGPoint* p1, EGPoint* p2,
	       float maxDrtn,
	       TYPE t
	       ) {
  ID = id;
  name = n;
  startPoint = p1;
  endPoint = p2;
  maxDuration = maxDrtn;

  type = t;
}

EGSpan::~EGSpan() {
  // clean up here
}

// setter
void EGSpan::setStartLevel(float l) {
  startPoint->setLevel(l);
}

void EGSpan::setEndLevel(float l) {
  endPoint->setLevel(l);
}

void EGSpan::setStartTime(float st) {
  if (st <= endPoint->getTime()) {
    if (fabs(endPoint->getTime() - st) < maxDuration) {
      startPoint->setTime(st);
    }
  }
}

void EGSpan::setEndTime(float et) {
  if (et >= startPoint->getTime()) {
    if (fabs(et - startPoint->getTime()) < maxDuration) {
      endPoint->setTime(et);
    }
  }
}

float EGSpan::getStartTime() {
  return startPoint->getTime();
}

float EGSpan::getEndTime() {
  return endPoint->getTime();
}


// getter
float EGSpan::getID() {
  return ID;
}

float EGSpan::getStartLevel() {
  return startPoint->getLevel();
}

float EGSpan::getEndLevel() {
  return endPoint->getLevel();
}

float EGSpan::getDuration() {
  return fabs(endPoint->getTime() - startPoint->getTime());
}

float EGSpan::getMaxDuration() {
  return maxDuration;
}

int EGSpan::getTypeStart() {
  return startPoint->getType();
}

int EGSpan::getTypeEnd() {
  return endPoint->getType();
}

std::string EGSpan::getName() {
  return name;
}


// sanity checking

bool EGSpan::check(int id, float tme) {
 
  if (getID() == id) {// correct EGSpan ??
    std::cout << "ep, " << startPoint->getName();
    return (fabs(tme - startPoint->getTime()) <= getMaxDuration());
  }

  return true;
}


void EGSpan::print() {
  std::cout << getName()
	    << ","
	    << startPoint->getTime()
	    << ","
	    << endPoint->getTime()
	    << ","
	    << getDuration()
	    << ","
	    << getMaxDuration()
	    << std::endl;
}



