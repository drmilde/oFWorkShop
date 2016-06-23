#ifndef _TOUCH_POINT_FIELD_h_
#define _TOUCH_POINT_FIELD_h_

#include "ofMain.h"
#include "Selectable.h"
#include "TouchPoint.h"
#include "IDGenerator.h"

class TouchPointField : public Selectable {
 public:
  TouchPointField();
  TouchPointField(std::string name);
  virtual ~TouchPointField();

  
  void draw();
  void drawTouchPoints();
  void addTouchPoint(int x, int y, int r);
  void drag(int x, int y);
  void clicked(int x, int y);


 private:
  int normX(int x);
  int normY(int y);
  IDGenerator IDG = IDGenerator();

  vector <TouchPoint *> tpoints;


};


#endif
