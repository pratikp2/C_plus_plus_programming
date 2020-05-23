#include "Rectangle.h"




Rectangle::Rectangle(int w, int h):m_Width{w}, m_Height{h} {
}

int Rectangle::GetWidth() const {
	return m_Width ;
}

int Rectangle::GetHeight() const {
	return m_Height ;
}

void Rectangle::SetWidth(int w) {
	m_Width = w ;
}

void Rectangle::SetHeight(int h) {
	m_Height = h ;
}

Rectangle::~Rectangle()
{
}
