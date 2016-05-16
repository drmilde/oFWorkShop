#include "GuiDrawable.h"

GuiDrawable::GuiDrawable(int x, int y, int w, int h) {
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

