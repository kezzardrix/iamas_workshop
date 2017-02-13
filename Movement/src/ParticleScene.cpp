//
//  ParticleScene.cpp
//  Movement
//
//  Created by kezzardrix2 on 2017/02/03.
//
//

#include "ParticleScene.hpp"

void ParticleScene::setup(){
    
    for(int i = 0; i < NUM; i++){
        mVerts.push_back(ofPoint(0,0,0));
    }
    
    mVbo.setVertexData(&mVerts[0], NUM, GL_DYNAMIC_DRAW);
    
    mShader.load("shaders/pointSprite");
    mSpeed.set(0,0,1000);
    
};

void ParticleScene::update(){
        
    mProgress += mSpeed * ofGetLastFrameTime();
    
    mCam.update();
};

void ParticleScene::receiveOsc(ofxOscMessage &m){
    if(m.getAddress() == "/particle/rot"){
        mRot.set(m.getArgAsFloat(0),
                 m.getArgAsFloat(1),
                 m.getArgAsFloat(2));
    }
    
    if(m.getAddress() == "/particle/speed"){
        mSpeed.set(m.getArgAsFloat(0),
                   m.getArgAsFloat(1),
                   m.getArgAsFloat(2));
    }
};

void ParticleScene::draw(){
    
    enablePointSprite();
  
    ofDisableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    mCam.begin();
    
    mShader.begin();
    mShader.setUniform3f("progress", mProgress);
    mVbo.draw(GL_POINTS, 0, NUM);
    mShader.end();
    
    mCam.end();
};