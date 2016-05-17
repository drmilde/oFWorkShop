#ifndef _BINARY_SWITCH_h_
#define _BINARY_SWITCH_h_

#include "ofMain.h"
#include "ofTrueTypeFont.h"
#include "Selectable.h"

class BinarySwitch : public Selectable {
 public:
  BinarySwitch(std::string name);
  BinarySwitch(std::string name, 
	       float low, float hi, 
	       std::string lowStrng, std::string hiStrng);
  virtual ~BinarySwitch();

  void draw();
  void setValue(float value);
  void toggle();

 private:
  ofRectangle box;
  std::string lowString;
  std::string hiString;
  float hiValue;
  float lowValue;
  float value = 0;

  ofTrueTypeFont smallFont;
  ofImage imgSwitch;
  int imgOffsetX = 0;
};


#endif
