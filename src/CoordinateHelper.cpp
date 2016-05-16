#include "CoordinateHelper.h"
 
CoordinateHelper::CoordinateHelper() {
  // do something useful here
  reset();
}

CoordinateHelper::~CoordinateHelper() {
  // clean up
}

void CoordinateHelper::reset() {
  set(0,0,0);
}

void CoordinateHelper::set(int x, int y) {
  set (x,y,0);
}

void CoordinateHelper::set(int x, int y, int z) {
  vertices.set(x,y,z);
}

void CoordinateHelper::translate (int x, int y) {
  vertices = vertices + ofVec3f (x, y , 0);
}

void CoordinateHelper::scale (int factor) {
  vertices = vertices * ofVec3f (factor, factor, factor);  
}

void CoordinateHelper::rotateZ (int angle) {
  vertices.rotate(angle, ofVec3f(0, 0, 1));
}

int CoordinateHelper::getScreenX() {
  return vertices.x;
}

int CoordinateHelper::getScreenY() {
  return vertices.y;
}


