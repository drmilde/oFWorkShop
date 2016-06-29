#ifndef _TOUCH_POINT_FIELD_h_
#define _TOUCH_POINT_FIELD_h_

#include "ofMain.h"
#include "DynamicSelectable.h"
#include "TouchPoint.h"
#include "IDGenerator.h"

class TouchPointField : public DynamicSelectable {
 public:
  TouchPointField();
  TouchPointField(std::string name);
  virtual ~TouchPointField();

  
  void draw();
  void drawTouchPoints();
  int addTouchPoint(int x, int y, int r);
  void resize();
  void setOffSet(int x, int y);

  void drag(int x, int y);
  void clicked(int x, int y);

  TouchPoint* getTouchPoint(int id);


 private:
  IDGenerator IDG = IDGenerator();

  vector <TouchPoint *> tpoints;

  int offx = 0;
  int offy = 0;


};


#endif
