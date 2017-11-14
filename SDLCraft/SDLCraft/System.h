#pragma once
#include "Message.h"

class Engine;

class System
{
public:

	virtual void Update(){};
	virtual void SendMessage(Message msg){};
	virtual void Init(){};

	virtual ~System() {};

protected:
	System(Engine& e)
		: m_engine(e)
	{};
	Engine& m_engine;

};

#include "Engine.h"

