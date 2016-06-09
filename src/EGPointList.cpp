#include "EGPointList.h"

EGPointList::EGPointList() {
  // do something useful here
}

EGPointList::~EGPointList() {
  // clean up here
}

void EGPointList::add(EGPoint* pnt) {
  points.push_back(pnt);
}

EGPoint* EGPointList::get(int id) {

  for (unsigned int i=0; i< points.size(); i++) {
    int val = (points[i])->getID();
    if (val == id) {
      points[i];
    }
  }

  return NULL;
}

float EGPointList::getDuration() {
  float result = 0;
  for (unsigned int i=0; i< points.size(); i++) {
    result += (points[i])->getDuration();
  }
  return result;
}


int EGPointList::size() {
  return (int)(points.size());
}

