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
    }
    
    mVbo.setVertexData(&mVerts[0],NUM,GL_DYNAMIC_DRAW);

    mPointSprite.load("shaders/ShadingParticle/pointSprite");

    mCam.setupPerspective();
    
};
void ShadingParticle::update(){
    mVbo.updateVertexData(&mVerts[0],NUM);
};
void ShadingParticle::draw(){
    
    enablePointSprite();
    ofDisableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);

    ofClear(0,0);
    mCam.begin();
    //mPointSprite.begin();
    mVbo.draw(GL_POINTS,0,NUM);
    //mPointSprite.end();
    
    mCam.end();
 
};