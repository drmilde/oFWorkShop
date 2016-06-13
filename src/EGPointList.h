#ifndef _EG_POINT_LIST_h_
#define _EG_POINT_LIST_h_

#include "ofMain.h"
#include "EGSpan.h"

class EGPointList {

 public:
  EGPointList();
  virtual ~EGPointList();

  void add(EGSpan* pnt);
  EGSpan* get(int id);
  float getDuration();
  float getMaxDuration();
  int size();

  void connect(); // connect nodes

 protected:
  vector <EGSpan *> points;
  
};


#endif
