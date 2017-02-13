#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    mFlat.setup();
    
    mPostEffect.setup();

}

//--------------------------------------------------------------
void ofApp::update(){

    mFlat.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);

    mPostEffect.begin();
    mFlat.draw();
    mPostEffect.end();
    
    mPostEffect.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
