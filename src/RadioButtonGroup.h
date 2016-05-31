#ifndef _RADIO_BUTTOB_GROUD_h_
#define _RADIO_BUTTOB_GROUD_h_

#include "ofMain.h"
#include "Selectable.h"
#include "ToggleButton.h"

class RadioButtonGroup: public Selectable {

 public:
  RadioButtonGroup();
  RadioButtonGroup(int c);
  virtual ~RadioButtonGroup();

  void draw();
  void addButton(ToggleButton button);
  void setPosition(int x, int y, int fx, int fy);
  void toggle(int msx, int msy);
  void addColString(std::string s);

  int getSelected();
  void setCurrent(int idx);


 private:
  int cols;
  int current = 0;

  vector <ToggleButton> buttons;
  vector <std::string> colStrings;


};


#endif
