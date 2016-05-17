#ifndef _SELECTABLE_h_
#define _SELECTABLE_h_

#include <iostream>
#include "ofMain.h"
#include "GuiDrawable.h"

class Selectable : public GuiDrawable {
 public:
  Selectable(std::string name);
  virtual ~Selectable();

  void setBoundingBox (int x, int y, int w, int h);
  void setSelected(bool sel);
  bool isSelected();
  bool inside(int x, int y);
  void draw();

 private:
  ofRectangle box;
  bool selected = false;

};

#endif
