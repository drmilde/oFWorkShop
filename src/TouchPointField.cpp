#include "TouchPointField.h"

TouchPointField::TouchPointField () : TouchPointField("tou tou tou tou tou tou touch me") {
  // do something useful here
}

TouchPointField::TouchPointField (std::string name) : DynamicSelectable(name) {
  // do something useful here
}

TouchPointField::~TouchPointField() {
  // clean up here
}

void TouchPointField::draw() {
  ofPushStyle();
  ofSetColor(GuiHelper::BG2());
  ofFill();
  ofDrawRectangle(posx, posy, width, height);

  drawTouchPoints();
  ofPopStyle();
}

void TouchPointField::drawTouchPoints() {
  for (unsigned int i = 0; i < tpoints.size(); i++) {
    TouchPoint* tp = tpoints[i];
    if (tp !=  NULL) {
      tp->draw();
    }
  }
}

// interface routinen

void TouchPointField::addTouchPoint (int x, int y, int r) {
  TouchPoint* tp = new TouchPoint(IDG.nextID(), "tpf point");
  
  tp->setBoundingBox(offx + x - (r/2), offy + y - (r/2), r,r);
  tpoints.push_back(tp);
  resize();
}


// mouse interaction

void TouchPointField::drag(int x, int y) {
  // what to do here ?
  // drag one handle, if selected
  for (unsigned int i = 0; i < tpoints.size(); i++) {
    TouchPoint* tp = tpoints[i];

    if (tp != NULL) {
      if (tp->isSelected()) {
	// test, if tp->getPosX(), tp->getPosY() inside maximum boudaries
	tp->drag(x,y);
	resize();
	// do something with the offset offx and offy ????
      }
    }
  }
}

void TouchPointField::clicked(int x, int y) {
  // is a handle selected ?
  std::cout << "clicked inside tpf\n";

  int count = 0;
  for (unsigned int i = 0; i < tpoints.size(); i++) {
    TouchPoint* tp = tpoints[i];

    if (tp != NULL) {
      tp->setSelected(false); // reset selection
      if (count == 0) { // none selected so far, single selection only
	if (tp->inside(x,y)) {
	  count++;
	}
      }
    }

  }
}

void TouchPointField::resize() {
  if (tpoints.size() > 0) {
    if (tpoints[0] == NULL) {
      // error, can't compute
    } else {
      int minx = tpoints[0]->getPosX();
      int miny = tpoints[0]->getPosY();
      int maxx = minx + tpoints[0]->getWidth();
      int maxy = miny + tpoints[0]->getHeight();


      for (unsigned int i = 0; i < tpoints.size(); i++) {
	TouchPoint* tp = tpoints[i];
	if (tp != NULL) {
	  minx = min(minx, tpoints[i]->getPosX());
	  miny = min(miny, tpoints[i]->getPosY());
	  maxx = max(maxx, tpoints[i]->getPosX() + tpoints[i]->getWidth());
	  maxy = max(maxy, tpoints[i]->getPosY() + tpoints[i]->getHeight());
	} 
      }

      DynamicSelectable::resize (minx, miny, abs(maxx-minx), abs(maxy-miny));
    }
  }
}


void TouchPointField::setOffSet(int x, int y) {
  offx = x;
  offy = y;
}

