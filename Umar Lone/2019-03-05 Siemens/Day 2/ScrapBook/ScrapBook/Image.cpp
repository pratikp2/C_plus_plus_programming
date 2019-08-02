#include "Image.h"
#include <iostream>
#include <fstream>

Image::Image()
{
}


Image::~Image()
{
}

const  char* Image::GetData() const {
	return m_pRaw ;
}

void Image::SetData(char *pRawData) {
	if(m_pRaw)
		delete []m_pRaw ;
	m_pRaw = pRawData ;
}

void Image::Display() {
	std::cout << m_pRaw << std::endl; 
}
