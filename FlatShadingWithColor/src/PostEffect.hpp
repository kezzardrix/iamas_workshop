//
//  PostEffect.hpp
//  Movement
//
//  Created by kezzardrix2 on 2017/02/07.
//
//

#ifndef PostEffect_hpp
#define PostEffect_hpp

#include "ofMain.h"
#include "ofxBlur.h"
#include "CommonUtil.h"

class PostEffect{
public:
    
    void setup();
    void begin();
    void end();
    void draw();
    
private:
    
    ofFbo mBase;
    ofFbo mComposite;
    
    CustomShader mColorGrading;
    float mGammaValue;
    
    ofShader mBrightnessThreshShader;
    float mBrightnessThresh;
    
    ofxBlur mBlur;
    
    ofImage mGradtionMap;

};

#endif /* PostEffect_hpp */
