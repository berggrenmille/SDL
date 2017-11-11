#include "MolecularEngine.h"

class MolecularEngine::Input
{
public:
	static void UpdateState();
	static bool GetKeyDown(SDL_Keycode key);
	static bool GetKeyDown();
private:
	Input();
	static bool exit;
	const static Uint8* keyboardState;
};