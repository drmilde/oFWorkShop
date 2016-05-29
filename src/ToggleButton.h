#ifndef _TOGGLE_BUTTON_h_
#define _TOGGLE_BUTTON_h_

#include <iostream>
#include "ofMain.h"
#include "Selectable.h"

class ToggleButton : public Selectable {
 public:
  ToggleButton();
  ToggleButton(std::string name);
  virtual ~ToggleButton();

  void draw();
  void drawAt(int x, int y);
  void toggle();

  void setGridID(int c, int r);
  int getGridCol();
  int getGridRow();
  void setValue (float v);
  float getValue ();


 private:
  bool on = false;

  int col;
  int row;
  float value;

};

#endif
