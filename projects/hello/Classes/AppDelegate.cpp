#include "AppDelegate.h"
#include "HelloWorldScene.h"

//#include <thread>

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = HelloWorld::scene();

    // run
    pDirector->runWithScene(pScene);

    #if 0
    CCLog("> Current cocos thread = %lu", std::hash<std::thread::id>{}(std::this_thread::get_id()));
    std::thread th ([pDirector]() {
        CCLog("> Hello from thread = %lu", std::hash<std::thread::id>{}(std::this_thread::get_id()));
        pDirector->getScheduler()->performFunctionInCocosThread([]() {
            CCLog("> Hello from cocos thread = %lu", std::hash<std::thread::id>{}(std::this_thread::get_id()));
        });
    });
    th.join();
    #endif

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
