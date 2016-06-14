#ifndef _EG_SPAN_LIST_h_
#define _EG_SPAN_LIST_h_

#include "ofMain.h"
#include "EGSpan.h"

class EGSpanList {

 public:
  EGSpanList();
  virtual ~EGSpanList();

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
