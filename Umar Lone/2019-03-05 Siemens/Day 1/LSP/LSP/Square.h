#pragma once
#include "Rectangle.h"
class Square :
	public Rectangle {
public:
	Square(int side);
	~Square();
	void SetWidth(int w) ;
	void SetHeight(int h) ;
};

