#pragma once
#include <vector>
class ScrapData ;
using ScrapArray = 	std::vector<ScrapData *> ;

class FileStorage {
public:
	FileStorage();
	~FileStorage();
	void Write(ScrapArray & scraps)const ;
	void Read(ScrapArray & scraps)const ;
};

