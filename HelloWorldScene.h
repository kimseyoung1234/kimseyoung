#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Picture.h"

#define PICTURE_COUNT	9
#define PICTURE_1	cocos2d::Vec2(154, 246)
#define PICTURE_2	cocos2d::Vec2(240, 246)
#define PICTURE_3	cocos2d::Vec2(326, 246)
#define PICTURE_4	cocos2d::Vec2(154, 160)
#define PICTURE_5	cocos2d::Vec2(240, 160)
#define PICTURE_6	cocos2d::Vec2(326, 160)
#define PICTURE_7	cocos2d::Vec2(154, 74)
#define PICTURE_8	cocos2d::Vec2(240, 74)
#define PICTURE_9	cocos2d::Vec2(326, 74)

#define UP cocos2d::Vec2(0,170)
#define DOWN cocos2d::Vec2(0,-170)
#define LEFT cocos2d::Vec2(-170,0)
#define RIGHT cocos2d::Vec2(170,0)


class HelloWorld : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(HelloWorld);

	cocos2d::Vector <cocos2d::Sprite*> picture;
	Picture* sprite1;
	Picture* sprite2;
	Picture* sprite3;
	Picture* sprite4;
	Picture* sprite5;
	Picture* sprite6;
	Picture* sprite7;
	Picture* sprite8;
	Picture* sprite9;

	void addPicture();
};

#endif // __HELLOWORLD_SCENE_H__
