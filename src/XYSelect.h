#ifndef XY_SELECT_h_
#define XY_SELECT_h_

#include <iostream>
#include "ofMain.h"
#include "Selectable.h"

class XYSelect : public Selectable {
 public:
  XYSelect();
  XYSelect(std::string name);
  virtual ~XYSelect();
  
  void draw();
  void setClickPosition(int x, int y);

 private:
  void drawValueStringAt (int x, int y, float value);
  void drawNameStringAt (int x, int y);

  int relX = 0;
  int relY = 0;

  float valX = 0;
  float valY = 0;
};


#endif
