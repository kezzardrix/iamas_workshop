//
//  FlatShading.hpp
//  Movement
//
//  Created by kezzardrix2 on 2017/02/07.
//
//

#ifndef GeometryShaderTest_hpp
#define GeometryShaderTest_hpp

#include "ofMain.h"
#include "CommonUtil.h"

class ShadingParticle{
public:
    void setup();
    void update();
    void draw();
private:
    
    CustomShader mPointSprite;
    
    ofFbo mPre;
    
    ofVbo mVbo;
    vector<ofPoint>mVerts;

    static const int NUM = 3000;
    
    ofEasyCam mCam;
    
};

#endif /* GeometryShaderTest_hpp */
