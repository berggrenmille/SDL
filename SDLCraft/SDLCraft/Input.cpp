#include "stdafx.h"
#include "Input.h"

namespace MolecularEngine
{
	const Uint8* Input::keyboardState = nullptr;
	bool Input::keyUp[SDL_NUM_SCANCODES] = {false};
	bool Input::keyDown[SDL_NUM_SCANCODES] = {false};
	
	void Input::Update()
	{
		//Update events
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) //Exit program
				m_engine.SendMessage(Message(1, 0 ,(void*)new bool(true)));
			if (e.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				/*SDL_Log("Window %d resized to %dx%d",
					e.window.windowID, e.window.data1,
					e.window.data2);
				WIDTH = e.window.data1; HEIGHT = e.window.data2;
				Resize(e.window.data1, e.window.data2);*/
			}
			UpdateEventState(e);
		}
		UpdateKeyState();
	}

	void Input::SendMessage(Message msg)
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

		if (keyboardState[SDL_GetScancodeFromKey(key)])
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
