//
//  FlatShading.cpp
//  Movement
//
//  Created by kezzardrix2 on 2017/02/07.
//
//

#include "ShadingParticle.hpp"

void ShadingParticle::setup(){
    
    for(int i = 0; i < NUM; i++){
        mVerts.push_back(ofPoint(0));
        mNormals.push_back(ofPoint(ofRandom(1.0),
                                   ofRandom(1.0),
                                   ofRandom(1.0)));
    }
    
    mVbo.setVertexData(&mVerts[0],NUM,GL_DYNAMIC_DRAW);
    mVbo.setNormalData(&mNormals[0],NUM,GL_DYNAMIC_DRAW);

    ofFbo::Settings s;
    s.width = ofGetWidth();
    s.height = ofGetHeight();
    s.internalformat = GL_RGBA32F;
    s.numColorbuffers = 2;
    
    mPre.allocate(s);
    
    mPointSprite.load("shaders/ShadingParticle/pointSprite");

    mCam.setupPerspective();
    
};
void ShadingParticle::update(){
    mVbo.updateVertexData(&mVerts[0],NUM);
    mVbo.updateNormalData(&mNormals[0], NUM);
};
void ShadingParticle::draw(){
    
    enablePointSprite();
    ofDisableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    mPre.begin();
    mPre.activateAllDrawBuffers();
    ofClear(0,0);
    mCam.begin();
    mPointSprite.begin();
    mVbo.draw(GL_POINTS,0,NUM);
    mPointSprite.end();
    mCam.end();
    
    mPre.end();
    
    ofSetColor(255);
    mPre.getTexture(0).draw(0, 0, ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    
    ofSetColor(255);
    mPre.getTexture(1).draw(ofGetWidth() * 0.5, 0, ofGetWidth() * 0.5, ofGetHeight() * 0.5);
};