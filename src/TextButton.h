#ifndef _TEXT_BUTTON_h_
#define _TEXT_BUTTON_h_

#include "ofMain.h"
#include "Selectable.h"

class TextButton : public Selectable {

 public:
  TextButton();
  TextButton(std::string text);
  virtual ~TextButton();

  void draw();
 
 private:
  std::string label;

};


#endif
