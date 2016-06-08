#ifndef _GUI_HELPER_h_
#define _GUI_HELPER_h_

#include "ofMain.h"
#include "ofTrueTypeFont.h"
#include "Selectable.h"
#include "CS.h"
#include "CSRed.h"
#include "CSBlue.h"

class GuiHelper : public Selectable {

 public:
  GuiHelper();
  virtual ~GuiHelper();

  static void setColorScheme (CS* c);

  static void stringLAt (std::string s, int x, int y);
  static void stringRAt (std::string s, int x, int y);

  static void stringLCAt (std::string s, int x, int y);
  static void stringRCAt (std::string s, int x, int y);

  static void stringCCAt (std::string s, int x, int y);

  static ofColor BG0();
  static ofColor BG1();
  static ofColor BG2();
  static ofColor BG3();
  static ofColor BG4();

  static ofColor FG0();
  static ofColor FG1();
  static ofColor FG2();
  static ofColor FG3();
  static ofColor FG4();

  static ofColor TXT0();

 private:
  static ofTrueTypeFont standardFont;
  static ofTrueTypeFont smallFont;
  static CS* colors;

};


#endif 
