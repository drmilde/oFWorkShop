#ifndef _GUI_COLOR_SCHEME_h_
#define _GUI_COLOR_SCHEME_h_

#include "ofMain.h"
#include "Selectable.h"
#include "GuiHelper.h"

class GUIColorScheme : public Selectable {

 public:
  GUIColorScheme();
  GUIColorScheme(std::string name);
  virtual ~GUIColorScheme();

  void draw();

};


#endif
