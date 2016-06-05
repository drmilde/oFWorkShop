#ifndef _TEXT_BUTTON_h_
#define _TEXT_BUTTON_h_

#include "ofMain.h"
#include "Selectable.h"
#include "GuiHelper.h"

class TextButton : public Selectable {

 public:
  TextButton();
  TextButton(std::string text, std::string text1);
  virtual ~TextButton();

  void draw();
  void toggle();
 
 private:
  std::string label;
  std::string label1;
  int state = 0;

};


#endif
