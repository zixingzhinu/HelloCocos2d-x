#include "HelloWorldScene.h"
#include "ImageScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
//    auto label = LabelTTF::create("Hello World", "Arial", 24);
//    
//    // position the label on the center of the screen
//    label->setPosition(Vec2(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - label->getContentSize().height));
//
//    // add the label as a child to this layer
//    this->addChild(label, 1);
//
//    // add "HelloWorld" splash screen"
//    auto sprite = Sprite::create("HelloWorld.png");
//
//    // position the sprite on the center of the screen
//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//    // add the sprite as a child to this layer
//    this->addChild(sprite, 0);
    
    /* 场景切换*/
     
    auto labelText = Label::create();
    labelText->setSystemFontSize(36);
    labelText->setSystemFontName("Courier New");
    labelText->setString("please click me");
    labelText->setPosition(visibleSize.width/2, visibleSize.height/2);
    addChild(labelText);
    
//    auto listener = EventListenerTouchOneByOne::create();
//    listener->onTouchBegan = [labelText,this](Touch *t, Event *e) {
//        if (labelText->getBoundingBox().containsPoint(t->getLocation())) {
//            log("<<<<");
            //带动画的场景切换
//            Director::getInstance()->replaceScene(TransitionJumpZoom::create(0.5f, ImageLayer::createScene()));
            //不带动画的场景切换
//            Director::getInstance()->replaceScene(ImageLayer::createScene());
            //动作-Action
            //重复某个动作3次
//            labelText->runAction(Repeat::create(MoveBy::create(0.5f, Vec2(-100, 100)), 3));
            //永久重复某个动作
//            labelText->runAction(RepeatForever::create(RotateBy::create(0.5f, 180)));
            //序列播放系列动作
//            MoveBy *moveBy = MoveBy::create(0.5f, Vec2(100, 100));
//            labelText->runAction(Sequence::create(moveBy, moveBy->reverse(), RotateBy::create(0.5f, 180),CallFunc::create([](){
//                MessageBox("Action completed", "Complete");
//            }), NULL));
            //并列播放系列动作
//            MoveBy *moveBy = MoveBy::create(0.5f, Vec2(100, 100));
//            JumpBy *jumpBy = JumpBy::create(0.5f, Vec2(50, 50), 200, 3);
//            RotateBy *rotateBy = RotateBy::create(0.5f, 720);
//            labelText->runAction(Spawn::create(moveBy, jumpBy, rotateBy, NULL));
            //播放逐帧动画
//            auto cache = SpriteFrameCache::getInstance();
//            cache->addSpriteFramesWithFile("anim.plist");
//            
//            Vector<SpriteFrame*> vec;
//            char name[15];
//            memset(name, 0, 15);
//            for (int i=0; i<20; i++) {
//                sprintf(name, "anim%04d",i);
//                vec.pushBack(cache->getSpriteFrameByName(name));
//            }
//            
//            Animation *animation = Animation::createWithSpriteFrames(vec,0.1f);
//            Animate *animate = Animate::create(animation);
//            auto sprite = Sprite::create();
//            sprite->setPosition(300, 300);
//            this->addChild(sprite);
//            sprite->runAction(RepeatForever::create(animate));
//        }
//        return false;
//    };
//    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    //加速度传感器
//    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(EventListenerAcceleration::create([](Acceleration *a, Event *e){
//        log("x:%g,y:%g,z:%g",a->x,a->y,a->z);
//    }), this);
    
    //物理按键交互
    auto listener = EventListenerKeyboard::create();
    listener->onKeyReleased = [](EventKeyboard::KeyCode keyCode, Event *e) {
        log("keyCode:%d",keyCode);
        switch (keyCode) {
                //点击后退键退出游戏
            case cocos2d::EventKeyboard::KeyCode::KEY_BACKSPACE:
                Director::getInstance()->end();
                break;
                
            default:
                break;
        }
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void HelloWorld::myCall() {
    MessageBox("Action completed", "Complete");
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
