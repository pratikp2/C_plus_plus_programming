#include "graphics.h"

Graphics::Graphics()
{
	factory = NULL;
	rendertarget = NULL;
}

Graphics :: ~Graphics()
{
	factory->Release();
	rendertarget->Release();
}

bool Graphics::Init(HWND windowHandle)
{
	HRESULT  res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED,&factory);
	if (res != S_OK) { return false;}		// HRESULT is status of the function Value S_OK for HRESULT means function have succeeded.

	RECT rect;
	GetClientRect(windowHandle, &rect);

	res = factory->CreateHwndRenderTarget(D2D1 :: RenderTargetProperties(),
										  D2D1 :: HwndRenderTargetProperties(windowHandle, D2D1 :: SizeU(rect.right,rect.bottom)),
										  &rendertarget);
	if (res != S_OK) { return false; }

	return true;
}	