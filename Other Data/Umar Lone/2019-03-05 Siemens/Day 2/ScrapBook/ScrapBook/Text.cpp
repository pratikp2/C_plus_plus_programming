#include "Text.h"
#include <iostream>
#include <fstream>


Text::Text()
{
}


Text::~Text()
{
}

void Text::Display() {
	std::cout << m_Text << std::endl;

}

const  char* Text::GetData() const {
	return m_Text.data() ;
}

void Text::SetData(char *pRawData) {
	m_Text = pRawData ;
}
