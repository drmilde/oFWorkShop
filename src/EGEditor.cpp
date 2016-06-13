#include "EGEditor.h"

EGEditor::EGEditor() : EGEditor("Mr Postman") {
  // do something useful here
}

EGEditor::EGEditor(std::string name) : Selectable(name, EG_EDITOR) {
  // do something useful here

  // configuring a standard ADSR envelope
  EGSpan* p0 = new EGSpan(0, "attack",
			  0.0, 1.0, 
			  0.0, 1.0, 
			  3.0, 
			  EGSpan::FIXED, EGSpan::ALL);
  list.add(p0);
  EGSpan* p1 = new EGSpan(1, "decay", 
			  1.0, 0.5, 
			  1.0, 0.7, 
			  3.0, 
			  EGSpan::ALL, EGSpan::ALL);
  list.add(p1);


  EGSpan* p2 = new EGSpan(2, "sustain", 
			  0.5, 0.5, 
			  1.7, 1.0, 
			  1.0, 
			  EGSpan::LEVEL, EGSpan::LEVEL);
  list.add(p2);

  EGSpan* p3 = new EGSpan(3, "release", 
			  0.5, 0.0, 
			  2.7, 2.0, 
			  5.0, 
			  EGSpan::ALL, EGSpan::ALL);
  list.add(p3);

  std::cout << "length = " << list.size() << std::endl;
  std::cout << "duration = " << list.getDuration() << std::endl;

  for (int i = 0; i < list.size(); i++) {
    EGSpan* p = list.get(i);
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
  // draw the handles
  if (isSelected()) {
    drawHandles();
  }

  ofPopStyle();
}


void EGEditor::drawPolygon() {
  ofPushStyle();

  ofSetColor(GuiHelper::FG2());
  ofSetLineWidth(3);    
  
  float dur = list.getMaxDuration();
  float currentEndDur = 0;
  int x = 0;

  for (int i = 0; i < list.size(); i++) {
    EGSpan* p = list.get(i);
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
  
  float dur = list.getMaxDuration();
  float currentEndDur = 0;

  for (int i = 0; i < list.size(); i++) {
    EGSpan* p = list.get(i);
    if (p != NULL) {

      float d = p->getDuration();
      currentEndDur += d; // increase current end x position
      int endX = (int)ofMap(currentEndDur, 0, dur, 0, width); // map to screen

      // screen values for start/end level (assuming interval [0-1])
      int deltaYEnd = (int)ofMap(p->getEndLevel(), 0, 1, 0, height);

      // drawing circles, inverting y coordinates
      if (near(endX, height-deltaYEnd)) {
	if (move) {
	  // remap screen to level/duration
	  // set values
	  float remapX = ofMap(currentMouseX, 0, width, 0, dur);
	  float remapY = ofMap(currentMouseY, 0, height, 1, 0);
	  std::cout << remapX << "," << remapY << "\n";

	  p->setEndTime(remapX);
	  p->setEndLevel(remapY);

	  list.connect();
	}

	ofSetColor(GuiHelper::FG2());
	ofDrawCircle(posx + endX,
		     (posy + height) - deltaYEnd,
		     25);
	
      } else {
	ofSetColor(GuiHelper::TXT0());
	ofDrawCircle(posx + endX,
		     (posy + height) - deltaYEnd,
		     25);
      }      
    }
  }

  ofFill();
  ofDrawCircle(posx + currentMouseX, posy + currentMouseY, 10);

  ofPopStyle();
}


// test routines

void EGEditor::drag(int msx, int msy) {
  currentMouseX = msx - posx;
  currentMouseY = msy - posy;
  move = true;
}


void EGEditor::highlight(int msx, int msy) {
  currentMouseX = msx - posx;
  currentMouseY = msy - posy;
  move = false;
}

bool EGEditor::near (int x, int y) {
  bool result = false;
  int distx = x - currentMouseX;
  int disty = y - currentMouseY;

  result = ((distx * distx) + (disty * disty)) < ((50/2)*(50/2));

  return result;
}

