#include "HelloWorldScene.h"
#include "Ball.h"

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
    
//    Sprite *s = Sprite::create("HelloWorld.png");
//    s->setPosition(visibleSize.width / 2, visibleSize.height / 2);
//    s->setAnchorPoint(Vec2::ZERO);
//    addChild(s);
//    
//    log("Hello log %d", 200);
//    
//    auto label = Label::create();
//    label->setPosition(visibleSize.width / 2, visibleSize.height / 2);
//    label->setString("Hello Director");
//    label->setSystemFontSize(36);
//    addChild(label);
//    
//    MessageBox("对话框内容", "对话框标题");
    
//    TextFieldTTF *tf = TextFieldTTF::textFieldWithPlaceHolder("在这里输入", "宋体", 36);
//    tf->setPosition(visibleSize.width / 2, visibleSize.height / 2);
//    addChild(tf);
//    
//    auto listener = EventListenerTouchOneByOne::create();
//    listener->onTouchBegan = [tf](Touch *t, Event *e) {
//        if (tf->getBoundingBox().containsPoint(t->getLocation())) {
//            tf->attachWithIME();
//        }
//        else {
//            tf->detachWithIME();
//        }
//        return false;
//    };
//    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    //自定义类
//    auto b = Ball::create();
//    b->setPosition(visibleSize.width / 2, visibleSize.height / 2);
//    addChild(b);
    
    //list列表
    TableView *tv = TableView::create(this, Size(300, 300));
    tv->setAnchorPoint(Vec2::ZERO);
    tv->setPosition(150, 0);
    tv->setDelegate(this);
    addChild(tv);

    return true;
}

Size HelloWorld::cellSizeForTable(cocos2d::extension::TableView *table) {
    return Size(300, 50);
}

TableViewCell* HelloWorld::tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx) {
    TableViewCell *cell = table->dequeueCell();
    Label *textLabel;
    if (cell==NULL) {
        cell = TableViewCell::create();
        textLabel = Label::create();
        textLabel->setSystemFontSize(36);
        textLabel->setAnchorPoint(Vec2::ZERO);
        textLabel->setTag(2);
        cell->addChild(textLabel);
    }
    else {
        textLabel = (Label*)cell->getChildByTag(2);
    }
    textLabel->setString(StringUtils::format("Label %ld", idx));
    return cell;
}

ssize_t HelloWorld::numberOfCellsInTableView(cocos2d::extension::TableView *table) {
    return 100;
}

void HelloWorld::tableCellTouched(cocos2d::extension::TableView *table, cocos2d::extension::TableViewCell *cell) {
    Label *text = (Label*)cell->getChildByTag(2);
    log("label text is:%s",text->getString().c_str());
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
