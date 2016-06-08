#ifndef _CS_RED_h_
#define _CS_RED_h_

#include "CS.h"
#include "ofMain.h"

class CSRed : public CS {

 public:
  CSRed();
  CSRed(std::string name);
  virtual ~CSRed();

  // 
  ofColor getDkBck();
  ofColor getMdBck();
  ofColor getLtBck();
  ofColor getLtrBck();
  ofColor getFlBck();

  ofColor getDkFor();
  ofColor getMdFor();
  ofColor getLtFor();
  ofColor getLtrFor();
  ofColor getFlFor();

  ofColor getTextCol();


};


#endif
