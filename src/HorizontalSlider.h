#ifndef _HORIZONTAL_SLIDER_h_
#define _HORIZONTAL_SLIDER_h_

#include <iostream>
#include "ofMain.h"
#include "Slider.h"

class HorizontalSlider: public Slider {
 public:
  
  HorizontalSlider();
  HorizontalSlider(std::string name);
  HorizontalSlider(std::string name, float value, float min, float max);  
  virtual ~HorizontalSlider();

  void setClickPosition(int x);
  void setValue(float value);
  void changeValue(float delta);
  void draw();

 private:
  int handleX;

    
};

#endif
