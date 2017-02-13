#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    mReceiver.setup(9000);
    
    mFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB32F);
        
    mScenes.push_back(make_shared<MoveCircleScene>());
    mScenes.push_back(make_shared<ParticleScene>());
    
    for(auto &v:mScenes){
        v->setup();
    }
    
    mCurrentScene = 0;

    mReverse.load("","shaders/reverse.frag");
}

//--------------------------------------------------------------
void ofApp::update(){
    
    while (mReceiver.hasWaitingMessages()) {
        ofxOscMessage m;
        mReceiver.getNextMessage(m);
       // mScene.receiveOsc(m);
        
        if(m.getAddress() == "/reverse"){
            mReverseValue.to(m.getArgAsFloat(0));
        }
        
        if(m.getAddress() == "/scene"){
            mCurrentScene = m.getArgAsInt32(0);
        }
        
        mScenes[mCurrentScene]->receiveOsc(m);
        
    }
    
    mScenes[mCurrentScene]->update();
    mReverseValue.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    
    mFbo.begin();
    ofClear(0,0);
    mScenes[mCurrentScene]->draw();
    mFbo.end();
    
    mReverse.begin();
    mReverse.setUniform1f("reverse", mReverseValue.getValue());
    mFbo.draw(0,0);
    mReverse.end();
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
