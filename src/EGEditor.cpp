#include "EGEditor.h"

EGEditor::EGEditor() : EGEditor("Mr Postman") {
  // do something useful here
}

EGEditor::EGEditor(std::string name) : Selectable(name, EG_EDITOR) {
  // do something useful here
}

EGEditor::~EGEditor() {
  // clean up here
}


void EGEditor::draw() {

  ofPushStyle();
  
  ofPopStyle();

}
