#ifndef _VERTICAL_SLIDER_h_
#define _VERTICAL_SLIDER_h_

#include <iostream>
#include "ofMain.h"
#include "Slider.h"

class VerticalSlider: public Slider {
 public:
  
  VerticalSlider();
  VerticalSlider(std::string name);
  VerticalSlider(std::string name, float value, float min, float max);  
  virtual ~VerticalSlider();

  void setClickPosition(int y);
  void setValue(float value);
  void changeValue(float delta);
  void draw();
  void drawAt(int x, int y);

 private:
  int handleY;

    
};

#endif
