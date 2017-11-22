#include "stdafx.h"
#include "MessageBusMaster.h"
#include "Message.h";
MessageBusMaster::MessageBusMaster()
{
}


MessageBusMaster::~MessageBusMaster()
{
}

void MessageBusMaster::Notify(Message msg)
{
	for (auto i = 0; i < subscribers.size(); i++)
	{
		ListHelper::GetListElementAtIndex(subscribers, i)->OnNotify(msg);
	}
}
