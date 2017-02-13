//
//  TriggerParticle.hpp
//  Movement
//
//  Created by kezzardrix2 on 2017/02/03.
//
//

#ifndef TriggerParticle_hpp
#define TriggerParticle_hpp

#include "ofMain.h"

class TriggerParticle{
public:
    void setup();
    void fire(ofPoint pos);
    void update();
    void draw();
private:
    ofVbo mVbo;
    vector<ofPoint>mVerts;
    vector<ofFloatColor>mColors;

    static const int NUM = 1000;
    int mCounter;
    int mOneShotNum;
    
    class VecPoint : public ofPoint{
    public:
        void fire(ofPoint pos){
            set(pos + ofPoint(ofRandom(-10,10),
                              ofRandom(-10,10)));
            
            float theta = ofRandom(0,TWO_PI);
            float x = cos(theta);
            float y = sin(theta);
            
            mVec.set(x,y);
            mVec *= ofRandom(2.0, 3.0);
            
            mAlpha = 1.0;
        }
        
        void update(){
            this->x += mVec.x;
            this->y += mVec.y;
            this->z += mVec.z;
            mAlpha -= 0.02;
            mAlpha = ofClamp(mAlpha, 0.0, 1.0);
        }
        
        float getAlpha(){
            return mAlpha;
        }
        
    private:
        ofPoint mVec;
        float mAlpha;
    };
    
    vector<VecPoint>mPts;
};

#endif /* TriggerParticle_hpp */
