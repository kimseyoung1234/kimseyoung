#include "Singleton.h"
#include "cocos2d.h"
USING_NS_CC;

DataSingleTon * DataSingleTon::m_pInstance = nullptr;

DataSingleTon::DataSingleTon() :m_nData(0) {
}
void DataSingleTon::setData(int nData)
{
	m_nData = nData;
}

DataSingleTon * DataSingleTon::getInstance()
{

	if (!m_pInstance)  //getInstace�� ȣ���ϴ� ���� �޸𸮸� ��� ������� �ص� �ǰ�
	{
		m_pInstance = new DataSingleTon;
	}

	return m_pInstance;
}


void DataSingleTon::setPicutre(Picture *p)
{
	picture.pushBack(p);
}

cocos2d::Vector<Picture*> DataSingleTon::getPicutre()
{
	return picture;
}
