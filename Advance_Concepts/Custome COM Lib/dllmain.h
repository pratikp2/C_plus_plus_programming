// dllmain.h : Declaration of module class.

class CCustomeCOMLibModule : public ATL::CAtlDllModuleT< CCustomeCOMLibModule >
{
public :
	DECLARE_LIBID(LIBID_CustomeCOMLibLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CUSTOMECOMLIB, "{3f69f654-baa0-460a-882a-dbe3aabeb553}")
};

extern class CCustomeCOMLibModule _AtlModule;
