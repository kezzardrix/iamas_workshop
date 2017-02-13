//
//  CommonUtil.h
//  Movement
//
//  Created by kezzardrix2 on 2017/02/03.
//
//

#ifndef CommonUtil_h
#define CommonUtil_h

#include "ofMain.h"

static void enablePointSprite(){
    glEnable(GL_POINT_SPRITE);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
}

static ofPoint getWindowRandom(float marginX, float marginY){
    return ofPoint(ofRandom(marginX,ofGetWidth() - marginX),
                   ofRandom(marginY,ofGetHeight() - marginX));
}

class CustomShader : public ofShader{
public:
    
    void begin(){
        ofShader::begin();
        setLazyUniforms();
    }
    
    void setLazyUniforms(){
        setUniform1f("time",ofGetElapsedTimef());
        setUniform1f("frame",ofGetFrameNum());
        setUniform2f("resolution",ofGetWidth(),ofGetHeight());
    }
};

class ShakeCam{
public:
    
    ShakeCam(){
        
        mShakeScale.set(ofRandom(0.5,1.0),
                        ofRandom(0.5,1.0),
                        ofRandom(0.5,1.0));
        
        mShakeRad.set(ofRandom(-30,30),
                      ofRandom(-30,30),
                      ofRandom(-30,30));
    }
    
    void update(){
        
        float theta = ofGetElapsedTimef();
        
        float x = cos(theta * mShakeScale.x) * mShakeRad.x;
        float y = sin(theta * mShakeScale.y) * mShakeRad.y;
        float z = cos(theta * mShakeScale.z) * mShakeRad.z;
        
        mCam.setPosition(x,y,z + 400);
        mCam.setTarget(ofPoint(0,0,0));
    }
    
    void begin(){
        mCam.begin();
    }
    
    void end(){
        mCam.end();
    }
    
private:
    ofEasyCam mCam;
    ofPoint mShakeRad;
    ofPoint mShakeScale;
};

class SmoothValue{
public:
    
    SmoothValue():mSpeed(0.2),mValue(0),mTarget(0){
        
    }
    
    void update(){
        mValue += (mTarget - mValue) * mSpeed;
    }
    
    void to(float target){
        mTarget = target;
    }
    
    void set(float target){
        mValue = target;
        mTarget = target;
    }
    
    float getValue(){
        return mValue;
    };
    
    void setSpeed(float speed){
        mSpeed = speed;
    }
    
private:
    float mValue;
    float mTarget;
    float mSpeed;
};

class SmoothPoint : public ofPoint{
public:
    
    SmoothPoint():mSpeed(0.2){
        
    }
    
    void update(){
        this->x += (mTarget.x - this->x) * mSpeed;
        this->y += (mTarget.y - this->y) * mSpeed;
        this->z += (mTarget.z - this->z) * mSpeed;
    }
    
    void to(ofPoint target){
        mTarget = target;
    }
    
    void set(ofPoint target){
        mTarget = target;
        ofPoint::set(target);
    }
    
    void setSpeed(float speed){
        mSpeed = speed;
    }
    
private:
    ofPoint mTarget;
    float mSpeed;
};

#endif /* CommonUtil_h */
