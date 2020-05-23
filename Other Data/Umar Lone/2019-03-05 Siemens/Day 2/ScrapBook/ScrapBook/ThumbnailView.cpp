#include "ThumbnailView.h"
#include "DataManager.h"
#include <iostream>


ThumbnailView::ThumbnailView(DataManager* p):View{p} {
}

void ThumbnailView::Display(size_t index) {
	const ScrapData *pScrap{} ;
	for(size_t i = 0 ; i < m_pDataMgr->GetSize(); ++i) {
		pScrap = m_pDataMgr->GetScrap(i) ;
		std::cout << "\n\n----------------------------\n" ;
		std::cout << "Scrap type->" << pScrap->GetType()<< std::endl; 
		std::cout << "Title->" << pScrap->GetTitle() << std::endl;
		std::cout << "Description->" << pScrap->GetDescription() << std::endl;
		if(pScrap->GetType() == "text") {
			//Render the text on the view
			std::cout << "Preview->" ; 
			for(int i = 0 ; i < 5 ; ++i){
				std::cout << pScrap->GetData()[i] ;
			}
			std::cout << std::endl; 
		}else if(pScrap->GetType() == "image") {
			//Displaying an image will require different implementation
			std::cout << "Preview->" ; 
			for(int i = 0 ; i < 5 ; ++i){
				std::cout << pScrap->GetData()[i] ;
			}
			std::cout << std::endl;  
		}
		std::cout << "Path ->" << pScrap->GetPath() << std::endl ;
	}
}

ThumbnailView::~ThumbnailView()
{
}
