#include "Application.h"
#include <iostream>
#include <fstream>
#include "Text.h"
#include "Image.h"
#include "ThumbnailView.h"
#include "DataManager.h"
#include "TextView.h"
#include <algorithm>


Application::Application(DataManager* p, ThumbnailView *pTv) :m_pDataMgr{ p } {
	m_Views.push_back(pTv) ;
}

Application::~Application()
{
}

void Application::New() {
	int subChoice = -1;

	std::cout << "1. Text" << std::endl;
	std::cout << "2. Image" << std::endl;
	std::cout << "Any number to go to previous menu" << std::endl;
	std::cin >> subChoice;
	switch (subChoice) {
	case 1:
		m_pDataMgr->Add(CreateText());
		Pause("Text scrap added successfully");
		break;
	case 2:
		m_pDataMgr->Add(CreateImage());
		Pause("Image scrap added successfully");
		break;
	default:
		Pause("Bad choice");
	}
}

void Application::Delete() {
	std::cout << "Index of the scrap to delete?";
	size_t index{};
	std::cin >> index;
	if (index > m_pDataMgr->GetSize()) {
		Pause("Invalid index");
		std::cout << "Invalid index" << std::endl;
		return;
	}
	m_pDataMgr->Delete(index);
	Pause("Scrap deleted successfully");
}


void Application::Save() {
	m_pDataMgr->Save();
}

void Application::Load() {
	m_pDataMgr->Load();
}

void Application::Sort() {
	std::cout << "1. By type" << std::endl;
	std::cout << "2. By title" << std::endl;
	int type{} ;
	std::cin >> type ;
	m_pDataMgr->Sort(type) ;
}

void Application::InputLoop() {
	bool running{ true };
	int choice = -1;
	m_pDataMgr->Load() ;
	NotifyViews(0);
	Pause("");

	while (running) {
		std::cout << "1. Add scrap" << std::endl;
		std::cout << "2. Delete scrap" << std::endl;
		std::cout << "3. Save all" << std::endl;
		std::cout << "4. Load all" << std::endl;
		std::cout << "5. View all" << std::endl;
		std::cout << "6. Select thumbnail" << std::endl;
		std::cout << "7. Sort by type" << std::endl; 
		std::cout << "0. Exit" << std::endl;
		std::cin >> choice;
		std::cin.ignore();
		switch (choice) {
		case 1:
			New();
			NotifyViews(0) ;
			Pause("New scrap added successfully");
			break;
		case 2:
			Delete();
			break;
		case 3:
			Save();
			Pause("All scraps saved into file");
			break;
		case 4:
			Load();
			Pause("Scraps loaded successfully");
			break;
		case 5:
			system("cls");
			NotifyViews(0) ;
			Pause("");
			break;
		case 6:
			SelectThumbnail() ;
			break ;
		case 7:
			Sort() ;
			break ;
		case 0:
			running = false;
			break;
		default:
			Pause("Bad choice or unknown option");
			break;
		}
	}
}

void Application::NotifyViews(size_t index)
{
	for (auto view : m_Views) {
		view->Display(index);
	}
}

ScrapData * Application::CreateText() {

	ScrapData * p = new Text{};
	char *pData = new char[64]{ "Avoid using raw pointers. Use smart pointers instead" };
	p->SetData(pData);
	delete[]pData;
	p->SetDescription("Article on memory leaks");
	p->SetTitle("Memory leaks");
	p->SetPath("textscrap.txt");
	return p;
}
ScrapData * Application::CreateImage() {
	ScrapData * p = new Image{};
	char *pData = new char[64]{ "##########################################" };
	p->SetData(pData);
	p->SetDescription("Photo from the vacation");
	p->SetTitle("Photo");
	p->SetPath("imagescrap.png");

	return p;
}

void Application::Pause(const char* message) {
	std::cout << message << std::endl;
	system("pause");
	system("cls");
}

void Application::SelectThumbnail() {
	std::cout << "Enter index:" ;
	int index{} ;
	std::cin >> index ;
	if (index > m_pDataMgr->GetSize()) {
		Pause("Invalid index");
		return;
	}
	TextView *pTV = new TextView{m_pDataMgr} ;
	RegisterView(pTV) ;
	NotifyViews(index) ;

}

void Application::RegisterView(View* pv) {
	m_Views.push_back(pv) ;
}

void Application::UnregisterView(View* pv) {
	m_Views.remove(pv) ;
}
