#ifndef _EG_SPAN_h_
#define _EG_SPAN_h_

#include "ofMain.h"

class EGSpan {
 public:

  enum TYPE {
    FIXED,
    TIME,
    LEVEL,
    ALL
  };
  
  EGSpan(int id, std::string n,
	 float startL, float endL, 
	 float startT, float dur, float maxD, 
	 TYPE t1, TYPE t2);
  virtual ~EGSpan();

  // getter
  float getID();
  float getStartLevel();
  float getEndLevel();
  float getEndTime();
  float getDuration();
  float getMaxDuration();
  float getTypeStart();
  float getTypeEnd();
  std::string getName();

  // setter
  void setStartLevel(float l);
  void setEndLevel(float l);
  void setStartTime(float st);
  void setEndTime(float et);
  void setDuration(float dur);

 private:
  float startLevel;
  float endLevel;

  float startTime;
  float duration;

  float maxDuration;
  TYPE type1;
  TYPE type2;
  int ID;
  std::string name;
  
};


#endif
