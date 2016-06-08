#ifndef _CS_BLUE_h_
#define _CS_BLUE_h_

#include "CS.h"
#include "ofMain.h"

class CSBlue : public CS {

 public:
  CSBlue();
  CSBlue(std::string name);
  virtual ~CSBlue();

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
