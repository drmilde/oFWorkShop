#ifndef _PULSE_h_
#define _PULSE_h_

#include <iostream>
#include <thread>
#include <math.h>
#include <chrono>
#include <unistd.h>

using ns = std::chrono::nanoseconds;
using get_time = std::chrono::steady_clock;

/**
 * Pulse ... basic timer
 * 
 * @author jtm,
 * email: @email milde@hs-fulda.de
 * @since 04-2016
 * @version 1.0
 **/
class Pulse {

 public: 
  Pulse();

  void start();
  void stop();
  long getMillis();
  bool isRunning();

 private:
  void run();  
  bool halt = true;
  long millis = 0;

  get_time::time_point st = get_time::now();



  
};

#endif
