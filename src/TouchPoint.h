#ifndef _TOUCH_POINT_h_
#define _TOUCH_POINT_h_

#include <iostream>
#include "ofMain.h"
#include "Selectable.h"
#include "GuiHelper.h"

class TouchPoint : public Selectable {
 public:
  TouchPoint();
  TouchPoint(std::string name);
  virtual ~TouchPoint();

  void draw();
  void drawAt(int x, int y);

  float getValue ();
  void setValue(float v);

 private:
  bool on = true;
  float value;

};

#endif
