//
//  FlatShading.cpp
//  Movement
//
//  Created by kezzardrix2 on 2017/02/07.
//
//

#include "GeometryShaderTest.hpp"

void GeometryShaderTest::setup(){
    
    mShader.unload();
    mShader.setGeometryInputType(GL_TRIANGLES);
    mShader.setGeometryOutputType(GL_TRIANGLES);
    mShader.setGeometryOutputCount(3);
    mShader.load("shaders/geomBurst/vert.glsl",
                 "shaders/geomBurst/frag.glsl",
                 "shaders/geomBurst/geom.glsl");
    mLightPos.set(500, 0, 1000);
    mCam.setupPerspective();
    ofSetSphereResolution(30);

};
void GeometryShaderTest::update(){
  
};
void GeometryShaderTest::draw(){
    
    ofEnableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    mCam.begin();
    mShader.begin();
    mShader.setUniform3f("lightPos",mLightPos * mCam.getModelViewMatrix());
    ofDrawSphere(0,0,0,100);
    mShader.end();
    mCam.end();
};