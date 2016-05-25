#include "WidgetsTest.h"

WidgetsTest::WidgetsTest() {
  // do something useful here
  myfont.load("Courier-Sans.ttf", 28);
  smallfont.load("Courier-Sans.ttf", 18);

  //knobs
  freqKnob =  Knob("freq", 0.0, 0, 1, 220, 140);
  freqKnob.setBoundingBox(55,80, 32*3, 32*3);

  // binary switches
  vcoWaveFormSwitch = BinarySwitch("vco wave form", 0, 1, "Pulse", "Saw");
  vcoWaveFormSwitch.setBoundingBox(260, 95, 35, 66, 4, 1);

  // test sliders
  hs  = HorizontalSlider("hslider", 0, 0, 200);
  hs.setBoundingBox(140,35,400,20,1,3);
  hs.setValue(0);

  vs  = VerticalSlider("Attack", 0, 0, 127);
  vs.setBoundingBox(560,100,20,200,3,1);
  vs.setValue(0);

  // test XYSelect
  xy  = XYSelect();
  xy.setBoundingBox(200,300,300,300,1,1);
}

WidgetsTest::~WidgetsTest() {
  // clean up 
}


void WidgetsTest::draw() {
  // draw knobs
  freqKnob.draw();

  // draw binary switch
  vcoWaveFormSwitch.draw();

  // draw the horizontal slider
  hs.draw();
  vs.draw();

  // XYSelect
  xy.draw();
}


void WidgetsTest::drag(int msx, int msy, int x, int y) {
  // process dragging knobs
  if (freqKnob.isSelected()) {
    float step = 1.0 / 128; // standard: 128 steps for complete range
    // dragging up
    if ((msy - ofGetPreviousMouseY()) < 0) {
      freqKnob.changeValue(-step);
    }
    // dragging down
    if ((msy - ofGetPreviousMouseY()) > 0) {
      freqKnob.changeValue(+step);
    }
    
    // dragging left
    if ((msx - ofGetPreviousMouseX()) < 0) {
      freqKnob.changeValue(-step);
    }
    // dragging right
    if ((msx - ofGetPreviousMouseX()) > 0) {
      freqKnob.changeValue(+step);
    }    
  }


  // HORIZONTAL/VERTICAL SLIDER
  if (hs.isSelected()) {
    hs.setClickPosition(x);
  }
  if (vs.isSelected()) {
    vs.setClickPosition(y);
  }


  // XYSelect

  if (xy.isSelected()) {
    xy.setClickPosition(x,y);
  }
}

void WidgetsTest::mousePressed(int x, int y) {
  // check knob
  freqKnob.inside(x,y);

  // switches
  vcoWaveFormSwitch.inside(x,y);
  if (vcoWaveFormSwitch.isSelected()) {
    vcoWaveFormSwitch.toggle();
    vcoWaveFormSwitch.setSelected(false);  
  }  


  // HORIZONTAL/VERTICAL SLIDER
  if (hs.inside(x,y)) {
    hs.setClickPosition(x);
  }
  if (vs.inside(x,y)) {
    vs.setClickPosition(y);
  }

  // XYSelect

  if (xy.inside(x,y)) {
    xy.setClickPosition(x,y);
  }


}
