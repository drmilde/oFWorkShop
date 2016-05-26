#include "Page.h"

Page::Page() : Page ("Jimmy Paige") {
  // do something useful here
}

Page::Page(std::string name) : GuiDrawable(name,0,0,0,0){
}

Page::~Page() {
  // clean up here
}

void Page::add(Selectable* el) {
  elements.push_back(el);
}


void Page::draw() {
  if (isActive()) {
    for (unsigned int i = 0; i < elements.size(); i++) {
      (elements[i]) -> draw();
    }
  }
}

void Page::setActive(bool a) {
  active = a;
}

bool Page::isActive() {
  return active;
}


// proccessing mouse events

void Page::mouseDragged(int msx, int msy, 
			       int x, int y, int button){

  if (isActive()) {

    for (unsigned int i = 0; i < elements.size(); i++) {
      // check, if ANY element is selected
      if (elements[i]->isSelected()) {
	
	float step = 1.0 / 128; // standard: 128 steps for complete range
	// dragging up
	if ((msy - ofGetPreviousMouseY()) < 0) {
	  ((Knob *)(elements[i]))->changeValue(-step);
	}
	// dragging down
	if ((msy - ofGetPreviousMouseY()) > 0) {
	  ((Knob *)(elements[i]))->changeValue(+step);
	}
	
	// dragging left
	if ((msx - ofGetPreviousMouseX()) < 0) {
	  ((Knob *)(elements[i]))->changeValue(-step);
	}
	// dragging right
	if ((msx - ofGetPreviousMouseX()) > 0) {
	  ((Knob *)(elements[i]))->changeValue(+step);
	}
	
      }      
    }

  }
}



void Page::mousePressed(int msx, int msy, int button){
  
  if (isActive()) {
    // KNOBS and SWITCHES
    for (unsigned int i = 0; i < elements.size(); i++) {
      // check, if ANY element is selected
      elements[i]->inside(msx,msy);
      
      // dispatch
      switch(elements[i]->getType()) {
      case (Selectable::BINARY_SWITCH): {
	// toggle switches
	if (elements[i]->isSelected()) {
	  ((BinarySwitch*)elements[i])->toggle();
	  elements[i]->setSelected(false);
	}
	break;
      }
      }
    }   
  }
}


