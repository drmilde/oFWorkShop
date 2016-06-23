#ifndef _TOUCH_POINT_FIELD_h_
#define _TOUCH_POINT_FIELD_h_

#include "ofMain.h"
#include "Selectable.h"
#include "TouchPoint.h"

class TouchPointField : public Selectable {
 public:
  TouchPointField();
  TouchPointField(std::string name);
  virtual ~TouchPointField();

  
  void draw();
  void drawTouchPoints();
  void addTouchPoint(int id, int x, int y, int r);


 private:
  int normX(int x);
  int normY(int y);

  vector <TouchPoint *> tpoints;


};


#endif
