#ifndef __SINGLETON__H__
#define __SINGLETON__H__
#include "cocos2d.h"
#include "Picture.h"

class DataSingleTon {
private:
	static DataSingleTon *m_pInstance;  //프로그램 시작시에 이놈 하나만 메모리 잡고 이것만 씀.  
	int m_nData;
	cocos2d::Vector <cocos2d::Sprite*> picture;
private:
	DataSingleTon(); //생성자 그냥 사용못해요.
public:
	void setData(int nData);
	void printData();
	static DataSingleTon *getInstance(); //m_instance의 주소값을 얻어와서 사용. 

};

#endif