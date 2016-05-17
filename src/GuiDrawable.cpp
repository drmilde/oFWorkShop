#include "GuiDrawable.h"

GuiDrawable::GuiDrawable(std::string n, 
			 int x, int y, int w, int h) {
  name = n;
  setBoundingBox(x,y,w,h);
}

GuiDrawable::~GuiDrawable() {
  // clean up here
}

void GuiDrawable::setBoundingBox (int x, int y, int w, int h) {
  posx = x;
  posy = y;
  width = w;
  height = h;
}

