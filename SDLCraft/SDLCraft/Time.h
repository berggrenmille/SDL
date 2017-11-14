#pragma once
#include "MolecularEngine.h"
#include "System.h"

///<Summary>Time is responsible for simple management of time</Summary>
class MolecularEngine::Time : public System
{
public:
	static float time;
	static float delta;
	static void Tick();
	Time(Engine& e);
	void Update() override;
};

