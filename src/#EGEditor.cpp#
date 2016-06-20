#include "EGEditor.h"

EGEditor::EGEditor() : EGEditor("Mr Postman") {
  // do something useful here
}

EGEditor::EGEditor(std::string name) : Selectable(name, EG_EDITOR) {
  // configuring a standard ADSR envelope
  list.addPoint(0, "attack start", 0, 0, EGPoint::FIXED);
  list.addPoint(1, "attack end", 1.0, 2.0, EGPoint::ALL);
  list.addPoint(2, "decay end", 0.5, 4.0, EGPoint::ALL);
  list.addPoint(3, "sustain end", 0.5, 6.0, EGPoint::ALL);
  list.addPoint(4, "release end", 0.0, 8.0, EGPoint::TIME);

  list.addSpan("attack", 0, 1, 3.0, EGSpan::FREE);
  list.addSpan("decay", 1, 2, 3.0, EGSpan::FREE);
  list.addSpan("sustain", 2, 3, 3.0, EGSpan::FIXED_LEVEL);
  list.addSpan("release", 3, 4, 3.0, EGSpan::FREE);

  std::cout << "length = " << list.size() << std::endl;
  std::cout << "duration = " << list.getDuration() << std::endl;

  for (int i = 0; i < list.size(); i++) {
    EGSpan* p = list.getSpan(i);
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

  for (int i = 0; i < list.size(); i++) {
    EGSpan* p = list.getSpan(i);
    if (p != NULL) {

      int startX = (int)ofMap(p->getStartTime(), 0, dur, 0, width); // map to screen
      int endX = (int)ofMap(p->getEndTime(), 0, dur, 0, width); // map to screen

      // screen values for start/end level (assuming interval [0-1])
      int deltaYStart = (int)ofMap(p->getStartLevel(), 0, 1, 0, height);
      int deltaYEnd = (int)ofMap(p->getEndLevel(), 0, 1, 0, height);

      // drawing line, inverting y coordinates
      ofDrawLine(posx + startX, 
		 (posy + height) - deltaYStart,
		 posx + endX,
		 (posy + height) - deltaYEnd);      
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

  for (int i = 0; i < list.size(); i++) {
    EGSpan* span = list.getSpan(i);
    if (span != NULL) {

      int endX = (int)ofMap(span->getEndTime(), 0, dur, 0, width); // map to screen

      // screen values for start/end level (assuming interval [0-1])
      int deltaYEnd = (int)ofMap(span->getEndLevel(), 0, 1, 0, height);

      // drawing circles, inverting y coordinates
      if (near(endX, height-deltaYEnd)) {
	if (move) {
	  // remap screen to level/duration
	  // set values
	  float remapX = ofMap(currentMouseX, 0, width, 0, dur);
	  float remapY = ofMap(currentMouseY, 0, height, 1, 0);
	  std::cout << remapX << "," << remapY << "\n";
	  span->print();

	  if (list.checkSpans(span->getEndPoint()->getID(), remapX)) {
	    span->setEndTime(remapX);
	    span->setEndLevel(remapY);
	    
	    list.order(); // force ordered list
	  } else {
	    std::cout << "error in span: ";
	    span->print();
	  }
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

