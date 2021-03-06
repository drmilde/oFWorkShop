#pragma once

#include "ofMain.h"
#include "Knob.h"
#include "RectAngleManager.h"
#include "WorkShopGUI.h"
#include "WidgetsTest.h"

class ofApp : public ofBaseApp {
 public:
  void setup();
  void update();
  void draw();
  
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  
 private:
  ofImage backImage;
  int angle = 0;
  int imgRef = 1;

  RectAngleManager rm;
  vector <Knob> knobs;

  WorkShopGUI gui;
  WidgetsTest wt;
};
