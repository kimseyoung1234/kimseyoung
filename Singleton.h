#ifndef __SINGLETON__H__
#define __SINGLETON__H__
#include "cocos2d.h"
#include "Picture.h"

// Picture와 HelloWorld 클래스 양쪽에서 전역변수 처럼 사용하기 위해 싱글톤 객체 생성
class DataSingleTon {
private:
	static DataSingleTon *m_pInstance; 
	int m_nData;
	//cocos2d::Sprite* emptyImage;
	cocos2d::Vector <Picture*> picture;
	cocos2d::Vector <cocos2d::Sprite*> emptyImage;
private:
	DataSingleTon();
public:
	void setData(int nData);
	void setPicutre(Picture *p);
	cocos2d::Vector<Picture*> getPicutre();
	void setEmptyImage(cocos2d::Sprite *s);
	cocos2d::Vector<cocos2d::Sprite*> getEmptyImage();
	static DataSingleTon *getInstance(); 

};

#endif