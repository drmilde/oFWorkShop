#include "EGSpanList.h"

EGSpanList::EGSpanList() {
  // do something useful here
}

EGSpanList::~EGSpanList() {
  // clean up here
}

void EGSpanList::add(EGSpan* pnt) {
  points.push_back(pnt);
}

EGSpan* EGSpanList::get(int id) {

  for (unsigned int i=0; i < points.size(); i++) {
    int val = (points[i])->getID();
    if (val == id) {
      return points[i];
    }
  }

  return NULL;
}

float EGSpanList::getDuration() {
  float result = 0;
  for (unsigned int i=0; i < points.size(); i++) {
    result += (points[i])->getDuration();
  }
  return result;
}

float EGSpanList::getMaxDuration() {
  float result = 0;
  for (unsigned int i=0; i < points.size(); i++) {
    result += (points[i])->getMaxDuration();
  }
  return result;
}


int EGSpanList::size() {
  return (int)(points.size());
}

void EGSpanList::connect() {
  for (unsigned int i=0; i < points.size(); i++) {
    if (i < (points.size()-1)) {
      points[i+1]->setStartTime(points[i]->getEndTime());
      points[i+1]->setStartLevel(points[i]->getEndLevel());
    }
  }
 }

