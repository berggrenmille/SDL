#include "stdafx.h"
#include "ObserverMaster.h"

bool ObserverMaster::Subscribe(Observer* obs)
{
	if (obs == nullptr)
		return 0;
	obs->OnSubscribe(this);
	subscribers.push_back(obs);
	return 1;
}
bool  ObserverMaster::Unsubscribe(Observer* obs)
{
	if (obs == nullptr)
		return 0;
	subscribers.remove(obs);
	return 1;
}