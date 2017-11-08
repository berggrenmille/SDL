#include "MolecularEngine.h"
class MolecularEngine::Input
{
public:
	static bool GetKeyDown(SDL_Keycode key);
	static bool GetKeyDown();
private:
	static bool exit;
};