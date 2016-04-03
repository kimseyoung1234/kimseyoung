#include "Picture.h"
#include "HelloWorldScene.h"
#include "Singleton.h"

USING_NS_CC;

Picture::Picture()
	:_listener(nullptr)
	, _fixedPriority(0)
	, _useNodePriority(false)
{
	bool bOk = initWithTexture(nullptr, Rect::ZERO);
	if (bOk)
	{
		this->autorelease();
	}
}
void Picture::setPriority(int fixedPriority)
{
	_fixedPriority = fixedPriority;
	_useNodePriority = false;
}

void Picture::setPriorityWithThis(bool useNodePriority)
{
	_useNodePriority = useNodePriority;
	_fixedPriority = false;
}

void Picture::onEnter()
{
	Sprite::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [=](Touch * touch, Event * event)
	{
		Vec2 spritePosition = this->getPosition();
		Vec2 locationInNode = this->convertToNodeSpace(touch->getLocation());
	//	log("x : %f y : %f", locationInNode.x, locationInNode.y);
		Size s = this->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);
		if (rect.containsPoint(locationInNode))
		{
			transCheck(spritePosition);
			this->setColor(Color3B::RED);
			return true;
		}
		return false;
	};

	listener->onTouchMoved = [=](Touch* touch, Event* event)
	{
	};

	listener->onTouchEnded = [=](Touch* touch, Event* event)
	{
		this->setColor(Color3B::WHITE);
	};

	if (_useNodePriority)
	{
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	}
	else
	{
		_eventDispatcher->addEventListenerWithFixedPriority(listener, _fixedPriority);
	}
	_listener = listener;

}

void Picture::onExit()
{
	_eventDispatcher->removeEventListener(_listener);

	Sprite::onExit();
}

void Picture::transCheck(Vec2 position)
{
	Vector <Picture*> pictures = DataSingleTon::getInstance()->getPicutre();
	log("%d", pictures.size());
	this->setPosition(Vec2(0, 0));
	//pictures.at(8)->setPosition(Vec2(0, 0));
//	log("x : %f y : %f", position.x, position.y);
}