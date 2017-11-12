#pragma once
#include "MolecularEngine.h"
///<Summary>Time is responsible for simple management of time</Summary>
class MolecularEngine::Time
{
public:
	static float time;
	static float delta;
	static void Tick();
protected:
	Time(){};
};

