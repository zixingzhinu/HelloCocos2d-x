//
//  Line.cpp
//  HelloDrawing
//
//  Created by James on 14-9-15.
//
//

#include "Line.h"


namespace james {
    bool Line::init() {
        return true;
    }
    
    /**
     * Override this method to draw your own node.
     * The following GL states will be enabled by default:
     * - `glEnableClientState(GL_VERTEX_ARRAY);`
     * - `glEnableClientState(GL_COLOR_ARRAY);`
     * - `glEnableClientState(GL_TEXTURE_COORD_ARRAY);`
     * - `glEnable(GL_TEXTURE_2D);`
     * AND YOU SHOULD NOT DISABLE THEM AFTER DRAWING YOUR NODE
     * But if you enable any other GL state, you should disable it after drawing your node.
     */
    void Line::draw(Renderer *renderer, const Mat4& transform, bool transformUpdated) {
        CHECK_GL_ERROR_DEBUG();
        DrawPrimitives::drawLine(Vec2(0, 0), Vec2(100, 100));
    }
}