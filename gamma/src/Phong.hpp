//
//  Gamma.hpp
//  Movement
//
//  Created by kezzardrix2 on 2017/02/13.
//
//

#ifndef Gamma_hpp
#define Gamma_hpp

#include "ofMain.h"
#include "CommonUtil.h"

class Phong{
public:
    void setup();
    void draw();
private:
    ofEasyCam mCam;
    CustomShader mShader;
    ofPoint mLightPos;
};

#endif /* Gamma_hpp */
