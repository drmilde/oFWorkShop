#include "EGEditor.h"

EGEditor::EGEditor() : EGEditor("Mr Postman") {
  // do something useful here
}

EGEditor::EGEditor(std::string name) : Selectable(name, EG_EDITOR) {
  // do something useful here

  EGPoint* p = new EGPoint(0, 0.0, 1.0, 3.0, EGPoint::LEVEL);
  list.add(p);

}

EGEditor::~EGEditor() {
  // clean up here
}

void EGEditor::draw() {

  ofPushStyle();

  // draw background
  ofSetColor(GuiHelper::BG2());
  ofDrawRectangle(posx, posy, width, height);

  ofPopStyle();

}
