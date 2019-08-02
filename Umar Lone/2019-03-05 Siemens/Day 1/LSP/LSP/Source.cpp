#include "Rectangle.h"
#include <iostream>
#include "Square.h"
#include <cassert>

void Area(Rectangle &r) {
	r.SetHeight(6) ;
	r.SetWidth(4) ;
	auto area = r.GetHeight() * r.GetWidth() ;
	if(typeid(r) != typeid(Square))
		assert(area == 24) ;
	std::cout << "Area is:" << area << std::endl ;
}

int main() {
	Rectangle shape{5,3} ;
	//Square shape{5} ;
	Area(shape) ;
}
