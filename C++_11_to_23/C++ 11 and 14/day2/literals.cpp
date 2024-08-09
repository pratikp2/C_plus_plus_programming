#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readFile(const char* path){
	ifstream file(path);
	if(file.is_open()){
		
		string line;
		while(!file.eof()){
			std::getline(file, line);
			cout << line << endl;
		}
	}else{
		cout << "Could not able to open file for reading";
	}
}

void writeFile(string& path){
	ofstream file(path);
	if(file.is_open()){
		file << R"DATA(<Configuration
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xsi:noNamespaceSchemaLocation="containerconfig.xsd">
        <BaseImage value = "centos:latest"/>
        <Group value = "atlasGroup">
        <User value = "atlasUser">
        <Workdir value = "(/app)">
        <EnvVariable name = "LD_LIBRARY_PATH" value = "/app/nxbin">
</Configuration>)DATA" << endl;
	}else
		cout << "Could not able to open file for writing";
}
void main()
{
	const char* inputFile = R"(D:\workdir\input.config)";
	readFile(inputFile);
	
	auto outputPath = R"(D:\workdir\output.config)"s;
	writeFile(outputPath);
}
