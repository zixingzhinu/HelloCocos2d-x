#include "HelloWorldScene.h"
#include <tinyxml2/tinyxml2.h>
#include <json/document.h>

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
    
    label = Label::create();
    label->setAnchorPoint(Vec2::ZERO);
    label->setSystemFontName("Courier New");
    label->setSystemFontSize(36);
    label->setString("James");
    addChild(label);
    
    //第一种计时器
//    scheduleUpdate();
    //第二种计时器
    //每一帧(大约0.01秒)执行updateHandler函数（该函数名随便写）一次
//    schedule(schedule_selector(HelloWorld::updateHandler));
    //每一秒执行updateHandler函数（该函数名随便写）一次
    //    schedule(schedule_selector(HelloWorld::updateHandler), 1);
    //每0.1秒执行updateHandler函数（该函数名随便写）一次，共执行100次，且延迟5秒开始执行
//    schedule(schedule_selector(HelloWorld::updateHandler), 0.1f, 100, 5);
    
    //用户的共享首选项
//    UserDefault::getInstance()->setStringForKey("data", "Hello James");
//    std::string s = UserDefault::getInstance()->getStringForKey("data1", "Hello Cocos2d-x");
//    log("cocos2d-x:%s", s.c_str());
    
    //cocos2d-x文件操作
//    auto fu = FileUtils::getInstance();
//    FILE *f = fopen(fu->fullPathFromRelativeFile("data.txt", fu->getWritablePath()).c_str(), "w");
//    fprintf(f, "Hello Cocos2d-x!\n"); //最后的\n不要忘记
//    fclose(f);
//    
//    Data d = fu->getDataFromFile(fu->fullPathFromRelativeFile("data.txt", fu->getWritablePath()));
//    log("The file content is : %s", d.getBytes());
    
    //cocos2d-x 操作plist文件
//    auto fu = FileUtils::getInstance();
//    ValueMap vm = fu->getValueMapFromFile("data.plist");
//    log("name:%s",vm["name"].asString().c_str());
//    log("age:%d",vm["age"].asInt());
//    log("arr[0]:%s",vm["arr"].asValueVector()[0].asString().c_str());
    
    //cocos2d-x解析xml文件
//    auto xmlParser = new tinyxml2::XMLDocument();
//    xmlParser->Parse(FileUtils::getInstance()->getStringFromFile("text.xml").c_str());
//    auto root = xmlParser->RootElement();
//    for (auto e = root->FirstChildElement(); e; e = e->NextSiblingElement()) {
//        std::string str;
//        str+="{";
//        str+=e->Name();
//        str+=":";
//        str+=e->GetText();
//        str+="->";
//        for (auto attr = e->FirstAttribute(); attr; attr = attr->Next()) {
//            str+=attr->Name();
//            str+=":";
//            str+=attr->Value();
//            str+=" ";
//        }
//        str+="}";
//        log("str: %s", str.c_str());
//    }
    
    //cocos2d-x解析json
    
    rapidjson::Document parser;
    parser.Parse<0>(FileUtils::getInstance()->getStringFromFile("text.json").c_str());
    log("%s", parser["programmers"][(int)1]["firstName"].GetString());
    
    return true;
}

void HelloWorld::updateHandler(float dt) {
    label->setPosition(label->getPositionX()+1, label->getPositionY()+1);
    if (label->getPositionX()>300) {
        unschedule(schedule_selector(HelloWorld::updateHandler));
    }
}

void HelloWorld::update(float dt) {
    label->setPosition(label->getPositionX()+1, label->getPositionY()+1);
    
    if (label->getPositionX() > 300) {
        unscheduleUpdate();
    }
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
