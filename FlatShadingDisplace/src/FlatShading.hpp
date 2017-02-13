//
//  FlatShading.hpp
//  Movement
//
//  Created by kezzardrix2 on 2017/02/07.
//
//

#ifndef FlatShading_hpp
#define FlatShading_hpp

#include "ofMain.h"
#include "CommonUtil.h"

class FlatShading{
public:
    void setup();
    void update();
    void draw();
private:
    CustomShader mShader;
    ofEasyCam mCam;
    ofPoint mLightPos;
};

#endif /* FlatShading_hpp */
