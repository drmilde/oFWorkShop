#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowShape(1280, 800);
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
  if (imgRef == 0) {
    backImage.draw(0,0);
  } 
  if (imgRef == 1) {
    gui.draw();
  } 

  if (imgRef == 2) {
    // draw widgets
    wt.draw();
  } 
  
  //rm.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  gui.setActive(false);

  if (key == 't'){
    imgRef = 0;
  } 
  else if (key == 'g') {
    imgRef = 1;
    gui.setActive(true);
  }
  else if (key == 'w') {
    imgRef = 2;
  }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
  gui.mouseDragged(mouseX, mouseY, x, y, button);
  wt.drag(mouseX, mouseY, x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  std::cout << "Clicked at (" << x << ", " << y << ")" << std::endl;
  gui.mousePressed(x,y,button);
  wt.mousePressed(x,y);
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
