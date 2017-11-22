#pragma once
#include "ObserverMaster.h"
class ObserverMaster;
class Message;
class Observer
{
private:
	ObserverMaster* m_master;
public:
	virtual void OnSubscribe(ObserverMaster* obsMaster) { m_master = obsMaster; };
	virtual void OnUnsubscribe() { m_master = nullptr; };
	virtual void OnNotify(Message msg) = 0;
};
