#include <iostream>
#include <objbase.h>
#include "../Custome COM Lib/CustomeCOMLib_i.c"
#include "../Custome COM Lib/CustomeCOMLib_i.h"

int main()
{
	CoInitializeEx(nullptr, COINIT::COINIT_MULTITHREADED);

	// Calling COM APIs from  lCustom Components
	ICoustomCOMClass* ptrComObject;
	HRESULT hr = CoCreateInstance(CLSID_CoustomCOMClass, nullptr, CLSCTX_INPROC_SERVER, IID_ICoustomCOMClass, (LPVOID*)&ptrComObject);

	if (SUCCEEDED(hr))
	{
		double sqr;
		ptrComObject->AddRef();
		ptrComObject->put_MySampleProperty(20);

		ptrComObject->get_MySampleProperty(&sqr);
		std::cout << "Value Set for Property	: " << sqr << std::endl;

		ptrComObject->MySampleFunction(&sqr);
		std::cout << "Squared Value	of Property	: " << sqr << std::endl;

		getchar();
		ptrComObject->Release();
	}

	CoUninitialize();
	return 0;
}

