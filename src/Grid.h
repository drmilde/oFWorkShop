#ifndef _GRID_h_
#define _GRID_h_

#include "Selectable.h"
#include "ToggleButton.h"
#include "VerticalSlider.h"

class Grid : public Selectable {

 public:
  Grid();
  Grid(int r, int c);
  virtual ~Grid();

  void draw();
  void toggle(int msx, int msy);

  void setPosition(int x, int y, int fx, int fy);
  void setClickPosition(int y);
  void drag(int msx, int msy, int x, int y);
  void addRowString(std::string s);
  void addColString(std::string s);

 private:
  int cols = 0;
  int rows = 0;

  vector <ToggleButton> buttons;
  vector <std::string> rowStrings;
  vector <std::string> colStrings;

  VerticalSlider vs;

};

#endif


