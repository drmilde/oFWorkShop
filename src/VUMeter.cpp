#include "VUMeter.h"

VUMeter::VUMeter() {
  // do something useful here
}

VUMeter::~VUMeter() {
  // clean up here
}

void VUMeter::draw() {
  ofPushStyle();

  ofSetColor(GuiHelper::BG2());
  ofDrawRectangle(posx, posy, width, height);

  ofPath path;
  path.setCircleResolution(35);
  path.setFillColor(GuiHelper::BG1());

  int x = posx + (width/2);
  int y =  posy + (height/2) + 15;

  path.moveTo(x,y);
  path.arc(x,y,
	   width/2, height/2+5, 
	   200, 340);
  path.draw();

  // draw needle
  ofPushStyle();
  ofSetColor(GuiHelper::FG2());
  ofSetLineWidth(3);    
  
  ofPushMatrix();
  ofTranslate(x,y + 30);

  angle = (angle + 1) % 128;
  setValue(angle/127.0);

  int a = (int) (ofMap(getValue() , 0, 1, 310, 410));

  ofRotate(a % 360);
  ofDrawLine(0,0,0,-100);
  ofPopMatrix();
  ofPopStyle();

  // draw cover
  ofSetColor(GuiHelper::BG1());
  ofDrawCircle(x,y+30,10);

  // display current value
  ofSetColor(255);
  GuiHelper::stringLAt ("+" + ofToString(getValue(),3), posx + 10, posy + height - 10);

  ofPopStyle();
}
