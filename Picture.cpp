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

	//��ġ�̺�Ʈ ���� ����
	listener->onTouchBegan = [=](Touch * touch, Event * event)
	{
		Vec2 spritePosition = this->getPosition();	// ��ġ�� ����� ��ǥ
		Vec2 locationInNode = this->convertToNodeSpace(touch->getLocation());
	
		Size s = this->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);
		if (rect.containsPoint(locationInNode))	
		{
			transCheck(spritePosition);	// �̵� ����üũ �Լ� ȣ��
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

// ��ġ�� ����� ��� �������� �̵��������� üũ
void Picture::transCheck(Vec2 position)
{
	bool isTrans = true;	// �� �������� �̵� �������� üũ �� �ʱⰪ
	Vector <Sprite*> sprite = DataSingleTon::getInstance()->getEmptyImage();	// �̱��� ��ü���� ����ִ� ��� ��������Ʈ ������ 
	Vec2 EmptyPosition = sprite.at(0)->getPosition();	// ����ִ� ��� ��ġ ����

	// ��ġ�� ��ġ�� ���� ��� �̹����� ���ȴ��� üũ�ϰ� �� �̹����� �̵������� ������ üũ�Ѵ� 
	if (position == PICTURE_8)
	{	//����üũ
		isTrans = LeftCheck(position);
		if (isTrans)
		{	// ��ġ�� �̹����� ������ �ִ� ����ִ� ��� ��ġ ��ȯ
			this->setPosition(EmptyPosition); 
			sprite.at(0)->setPosition(position);
			return;
		}
		// ����üũ 
		if (!isTrans) // ����üũ �� �̵��� �� �����ٸ� üũ
			isTrans = UpCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// ������üũ
		if (!isTrans) // ����, ���� üũ �� �̵��� �� �����ٸ� üũ
			isTrans = RightCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
	}

	if (position == PICTURE_7)
	{	//����üũ
		isTrans = LeftCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// ����üũ
		if (!isTrans)
			isTrans = UpCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// ������üũ
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
		log("���� �ֹٲ�");
		// ����üũ
			isTrans = UpCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// ������üũ
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
	{	//����üũ
		isTrans = LeftCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// ����üũ
		if (!isTrans)
			isTrans = UpCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// �Ʒ�üũ
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
	{	//����üũ
		isTrans = LeftCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// ����üũ
		if (!isTrans)
			isTrans = UpCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// �Ʒ�üũ
		if (!isTrans)
			isTrans = DownCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// ������üũ
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
	{	//������üũ
		isTrans = RightCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// ����üũ
		if (!isTrans)
			isTrans = UpCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// �Ʒ�üũ
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
	{	//����üũ
		isTrans = LeftCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// �Ʒ�üũ
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
	{	//������üũ
		isTrans = RightCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// ����üũ
		if (!isTrans)
			isTrans = LeftCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// �Ʒ�üũ
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
	{	//������üũ
		isTrans = RightCheck(position);
		if (isTrans)
		{
			this->setPosition(EmptyPosition);
			sprite.at(0)->setPosition(position);
			return;
		}
		// �Ʒ�üũ
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
	{	// ����üũ
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


// ���� üũ
bool Picture::LeftCheck(Vec2 position)
{
	Vector <Picture*> pictures = DataSingleTon::getInstance()->getPicutre();	//�̱��� ��ü���� 9���� �̹����� ������

	bool isTrans = true;
	for (int i = 0; i < pictures.size(); i++)	// �� �̹��� �ٿ�� �ڽ��� �̿��� üũ�ϴ� ���⿡ �̹����� �����ϴ��� Ȯ��
	{
		if (pictures.at(i)->getBoundingBox().containsPoint(position + LEFT)) // ���� �̹��� ��ġ���� ����
		{
			isTrans = false;	// �����Ѵٸ� �̵��� �� ����
			break;
		}
	}
	return isTrans;	// �οﰪ ����
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