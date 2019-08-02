#pragma once
#include <vector>
#include "ScrapData.h"
#include <list>
class DataManager ;
class ThumbnailView ;
class View ;
class Application {
	DataManager *m_pDataMgr ;
	std::list<View *> m_Views ;
public:
	Application(DataManager *p, ThumbnailView *pTv);
	~Application();
	void RegisterView(View *pv) ;
	void UnregisterView(View *pv) ;
	void New();
	void Delete();
	void Save();
	void Load();
	void Sort();
	void InputLoop();
	void NotifyViews(size_t index);
	ScrapData * CreateText();
	ScrapData * CreateImage();
	void Pause(const char *) ;
	void SelectThumbnail() ;
};

