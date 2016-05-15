#include "Knob.h"

Knob::Knob() : Knob (0.0, 0.0, 1.0, 0, 359) {
  // do something useful here
}

Knob::Knob(float value, float min, float max, int start, int end) {
  strip.load("blue-yellow-linear.png");
  strip.load("green-metal-yellow.png");

  from = min;
  to = max;
  startAngle = start;
  endAngle = end;
  setValue(value);
}

Knob::~Knob() {
}

void Knob::drawAt(int x, int y) {
  ofPushMatrix();
  ofTranslate(x,y);
  ofScale(scaleFactor, scaleFactor);
  strip.drawSubsection(0,0, tileWidth, tileHeight, 0, idx);
  ofPopMatrix(); 
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
  idx = (idx / tileHeight) * tileHeight;
}
