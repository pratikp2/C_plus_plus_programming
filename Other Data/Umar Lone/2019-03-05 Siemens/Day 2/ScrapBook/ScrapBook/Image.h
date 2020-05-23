#pragma once
#include "ScrapData.h"
class Image :
	public ScrapData {
	char *m_pRaw{} ;
public:
	Image();
	~Image();
	const char* GetData() const override;
	void SetData(char *pRawData) override;

	void Display() override;
		const char* GetType() const override {
		return "image" ;
	}
};

