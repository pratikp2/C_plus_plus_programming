#include "TextView.h"
#include <iostream>
#include "DataManager.h"
#include "ScrapData.h"

TextView::TextView(DataManager* pDM) :View{ pDM } {
}

TextView::~TextView()
{
}

void TextView::Display(size_t index) {
	const ScrapData *pScrap = m_pDataMgr->GetScrap(index);
	if(pScrap->GetType() != "text")
		return ;
	std::cout << "\n\n---------FULL DATA----------\n";
	std::cout << "Scrap type->" << pScrap->GetType() << std::endl;
	std::cout << "Title->" << pScrap->GetTitle() << std::endl;
	std::cout << "Description->" << pScrap->GetDescription() << std::endl;
	if (pScrap->GetType() == "text") {
		//Render the text on the view
		std::cout << pScrap->GetData() << std::endl;
	}
	std::cout << "Path ->" << pScrap->GetPath() << std::endl;
}
