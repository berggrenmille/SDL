#pragma once
#include "MolecularEngine.h"
#include "System.h"

///<summary>MolecularEngine's abstraction of handling input<summary>
class MolecularEngine::Input : public System
{
public:
	Input(Engine& e)
		: System(e)
	{
	}
	~Input()
	{
		
	}

	virtual void Update() override;
	virtual void Initialize() override;
	virtual void SendMessage(Message msg) override;
	static bool exit;

	static void UpdateKeyState();
	static void UpdateEventState(SDL_Event& e);
	static bool GetKeyHold(SDL_Keycode key);
	static bool GetKeyDown(SDL_Keycode key);
	static bool GetKeyDown();
	static bool GetKeyUp(SDL_Keycode key);
	static bool GetKeyUp();
private:
	
	static const Uint8* keyboardState;
	static bool keyUp[SDL_NUM_SCANCODES];
	static bool keyDown[SDL_NUM_SCANCODES];
};