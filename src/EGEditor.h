#ifndef _EG_EDITOR_h_
#define _EG_EDITOR_h_

#include "ofMain.h"
#include "Selectable.h"

class EGEditor : public Selectable {

 public:
  EGEditor();
  EGEditor(std::string name);
  virtual ~EGEditor();

  void draw();

};


#endif
