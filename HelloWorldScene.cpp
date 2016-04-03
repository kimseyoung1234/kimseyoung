#include "HelloWorldScene.h"
#include "Singleton.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
  
    auto scene = Scene::create();
    
    auto layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}


bool HelloWorld::init()
{

    if ( !LayerColor::initWithColor(Color4B(255, 255, 255, 0)) )
    {
        return false;
    }
    ////////////////////////////
	
	this->addPicture();
	//랜덤으로 터치해서 섞기
	Vector <Picture*> pictures = DataSingleTon::getInstance()->getPicutre();
	for (int i = 0; i < 1000; i++)
	{
		int a = random(0, 8);
		Vec2 position = pictures.at(a)->getPosition();
		pictures.at(a)->transCheck(position);
	}
	
    return true;
}


// 512x512 이미지 9조각으로 자르기
void HelloWorld::addPicture()
{
	auto background = Sprite::create("images/background.png");
	background->setColor(Color3B::WHITE);
	background->setTextureRect(Rect(0, 0, 170, 170));
	background->setScale(0.5f);
	background->setPosition(Vec2(EMPTY));
	this->addChild(background);
	DataSingleTon::getInstance()->setEmptyImage(background);

	sprite1 = new Picture();
	sprite1->setTexture("images/sprite.png");
	sprite1->setPosition(PICTURE_0);
	sprite1->setPriority(11);
	sprite1->setTextureRect(Rect(0, 0, 170, 170));
	sprite1->setScale(0.5f);
	this->addChild(sprite1);
	DataSingleTon::getInstance()->setPicutre(sprite1);

	sprite2 = new Picture();
	sprite2->setTexture("images/sprite.png");
	sprite2->setPosition(PICTURE_1);
	sprite2->setPriority(11);
	sprite2->setTextureRect(Rect(170, 0, 170, 170));
	sprite2->setScale(0.5f);
	this->addChild(sprite2);
	DataSingleTon::getInstance()->setPicutre(sprite2);

	sprite3 = new Picture();
	sprite3->setTexture("images/sprite.png");
	sprite3->setPosition(PICTURE_2);
	sprite3->setPriority(11);
	sprite3->setTextureRect(Rect(340, 0, 170, 170));
	sprite3->setScale(0.5f);
	this->addChild(sprite3);
	DataSingleTon::getInstance()->setPicutre(sprite3);


	sprite4 = new Picture();
	sprite4->setTexture("images/sprite.png");
	sprite4->setPosition(PICTURE_3);
	sprite4->setPriority(11);
	sprite4->setTextureRect(Rect(0, 170, 170, 170));
	sprite4->setScale(0.5f);
	this->addChild(sprite4);
	DataSingleTon::getInstance()->setPicutre(sprite4);


	sprite5 = new Picture();
	sprite5->setTexture("images/sprite.png");
	sprite5->setPosition(PICTURE_4);
	sprite5->setPriority(11);
	sprite5->setTextureRect(Rect(170, 170, 170, 170));
	sprite5->setScale(0.5f);
	this->addChild(sprite5);
	DataSingleTon::getInstance()->setPicutre(sprite5);


	sprite6 = new Picture();
	sprite6->setTexture("images/sprite.png");
	sprite6->setPosition(PICTURE_5);
	sprite6->setPriority(11);
	sprite6->setTextureRect(Rect(340, 170, 170, 170));
	sprite6->setScale(0.5f);
	this->addChild(sprite6);
	DataSingleTon::getInstance()->setPicutre(sprite6);

	sprite7 = new Picture();
	sprite7->setTexture("images/sprite.png");
	sprite7->setPosition(PICTURE_6);
	sprite7->setPriority(11);
	sprite7->setTextureRect(Rect(0, 340, 170, 170));
	sprite7->setScale(0.5f);
	this->addChild(sprite7);
	DataSingleTon::getInstance()->setPicutre(sprite7);

	sprite8 = new Picture();
	sprite8->setTexture("images/sprite.png");
	sprite8->setPosition(PICTURE_7);
	sprite8->setPriority(11);
	sprite8->setTextureRect(Rect(170, 340, 170, 170));
	sprite8->setScale(0.5f);
	this->addChild(sprite8);
	DataSingleTon::getInstance()->setPicutre(sprite8);

	sprite9 = new Picture();
	sprite9->setTexture("images/sprite.png");
	sprite9->setPosition(PICTURE_8);
	sprite9->setPriority(11);
	sprite9->setTextureRect(Rect(340, 340, 170, 170));
	sprite9->setScale(0.5f);
	this->addChild(sprite9);
	DataSingleTon::getInstance()->setPicutre(sprite9);

}
