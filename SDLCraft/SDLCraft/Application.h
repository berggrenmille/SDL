#pragma once
#include "Display.h"
#include "Renderer.h"

class Application
{
public:
	Application(Display& display, Renderer& renderer);

	bool running = true;
	void MainLoop() const;

private:
	Display& m_display;
	Renderer& m_renderer;

	void ManageEvents() const;
};

