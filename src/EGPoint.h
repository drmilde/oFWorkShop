#ifndef _EG_POINT_h_
#define _EG_POINT_h_

#include "ofMain.h"

class EGPoint {
 public:

  enum TYPE {
    FIXED,
    TIME,
    LEVEL,
    ALL
  };

  EGPoint();
  EGPoint(int id, std::string n,
	  float lvl, float tme,
	  TYPE t);
  virtual ~EGPoint();

  // getter
  float getID();
  float getLevel();
  float getTime();
  int getType();
  std::string getName();

  // setter
  void setLevel(float lvl);
  void setTime(float tme);

 private:
  float level;
  float time;
  TYPE type;
  int ID;
  std::string name;
  
};


#endif
