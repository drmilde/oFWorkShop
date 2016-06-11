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

 private:
  void drawPolygon();
  void drawHandles();

  EGPointList list;

};


#endif
