#ifndef _TOUCH_POINT_h_
#define _TOUCH_POINT_h_

#include <iostream>
#include "ofMain.h"
#include "Selectable.h"
#include "GuiHelper.h"

class TouchPoint : public Selectable {
 public:
  TouchPoint();
  TouchPoint(int id, std::string name);
  virtual ~TouchPoint();

  void draw();
  void drawAt(int x, int y);

  float getValue ();
  void setValue(float v);

  void drag(int msx, int msy);
  void highlight(int msx, int msy);
  bool near (int x, int y, int d);

  int getCenterX();
  int getCenterY();

  int getID();


 private:
  bool on = true;
  float value;
  int currentMouseX;
  int currentMouseY;
  bool move = false;
  int ID;

};

#endif
