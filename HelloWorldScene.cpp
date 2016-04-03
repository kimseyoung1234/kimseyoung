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

	
    return true;
}


void HelloWorld::addPicture()
{
	
	sprite1 = new Picture();
	sprite1->setTexture("images/sprite.png");
	sprite1->setPosition(PICTURE_1);
	sprite1->setPriority(10);
	sprite1->setTextureRect(Rect(0, 0, 170, 170));
	sprite1->setScale(0.5f);
	this->addChild(sprite1);

	sprite2 = new Picture();
	sprite2->setTexture("images/sprite.png");
	sprite2->setPosition(PICTURE_2);
	sprite2->setPriority(11);
	sprite2->setTextureRect(Rect(170, 0, 170, 170));
	sprite2->setScale(0.5f);
	this->addChild(sprite2);

	sprite3 = new Picture();
	sprite3->setTexture("images/sprite.png");
	sprite3->setPosition(PICTURE_3);
	sprite3->setPriority(11);
	sprite3->setTextureRect(Rect(340, 0, 170, 170));
	sprite3->setScale(0.5f);
	this->addChild(sprite3);

	sprite4 = new Picture();
	sprite4->setTexture("images/sprite.png");
	sprite4->setPosition(PICTURE_4);
	sprite4->setPriority(11);
	sprite4->setTextureRect(Rect(0, 170, 170, 170));
	sprite4->setScale(0.5f);
	this->addChild(sprite4);

	sprite5 = new Picture();
	sprite5->setTexture("images/sprite.png");
	sprite5->setPosition(PICTURE_5);
	sprite5->setPriority(11);
	sprite5->setTextureRect(Rect(170, 170, 170, 170));
	sprite5->setScale(0.5f);
	this->addChild(sprite5);

	sprite6 = new Picture();
	sprite6->setTexture("images/sprite.png");
	sprite6->setPosition(PICTURE_6);
	sprite6->setPriority(11);
	sprite6->setTextureRect(Rect(340, 170, 170, 170));
	sprite6->setScale(0.5f);
	this->addChild(sprite6);

	sprite7 = new Picture();
	sprite7->setTexture("images/sprite.png");
	sprite7->setPosition(PICTURE_7);
	sprite7->setPriority(11);
	sprite7->setTextureRect(Rect(0, 340, 170, 170));
	sprite7->setScale(0.5f);
	this->addChild(sprite7);

	sprite8 = new Picture();
	sprite8->setTexture("images/sprite.png");
	sprite8->setPosition(PICTURE_8);
	sprite8->setPriority(11);
	sprite8->setTextureRect(Rect(170, 340, 170, 170));
	sprite8->setScale(0.5f);
	this->addChild(sprite8);

	sprite9 = new Picture();
	sprite9->setTexture("images/sprite.png");
	sprite9->setPosition(PICTURE_9);
	sprite9->setPriority(11);
	sprite9->setTextureRect(Rect(340, 340, 170, 170));
	sprite9->setScale(0.5f);
	this->addChild(sprite9);

}
