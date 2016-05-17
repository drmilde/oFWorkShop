#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowShape(1200, 730);
  //backImage.load("blue-yellow-linear.png");
  backImage.load("werkstatt.png");

  for (int x = 30; x < 1000; x += 32*3) {
    for (int y = 50; y < 600; y += 32*4) {
      Knob knob = Knob("knopf", 0.0, 0, 1, 220, 140);
      knob.setBoundingBox(x,y, 32*3, 32*3);
      knobs.push_back(knob);
    }  
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  //ofBackground(22, 55,245);
  ofBackground(22);
  angle = (int)(ofMap(mouseX, 0, 359, 0, backImage.getWidth()));
  angle = angle %(int)(backImage.getWidth());
}

//--------------------------------------------------------------
void ofApp::draw(){
  //backImage.draw(0,0);

  ofPushStyle();
  ofNoFill();
  // erste Zeile
  ofDrawRectRounded(10, 10, 400, 300, 10);
  ofDrawRectRounded(410+10, 10, 400, 300, 10);
  ofDrawRectRounded(810+20, 10, 250, 300, 10);

  // zweite Zeile
  ofDrawRectRounded(10, 310+10, 400, 300, 10);
  ofDrawRectRounded(410+10, 310+10, 400, 300, 10);
  ofPopStyle();

  for (int i=0; i < knobs.size()/2; i++) {
    knobs[i].draw();
  }

  //rm.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
  for (int i=0; i < knobs.size(); i++) {

    if (knobs[i].isSelected()) {
      float step = 1.0 / 128; 
      if ((mouseY - ofGetPreviousMouseY()) < 0) {
	knobs[i].changeValue(-step);
      }
      if ((mouseY - ofGetPreviousMouseY()) > 0) {
	knobs[i].changeValue(+step);
      }

    }
  }

  /*
  */

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  std::cout << "Clicked at (" << x << ", " << y << ")" << std::endl;
  for (int i=0; i < knobs.size(); i++) {
    knobs[i].inside(x,y);
  }
  rm.inside(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
