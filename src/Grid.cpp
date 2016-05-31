#include "Grid.h"

Grid::Grid() : Grid(0,0) {
  // do something useful here
}

Grid::Grid(int r, int c) : Selectable("Vier Gewinnt", GRID) {
  smallFont.load("Courier-Sans.ttf", 18);

  rows = r;
  cols = c;

  // create the toggle button array
  for (int x = 0; x < cols; x++) {
    for (int y = 0; y < rows; y++) {
      ToggleButton tb = ToggleButton();
      tb.setGridID(x,y);
      tb.setValue(0);

      tb.setBoundingBox(x*50, y*50, 50, 50,1,1);

      buttons.push_back(tb);
    }
  }

  // vertical slider
  vs  = VerticalSlider("", 0, 0, 127);
  vs.setBoundingBox(0,0,
		    20, max(200, rows*50),
		    5,1);
  vs.setValue(127/2);

}

Grid::~Grid() {
  // clean up here
}

void Grid::setPosition(int x, int y, int fx, int fy) {
  Selectable::setBoundingBox(x,y, cols*50, rows*50, fx, fy);
  vs.setBoundingBox(posx + width + 35, posy,
		    20, max(200, rows*50),
		    5,1);
  vs.setValue(0);
}

void Grid::setClickPosition(int y) {
  vs.setClickPosition(y);
}


void Grid::draw() {
  ofPushStyle();

  ofDrawRectangle(posx, posy, width, height);
  
  for (unsigned int i = 0; i < buttons.size(); i++) {
    buttons[i].drawAt(posx, posy, (i==current));
  }

  // draw strings
  for (unsigned int i = 0; i < rowStrings.size(); i++) {
    ofRectangle box = smallFont.getStringBoundingBox(rowStrings[i],0,0);

    smallFont.drawString(rowStrings[i], posx - box.getWidth() -15, 
			 posy + (i*50) + (50/2) + (box.getHeight()/2));
  }


  for (unsigned int i = 0; i < colStrings.size(); i++) {
    ofRectangle box = smallFont.getStringBoundingBox(colStrings[i],0,0);
    
    ofPushMatrix();
    ofTranslate(posx + (i * 50) + (50/2), posy - (box.getHeight()/2));
    ofRotate(-35);
    smallFont.drawString(colStrings[i], 0, 0 );
    ofPopMatrix();
  }


  // draw slider
  vs.draw();

  ofPopStyle();
}

void Grid::toggle(int msx, int msy) {
  
  for (unsigned int i = 0; i < buttons.size(); i++) {
    if (buttons[i].insideAt(msx, msy, posx, posy)) {

      if (buttons[i].isSelected()) {
	// toggle button and deselect
	buttons[i].toggle();
	buttons[i].setSelected(false);  

	current = i;

	// transfer value to slider
	vs.setValue(buttons[i].getValue());
      }  

    }
  }  
}

// processing events

void Grid::drag(int msx, int msy, int x, int y) {
  if (vs.inside(x,y)) {
    setClickPosition(y);
    if (current >= 0) {
      buttons[current].setValue(vs.getValue());
    }
  }
}


// adding Strings

void Grid::addRowString(std::string s) {
  rowStrings.push_back(s);
}

void Grid::addColString(std::string s) {
  colStrings.push_back(s);
}

 
