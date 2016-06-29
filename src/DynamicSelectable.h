#ifndef _DYNAMIC_SELECTABLE_h_
#define _DYNAMIC_SELECTABLE_h_

#include "ofMain.h"
#include "Selectable.h"

class DynamicSelectable : public Selectable {
 public:
  DynamicSelectable();
  DynamicSelectable(std::string name);
  virtual ~DynamicSelectable();

  void resize(int x, int y, int w, int h);

};

#endif
