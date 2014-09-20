//
//  ImageScene.h
//  HelloCCAnim
//
//  Created by James on 14-9-13.
//
//

#ifndef __HelloCCAnim__ImageScene__
#define __HelloCCAnim__ImageScene__

#include <iostream>
#include <cocos2d.h>

USING_NS_CC;

class ImageLayer : public Layer {
    
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(ImageLayer);
};

#endif /* defined(__HelloCCAnim__ImageScene__) */
