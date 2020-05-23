#pragma once
class DataManager ;
class View {
protected:
	DataManager *m_pDataMgr ;
public:
	View(DataManager *pDM) :m_pDataMgr{pDM} {
		
	}
	virtual void Display(size_t index) = 0 ;
	virtual ~View(){}
};

