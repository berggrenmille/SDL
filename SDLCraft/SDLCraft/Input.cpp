#include "stdafx.h"
#include "Input.h"
#include <mutex>

namespace MolecularEngine
{
	const Uint8* Input::keyboardState = NULL;
	bool Input::keyUp[SDL_NUM_SCANCODES] = {false};
	bool Input::keyDown[SDL_NUM_SCANCODES] = {false};
	
	void Input::Update()
	{
		std::cout << " fiem";
	}
	void Input::Initialize()
	{
		
	}



	void Input::UpdateKeyState()
	{
		keyboardState = SDL_GetKeyboardState(nullptr);	
	}
	void Input::UpdateEventState(SDL_Event& e)
	{
		if (e.key.repeat == 0)
		{
			if (e.type == SDL_KEYDOWN)
			{
				keyDown[e.key.keysym.scancode] = true;
			}
			else if (e.type == SDL_KEYUP)
			{
				keyUp[e.key.keysym.scancode] = true;
				keyDown[e.key.keysym.scancode] = false;
			}
		}
	}


	bool Input::GetKeyHold(SDL_Keycode key)
	{
		if(keyboardState[SDL_GetScancodeFromKey(key)])
			return true;
		return false;
	}
	bool Input::GetKeyDown(SDL_Keycode key)
	{
		if (keyDown[SDL_GetScancodeFromKey(key)])
		{
			keyDown[SDL_GetScancodeFromKey(key)] = false;
			return true;
		}
		return false;
	}
	bool Input::GetKeyUp(SDL_Keycode key)
	{
		if (keyUp[SDL_GetScancodeFromKey(key)])
		{
			keyUp[SDL_GetScancodeFromKey(key)] = false;
			return true;
		}
		return false;
	}

}
