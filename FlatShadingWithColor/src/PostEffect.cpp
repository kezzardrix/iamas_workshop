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
    
    mColorGrading.load("","shaders/colorGrading.frag");
    mGammaValue = 1.0 / 2.2;
    
    mBrightnessThreshShader.load("","shaders/brightnessThresh.frag");
    mBrightnessThresh = 0.5;
    
    mBlur.setup(ofGetWidth(), ofGetHeight(),10, 0.2, 4, .5, true);
    mBlur.setBrightness(1.0);
    
    ofDisableArbTex();
    mGradtionMap.load("gradationMap/001.png");
    ofEnableArbTex();
    
}

void PostEffect::begin(){
    mBase.begin();
    ofClear(0,0);
}

void PostEffect::end(){
    
    mBase.end();

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
    mBase.draw(0,0);
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    mBlur.draw();
    
    mComposite.end();
    
}

void PostEffect::draw(){
    ofSetColor(255);
    mColorGrading.begin();
    mColorGrading.setUniform1f("gamma", mGammaValue);
    mColorGrading.setUniformTexture("gradationMap", mGradtionMap.getTexture(),1);
    mComposite.draw(0,0);
    mColorGrading.end();

}