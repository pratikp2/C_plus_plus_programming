/*
 * setpr.h
 *
 *	Generated on: 28-10-2016 by kbusxml2cpp
 *	
 *	! This is an auto generated interface definition
 *		from the DBus XML specification
 */

#ifndef SETPR_P_H_
#define SETPR_P_H_

#include <kivi.h>
#include <logger.h>
#include <ipc/common.h>
#include <ipc/ipcerror.h>
#include <stlinc.h>

using namespace kivi::ipc;

namespace kivi{
namespace mw{
namespace refl{

class IUpdateManagerObject;

class IUpdateManagerEvents {
public:
	virtual ~IUpdateManagerEvents() {
	}
	virtual void OnSetStatus(kuint32_t  retVal)=0;
};

class UpdateManager {
public:
	UpdateManager() : signalCount(1), m_broker(NULL),m_isServiceAlive(false)
	,m_name("com.kivi.ksvcswupdate.UpdateManager"), m_pe(NULL) {
		LOGMSG2("DBus", ("UpdateManager\n"));

		m_signals[0].name = "OnSetStatus";
		m_signals[0].method = &UpdateManager::OnSetStatus_Stub;

	}
	virtual ~UpdateManager() {
	}

private:
	msg_t OnSetStatus_Stub(const msg_t &msg) {
		LOG3(("Enter\n"));
		msg_iterator iter = msg.reader();

		kuint32_t  retVal = (kuint32_t  )iter.getUint32();iter.next();
		kint16_t requestID = iter.getInt16();
		RequestMapIterator reqIter =UpdateManager::m_request_map.find(requestID);
		if (reqIter != UpdateManager::m_request_map.end()) {
			reqIter->second->OnSetStatus(retVal);
		}
		return_msg_t retmsg(msg);
		retmsg.end();
		return retmsg;
	}

private:
	msg_t HandleMessage(msg_t &msg) {
		msg_t ret;
		const char *member = msg.method();
		LOG3((TEXT("Looking for %s\n"), member));
#ifdef USE_STL
		MethodMapIterator it = m_methodMap.find(member);
		if (it != m_methodMap.end()) {
			ret = (this->*(it->second))(msg);
		}
		else {
			LOGERR("DBus", "Unable to find method %s\n", member);
		}
#else
		for(int i=0; i < signalCount; i++) {
			if (strcasecmp(m_signals[i].name, member) == 0) {
				LOG3((TEXT("Invoking %s\n"), m_signals[i].name));
				ret = (this->*m_signals[i].method)(msg);
				break;
			}
		}
#endif
		assert (ret != NULL);
		return ret;
	}

public:
public:
	void AsyncSet(kuint32_t  first_arg,IUpdateManagerEvents* pe=NULL) {
		LOG3(("Enter\n"));
		if(!m_isServiceAlive)
		{
			LOGERR((TEXT("UpdateManager: AsyncSet failed,As service is not alive !\n")));
			return;
		}
		call_msg_t msg("com.kivi.ksvcswupdate", "/com/kivi/ksvcswupdate/UpdateManager", m_name, "Set");
		msg_iterator w_iter = msg.writer();
		w_iter.append(first_arg);
		kint16_t requestID = ++m_Requestid;
		w_iter.append(requestID);
		w_iter.append(UpdateManager::m_ClientBusRegisterID);
		if (NULL != pe) {
			UpdateManager::m_request_map.insert(make_pair(requestID, pe));
		}
		msg.end();
		if (IPC_NoError == m_broker->AsyncSend(msg)){
		}
		else {
			LOGERR((TEXT("UpdateManager: Set failed !\n")));
		}
	}
	void PrepareForAsync(string ifName, IIPC* broker,string objectPath){
		LOG3(("Enter"));
		call_msg_t msg("com.kivi.ksvcswupdate", "/com/kivi/ksvcswupdate/UpdateManager", ifName.c_str(), "__Register__");
		msg_iterator iter = msg.writer();
		iter.append(objectPath.c_str());
		msg.end();
		msg_t returnmsg;
		if (IPC_NoError == broker->Send(msg, returnmsg)) {
			msg_iterator r_iter = returnmsg.reader();
			UpdateManager::m_ClientBusRegisterID = r_iter.getInt16();
		}
		else {
			LOGERR((TEXT("UpdateManager: PrepareForAsync failed !\n")));
		}
	}

private:
	typedef msg_t (UpdateManager::*pfnStubMethod)(const msg_t &msg);
#ifdef USE_STL
	struct ltstr {
		bool operator()(const char* s1, const char* s2) const {
			return strcasecmp(s1, s2) < 0;
		}
	};
	typedef map<const char*, pfnStubMethod, ltstr> SignalMap;
	typedef SignalMap::iterator SignalMapIterator;
	SignalMap m_signalMap;
#else
	typedef struct tagSignal {
		const char *name;
		pfnStubMethod method;
	}SignalStub;
	const int signalCount;
	SignalStub m_signals[1];
#endif

	typedef map<kint16_t, IUpdateManagerEvents*> RequestMap;
	typedef RequestMap::iterator RequestMapIterator;
	static RequestMap m_request_map;
protected:
	IIPC *m_broker;
	bool m_isServiceAlive;
	const char *m_name;
	IUpdateManagerEvents *m_pe;
	static kint16_t  m_Requestid;
	kint16_t m_ClientBusRegisterID;
	friend class UpdateManagerObject;
};

class UpdateManagerObject : virtual IServiceProxy , virtual IServiceAdapter{
public:
	UpdateManagerObject(IIPC *pbroker, IUpdateManagerEvents *pe) : m_pbroker(pbroker) {
		m_objPathBuffer = new char[256]();
		sprintf ( m_objPathBuffer, "/com/kivi/ksvcswupdate/UpdateManager_client_%d", ++m_proxyObjectCount);
		int ret = m_pbroker->CreateObject("/com/kivi/ksvcswupdate/UpdateManager", this, &m_Objid,"com.kivi.ksvcswupdate");
		if (ret != IPC_NoError) {
			LOGMSG2("UpdateManagerObject", ("Create Object failed for UpdateManager\n"));
		} else {
			LOGMSG2("UpdateManagerObject", (TEXT("Created Object with id = %d\n"),m_Objid));
			m_UpdateManager.m_broker = m_pbroker;
			m_UpdateManager.m_pe = pe;
		}
		ret = m_pbroker->RegisterObject(m_objPathBuffer, this, &m_ObjclientID);
		if (ret != IPC_NoError) {
			LOGMSG2("UpdateManager",("Register Object failed for /com/kivi/ksvcswupdate/UpdateManager\n"));
		}
		else {
			LOGMSG2("UpdateManager",(TEXT("Register Object with id = %d\n"),m_ObjclientID));
			if(m_pbroker->isServiceAvilable("com.kivi.ksvcswupdate"))
			{
				m_UpdateManager.m_isServiceAlive = true;
				m_UpdateManager.PrepareForAsync(m_UpdateManager.m_name, m_pbroker,m_objPathBuffer);
			}
			else
			{
				m_UpdateManager.m_isServiceAlive = false;
			}
		}
	}
	~UpdateManagerObject() {
		 delete m_objPathBuffer;
	}

	const char* Interface() { return "com.kivi.ksvcswupdate.UpdateManager"; }

	bool HandleMessage(msg_t &msg) {
		if (msg.isSignal()) {
			if (strcasecmp(msg.interface(), "com.kivi.ksvcswupdate.UpdateManager") == 0) {
				LOGINFO2("UpdateManager", (TEXT("emitting signal \n")));
				msg_t ret = m_UpdateManager.HandleMessage(msg);
				m_pbroker->AsyncSend(ret);
			}
			else {
				if(strcasecmp(msg.method(),"NameOwnerChanged") == 0)
				{
					if(m_pbroker->isServiceAvilable("com.kivi.ksvcswupdate"))
					{
						if(!m_UpdateManager.m_isServiceAlive)
						{
							m_UpdateManager.m_isServiceAlive = true;
							m_UpdateManager.PrepareForAsync(m_UpdateManager.m_name, m_pbroker,m_objPathBuffer);
						}
						LOGINFO2("UpdateManager", (TEXT("Service is alive \n")));
					}
					else
					{
						m_UpdateManager.m_isServiceAlive = false;
						LOGINFO2("UpdateManager", (TEXT("Service is not alive \n")));
					}
				}
				return false;
			}
		}
		else if (msg.isMethod()) {
			if (strcasecmp(msg.interface(), "com.kivi.ksvcswupdate.UpdateManager_client") == 0) {
				LOGINFO2("UpdateManager", (TEXT("received callback method \n")));
				msg_t ret = m_UpdateManager.HandleMessage(msg);
				m_pbroker->AsyncSend(ret);
			}
			else {
				return false;
			}
		}
		return true;
	}

public:
	UpdateManager m_UpdateManager;

private:
	IIPC *m_pbroker;
	ObjectID m_Objid;
	ObjectID m_ObjclientID;
	static kint16_t m_proxyObjectCount;
	char* m_objPathBuffer;
};

} //refl
} //mw
} //kivi
#endif /* SETPR_P_H_ */

