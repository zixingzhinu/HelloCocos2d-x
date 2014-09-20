//
//  Rect.cpp
//  HelloDrawing
//
//  Created by James on 14-9-14.
//
//

#include "Rect.h"

namespace james {
    bool Rect::init() {
        if (!Node::init()) {
            return false;
        }
        return true;
    }
    
    void Rect::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, bool transformUpdated) {
        CHECK_GL_ERROR_DEBUG();
        //绘制矩形
        DrawPrimitives::drawRect(Vec2(100, 100), Vec2(300, 300));
        DrawPrimitives::drawSolidRect(Vec2(50, 50), Vec2(200, 200), Color4F(1, 0, 0, 1));
        DrawPrimitives::drawCircle(Vec2(400, 400), 50, M_PI * 2, 30, true);
        DrawPrimitives::setDrawColor4B(255, 0, 0, 255);
        DrawPrimitives::drawSolidCircle(Vec2(400, 150), 100, M_PI*2, 50);
        
    }
}