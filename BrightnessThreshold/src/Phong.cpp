//
//  Gamma.cpp
//  Movement
//
//  Created by kezzardrix2 on 2017/02/13.
//
//

#include "Phong.hpp"

void Phong::setup(){
    mShader.load("shaders/phong.vert",
                 "shaders/phong.frag");
    mLightPos.set(100, 0, 1000);
};
void Phong::draw(){
    
    ofSetSphereResolution(100);
    
    ofEnableDepthTest();
    
    mCam.begin();
    mShader.begin();
    mShader.setUniform3f("lightPos",mLightPos * mCam.getModelViewMatrix());
    mShader.setUniform1f("colorIntensity",1.0);
    ofSetColor(255,150,0);
    ofDrawSphere(0,0,0,100);
    mShader.end();
    mCam.end();
    
};