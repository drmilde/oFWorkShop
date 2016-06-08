#include "GUIColorScheme.h"

GUIColorScheme::GUIColorScheme() : GUIColorScheme ("dark star") {
  // do something useful here
}

GUIColorScheme::GUIColorScheme(std::string name) : Selectable(name, COLOR_SCHEME) {
}

GUIColorScheme::~GUIColorScheme() {
  // clean up here
}

void GUIColorScheme::draw() {
  ofPushStyle();

  // background
  ofSetColor(GuiHelper::BG0());
  ofDrawRectangle(posx + (0*50), posy, 50 , 50);

  ofSetColor(GuiHelper::BG1());
  ofDrawRectangle(posx + (1*50), posy, 50 , 50);

  ofSetColor(GuiHelper::BG2());
  ofDrawRectangle(posx + (2*50), posy, 50 , 50);

  ofSetColor(GuiHelper::BG3());
  ofDrawRectangle(posx + (3*50), posy, 50 , 50);

  // foreground
  ofSetColor(GuiHelper::FG0());
  ofDrawRectangle(posx + (0*50), posy + 50, 50 , 50);

  ofSetColor(GuiHelper::FG1());
  ofDrawRectangle(posx + (1*50), posy + 50, 50 , 50);

  ofSetColor(GuiHelper::FG2());
  ofDrawRectangle(posx + (2*50), posy + 50, 50 , 50);

  ofSetColor(GuiHelper::FG3());
  ofDrawRectangle(posx + (3*50), posy + 50, 50 , 50);

  // text color
  ofSetColor(GuiHelper::TXT0());
  GuiHelper::stringLAt ("Text", posx + (4*50) + 10, posy + 50);

  ofPopStyle();
}

