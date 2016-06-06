#ifndef _VU_METER_h
#define _VU_METER_h

#include "Meter.h"
#include "GuiHelper.h"

class VUMeter: public Meter {

 public:
  VUMeter();
  virtual ~VUMeter();

  void draw();

 private:
  int angle = 0;

};

#endif
