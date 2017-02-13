//
//  MoveCircle.cpp
//  Movement
//
//  Created by kezzardrix2 on 2017/02/03.
//
//

#include "MoveCircleScene.hpp"

void MoveCircleScene::MoveCircle::setup(){
    mRad = 10;
    mParticle.setup();
};

void MoveCircleScene::MoveCircle::fire(){
    mCenter.to(getWindowRandom(100, 100));
    mParticle.fire(mCenter);
    mRadAdd.set(ofRandom(30,50));
    mRadAdd.to(0);
};

void MoveCircleScene::MoveCircle::update(){
    mCenter.update();
    
    mParticle.update();
    
    mRadAdd.update();
    mColor.update();
};
void MoveCircleScene::MoveCircle::draw(){
    ofSetColor(255);
    ofDrawCircle(mCenter,mRad + mRadAdd.getValue());
    mParticle.draw();
};

////////////////////////

void MoveCircleScene::setup(){
    
    for(int i = 0; i < 1; i++){
        mCircles.emplace_back();
    }
    
    for(auto &v:mCircles){
        v.setup();
    }
    
    fire();
    
    mBackground.load("","shaders/noiseBackground.frag");
    mBackgroundAlpha = 0.0;
    
};
void MoveCircleScene::update(){
    
    if(ofGetFrameNum() % 30 == 0){
        fire();
    }
    
    for(auto &v:mCircles){
        v.update();
    }
    
};

void MoveCircleScene::receiveOsc(ofxOscMessage &m){
    if(m.getAddress() == "/background/alpha"){
        mBackgroundAlpha = m.getArgAsFloat(0);
    }
};

void MoveCircleScene::fire(){
    for(auto &v:mCircles){
        v.fire();
    }
};

void MoveCircleScene::draw(){
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    mBackground.begin();
    mBackground.setUniform1f("alpha",mBackgroundAlpha);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    mBackground.end();
    
    for(auto &v:mCircles){
        v.draw();
    }
};