#pragma once
#include "MolecularEngine.h"

class MolecularEngine::Time
{
public:
	static float time;
	static float delta;
	static void Tick();
protected:
	Time();
};

