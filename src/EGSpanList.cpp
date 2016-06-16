#include "EGSpanList.h"

EGSpanList::EGSpanList() {
  // do something useful here
  clear();
}

EGSpanList::~EGSpanList() {
  // clean up here
}

void EGSpanList::addSpan(std::string name, 
			 int p1ID, int p2ID, 
			 float maxD,
			 EGSpan::TYPE t
			 ) {
  int id = IDG.nextID();
  EGPoint* p1 = getPoint(p1ID);
  EGPoint* p2 = getPoint(p2ID);

  if ((p1 != NULL) && (p2 != NULL)) {
    spans.push_back(new EGSpan(id, name, p1, p2, maxD, t));
  }
}

void EGSpanList::addPoint(int id,
			  std::string name, 
			  float lvl, 
			  float tme, 
			  EGPoint::TYPE t) {

  points.push_back(new EGPoint(id, name, lvl, tme, t));

}


EGSpan* EGSpanList::getSpan(int id) {

  for (unsigned int i=0; i < spans.size(); i++) {
    int val = (spans[i])->getID();
    if (val == id) {
      return spans[i];
    }
  }

  return NULL;
}

EGPoint* EGSpanList::getPoint(int id) {

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
  for (unsigned int i=0; i < spans.size(); i++) {
    result += (spans[i])->getDuration();
  }
  return result;
}

float EGSpanList::getMaxDuration() {
  float result = 0;
  for (unsigned int i=0; i < spans.size(); i++) {
    result += (spans[i])->getMaxDuration();
  }
  return result;
}


int EGSpanList::size() {
  return (int)(spans.size());
}

void EGSpanList::clear() {
  spans.clear();
  points.clear();
  IDG.reset();
}

// list constraints

void EGSpanList::order() {
  for (unsigned int i=0; i < (points.size()-1); i++) {
    if (points[i]->getTime() > points[i+1]->getTime()) {
      points[i]->setTime(points[i+1]->getTime());
    }
  }
}

