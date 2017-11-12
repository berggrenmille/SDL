#pragma once
#include "GLMVectors.h"

struct Transform 
{
	// TODO: ADD ALL TRANSFORM FUNCTIONALITY HERE
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	Vector3 Forward();
	Vector3 Up();
	Vector3 Right();
};

