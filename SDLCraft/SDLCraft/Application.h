#pragma once
#include "Display.h"
#include "Renderer.h"
#include <thread>

class Application
{
public:
	Application();

	bool running = true;
	void MainLoop() const;
	void ManageEvents() const;

private:
	Display& m_display;
	Renderer& m_renderer;
	SDL_Thread* m_inputThread;
	

	
};

