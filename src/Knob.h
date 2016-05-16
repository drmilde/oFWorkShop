#ifndef __KNOB_h_
#define __KNOB_h_

#include "ofMain.h"
#include "ofTrueTypeFont.h"
#include "Selectable.h"

class Knob : public Selectable {
 public:
  Knob();
  Knob(float value, float min, float max, int start, int end);
  virtual ~Knob();

  void draw();
  void drawValueStringAt (int x, int y);
  void setValue(float value);
  void changeValue(float delta);

 private:
  void setIndex();
  void normInterval();

  // image strip
  ofImage strip;
  int tileHeight = 32;
  int tileWidth = 32;
  int factor = 3;
  int idx = 0;

  // represented value
  float value;

  int startAngle = 230;
  int endAngle = 130;

  float from = -1.0f;
  float to = 1.0f;

  // text output
  ofTrueTypeFont myfont;

};

#endif
