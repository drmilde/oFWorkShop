#ifndef _ID_Generator_h_
#define _ID_Generator_h_

#include <string>
#include <iostream>


class IDGenerator {

 public:
  IDGenerator();
  int nextID();
  void reset();

 private:
  static int CURRENT_ID;
};

#endif
