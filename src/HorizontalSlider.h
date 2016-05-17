#ifndef _HORIZONTAL_SLIDER_h_
#define _HORIZONTAL_SLIDER_h_

#include "Slider.h"

class HorizontalSlider: public Slider {
 public:
  HorizontalSlider();
  virtual ~HorizontalSlider();
  
  void draw();
};

#endif
