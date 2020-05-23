#pragma once
#include "ScrapData.h"
class Text :
	public ScrapData {
	std::string m_Text ;
public:
	Text();
	~Text();
	void Display() override;
	const char* GetData() const override;
	void SetData(char *pRawData) override;
	const char* GetType() const override {
		return "text" ;
	}
};

