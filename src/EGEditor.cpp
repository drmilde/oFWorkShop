#include "EGEditor.h"

EGEditor::EGEditor() : EGEditor("Mr Postman") {
  // do something useful here
}

EGEditor::EGEditor(std::string name) : Selectable(name, EG_EDITOR) {
  // do something useful here

  // configuring a standard ADSR envelope
  EGPoint* p0 = new EGPoint(0, "attack",
			    0.0, 1.0, 
			    1.0, 
			    3.0, EGPoint::TIME);
  list.add(p0);
  EGPoint* p1 = new EGPoint(1, "decay", 
			    1.0, 0.5, 
			    0.7, 
			    3.0, EGPoint::TIME);
  list.add(p1);


  EGPoint* p2 = new EGPoint(2, "sustain", 
			    0.5, 0.5, 
			    1.0, 
			    1.0, EGPoint::LEVEL);
  list.add(p2);

  EGPoint* p3 = new EGPoint(3, "release", 
			    0.5, 0.0, 
			    2.0, 
			    5.0, EGPoint::TIME);
  list.add(p3);

  std::cout << "length = " << list.size() << std::endl;
  std::cout << "duration = " << list.getDuration() << std::endl;

  for (int i = 0; i < list.size(); i++) {
    EGPoint* p = list.get(i);
    if (p != NULL) {
      std::cout << "p: " << p->getName() << std::endl;
    }
  }


}

EGEditor::~EGEditor() {
  // clean up here
}

void EGEditor::draw() {

  ofPushStyle();

  // draw background
  ofSetColor(GuiHelper::BG1());
  ofDrawRectangle(posx-25, posy-25, width+50, height+50);
  ofSetColor(GuiHelper::BG2());
  ofDrawRectangle(posx, posy, width, height);


  // draw the curves
  drawPolygon();
  drawHandles();

  ofPopStyle();
}


void EGEditor::drawPolygon() {
  ofPushStyle();

  ofSetColor(GuiHelper::FG2());
  ofSetLineWidth(3);    
  
  float dur = list.getDuration();
  float currentEndDur = 0;
  int x = 0;

  for (int i = 0; i < list.size(); i++) {
    EGPoint* p = list.get(i);
    if (p != NULL) {

      float d = p->getDuration();
      currentEndDur += d; // increase current end x position
      int endX = (int)ofMap(currentEndDur, 0, dur, 0, width); // map to screen

      // screen values for start/end level (assuming interval [0-1])
      int deltaYStart = (int)ofMap(p->getStartLevel(), 0, 1, 0, height);
      int deltaYEnd = (int)ofMap(p->getEndLevel(), 0, 1, 0, height);

      // drawing lines, inverting y coordinates
      ofDrawLine(posx + x, 
		 (posy + height) - deltaYStart,
		 posx + endX,
		 (posy + height) - deltaYEnd);
      
      // setting start offset for next partial line
      x = endX;
    }
  }

  ofPopStyle();
}


void EGEditor::drawHandles() {
  ofPushStyle();

  ofSetColor(GuiHelper::TXT0());
  ofSetLineWidth(3);   
  ofNoFill();
  
  float dur = list.getDuration();
  float currentEndDur = 0;
  int x = 0;

  for (int i = 0; i < list.size(); i++) {
    EGPoint* p = list.get(i);
    if (p != NULL) {

      float d = p->getDuration();
      currentEndDur += d; // increase current end x position
      int endX = (int)ofMap(currentEndDur, 0, dur, 0, width); // map to screen

      // screen values for start/end level (assuming interval [0-1])
      int deltaYStart = (int)ofMap(p->getStartLevel(), 0, 1, 0, height);
      int deltaYEnd = (int)ofMap(p->getEndLevel(), 0, 1, 0, height);

      // drawing lines, inverting y coordinates
      ofDrawCircle(posx + x, 
		   (posy + height) - deltaYStart, 
		   25);
      ofDrawCircle(posx + endX,
		   (posy + height) - deltaYEnd,
		   25);
      
      // setting start offset for next partial line
      x = endX;
    }
  }

  ofPopStyle();
}
