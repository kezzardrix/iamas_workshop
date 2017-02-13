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

class PostEffect{
public:
    
    void setup();
    void begin();
    void end();
    void draw();
    
private:
    
    ofFbo mBase;
    ofFbo mComposite;
    
    ofShader mGammaShader;
    float mGammaValue;
    
    ofShader mBrightnessThreshShader;
    float mBrightnessThresh;
    
    ofxBlur mBlur;


};

#endif /* PostEffect_hpp */
