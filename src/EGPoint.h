#ifndef _EG_POINT_h_
#define _EG_POINT_h_

#include "ofMain.h"

class EGPoint {
 public:

  enum TYPE {
    TIME,
    LEVEL
  };
  
  EGPoint(int id, std::string n,
	  float startL, float endL, 
	  float dur, float maxD, 
	  TYPE t);
  virtual ~EGPoint();

  // getter
  float getID();
  float getStartLevel();
  float getEndLevel();
  float getDuration();
  float getMaxDuration();
  float getType();
  std::string getName();

  // setter
  void setStartLevel(float l);
  void setEndLevel(float l);
  void setDuration(float dur);

 private:
  float startLevel;
  float endLevel;
  float duration;
  float maxDuration;
  TYPE type;
  int ID;
  std::string name;
  
};


#endif
