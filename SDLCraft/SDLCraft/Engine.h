#pragma once
#include "Display.h"
#include "Renderer.h"
#include <thread>
#include "System.h"
#include "Input.h"

class Engine
{
public:
	Engine();
private:
	bool running = true;
	void MainLoop() const;
	void Update() const;

	Display& m_display;
	Renderer& m_renderer;

	std::vector<std::unique_ptr<System>> m_systems = 
	{	std::make_unique<System>(MolecularEngine::Input(*this))
	};
	

	
};

