#ifndef _GUI_DRAWABLE_h_
#define _GUI_DRAWABLE_h_

#include <iostream>

class GuiDrawable {

 public:
  GuiDrawable(std::string n, int x, int y, int w, int h);
  virtual ~GuiDrawable();

  void setBoundingBox(int x, int y, int w, int h);
  virtual void draw() = 0; // has to be implemented by sub class

 protected:
  int posx;
  int posy;
  int width;
  int height;

  std::string name;

};

#endif
