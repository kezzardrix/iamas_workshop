//
//  PostEffect.cpp
//  Movement
//
//  Created by kezzardrix2 on 2017/02/07.
//
//

#include "PostEffect.hpp"

void PostEffect::setup(){
    
    ofFbo::Settings s;
    
    s.width = ofGetWidth();
    s.height = ofGetHeight();
    s.internalformat = GL_RGB32F;
    s.numSamples = 4;
    s.useDepth = true;
    
    mBase.allocate(s);
   
    mComposite.allocate(ofGetWidth(),ofGetHeight(), GL_RGB32F);
    
    mGammaShader.load("","shaders/gamma.frag");
    mGammaValue = 1.0 / 2.2;
    
    mBrightnessThreshShader.load("","shaders/brightnessThresh.frag");
    mBrightnessThresh = 0.5;
    
    mBlur.setup(ofGetWidth(), ofGetHeight(), 10, 0.2, 4, .5, true);
    mBlur.setBrightness(1.0);
    
}

void PostEffect::begin(){
    mBase.begin();
    ofClear(0,0);
}

void PostEffect::end(){
    
    mBase.end();
    
    mBrightnessThresh = ofMap(ofGetMouseX(),0,ofGetWidth(),0.0,1.0);

    ofDisableDepthTest();
    mBlur.begin();
    ofClear(0,0);
    mBrightnessThreshShader.begin();
    mBrightnessThreshShader.setUniform1f("thresh", mBrightnessThresh);
    mBase.draw(0,0);
    mBrightnessThreshShader.end();
    mBlur.end();
    
    mComposite.begin();
    ofClear(0,0);
   
    ofSetColor(255);
   // mBase.draw(0,0);
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    mBlur.draw();
    
    mComposite.end();

}

void PostEffect::draw(){
    ofSetColor(255);
    mGammaShader.begin();
    mGammaShader.setUniform1f("gamma", mGammaValue);
    mComposite.draw(0,0);
    mGammaShader.end();

}