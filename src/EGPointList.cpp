#include "EGPointList.h"

EGPointList::EGPointList() {
  // do something useful here
}

EGPointList::~EGPointList() {
  // clean up here
}

void EGPointList::add(EGSpan* pnt) {
  points.push_back(pnt);
}

EGSpan* EGPointList::get(int id) {

  for (unsigned int i=0; i < points.size(); i++) {
    int val = (points[i])->getID();
    if (val == id) {
      return points[i];
    }
  }

  return NULL;
}

float EGPointList::getDuration() {
  float result = 0;
  for (unsigned int i=0; i < points.size(); i++) {
    result += (points[i])->getDuration();
  }
  return result;
}

float EGPointList::getMaxDuration() {
  float result = 0;
  for (unsigned int i=0; i < points.size(); i++) {
    result += (points[i])->getMaxDuration();
  }
  return result;
}


int EGPointList::size() {
  return (int)(points.size());
}

void EGPointList::connect() {
  for (unsigned int i=0; i < points.size(); i++) {
    if (i < (points.size()-1)) {
      points[i+1]->setStartTime(points[i]->getEndTime());
      points[i+1]->setStartLevel(points[i]->getEndLevel());
    }
  }
 }

