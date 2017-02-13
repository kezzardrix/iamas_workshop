//
//  FlatShading.cpp
//  Movement
//
//  Created by kezzardrix2 on 2017/02/07.
//
//

#include "FlatShading.hpp"

void FlatShading::setup(){
    mShader.load("shaders/flat");
    mLightPos.set(500, 0, 1000);
    mCam.setupPerspective();
    ofSetSphereResolution(30);
};
void FlatShading::update(){
    mShader.load("shaders/flat");
};
void FlatShading::draw(){
    
    ofEnableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    mCam.begin();
    mShader.begin();
    mShader.setUniform3f("lightPos",mLightPos * mCam.getModelViewMatrix());
    ofDrawSphere(0,0,0,100);
    mShader.end();
    mCam.end();
};