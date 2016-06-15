#include "EGSpanList.h"

EGSpanList::EGSpanList() {
  // do something useful here
}

EGSpanList::~EGSpanList() {
  // clean up here
}

void EGSpanList::add(EGSpan* pnt) {
  spans.push_back(pnt);
}

EGSpan* EGSpanList::get(int id) {

  for (unsigned int i=0; i < spans.size(); i++) {
    int val = (spans[i])->getID();
    if (val == id) {
      return spans[i];
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

void EGSpanList::connect() {
  for (unsigned int i=0; i < spans.size(); i++) {
    if (i < (spans.size()-1)) {
      spans[i+1]->setStartTime(spans[i]->getEndTime());
      spans[i+1]->setStartLevel(spans[i]->getEndLevel());
    }
  }
 }

