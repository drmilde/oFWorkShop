#ifndef _SELECTABLE_h_
#define _SELECTABLE_h_

#include <iostream>
#include "ofMain.h"
#include "GuiDrawable.h"

class Selectable : public GuiDrawable {

 public:
  enum TYPE {KNOB, 
	     PUSH_BUTTON, 
	     BINARY_SWITCH, 
	     HSLIDER, VSLIDER, 
	     XYSELECT,
	     TOGGLE_BUTTON,
	     TOUCH_POINT,
	     TOUCH_POINT_FIELD,
	     RADIO_BUTTON_GROUP,
	     TEXT_BUTTON,
	     GUI_HELPER,
	     METER,
	     VUMETER,
	     EG_EDITOR,
	     COLOR_SCHEME,
	     GRID
  }; 

  Selectable(std::string name, TYPE t);
  virtual ~Selectable();

  void setBoundingBox (int x, int y, int w, int h);
  void setBoundingBox (int x, int y, int w, int h, int fx, int fy);
  void setSelected(bool sel);
  bool isSelected();
  bool inside(int x, int y);
  bool insideAt(int x, int y, int ox, int oy);
  void draw();
  TYPE getType();


 private:
  ofRectangle box;
  ofRectangle sensitiveField;
  ofRectangle sensitiveAtField;
  bool selected = false;
  TYPE type;

};

#endif
