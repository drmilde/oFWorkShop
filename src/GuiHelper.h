#ifndef _GUI_HELPER_h_
#define _GUI_HELPER_h_

#include "ofMain.h"
#include "ofTrueTypeFont.h"
#include "Selectable.h"

class GuiHelper : public Selectable {

 public:
  GuiHelper();
  virtual ~GuiHelper();

  static void drawStringAt (std::string s, int x, int y);
  static void drawSmallStringRightAt (std::string s, int x, int y);

  static void drawSmallStringLeftCenterAt (std::string s, int x, int y);
  static void drawSmallStringRightCenterAt (std::string s, int x, int y);

  static void drawStringCCAt (std::string s, int x, int y);

 private:
  static ofTrueTypeFont standardFont;
  static ofTrueTypeFont smallFont;



};


#endif 
