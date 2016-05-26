#ifndef _PAGE_h_
#define _PAGE_h_

#include "Selectable.h"
#include "GuiDrawable.h"
#include "Knob.h"
#include "BinarySwitch.h"

class Page : public GuiDrawable {
 public:
  Page();
  Page(std::string name);
  virtual ~Page();

  void draw();
  void add(Selectable* el);
  void setActive(bool a);
  bool isActive();
  virtual void mouseDragged(int msx, int msy, 
		    int x, int y, int button) = 0;
  virtual void mousePressed(int msx, int msy, 
			    int button) = 0;

 protected:
  vector <Selectable *> elements; // all selectable GUI Elements
  bool active = true;

};

#endif
