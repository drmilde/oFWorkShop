#ifndef _EG_POINT_h_
#define _EG_POINT_h_

class EGPoint {
 public:

  enum TYPE {
    TIME,
    LEVEL
  };
  
  EGPoint(int id, float startL, float endL, float maxD, TYPE t);
  virtual ~EGPoint();

  // getter
  float getID();
  float getStartLevel();
  float getEndLevel();
  float getDuration();
  float getMaxDuration();
  float getType();

  // setter
  void setStartLevel(float l);
  void setEndLevel(float l);


 private:
  float startLevel;
  float endLevel;
  float duration;
  float maxDuration;
  TYPE type;
  int ID;
  
};


#endif
