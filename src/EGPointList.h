#ifndef _EG_POINT_LIST_h_
#define _EG_POINT_LIST_h_

#include "ofMain.h"
#include "EGPoint.h"

class EGPointList {

 public:
  EGPointList();
  virtual ~EGPointList();

  void add(EGPoint* pnt);
  EGPoint* get(int id);
  float getDuration();
  int size();

 protected:
  vector <EGPoint *> points;
  
};


#endif
