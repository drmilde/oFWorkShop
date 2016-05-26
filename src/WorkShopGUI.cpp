#include "WorkShopGUI.h"

WorkShopGUI::WorkShopGUI() {
  myfont.load("Courier-Sans.ttf", 28);
  smallfont.load("Courier-Sans.ttf", 18);

  //knobs
  freqKnob =  Knob("freq", 0.0, 0, 1, 220, 140);
  freqKnob.setBoundingBox(55,80, 32*3, 32*3);
  add(&freqKnob);

  pwmKnob =  Knob("pwm", 0.0, 0, 1, 220, 140);
  pwmKnob.setBoundingBox(340 + 55,80, 32*3, 32*3);
  add(&pwmKnob);

  cutoffKnob =  Knob("cutoff", 0.0, 0, 1, 220, 140);
  cutoffKnob.setBoundingBox(665,80, 32*3, 32*3);
  add(&cutoffKnob);

  resKnob =  Knob("res", 0.0, 0, 1, 220, 140);
  resKnob.setBoundingBox(875,80, 32*3, 32*3);
  add(&resKnob);

  lfoAmntKnob =  Knob("lfo amnt", 0.0, 0, 1, 220, 140);
  lfoAmntKnob.setBoundingBox(250,330, 32*3, 32*3);
  add(&lfoAmntKnob);

  vcfAmntKnob =  Knob("vcf amnt", 0.0, 0, 1, 220, 140);
  vcfAmntKnob.setBoundingBox(875,330, 32*3, 32*3);
  add(&vcfAmntKnob);

  rateKnob =  Knob("rate", 0.0, 0, 1, 220, 140);
  rateKnob.setBoundingBox(100,600, 32*3, 32*3);
  add(&rateKnob);

  glideKnob =  Knob("glide", 0.0, 0, 1, 220, 140);
  glideKnob.setBoundingBox(265,600, 32*3, 32*3);
  add(&glideKnob);

  attackKnob =  Knob("attack", 0.0, 0, 1, 220, 140);
  attackKnob.setBoundingBox(875,600, 32*3, 32*3);
  add(&attackKnob);

  decayKnob =  Knob("decay", 0.0, 0, 1, 220, 140);
  decayKnob.setBoundingBox(1045,600, 32*3, 32*3);
  add(&decayKnob);

  // binary switches
  vcoWaveFormSwitch = BinarySwitch("vco wave form", 0, 1, "Pulse", "Saw");
  vcoWaveFormSwitch.setBoundingBox(260, 95, 35, 66, 4, 1);
  add(&vcoWaveFormSwitch);

  vcaModeSwitch = BinarySwitch("vca mode", 0, 1, "On", "EG");
  vcaModeSwitch.setBoundingBox(1100, 95, 35, 66, 4, 1);
  add(&vcaModeSwitch);

  vcoModSourceSwitch = BinarySwitch("vco mod source", 0, 1, "EG", "LFO");
  vcoModSourceSwitch.setBoundingBox(85, 350, 35, 66, 4, 1);
  add(&vcoModSourceSwitch);

  vcoModDestSwitch = BinarySwitch("vco mod dest", 0, 1, "PWM", "FREQ");
  vcoModDestSwitch.setBoundingBox(430, 350, 35, 66, 4, 1);
  add(&vcoModDestSwitch);

  vcfModSourceSwitch = BinarySwitch("vcf mod source", 0, 1, "EG", "LFO");
  vcfModSourceSwitch.setBoundingBox(690, 350, 35, 66, 4, 1);
  add(&vcfModSourceSwitch);

  vcfModPolaritySwitch = BinarySwitch("vcf mod polarity", 0, 1, "[+]", "[-]");
  vcfModPolaritySwitch.setBoundingBox(1085, 350, 35, 66, 4, 1);
  add(&vcfModPolaritySwitch);

  lfoWaveFormSwitch = BinarySwitch("lfo wave form", 0, 1, "Square", "Triangle");
  lfoWaveFormSwitch.setBoundingBox(430, 620, 35, 66, 4, 1);
  add(&lfoWaveFormSwitch);

  egSustainSwitch = BinarySwitch("eg sustain", 0, 1, "On", "Off");
  egSustainSwitch.setBoundingBox(690, 620, 35, 66, 4, 1);
  add(&egSustainSwitch);
}

WorkShopGUI::~WorkShopGUI() {
  // clean up here
}

void WorkShopGUI::draw() {
  ofPushStyle();
  ofNoFill();

  // erste Zeile
  drawTitle("VCO", 10 + 10, 20 + 20, 90, 40);
  ofDrawRectRounded(0   + 10,      10, 600, 250, 10);
  drawTitle("VCF", 600 + 20 + 10, 20 + 20, 90, 40);
  ofDrawRectRounded(600 + 10 + 10, 10, 400, 250, 10);
  drawTitle("VCA", 1000 + 20 + 10, 20 + 20, 90, 40);
  ofDrawRectRounded(1000 + 10 + 10, 10, 200, 250, 10);

  // beschriftung erste Zeile
  smallfont.drawString("FREQ", 50 + 20, 240);
  smallfont.drawString("WAVE", 180 + 50 + 20, 240);
  smallfont.drawString("PWM", 400 + 20, 240);

  smallfont.drawString("CUTOFF", 600 + 50 + 20, 240);
  smallfont.drawString("RES", 900, 240);
  smallfont.drawString("MODE", 1090, 240);  

  // zweite Zeile
  drawTitle("VCO MOD", 10 + 10, 250 + 20 + 30, 175, 40);
  ofDrawRectRounded(0   + 10,       250 + 10 + 10, 600, 250, 10);
  drawTitle("VCF MOD", 600 + 20 + 10, 250 + 20 + 30, 175, 40);
  ofDrawRectRounded(600 + 10 + 10,  250 + 10 + 10, 600, 250, 10);

  // beschriftung zweite Zeile
  smallfont.drawString("SOURCE", 50 + 20, 500);
  smallfont.drawString("AMOUNT", 180 + 50 + 20, 500);
  smallfont.drawString("DEST", 400 + 20, 500);

  smallfont.drawString("SOURCE", 600 + 50 + 20, 500);
  smallfont.drawString("AMOUNT", 875, 500);
  smallfont.drawString("POLARITY", 1050, 500);

  // dritte Zeile
  drawTitle("LFO", 10 + 10, 500 + 40 + 20, 90, 40);
  ofDrawRectRounded(0   + 10,       500 + 10 + 20, 600, 250, 10);
  drawTitle("ENVELOPE", 600 + 20 + 10, 500 + 30 + 30, 195, 40);
  ofDrawRectRounded(600 + 10 + 10,  500 + 10 + 20, 600, 250, 10);

  // Beschriftung dritte zeile
  smallfont.drawString("RATE", 110, 760);
  smallfont.drawString("GLIDE", 270, 760);
  smallfont.drawString("WAVE", 400 + 20, 760);

  smallfont.drawString("SUSTAIN", 600 + 50 + 20, 760);
  smallfont.drawString("ATTACK", 875, 760);
  smallfont.drawString("DECAY", 1050, 760);
  ofPopStyle();

  // draw the knobs
  // draw the switches
  Page::draw();
}


void WorkShopGUI::drawTitle(std::string txt, int x, int y, int w, int h) {
  ofPushStyle();
  ofColor(255,255,255);
  ofFill();
  ofDrawRectRounded(x - 10, y-30, 0, 
		    w, h, 
		    10, 0, 10, 0);
  
  ofSetColor(0,0,0);
  myfont.drawString(txt, x, y);
  ofPopStyle();
}


// callbacks
void WorkShopGUI::mouseDragged(int msx, int msy, 
			       int x, int y, int button){

  Page::mouseDragged(msx, msy, x, y,  button);

}

void WorkShopGUI::mousePressed(int msx, int msy, int button){

  Page::mousePressed(msx, msy, button);

}

