#ifndef __SINGLETON__H__
#define __SINGLETON__H__
#include "cocos2d.h"
#include "Picture.h"

class DataSingleTon {
private:
	static DataSingleTon *m_pInstance;  //���α׷� ���۽ÿ� �̳� �ϳ��� �޸� ��� �̰͸� ��.  
	int m_nData;
	cocos2d::Vector <Picture*> picture;
private:
	DataSingleTon(); //������ �׳� �����ؿ�.
public:
	void setData(int nData);
	void setPicutre(Picture *p);
	cocos2d::Vector<Picture*> getPicutre();
	static DataSingleTon *getInstance(); //m_instance�� �ּҰ��� ���ͼ� ���. 

};

#endif