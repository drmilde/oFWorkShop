#ifndef _PUSH_BUTTON_h_
#define _PUSH_BUTTON_h_

#include "ofMain.h"
#include "Selectable.h"
#include "GuiHelper.h"

class PushButton : public Selectable {

 public:
  PushButton();
  virtual ~PushButton();

  void draw();
  void pushed();
  void setPushed(bool p);

 private:
  bool hit = false;
  int count = 0;

};


#endif
