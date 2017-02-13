//
//  ParticleScene.hpp
//  Movement
//
//  Created by kezzardrix2 on 2017/02/03.
//
//

#ifndef ParticleScene_hpp
#define ParticleScene_hpp

#include "BaseScene.h"
#include "CommonUtil.h"

class ParticleScene : public BaseScene{
public:
    
   void setup()override;
   void update()override;
   void receiveOsc(ofxOscMessage &m)override;
   void draw()override;
    
private:
    
    vector<ofVec3f>mVerts;
    ofVbo mVbo;
    
    static const int NUM = 30000;
    
    ShakeCam mCam;
    
    CustomShader mShader;
    ofPoint mRot;
    
    ofPoint mSpeed;
    ofPoint mProgress;
};

#endif /* ParticleScene_hpp */
