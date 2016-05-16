#ifndef _COORDINATE_HELPER_h_
#define _COORDINATE_HELPER_h_

#include "ofMain.h"

class CoordinateHelper {
 public:
  CoordinateHelper();
  virtual ~CoordinateHelper();

  void reset();
  void set(int x, int y);
  void set(int x, int y, int z);
  void translate (int x, int y);
  void scale (int factor);
  void rotateZ (int angle);
  int getScreenX();
  int getScreenY();

 private:
  ofVec3f vertices;

};

#endif
