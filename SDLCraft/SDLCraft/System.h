#pragma once
#include "Message.h"
class Engine;

class System
{
public:
	virtual void Update() = 0;
	virtual void SendMessage(Message msg) = 0;
	virtual void Initialize() = 0;

	virtual ~System() {};

	Engine& m_engine;
protected:
	System(Engine& e);
};
#include "Engine.h"

inline System::System(Engine& e)
	: m_engine(e)
{
	
};

