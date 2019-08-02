#pragma once
#include "View.h"

class TextView : public View {
public:
	TextView(DataManager *pDM);
	~TextView();
	void Display(size_t index)override ;
};

