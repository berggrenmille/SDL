#include "stdafx.h"
#include "Time.h"
#include <ctime>

namespace MolecularEngine
{
	float Time::delta = 0;
	float Time::time = 0;
	void Time::Tick()
	{
		auto tick_time = SDL_GetTicks() / 1000.0f;
		delta = tick_time - time;
		time = tick_time;
	}

	void Time::Update()
	{
		Tick();
	}

	Time::Time(Engine& e)
		:	System(e)
	{
	}
}

	
