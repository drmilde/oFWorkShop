#ifndef _WORK_SHOP_GUI_h_
#define _WORK_SHOP_GUI_h_

#include "ofMain.h"
#include "ofTrueTypeFont.h"
#include "Knob.h"
#include "BinarySwitch.h"
#include "HorizontalSlider.h"
#include "VerticalSlider.h"

class WorkShopGUI {
 public:
  WorkShopGUI();
  virtual ~WorkShopGUI();

  void draw();
  void mouseDragged(int msx, int msy, int x, int y, int button);
  void mousePressed(int x, int y, int button);

 private:
  void drawTitle(std::string txt, int x, int y, int w, int h);
  
  // text output
  ofTrueTypeFont myfont;
  ofTrueTypeFont smallfont;

  // knobs
  Knob freqKnob = Knob("freq");
  Knob pwmKnob = Knob("pwm");
  Knob cutoffKnob = Knob("cutoff");
  Knob resKnob = Knob("res");
  Knob lfoAmntKnob = Knob("lfo amnt");
  Knob vcfAmntKnob = Knob("vcf amnt");
  Knob rateKnob = Knob("rate");
  Knob attackKnob = Knob("attack");
  Knob decayKnob = Knob("decay");
  Knob glideKnob = Knob("glide");

  BinarySwitch vcoWaveFormSwitch = BinarySwitch("vco wave form");
  BinarySwitch vcaModeSwitch = BinarySwitch("vca mode");
  BinarySwitch vcoModSourceSwitch = BinarySwitch("vco mod source");
  BinarySwitch vcoModDestSwitch = BinarySwitch("vco mod dest");
  BinarySwitch vcfModSourceSwitch = BinarySwitch("vcf mod source");
  BinarySwitch vcfModPolaritySwitch = BinarySwitch("vcf mod polarity");
  BinarySwitch lfoWaveFormSwitch = BinarySwitch("lfo wave form");
  BinarySwitch egSustainSwitch = BinarySwitch("eg sustain");
  vector <Knob> knobs;
  vector <BinarySwitch> switches;

};


#endif
