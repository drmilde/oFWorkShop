#ifndef _RECTANGLE_MANAGER_h_
#define _RECTANGLE_MANAGER_h_

#include "ofMain.h"
#include "CoordinateHelper.h"

class RectAngleManager {
 public:
  RectAngleManager();
  virtual ~RectAngleManager();
  void draw();

  void addRect(int x, int y, int w, int h);
  int inside (int x, int y);

 private:
  std::vector <ofRectangle*> rects;

  int selected = -1;
  
};

#endif
