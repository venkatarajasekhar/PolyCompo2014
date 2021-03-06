#include "AppDelegate.h"
#include "MenuScene.h"
#include "CreditsScene.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{}

AppDelegate::~AppDelegate()
{}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview)
    {
        //glview = GLView::createWithFullScreen (mGameTitle);
        glview = GLView::createWithRect(mGameTitle, cocos2d::Rect(0.f, 0.f, mWidth, mHeight), 1.f);
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(IS_STATS_ACTIVE);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / FRAMERATE);

    // create a scene. it's an autorelease object
    mMenuScene = MenuScene::createScene();

    // run
    director->runWithScene(TransitionFade::create(3, mMenuScene, Color3B(0, 0, 0)));

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
}
