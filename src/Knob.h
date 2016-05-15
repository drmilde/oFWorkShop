#ifndef __KNOB_h_
#define __KNOB_h_

#include "ofMain.h"

class Knob {
 public:
  Knob();
  Knob(float value, float min, float max, int start, int end);
  virtual ~Knob();

  void drawAt(int x, int y);
  void setValue(float value);
  void normInterval();

 private:
  void setIndex();

  ofImage strip;
  int tileHeight = 32;
  int tileWidth = 32;
  float value;
  int idx = 0;
  int scaleFactor = 3;

  int startAngle = 230;
  int endAngle = 130;

  float from = -1.0f;
  float to = 1.0f;

};

#endif
