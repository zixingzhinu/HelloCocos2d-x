//
//  Points.h
//  HelloDrawing
//
//  Created by James on 14-9-15.
//
//

#ifndef __HelloDrawing__Points__
#define __HelloDrawing__Points__

#include <iostream>

#include "cocos2d.h"

USING_NS_CC;

namespace james {
    class Points : public Node {
    public:
        virtual bool init();
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
        virtual void draw(Renderer *renderer, const Mat4& transform, bool transformUpdated);
        CREATE_FUNC(Points);
    };
}

#endif /* defined(__HelloDrawing__Points__) */
