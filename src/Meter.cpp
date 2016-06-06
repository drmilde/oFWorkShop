#include "Meter.h"

Meter::Meter() : Meter("Lying in Paris") {
  // do something useful here
}

Meter::Meter(std::string name) : Selectable (name, METER) {
  // do something useful here
}

Meter::~Meter() {
  // clean up here
}


void Meter::setValue(float v) {
  value = v;
  value = fmin(1.0, value);
  value = fmax(0.0, value);
}

float Meter::getValue() {
  return value;
}

