//
//  Ball.h
//  HelloCC
//
//  Created by James on 14-9-11.
//
//

#ifndef __HelloCC__Ball__
#define __HelloCC__Ball__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class Ball:public Sprite {
    
public:
    virtual bool init();
    CREATE_FUNC(Ball);
};

#endif /* defined(__HelloCC__Ball__) */
