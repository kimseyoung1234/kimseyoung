#include "Singleton.h"

DataSingleTon * DataSingleTon::m_pInstance = nullptr;

DataSingleTon::DataSingleTon() :m_nData(0) {
}
void DataSingleTon::setData(int nData)
{
	m_nData = nData;
}

DataSingleTon * DataSingleTon::getInstance()
{

	if (!m_pInstance)  //getInstace를 호출하는 순간 메모리를 잡는 방법으로 해도 되고
	{
		m_pInstance = new DataSingleTon;
	}

	return m_pInstance;
}


