#pragma once
#include <string>

class ScrapData {
	std::string m_Title ;
	std::string m_Description ;
protected:
	std::string m_Path ;
public:
	ScrapData()=default ;
	virtual ~ScrapData()=default ;
	const std::string & GetTitle()const {
		return m_Title ;
	}
	const std::string & GetDescription()const {
		return m_Description ;
	}
	const std::string & GetPath()const {
		return m_Path ;
	}
	void SetPath(const std::string &path) {
		m_Path = path ;
	}
	void SetDescription(const std::string &description) {
		m_Description = description ;
	}
	void SetTitle(const std::string &title) {
		m_Title = title ;
	}	
	
	virtual const char * GetData()const = 0;
	virtual void SetData(char *pRawData) = 0;
	virtual void Display() = 0 ;
	virtual const char * GetType()const = 0 ;
};

