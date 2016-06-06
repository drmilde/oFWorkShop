#ifndef _METER_h_
#define _METER_h_

#include "ofMain.h"
#include "Selectable.h"

class Meter : public Selectable {
  
 public:
  Meter();
  Meter(std::string name);
  virtual ~Meter();

 protected:
  void setValue(float v);
  float getValue();

  float value;

};


#endif
