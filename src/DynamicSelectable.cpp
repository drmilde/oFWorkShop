#include "DynamicSelectable.h"


DynamicSelectable::DynamicSelectable() : DynamicSelectable("batman and robin") {
  // do something useful here
}

DynamicSelectable::DynamicSelectable(std::string name) : Selectable (name, DYNAMIC_SELECTABE) {
  // do something useful here
}

DynamicSelectable::~DynamicSelectable() {
  // clean up here
}

void DynamicSelectable::resize(int x, int y, int w, int h) {
  setBoundingBox(x, y, w, h);
}

