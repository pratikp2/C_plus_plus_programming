#include "Square.h"




Square::Square(int side) :Rectangle{ side, side } {
}

void Square::SetWidth(int w) {
	Rectangle::SetWidth(w);
	Rectangle::SetHeight(w);
}

void Square::SetHeight(int h) {
	Rectangle::SetWidth(h);
	Rectangle::SetHeight(h);
}

Square::~Square()
{
}
