#include "IDGenerator.h"

int IDGenerator::CURRENT_ID;

IDGenerator::IDGenerator() {
  reset();
}

void IDGenerator::reset() {
  CURRENT_ID = 0;
}

int IDGenerator::nextID() {
  return CURRENT_ID++;
}

