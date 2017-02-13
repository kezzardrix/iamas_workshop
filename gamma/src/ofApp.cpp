#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mScene.setup();

    mFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB32F);
    mGamma.load("","shaders/gamma.frag");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    
    mFbo.begin();
    ofClear(0,0);
    for(int i = 0; i < 20; i++){
        
        ofSetColor(ofMap(i,0,20,0,255));
        
        ofDrawRectangle(i * 20, 100, 20, 20);
        mScene.draw();
    }
    mFbo.end();
    
    ofSetColor(255);

    if(ofGetKeyPressed('a')){

        mFbo.draw(0,0);

    }else{
        mGamma.begin();
        mGamma.setUniform1f("gamma", 1.0 / 2.2);
        mFbo.draw(0,0);
        mGamma.end();
    }

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
