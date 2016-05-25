#ifndef _SLIDER_h_
#define _SLIDER_h_

#include "ofMain.h"
#include "Selectable.h"

class Slider : public Selectable {

 public:
  Slider(std::string name);
  Slider(std::string name, float min, float max);
  virtual ~Slider();

  virtual void draw() = 0; // has to be implemented by sub classes

 protected:
  void setValue(float v);
  void changeValue(float delta);
  void drawValueStringAt (int x, int y);
  void drawNameStringAt (int x, int y);

  ofImage imgHandle;
  float value;
  float low;
  float high;  
};

#endif
