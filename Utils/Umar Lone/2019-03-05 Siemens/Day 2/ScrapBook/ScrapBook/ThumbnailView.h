#pragma once
#include "View.h"
class DataManager ;
class ThumbnailView :public View {
public:
	ThumbnailView(DataManager *p);
	~ThumbnailView();
	void Display(size_t index)override ;
};

