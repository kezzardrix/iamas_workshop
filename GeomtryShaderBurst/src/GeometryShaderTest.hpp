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

class GeometryShaderTest{
public:
    void setup();
    void update();
    void draw();
private:
    CustomShader mShader;
    ofEasyCam mCam;
    ofPoint mLightPos;
    
};

#endif /* GeometryShaderTest_hpp */
