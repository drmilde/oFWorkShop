#ifndef _WIDGETS_TEST_h_
#define _WIDGETS_TEST_h_

#include "ofMain.h"
#include "ofTrueTypeFont.h"
#include "Knob.h"
#include "BinarySwitch.h"
#include "HorizontalSlider.h"
#include "VerticalSlider.h"
#include "XYSelect.h"

class WidgetsTest {

 public:
  WidgetsTest();
  virtual ~WidgetsTest();
  void draw();
  void drag(int msx, int msy, int x, int y);
  void mousePressed(int x, int y);

 private:
  ofTrueTypeFont myfont;
  ofTrueTypeFont smallfont;

  // knobs
  Knob freqKnob = Knob("freq");
  BinarySwitch vcoWaveFormSwitch = BinarySwitch("vco wave form");

  // test sliders
  HorizontalSlider hs;
  VerticalSlider vs;

  // XYSelect

  XYSelect xy;
};


#endif
