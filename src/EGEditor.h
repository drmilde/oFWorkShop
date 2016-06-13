#ifndef _EG_EDITOR_h_
#define _EG_EDITOR_h_

#include "ofMain.h"
#include "Selectable.h"
#include "GuiHelper.h"
#include "EGPointList.h"

class EGEditor : public Selectable {

 public:
  EGEditor();
  EGEditor(std::string name);
  virtual ~EGEditor();

  void draw();
  void highlight(int msx, int msy);
  void drag(int msx, int msy);

 private:
  void drawPolygon();
  void drawHandles();
  bool near(int x, int y);

  EGPointList list;

  int currentMouseX = -100; // outside click range
  int currentMouseY = -100; // outside click range

  bool move = false;

};


#endif
