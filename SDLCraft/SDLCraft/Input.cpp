#include "stdafx.h"
#include "Input.h"

namespace MolecularEngine
{
	bool Input::exit = false;
	const Uint8* Input::keyboardState = NULL;
	void Input::UpdateState()
	{
		keyboardState = SDL_GetKeyboardState(NULL);
	}


	bool Input::GetKeyDown(SDL_Keycode key)
	{
		
		if(keyboardState[SDL_GetScancodeFromKey(key)])
			return true;
		else
			return false;
	}
	bool Input::GetKeyDown()
	{
		return false;
	}


}