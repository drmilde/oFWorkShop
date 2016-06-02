#ifndef _WIDGETS_TEST_h_
#define _WIDGETS_TEST_h_

#include "ofMain.h"
#include "ofTrueTypeFont.h"
#include "GuiDrawable.h"
#include "Knob.h"
#include "BinarySwitch.h"
#include "HorizontalSlider.h"
#include "VerticalSlider.h"
#include "XYSelect.h"
#include "Grid.h"
#include "ToggleButton.h"
#include "RadioButtonGroup.h"
#include "TextButton.h"
#include "GuiHelper.h"

class WidgetsTest : public GuiDrawable{

 public:
  WidgetsTest();
  virtual ~WidgetsTest();
  void draw();
  void drag(int msx, int msy, int x, int y);
  void mousePressed(int x, int y);

 private:

  // knobs
  Knob freqKnob = Knob("freq");
  BinarySwitch vcoWaveFormSwitch = BinarySwitch("vco wave form");

  // test sliders
  HorizontalSlider hs;
  VerticalSlider vs;

  // XYSelect
  XYSelect xy;

  // Grid
  Grid grid;

  // ToggleButton
  ToggleButton tb;

  // RadioButtonGroup
  RadioButtonGroup rg;

  // TextButton
  TextButton txtb;

  // GuiHelper
  GuiHelper gh;


};


#endif
