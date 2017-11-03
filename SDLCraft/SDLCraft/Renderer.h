#pragma once
#include <SDL.h>
#include "Model.h"

class Renderer
{
public:
	Renderer(SDL_Window& window);
	void Render(Model model);
private:
	SDL_Window& boundWindow;
};

