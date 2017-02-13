//
//  BaseScene.h
//  Movement
//
//  Created by kezzardrix2 on 2017/02/03.
//
//

#ifndef BaseScene_h
#define BaseScene_h

#include "ofxOsc.h"

class BaseScene{
public:
    virtual void setup(){};
    virtual void update(){};
    virtual void receiveOsc(ofxOscMessage &m){};
    virtual void draw(){};
};

#endif /* BaseScene_h */
