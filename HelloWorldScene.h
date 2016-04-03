#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Picture.h"

// 9조각으로 나눈 이미지들 각 블록에 해당하는 좌표
#define PICTURE_0	cocos2d::Vec2(154, 246)
#define PICTURE_1	cocos2d::Vec2(240, 246)
#define PICTURE_2	cocos2d::Vec2(326, 246)
#define PICTURE_3	cocos2d::Vec2(154, 160)
#define PICTURE_4	cocos2d::Vec2(240, 160)
#define PICTURE_5	cocos2d::Vec2(326, 160)
#define PICTURE_6	cocos2d::Vec2(154, 74)
#define PICTURE_7	cocos2d::Vec2(240, 74)
#define PICTURE_8	cocos2d::Vec2(326, 74)
#define EMPTY		cocos2d::Vec2(413, 74)

// 인접한 블록계산을 위한 벡터값
#define UP cocos2d::Vec2(0,85)
#define DOWN cocos2d::Vec2(0,-85)
#define LEFT cocos2d::Vec2(-85,0)
#define RIGHT cocos2d::Vec2(85,0)


class HelloWorld : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(HelloWorld);

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
