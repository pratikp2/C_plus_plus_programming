#pragma once
class Rectangle {
	int m_Width ;
	int m_Height ;
public:
	Rectangle(int w, int h);
	~Rectangle();
	int GetWidth()const ;
	int GetHeight() const ;
	virtual void SetWidth(int w) ;
	virtual void SetHeight(int h) ;

};

