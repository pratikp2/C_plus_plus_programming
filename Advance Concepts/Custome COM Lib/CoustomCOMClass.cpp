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


STDMETHODIMP CCoustomCOMClass::get_MySampleProperty(DOUBLE* pVal)
{
	// TODO: Add your implementation code here

	*pVal = m_ClassMember;
	return S_OK;
}


STDMETHODIMP CCoustomCOMClass::put_MySampleProperty(DOUBLE newVal)
{
	// TODO: Add your implementation code here

	m_ClassMember = newVal;
	return S_OK;
}
