//
//  Points.cpp
//  HelloDrawing
//
//  Created by James on 14-9-15.
//
//

#include "Points.h"

namespace james {
    bool Points::init() {
        return true;
    }
    
    void Points::draw(Renderer *renderer, const Mat4& transform, bool transformUpdated) {
        CHECK_GL_ERROR_DEBUG();
//        Vec2 points[50 * 50];
//        memset(points, 0, 50*50);
//        int index = 0;
//        for (int i=0; i<50; i++) {
//            for (int j=0; j<50; j++) {
//                points[index++] = Vec2(i, j);
//            }
//        }
//        DrawPrimitives::drawPoints(points, sizeof(points)/sizeof(points[0]));
        
        for (int i=0; i<50; i++) {
            for (int j=0; j<50; j++) {
                DrawPrimitives::setDrawColor4B(rand()%256, rand()%256, rand()%256, 255);
                DrawPrimitives::drawPoint(Vec2(i, j));
            }
        }
    }
}