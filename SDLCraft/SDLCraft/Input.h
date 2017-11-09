#include "MolecularEngine.h"
class MolecularEngine::Input
{
#define SDL_KEYCODE_TO_SCANCODE(X) (X & ~(1 << 30))
public:
	static void UpdateState();
	static bool GetKeyDown(SDL_Keycode key);
	static bool GetKeyDown();
private:
	Input();
	static bool exit;
	const static Uint8* keyboardState;
};