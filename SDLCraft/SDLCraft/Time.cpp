#include "stdafx.h"
#include "Time.h"
#include <ctime>

	namespace Time
	{
		float delta = 0;
		float time = 0;
		void Tick()
		{
			auto tick_time = SDL_GetTicks() / 1000.0f;
			delta = tick_time - time;
			time = tick_time;
		}
	}

	
