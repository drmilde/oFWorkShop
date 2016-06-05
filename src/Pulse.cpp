#include "Pulse.h"

Pulse::Pulse() {
}

bool Pulse::isRunning() {
  return !halt;
}

void Pulse::start() {
  halt = false;
  millis = 0;
  st = get_time::now();
}

void Pulse::stop() {
  halt = true;
}

long Pulse::getMillis() {
  run();
  return millis;
}

void Pulse::run() {
  if (!halt) {
    auto end = get_time::now();
    auto diff = end - st;
    
    millis = std::chrono::duration_cast<ns>(diff).count() / 1000 / 1000;  
  }
}
