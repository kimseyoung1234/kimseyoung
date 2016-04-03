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

	//터치이벤트 람다 형식
	listener->onTouchBegan = [=](Touch * touch, Event * event)
	{
		Vec2 spritePosition = this->getPosition();	// 터치한 블록의 좌표
		Vec2 locationInNode = this->convertToNodeSpace(touch->getLocation());
	
		Size s = this->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);
		if (rect.containsPoint(locationInNode))	
		{
			transCheck(spritePosition);	// 이동 방향체크 함수 호출
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

// 터치한 블록이 어느 방향으로 이동가능한지 체크
void Picture::transCheck(Vec2 position)
{
	bool isTrans = true;	// 각 방향으로 이동 가능한지 체크 전 초기값
	Vector <Sprite*> sprite = DataSingleTon::getInstance()->getEmptyImage();	// 싱글톤 객체에서 비어있는 블록 스프라이트 가져옴 
	Vec2 EmptyPosition = sprite.at(0)->getPosition();	// 비어있는 블록 위치 저장

	// 터치한 위치에 따라 어느 이미지가 눌렸는지 체크하고 그 이미지가 이동가능한 방향을 체크한다 
	if (position == PICTURE_8)
	{	//왼쪽체크
		isTrans = LeftCheck(position);
		if (isTrans)
		{	// 터치한 이미지와 인접해 있는 비어있는 블록 위치 교환
			this->setPosition(EmptyPosition); 
			sprite.at(0)->setPosition(position);
			return;
		}
		// 위쪽체크 
		if (!isTrans) // 왼쪽체크 후 이동할 수 없었다면 체크
			isTrans = UpCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// 오른쪽체크
		if (!isTrans) // 왼쪽, 위쪽 체크 후 이동할 수 없었다면 체크
			isTrans = RightCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
	}

	if (position == PICTURE_7)
	{	//왼쪽체크
		isTrans = LeftCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// 위쪽체크
		if (!isTrans)
			isTrans = UpCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// 오른쪽체크
		if (!isTrans)
			isTrans = RightCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
	}

	if (position == PICTURE_6)
	{
		log("여기 왜바꿈");
		// 위쪽체크
			isTrans = UpCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// 오른쪽체크
		if (!isTrans)
			isTrans = RightCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
	}
	if (position == PICTURE_5)
	{	//왼쪽체크
		isTrans = LeftCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// 위쪽체크
		if (!isTrans)
			isTrans = UpCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// 아래체크
		if (!isTrans)
			isTrans = DownCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
	}
	if (position == PICTURE_4)
	{	//왼쪽체크
		isTrans = LeftCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// 위쪽체크
		if (!isTrans)
			isTrans = UpCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// 아래체크
		if (!isTrans)
			isTrans = DownCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// 오른쪽체크
		if (!isTrans)
			isTrans = RightCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
	}
	if (position == PICTURE_3)
	{	//오른쪽체크
		isTrans = RightCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// 위쪽체크
		if (!isTrans)
			isTrans = UpCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// 아래체크
		if (!isTrans)
			isTrans = DownCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
	}

	if (position == PICTURE_2)
	{	//왼쪽체크
		isTrans = LeftCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// 아래체크
		if (!isTrans)
			isTrans = DownCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
	}

	if (position == PICTURE_1)
	{	//오른쪽체크
		isTrans = RightCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// 왼쪽체크
		if (!isTrans)
			isTrans = LeftCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// 아래체크
		if (!isTrans)
			isTrans = DownCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
	}
	if (position == PICTURE_0)
	{	//오른쪽체크
		isTrans = RightCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// 아래체크
		if (!isTrans)
			isTrans = DownCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
	}
	if (position == EMPTY)
	{	// 왼쪽체크
		if (isTrans)
			isTrans = LeftCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
	}
}


// 왼쪽 체크
bool Picture::LeftCheck(Vec2 position)
{
	Vector <Picture*> pictures = DataSingleTon::getInstance()->getPicutre();	//싱글톤 객체에서 9조각 이미지를 가져옴

	bool isTrans = true;
	for (int i = 0; i < pictures.size(); i++)	// 각 이미지 바운딩 박스를 이용해 체크하는 방향에 이미지가 존재하는지 확인
	{
		if (pictures.at(i)->getBoundingBox().containsPoint(position + LEFT)) // 누른 이미지 위치에서 왼쪽
		{
			isTrans = false;	// 존재한다면 이동할 수 없다
			break;
		}
	}
	return isTrans;	// 부울값 리턴
}

bool Picture::RightCheck(Vec2 position)
{
	Vector <Picture*> pictures = DataSingleTon::getInstance()->getPicutre();

	bool isTrans = true;
	for (int i = 0; i < pictures.size(); i++)
	{
		if (pictures.at(i)->getBoundingBox().containsPoint(position + RIGHT))
		{
			isTrans = false;
			break;
		}
	}
	return isTrans;
}


bool Picture::UpCheck(Vec2 position)
{
	Vector <Picture*> pictures = DataSingleTon::getInstance()->getPicutre();

	bool isTrans = true;
	for (int i = 0; i < pictures.size(); i++)
	{
		if (pictures.at(i)->getBoundingBox().containsPoint(position + UP))
		{
			isTrans = false;
			break;
		}
	}
	return isTrans;
}

bool Picture::DownCheck(Vec2 position)
{
	Vector <Picture*> pictures = DataSingleTon::getInstance()->getPicutre();

	bool isTrans = true;
	for (int i = 0; i < pictures.size(); i++)
	{
		if (pictures.at(i)->getBoundingBox().containsPoint(position + DOWN))
		{
			isTrans = false;
			break;
		}
	}
	return isTrans;
}