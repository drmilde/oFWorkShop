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

 private:
  ofRectangle box;
  std::string lowString;
  std::string hiString;
  float hiValue;
  float lowValue;

  ofTrueTypeFont smallFont;
};


#endif
