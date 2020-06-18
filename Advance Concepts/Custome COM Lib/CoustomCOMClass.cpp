// CoustomCOMClass.cpp : Implementation of CCoustomCOMClass

#include "pch.h"
#include "CoustomCOMClass.h"


// CCoustomCOMClass



STDMETHODIMP CCoustomCOMClass::MySampleFunction(DOUBLE* variable)
{
	// TODO: Add your implementation code here
	*variable = m_ClassMember * m_ClassMember;
	return S_OK;
}
