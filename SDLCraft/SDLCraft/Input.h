#include "MolecularEngine.h"

class MolecularEngine::Input
{
public:
	static void UpdateKeyState();
	static void UpdateEventState(SDL_Event& e);
	static bool GetKeyHold(SDL_Keycode key);
	static bool GetKeyDown(SDL_Keycode key);
	static bool GetKeyDown();
	static bool GetKeyUp(SDL_Keycode key);
	static bool GetKeyUp();
private:
	Input()
	{
	}
	static const Uint8* keyboardState;
	static bool keyUp[SDL_NUM_SCANCODES];
	static bool keyDown[SDL_NUM_SCANCODES];
};