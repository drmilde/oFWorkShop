#ifndef _CS_h_
#define _CS_h_

#include "ofMain.h"

class CS {

 public:
  CS();
  CS(std::string name);
  virtual ~CS();

  // have to be implemented in sub classes

  virtual ofColor getDkBck() = 0;
  virtual ofColor getMdBck() = 0;
  virtual ofColor getLtBck() = 0;
  virtual ofColor getLtrBck() = 0;
  virtual ofColor getFlBck() = 0;

  virtual ofColor getDkFor() = 0;
  virtual ofColor getMdFor() = 0;
  virtual ofColor getLtFor() = 0;
  virtual ofColor getLtrFor() = 0;
  virtual ofColor getFlFor() = 0;

  virtual ofColor getTextCol() = 0;

 protected:
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
