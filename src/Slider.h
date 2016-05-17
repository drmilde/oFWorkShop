#ifndef _SLIDER_h_
#define _SLIDER_h_

#include "ofMain.h"
#include "Selectable.h"

class Slider : public Selectable {

 public:
  Slider(std::string name);
  Slider(std::string name, float mn, float mx);
  virtual ~Slider();

  void setValue(float v);

  virtual void draw() = 0; // has to be implemented by sub classes

 protected:
  ofImage imgHandle;
  float value;
  float low;
  float high;
  
};

#endif
