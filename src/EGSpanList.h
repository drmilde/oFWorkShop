#ifndef _EG_SPAN_LIST_h_
#define _EG_SPAN_LIST_h_

#include "ofMain.h"
#include "EGSpan.h"
#include "EGPoint.h"
#include "IDGenerator.h"

class EGSpanList {

 public:
  EGSpanList();
  virtual ~EGSpanList();

  void addPoint(int id, std::string name, 
		float lvl, float tme, EGPoint::TYPE t);

  void addSpan(std::string name, 
	       int idP1, int idP2, 
	       float maxD,
	       EGSpan::TYPE t);

  EGSpan* getSpan(int id);
  EGPoint* getPoint(int id);

  float getDuration();
  float getMaxDuration();

  int size();
  void clear();

  // list constraints
  void order();

 protected:
  vector <EGSpan *> spans;
  vector <EGPoint *> points;
  IDGenerator IDG = IDGenerator();
  
};


#endif
