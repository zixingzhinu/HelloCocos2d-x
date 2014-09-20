//
//  Poly.cpp
//  HelloDrawing
//
//  Created by James on 14-9-15.
//
//

#include "Poly.h"

namespace james {
    bool Poly::init() {
        if (!Node::init()) {
            return false;
        }
        return true;
    }
    
    void Poly::draw(Renderer *renderer, const Mat4& transform, bool transformUpdated) {
        CHECK_GL_ERROR_DEBUG();
        Vec2 vertices[] = {Vec2(0, 400),Vec2(100,450),Vec2(150, 550),Vec2(50, 650)};
        DrawPrimitives::drawPoly(vertices, sizeof(vertices)/sizeof(vertices[0]), true);
    }
}