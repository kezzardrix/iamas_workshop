//
//  TriggerParticle.cpp
//  Movement
//
//  Created by kezzardrix2 on 2017/02/03.
//
//

#include "TriggerParticle.hpp"

void TriggerParticle::setup(){
    
    mOneShotNum = 50;
    
    for(int i = 0; i < NUM; i++){
        mVerts.emplace_back();
        mPts.emplace_back();
        mColors.emplace_back(1,1,1,0);
    }
    
    mVbo.setVertexData(&mVerts[0], NUM, GL_DYNAMIC_DRAW);
    mVbo.setColorData(&mColors[0], NUM, GL_DYNAMIC_DRAW);
  
    mCounter = 0;
};

void TriggerParticle::fire(ofPoint pos){
    
    for(int i = 0; i < mOneShotNum; i++){
        mPts[mCounter + i].fire(pos);
    }
    
    mCounter += mOneShotNum;
    mCounter %= NUM;
};

void TriggerParticle::update(){
    for(int i = 0; i < NUM; i++){
        mVerts[i] = mPts[i];
        mColors[i].a = mPts[i].getAlpha();
        mPts[i].update();
    
    }
    
    mVbo.updateVertexData(&mVerts[0], NUM);
    mVbo.updateColorData(&mColors[0], NUM);
};

void TriggerParticle::draw(){
    glPointSize(3);
    ofSetColor(255);
    mVbo.draw(GL_POINTS, 0, NUM);
};