#pragma once

#ifndef __Picture__H__
#define __Picture__H__

#include "cocos2d.h"



class Picture : public cocos2d::Sprite {
public:
	Picture();

	void setPriority(int fixedPriority);
	void setPriorityWithThis(bool useNodePriority);

	// 터치한 블록이 어느 방향으로 이동가능한지 체크
	void transCheck(cocos2d::Vec2 position);

	// 각 방향에 블록이 존재하는지 확인한다.
	bool LeftCheck(cocos2d::Vec2 position);
	bool RightCheck(cocos2d::Vec2 position);
	bool UpCheck(cocos2d::Vec2 position);
	bool DownCheck(cocos2d::Vec2 position);

	virtual void onEnter();
	virtual void onExit();
private:
	cocos2d::EventListener * _listener;
	int _fixedPriority;
	bool _useNodePriority;
};

#endif /* defined(__SpriteExtendEx_Monster__)*/