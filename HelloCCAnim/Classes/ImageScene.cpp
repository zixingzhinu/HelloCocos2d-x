//
//  ImageScene.cpp
//  HelloCCAnim
//
//  Created by James on 14-9-13.
//
//

#include "ImageScene.h"

Scene* ImageLayer::createScene() {
    auto scene = Scene::create();
    auto img = ImageLayer::create();
    scene->addChild(img);
    return scene;
}

bool ImageLayer::init() {
    if (!Layer::init()) {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(visibleSize.width/2, visibleSize.height/2);
    addChild(sprite);
    return true;
}