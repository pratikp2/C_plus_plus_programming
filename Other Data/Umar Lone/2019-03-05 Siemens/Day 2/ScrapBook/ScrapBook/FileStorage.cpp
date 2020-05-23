
#include <fstream>
#include "FileStorage.h"
#include "ScrapData.h"
#include "Image.h"
#include "Text.h"

FileStorage::FileStorage()
{
}


FileStorage::~FileStorage()
{
}

void FileStorage::Write(ScrapArray& scraps)const {
	std::ofstream fileList{ "filelist.txt" };
	for (const auto &pScrap : scraps) {
		fileList << pScrap->GetPath() << std::endl;
		std::ofstream out{ pScrap->GetPath() };
		if (pScrap->GetType() == "text") {
			out << pScrap->GetType() << std::endl;
			out << pScrap->GetTitle() << std::endl;
			out << pScrap->GetDescription() << std::endl;
			out << pScrap->GetData() << std::endl;
		} else if (pScrap->GetType() == "image") {
			out << pScrap->GetType() << std::endl;
			out << pScrap->GetTitle() << std::endl;
			out << pScrap->GetDescription() << std::endl;
			out << pScrap->GetData() << std::endl;
		}
	}
}

void FileStorage::Read(ScrapArray& scraps)const {
	std::ifstream registryInputStream{ "filelist.txt" };
	if (!registryInputStream) {
		throw std::runtime_error{ "Could not load the file registry" };
	}
	std::vector<std::string> fileRegistry;
	std::string line;
	while (std::getline(registryInputStream, line)) {
		fileRegistry.push_back(line);
	}
	registryInputStream.close();
	for (const auto &filename : fileRegistry) {
		ScrapData *scrap{};
		std::ifstream input{ filename };
		if (!input) {
			throw std::runtime_error{ "Could not open file" };
		}
		std::string type;
		std::string data;
		std::getline(input, type);
		if (type == "text") {
			//std::string line;
			std::string title;
			std::string description;
			std::getline(input, title);
			std::getline(input, description);

			while (std::getline(input, line)) {
				data += line += "\n";
			}
			scrap = new Text{};
			scrap->SetTitle(title);
			scrap->SetDescription(description);
			scrap->SetData(const_cast<char *>(data.c_str()));
		} else if (type == "image") {
			//std::string line;
			std::string title;
			std::string description;
			std::getline(input, title);
			std::getline(input, description);

			while (std::getline(input, line)) {
				data += line += "\n";
			}
			scrap = new Image{};
			char *pData = new char[data.length() + 1]{};
			strcpy(pData, data.c_str());
			scrap->SetTitle(title);
			scrap->SetDescription(description);
			scrap->SetData(pData);
		}
		scrap->SetPath(filename);

		scraps.push_back(scrap);
	}
}
