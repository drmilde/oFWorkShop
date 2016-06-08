#ifndef _CS_h_
#define _CS_h_

#include "ofMain.h"

class CS  {

 public:
  CS();
  CS(std::string name);
  virtual ~CS();

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

 private:
  ofColor darkBackground;
  ofColor middleBackground;
  ofColor lightBackground;
  ofColor lighterBackground;
  ofColor fullBackground;
  
  ofColor darkForeground;
  ofColor middleForeground;
  ofColor lightForeground;
  ofColor lighterForeground;
  ofColor fullForeground;

  ofColor textColor;

};


#endif
