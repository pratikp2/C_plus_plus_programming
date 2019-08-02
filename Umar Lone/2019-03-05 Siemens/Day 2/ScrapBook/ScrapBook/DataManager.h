#pragma once
#include "ScrapData.h"
#include <vector>
#include "FileStorage.h"

class DataManager {
	ScrapArray m_Scraps;
	FileStorage m_pStorage ;
public:
	DataManager();
	~DataManager();
	void Add(ScrapData *scrap);
	void Delete(size_t index);
	void Save();
	void Load();
	void Sort(int type) ;
	const ScrapData * GetScrap(size_t index)const {
		return m_Scraps[index];
	}
	size_t GetSize()const {
		return m_Scraps.size() ;
	}
};

