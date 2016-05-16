#ifndef _GUI_DRAWABLE_h_
#define _GUI_DRAWABLE_h_

class GuiDrawable {

 public:
  GuiDrawable(int x, int y, int w, int h);
  virtual ~GuiDrawable();

  void setBoundingBox(int x, int y, int w, int h);
  virtual void draw() = 0; // has to be implemented by sub class

 protected:
  int posx;
  int posy;
  int width;
  int height;

};

#endif
