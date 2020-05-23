#include "DataManager.h"
#include <algorithm>


DataManager::DataManager()
{
}


DataManager::~DataManager()
{
}

void DataManager::Add(ScrapData* scrap) {
	m_Scraps.push_back(scrap) ;
}

void DataManager::Delete(size_t index) {
	m_Scraps.erase(m_Scraps.begin()+index) ;
}

void DataManager::Save() {
	m_pStorage.Write(m_Scraps);
}

void DataManager::Load() {
	m_Scraps.clear() ;
	m_pStorage.Read(m_Scraps) ;
}

void DataManager::Sort(int type) {
	switch(type){
	case 1:
	sort(m_Scraps.begin(), m_Scraps.end(), [](const ScrapData *p1, const ScrapData *p2) {
		return p1->GetType() < p2->GetType() ;
	}) ;
		break ;
	case 2:
		sort(m_Scraps.begin(), m_Scraps.end(), [](const ScrapData *p1, const ScrapData *p2) {
		return p1->GetTitle() < p2->GetTitle() ;
	}) ;
		break ;
	}
}
