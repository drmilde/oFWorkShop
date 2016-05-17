#include "Knob.h"

Knob::Knob(std::string name) : Knob (name, 0.0, 0.0, 1.0, 0, 359) {
  // do something useful here
}

Knob::Knob(std::string n, float value, float min, 
	   float max, int start, int end): Selectable (n){
  strip.load("blue-yellow-linear.png");
  strip.load("green-metal-yellow.png");
  strip.resize(strip.getWidth() * factor,
	       strip.getHeight() * factor);
  myfont.load("Courier-Sans.ttf", 6 * factor);

  from = min;
  to = max;
  startAngle = start;
  endAngle = end;
  setValue(value);
}

Knob::~Knob() {
}

void Knob::draw() {
  ofPushStyle();

  strip.drawSubsection(posx, posy, 
		       tileWidth * factor, tileHeight * factor, 
		       0, idx);

  drawValueStringAt(posx + ((tileWidth * factor)/2-(17*factor)),
  		    posy + ((tileHeight * factor)+(7*factor)));

  Selectable::draw();

  ofPopStyle();
}

void Knob::drawValueStringAt (int x, int y) {
  std::string out = ofToString(fabs(value),3);
  if (value >= 0) {
    out = "+" + out;
  } else {
    out = "-" + out;
  }
  myfont.drawString(out,x,y);
}

void Knob::changeValue(float delta) {
  setValue(value + delta);
}

void Knob::setValue(float v) {
  value = v;
  value = fmax (value, from);
  value = fmin (value, to);
  setIndex();
}

void Knob::normInterval() {
  if (startAngle > endAngle) {
    startAngle -=360;
  }
}

void Knob::setIndex() {
  normInterval();
  idx = (int)ofMap(value, from, to, startAngle, endAngle);
  idx = (int)ofMap(idx, 0, 359, 0, strip.getHeight());
  int h = (int)(strip.getHeight());
  idx = (idx + h) % h; // to positive values and normalize
  idx = (idx / (tileHeight*factor)) * (tileHeight*factor);
}
