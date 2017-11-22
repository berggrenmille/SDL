#pragma once
#include "Observer.h"
#include <list>
#include "ListHelper.h"
class ObserverMaster
{
protected:
	std::list<Observer*> subscribers;
public:
	bool Subscribe(Observer* obs);
	bool Unsubscribe(Observer* obs);
	virtual void Notify(Message msg) = 0;
};