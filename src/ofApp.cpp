#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowShape(1200, 730);
  //backImage.load("blue-yellow-linear.png");
  backImage.load("green-metal-yellow.png");
  knob = Knob(0.0, -1, 1, 220, 140);

}

//--------------------------------------------------------------
void ofApp::update(){
  ofBackground(22, 55,245);
  angle = (int)(ofMap(mouseX, 0, 359, 0, backImage.getWidth()));
  angle = angle %(int)(backImage.getWidth());
}

//--------------------------------------------------------------
void ofApp::draw(){

  //knob.setValue(2*((float)mouseX / ofGetWidth())-1.0);
  knob.setValue(2*((float)mouseY / ofGetHeight())-1.0);
  knob.drawAt(mouseX, mouseY);
  for (int x = 0; x < 1000; x += 32*4) {
    for (int y = 0; y < 600; y += 32*4) {
      knob.drawAt(x,y);
    }  
  }
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
