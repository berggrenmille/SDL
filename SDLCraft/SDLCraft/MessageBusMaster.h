#pragma once
#include "ObserverMaster.h"
class MessageBusMaster :
	public ObserverMaster
{
public:
	MessageBusMaster();
	~MessageBusMaster();
	void Notify(Message msg) override;
};

