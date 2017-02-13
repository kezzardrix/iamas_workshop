//
//  MoveCircle.hpp
//  Movement
//
//  Created by kezzardrix2 on 2017/02/03.
//
//

#ifndef MoveCircle_hpp
#define MoveCircle_hpp

#include "ofMain.h"
#include "BaseScene.h"
#include "CommonUtil.h"
#include "TriggerParticle.hpp"

class MoveCircleScene : public BaseScene{
public:
    void setup()override;
    void update()override;
    void receiveOsc(ofxOscMessage &m)override;
    void draw()override;
    void fire();
private:
    
    CustomShader mBackground;
    float mBackgroundAlpha;
    
    class MoveCircle{
    public:
        void setup();
        void fire();
        void update();
        void draw();
    private:
        TriggerParticle mParticle;
        SmoothPoint mCenter;
        SmoothPoint mColor;
        SmoothValue mRadAdd;
        float mRad;
    };
    
    vector<MoveCircle>mCircles;
};

#endif /* MoveCircle_hpp */
