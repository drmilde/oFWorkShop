#ifndef _EG_SPAN_h_
#define _EG_SPAN_h_

#include "ofMain.h"
#include "EGPoint.h"

class EGSpan {
 public:

  enum TYPE {
    FIXED,
    FIXED_LEVEL,
    FIXED_DURATION,
    FREE
  };
  
  EGSpan(int id, std::string n,
	 EGPoint* p1, EGPoint* p2,
	 float maxDrtn,
	 TYPE t
	 );
  virtual ~EGSpan();

  // getter
  float getID();
  float getStartLevel();
  float getEndLevel();
  float getStartTime();
  float getEndTime();
  float getDuration();
  float getMaxDuration();
  int getTypeStart();
  int getTypeEnd();
  std::string getName();
  EGPoint* getStartPoint();
  EGPoint* getEndPoint();

  // setter
  void setStartLevel(float l);
  void setEndLevel(float l);
  void setStartTime(float st);
  void setEndTime(float et);

  // sanity checking
  bool check(int id, float tme);
  void print();

 private:
  void updateDuration();

  EGPoint* startPoint;
  EGPoint* endPoint;

  float maxDuration;
  int ID;
  std::string name;
  TYPE type;
  
};


#endif
