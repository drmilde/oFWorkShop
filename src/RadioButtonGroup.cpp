#include "RadioButtonGroup.h"


RadioButtonGroup::RadioButtonGroup() : RadioButtonGroup(0) {
  // do something useful here
}

RadioButtonGroup::RadioButtonGroup(int c) : Selectable("once in your life", RADIO_BUTTON_GROUP) {

  smallFont.load("Courier-Sans.ttf", 18);

  cols = c;

  // create the toggle button array
  int y = 0;
  for (int x = 0; x < cols; x++) {
    ToggleButton tb = ToggleButton();
    tb.setGridID(x,y);
    tb.setValue(0);    
    tb.setBoundingBox(x*50, y*50, 50, 50,1,1);
    
    if (x == current) {
      tb.setOn();
    } else {
      tb.setOff();
    }
    
    buttons.push_back(tb);
  }

}


void RadioButtonGroup::setPosition(int x, int y, int fx, int fy) {
  Selectable::setBoundingBox(x,y, cols*50, 1*50, fx, fy);
}


RadioButtonGroup::~RadioButtonGroup() {
  // clean up here
}

// process strings

void RadioButtonGroup::addColString(std::string s) {
  colStrings.push_back(s);
}

// add more buttons, if needed

void RadioButtonGroup::addButton(ToggleButton button) {
  buttons.push_back(button);
}


//  return the index of current selection

int RadioButtonGroup::getSelected() {
  return current;
}

void RadioButtonGroup::setCurrent(int idx) {
  current = idx;
  // 
  current = min(current, (int)(buttons.size()-1)); // ???? CHECK ????
  current = max(current, 0);
}


void RadioButtonGroup::draw() {
  for (int i = 0; i < buttons.size(); i++) {
    buttons[i].drawAt(posx, posy, false);
  }


  // draw column strings

  for (unsigned int i = 0; i < colStrings.size(); i++) {
    ofRectangle box = smallFont.getStringBoundingBox(colStrings[i],0,0);
    
    ofPushMatrix();
    ofTranslate(posx + (i * 50) + (50/2), posy - (box.getHeight()/2));
    ofRotate(-35);
    smallFont.drawString(colStrings[i], 0, 0 );
    ofPopMatrix();
  }

}

void RadioButtonGroup::toggle(int msx, int msy) {

  // process click
  for (unsigned int i = 0; i < buttons.size(); i++) {
    if (buttons[i].insideAt(msx, msy, posx, posy)) {

      if (buttons[i].isSelected()) {
	// toggle button and deselect
	buttons[i].toggle();
	buttons[i].setSelected(false);  
	current = i;
      }  

    }
  }  

  // perform radio action
  for (unsigned int i = 0; i < buttons.size(); i++) {
    if (i == current) {
      buttons[i].setOn();
    } else {
      buttons[i].setOff();
    }
  }

}




