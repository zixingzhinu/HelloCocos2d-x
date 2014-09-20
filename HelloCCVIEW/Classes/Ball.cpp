//
//  Ball.cpp
//  HelloCC
//
//  Created by James on 14-9-11.
//
//

#include "Ball.h"

bool Ball::init() {
    if (!Sprite::init()) {
        return false;
    }
    initWithFile("ball.png");
    return true;
}
