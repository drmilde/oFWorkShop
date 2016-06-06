#ifndef _COLOR_SCHEME_h_
#define _COLOR_SCHEME_h_

#include "ofMain.h"
#include "Selectable.h"

class ColorScheme : public Selectable {

 public:
  ColorScheme();
  ColorScheme(std::string name);
  virtual ~ColorScheme();

  ofColor getDkBck();
  ofColor getMdBck();
  ofColor getLtBck();

  ofColor getDkFor();
  ofColor getMdFor();
  ofColor getLtFor();

  ofColor getTextCol();

  void draw();

 private:
  ofColor darkBackground;
  ofColor middleBackground;
  ofColor lightBackground;
  
  ofColor darkForeground;
  ofColor middleForeground;
  ofColor lightForeground;

  ofColor textColor;


};


#endif
