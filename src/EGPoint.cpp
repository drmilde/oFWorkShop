#include "EGPoint.h"

EGPoint::EGPoint() : EGPoint(0,"punkt", 0, 0, EGPoint::FIXED) {
  // do something useful here
}

EGPoint::EGPoint(int id, std::string n, 
		 float lvl, float tme,
		 TYPE t) {
  ID = id;
  name = n;

  // level setzen und normalisieren
  level = lvl;
  level = fmax(0, level);
  level = fmin(1, level);

  // time setzen
  time = tme;
  
  // type setzen
  type = t;
}

EGPoint::~EGPoint() {
  // clean up here
}


// setter
void EGPoint::setLevel(float lvl) {
  if ((type == LEVEL) || (type == ALL)) {
    level = lvl;
    level = fmax(0, level);
    level = fmin(1, level);
  }
}

void EGPoint::setTime(float tme) {
  if ((type == TIME) || (type == ALL)) {
    time = tme;
  }
}


// getter
float EGPoint::getID() {
  return ID;
}

float EGPoint::getLevel() {
  return level;
}

float EGPoint::getTime() {
  return time;
}

int EGPoint::getType() {
  return type;
}

std::string EGPoint::getName() {
  return name;
}

