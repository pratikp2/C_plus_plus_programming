/*
 * setad.h
 *
 *	Generated on: 28-10-2016 by kdbusxml2cpp
 *	
 *  ! This is an auto generated interface definition
 *	   from the DBus XML specification
 */

#ifndef SETAD_A_H_
#define SETAD_A_H_


#include "config.h"
#include <kivi.h>
#include <logger.h>
#include <ipc/common.h>
#include <ipc/ipcerror.h>
#include <stlinc.h>

using namespace kivi::ipc;
namespace kivi{
namespace mw{
namespace refl{
class UpdateManagerAdapter;

class IUpdateManager {
public:
	IUpdateManager() : methodCount(2) {
		LOG3(("IUpdateManager\n"));

		Methods[0].name = "Set";
		Methods[0].method = &IUpdateManager::Set_Stub;

		Methods[1].name = "__Register__";
		Methods[1].method = &IUpdateManager::__Register__;

	}

	virtual ~IUpdateManager() {
		for(ClientIdentificationMapIterator it = m_clientIdentificationMap.begin(); it != m_clientIdentificationMap.end(); ++it){
			if((ClientIdentificationMap*)it->second != NULL)
				delete it->second;
		}
		m_clientIdentificationMap.clear();
	}

	virtual kuint32_t  Set(kuint32_t  first_arg)=0;

protected:

private:
	msg_t HandleMessage(msg_t &msg){
		msg_t ret;
		const char *member = msg.method();
		LOG3((TEXT("Looking for %s\n"), member));
#ifdef USE_STL
		MethodMapIterator it = m_methodMap.find(member);
		if (it != m_methodMap.end()) {
			ret = (this->*(it->second))(msg);
		}
		else {
			LOGERR("IPC", "Unable to find method %s\n", member);
		}
#else
		for(int i=0; i < methodCount; i++) {
			if (strcasecmp(Methods[i].name, member) == 0) {
				LOG3((TEXT("Invoking %s\n"), Methods[i].name));
				ret = (this->*Methods[i].method)(msg);
				break;
			}
		}
#endif
		return ret;
	}


	msg_t __Register__(const msg_t &msg){
		LOG3(("Enter\n"));
		msg_iterator reader = msg.reader();
		string objectPath = reader.getString();

		ClientIdentification *pClientIdentification = new ClientIdentification;
		pClientIdentification->busName = msg.sender();
		pClientIdentification->objectPath = objectPath;

		m_clientIdentificationMap.insert(make_pair(++m_ClientRegisterID,pClientIdentification));

		return_msg_t retmsg(msg);
		msg_iterator riter = retmsg.writer();
		riter.append((kint16_t)m_ClientRegisterID);
		retmsg.end();
		return retmsg;
	}

	msg_t Set_Stub(const msg_t &msg) {
		LOG3(("Enter\n"));
		msg_iterator in_iter = msg.reader();
		kuint32_t  first_arg = (kuint32_t  )in_iter.getUint32(); 
		in_iter.next();

		kint16_t requestID = in_iter.getInt16();
		in_iter.next();
		kint16_t clientID = in_iter.getInt16();

		kuint32_t  retVal = Set(first_arg);

		//asynchronous method invocation, so callback
		LOG3(("asynchronous call"));
		ClientIdentificationMapIterator clientIdentificationIter = m_clientIdentificationMap.find(clientID);
		if (clientIdentificationIter != m_clientIdentificationMap.end())
		{
			ClientIdentification *pClientIdentification = NULL;
			pClientIdentification = (ClientIdentification*)clientIdentificationIter->second;
			if(pClientIdentification != NULL)
			{
				call_msg_t msg(pClientIdentification->busName.c_str() ,pClientIdentification->objectPath.c_str(),"com.kivi.ksvcswupdate.UpdateManager_client","OnSetStatus");
				msg_iterator out_iter = msg.writer();
				out_iter.append((kuint32_t )retVal);
				out_iter.append((kint16_t)requestID);
				msg.end();
				if (IPC_NoError == m_broker->AsyncSend(msg)) {
				}
				else
				{
					LOGERR((TEXT("UpdateManager: Set failed !\n")));
				}
			}
			else
			{
				LOGERR((TEXT("UpdateManager: Set failed ! As clientIdentification not found\n")));
			}
		}
		else
		{
			LOGERR((TEXT("UpdateManager: Set failed ! As client is not registered\n")));
		}
		return_msg_t retmsg(msg);
		retmsg.end();
		return retmsg;
	}

private:
	typedef msg_t (IUpdateManager::*pfnStubMethod)(const msg_t &msg);
#ifdef USE_STL
	struct ltstr {
		bool operator()(const char* s1, const char* s2) const {
			return strcasecmp(s1, s2) < 0;
		}
	};
	typedef map< const char*, pfnStubMethod, ltstr> MethodMap;
	typedef MethodMap::iterator MethodMapIterator;
	MethodMap	m_methodMap;
#else
	typedef struct tagMethod {
		const char *name;
		pfnStubMethod method;
	}MethodStub;
	const int methodCount;
	MethodStub Methods[2];
#endif

	struct ClientIdentification{
		string busName;
		string objectPath;
	};

	typedef map<kint16_t ,ClientIdentification*> ClientIdentificationMap;
	typedef ClientIdentificationMap::iterator ClientIdentificationMapIterator;
	ClientIdentificationMap m_clientIdentificationMap;

	kint16_t m_ClientRegisterID;
protected:
	IIPC* m_broker;
	friend class UpdateManagerAdapter;

};

class UpdateManagerAdapter : IServiceAdapter {
public:
	UpdateManagerAdapter(IIPC *broker, IUpdateManager *pUpdateManager) : m_broker(broker), m_UpdateManager(pUpdateManager) {
		int ret = broker->RegisterObject("/com/kivi/ksvcswupdate/UpdateManager", this, &m_objid);
		if (ret != IPC_NoError) {
			LOGMSG2("UpdateManager", ("Create Object failed for UpdateManager\n"));
			exit(0);
		} 
		else {
			m_UpdateManager->m_broker = broker;
			LOGMSG2("UpdateManager", (TEXT("Created object with id=%d\n"), m_objid));
		}
	}
	virtual ~UpdateManagerAdapter() {
		m_broker->UnregisterObject(m_objid);
	}

	bool HandleMessage(msg_t &msg) {
		if (msg.isMethod()) {
			if (strcasecmp(msg.interface(), "com.kivi.ksvcswupdate.UpdateManager") == 0) {
				msg_t ret = m_UpdateManager->HandleMessage(msg);
				m_broker->AsyncSend(ret);
			} 
			else {
				LOG3((TEXT("unhandled message %s -> %s I=%s M=%s Err=%s\n"),
				msg.sender(),
				msg.destination(),
				msg.interface(),
				msg.method(),
				msg.isError() ? "DBus error" : ""));
				return false;
			}
		}
		else{
			LOGERR2("Benchmark", ("Invalid state!"));
		}
		return true;
	}

private:
	ObjectID m_objid;
	IIPC *m_broker;
	IUpdateManager *m_UpdateManager;
};

} //refl
} //mw
} //kivi
#endif /* SETAD_A_H_ */

