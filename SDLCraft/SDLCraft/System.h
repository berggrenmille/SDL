#pragma once
#include "Engine.h"
class Engine;

class System
{
public:
	
	virtual void Update() = 0;

	virtual void Initialize() = 0;

	virtual ~System() {}

	Engine& m_engine;
protected:
	System(Engine& e);
};

inline System::System(Engine& e)
	: m_engine(e)
{
	
};

