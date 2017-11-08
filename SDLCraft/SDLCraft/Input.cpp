#include "stdafx.h"
#include "Input.h"

namespace MolecularEngine
{
	bool Input::exit = false;

	bool Input::GetKeyDown(SDL_Keycode key)
	{
		if (key == SDLK_ESCAPE)
			return true;
		else
			return false;
	}
	bool Input::GetKeyDown()
	{
		return false;
	}


}